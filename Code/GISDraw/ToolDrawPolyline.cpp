// ToolDrawPolyline.cpp: implementation of the CToolDrawPolyline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolDrawPolyline.h"
#include "GISDrawDoc.h"
#include "Curve.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolDrawPolyline::CToolDrawPolyline(CView * ownerObj):CBaseTool(ownerObj){
	SetToolType(toolTypeDrawPolyline);
	m_pPoints=new CPoint[NUM_NEW_POINTS];
	m_lSize=NUM_NEW_POINTS;
}

CToolDrawPolyline::~CToolDrawPolyline()
{
	if(m_pPoints!=NULL)
		delete [] m_pPoints;
	m_vPoints.clear();
}

CPoint* CToolDrawPolyline::GetVertex(){
	long lOldSize = m_lSize;
	while(m_lSize<m_vPoints.size())
		m_lSize+=NUM_NEW_POINTS;
	if(m_lSize>lOldSize){
		delete [] m_pPoints;
		m_pPoints = new CPoint[m_lSize];
	}
	for(long i=0; i<m_vPoints.size(); i++)
		m_pPoints[i]=m_vPoints[i];
	return m_pPoints;
}

BOOL CToolDrawPolyline::DrawPolyline(CDC* pDC){
	long lSize=m_vPoints.size();
	if(lSize==1){
		pDC->MoveTo(m_vPoints[0]);
		return pDC->LineTo(m_vPoints[0]);
	}
	else if(lSize==2){
		pDC->MoveTo(m_vPoints[0]);
		return pDC->LineTo(m_vPoints[1]);
	}
	else if(lSize>2)
		return pDC->Polyline(GetVertex(),m_vPoints.size());
	else
		return FALSE;
}

//在此可作交互处理
short CToolDrawPolyline::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags)
{
	CDC *pdc = m_pView->GetDC();
	int nOldROP2 = pdc->SetROP2(R2_NOTXORPEN);
	CPen pen, *pOldPen=NULL;
	CBrush brush, *pOldBrush=NULL;
    pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	brush.CreateSolidBrush(RGB(0,0,255));
	CPoint ptXY;
	static bool flagsetcapture=0;
	switch(msg) {
	    case WM_LBUTTONDOWN:
    		pOldPen=pdc->SelectObject(&pen);
			pOldBrush=pdc->SelectObject(&brush);
			DrawPolyline(pdc);
			ptXY=*xy;
			m_vPoints.push_back(ptXY);
			DrawPolyline(pdc);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
			flagsetcapture = 1;
			break;
        case WM_MOUSEMOVE:
			if(flagsetcapture==1){   
				pOldPen=pdc->SelectObject(&pen);
				pOldBrush=pdc->SelectObject(&brush);
				DrawPolyline(pdc);
				if(m_vPoints.size()>1)
					m_vPoints.pop_back();
				ptXY=*xy;
				m_vPoints.push_back(ptXY);
				DrawPolyline(pdc);
				pdc->SelectObject(pOldPen);                        
				pdc->SelectObject(pOldBrush);
			}
			break;
		case WM_RBUTTONDOWN:
			if(flagsetcapture==1)
			{
				pOldPen=pdc->SelectObject(&pen);
				pOldBrush=pdc->SelectObject(&brush);
				//DrawPolyline(pdc);
				pdc->SelectObject(pOldPen);                        
				pdc->SelectObject(pOldBrush);
				flagsetcapture=0;
				//添加到管理器
				CGISDrawDoc *pDoc=(CGISDrawDoc*)m_pView->GetDocument();
				PointStruct pt;
				CCurve* pGeo=new CCurve;
				pGeo->SetLineType(PS_SOLID);
				pGeo->SetLineWidth(1);
				pGeo->SetPenColor(RGB(0,0,0));
				pGeo->SetBrushColor(RGB(0,0,255));
				for(int i=0; i<m_vPoints.size(); i++)
				{
					pt = m_vPoints[i];
					pGeo->InsertPoints(pt);
				}
				pDoc->m_objManager.InsertGeometryToLayer(pGeo);
				m_vPoints.clear();
			}
			break;
	}
	pdc->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pdc);	
	return 1;
}
