// ToolDrawFillCircle.cpp: implementation of the CToolDrawFillCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolDrawFillCircle.h"
#include <cmath>
#include "GISDrawDoc.h"
#include "Round.h"
#include "MainFrm.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolDrawFillCircle::CToolDrawFillCircle(CView * ownerObj):CBaseTool(ownerObj),m_dRadius(0.0)
{
	SetToolType(toolTypeDrawFillCircle);
}

CToolDrawFillCircle::~CToolDrawFillCircle()
{

}

//在此可作交互处理
short CToolDrawFillCircle::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags) {
	CDC *pdc = m_pView->GetDC();
	int nOldROP2 = pdc->SetROP2(R2_NOTXORPEN);
	CPen pen, *pOldPen=NULL;
	CBrush brush, *pOldBrush=NULL;
	int penStyle = PS_SOLID;
	int penWidth = 1;
	COLORREF penColor = RGB(0,0,0);
	COLORREF brushColor = RGB(0,0,255);
	CMainFrame* pMainFrm=(CMainFrame*)AfxGetMainWnd();
	if(pMainFrm->m_pGeoDlg!=NULL)
	{
		penStyle=pMainFrm->m_pGeoDlg->GetPenStyle();
		penWidth=pMainFrm->m_pGeoDlg->GetPenWidth();
		penColor=pMainFrm->m_pGeoDlg->GetPenColor();
		brushColor=pMainFrm->m_pGeoDlg->GetBrushColor();
	}
    pen.CreatePen(penStyle,penWidth,penColor);
	brush.CreateSolidBrush(brushColor);
	static long startx;
	static long starty;
	static long endx;
	static long endy;
	static bool flagsetcapture=0;
	switch(msg) {
	    case WM_LBUTTONDOWN:
			m_ptXY=*xy;
			startx = xy->x;
			starty = xy->y;
			endx = xy->x;
			endy = xy->y;
    		pOldPen=pdc->SelectObject(&pen);
			pOldBrush=pdc->SelectObject(&brush);
			pdc->Ellipse(startx,starty,endx,endy);
			pdc->SelectObject(pOldPen);
			pdc->SelectObject(pOldBrush);
			flagsetcapture = 1;
			break;
        case WM_MOUSEMOVE:
			if(flagsetcapture==1){   
				pOldPen=pdc->SelectObject(&pen);
				pOldBrush=pdc->SelectObject(&brush);
				pdc->Ellipse(startx,starty,endx,endy);
				m_dRadius = sqrt(pow(xy->x-m_ptXY.x,2)+pow(xy->y-m_ptXY.y,2));
				startx = (long)(m_ptXY.x-m_dRadius);
				starty = (long)(m_ptXY.y+m_dRadius);
				endx = (long)(m_ptXY.x+m_dRadius);
				endy = (long)(m_ptXY.y-m_dRadius);				
                pdc->Ellipse(startx,starty,endx,endy);
				pdc->SelectObject(pOldPen);                        
				pdc->SelectObject(pOldBrush);
			}
			break;
        case WM_LBUTTONUP:
			if(flagsetcapture==1)
			{
				pOldPen=pdc->SelectObject(&pen);
				pOldBrush=pdc->SelectObject(&brush);
				//pdc->Ellipse(startx,starty,endx,endy);
				pdc->SelectObject(pOldPen);                        
				pdc->SelectObject(pOldBrush);
				flagsetcapture = 0;
				//添加到管理器中
				CGISDrawDoc *pDoc=(CGISDrawDoc*)m_pView->GetDocument();
				PointStruct pt;
				pt = m_ptXY;
				CRound* pGeo=new CRound;
				pGeo->SetLineType(penStyle);
				pGeo->SetLineWidth(penWidth);
				pGeo->SetPenColor(penColor);
				pGeo->SetBrushColor(brushColor);
				pGeo->SetCenter(pt);
				pGeo->SetRadius(m_dRadius);
				pGeo->Fill();
				pDoc->m_objManager.InsertGeometryToLayer(pGeo);
			}
			break;                    
	}
	pdc->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pdc);	
	return 1;
}
