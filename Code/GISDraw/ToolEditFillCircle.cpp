// ToolEditFillCircle.cpp: implementation of the CToolMoveRound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolEditFillCircle.h"
#include "GISDrawDoc.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolMoveRound::CToolMoveRound(CView * ownerObj)
					:CBaseTool(ownerObj),m_pSelected(NULL),m_pCurLyr(NULL)
{
}

void CToolMoveRound::SetGeometryType(unsigned char type)
{
	switch(type)
	{
	case geoTypeCircle:
		SetToolType(toolTypeMoveCircle);
		break;
	case geoTypeRound:
		SetToolType(toolTypeMoveFillCircle);
		break;
	}
	//得到选择的图层
	CGISDrawDoc *pDoc=(CGISDrawDoc*)m_pView->GetDocument();
	m_pCurLyr=pDoc->m_objManager.GetLayerByType(type);
	CBaseTool::SetGeometryType(type);
}

CToolMoveRound::~CToolMoveRound()
{
	if(m_pSelected != NULL)
		m_pSelected->UnSelect();
}

//在此可作交互处理
short CToolMoveRound::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags) {
	CDC *pDC = m_pView->GetDC();
	int nOldROP2 = pDC->SetROP2(R2_NOTXORPEN);
	switch(msg) {
	case WM_LBUTTONDOWN:
		//如果还没有选择
		if(m_pSelected==NULL)
		{
			if(m_pCurLyr != NULL)
			{
				PointStruct pt;
				pt = *xy;
				m_pSelected = m_pCurLyr->Search(pt,1.0f);
			}
		}
		if(m_pSelected!=NULL)
		{
			m_pSelected->Select();
			m_pView->Invalidate();
		}
		break;
    case WM_MOUSEMOVE:
		if(m_pSelected != NULL)
		{
			m_pSelected->Draw(pDC);
			PointStruct pt;
			pt = *xy;
			m_pSelected->MoveTo(pt);
			m_pSelected->Draw(pDC);
		}
		break;
    case WM_LBUTTONUP:
		if(m_pSelected != NULL)
		{
			m_pSelected->Draw(pDC);
			m_pSelected->UnSelect();
			m_pSelected=NULL;
			m_pView->Invalidate();
		}
		break;                    
	}
	pDC->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pDC);	
	return 1;
}
