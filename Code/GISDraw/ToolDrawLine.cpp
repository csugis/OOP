// ToolDrawLine.cpp: implementation of the CToolDrawLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolDrawLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolDrawLine::CToolDrawLine(CView * ownerObj):CBaseTool(ownerObj)
{
	SetToolType(toolTypeDrawLine);
}

CToolDrawLine::~CToolDrawLine()
{

}

//在此可作交互处理
short CToolDrawLine::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags)
{
	CDC *pdc = m_pView->GetDC();
	int nOldROP2 = pdc->SetROP2(R2_NOTXORPEN);
	CPen pen, *pOldPen=NULL;
    pen.CreatePen(PS_SOLID,1,RGB(0,0,0));
	static bool flagsetcapture=0;
	switch(msg)	{
	    case WM_LBUTTONDOWN:
			m_ptStart=*xy;
			m_ptEnd=*xy;
    		pOldPen=pdc->SelectObject(&pen);
			pdc->MoveTo(m_ptStart);
			pdc->LineTo(m_ptEnd);
			pdc->SelectObject(pOldPen);
			flagsetcapture = 1;
			break;
        case WM_MOUSEMOVE:
			if(flagsetcapture==1) {   
				pOldPen=pdc->SelectObject(&pen);
				pdc->MoveTo(m_ptStart);
				pdc->LineTo(m_ptEnd);
				m_ptEnd=*xy;				
				pdc->MoveTo(m_ptStart);
				pdc->LineTo(m_ptEnd);
				pdc->SelectObject(pOldPen);                        
			}
			break;
        case WM_LBUTTONUP:
			pOldPen=pdc->SelectObject(&pen);
			pdc->MoveTo(m_ptStart);
			pdc->LineTo(m_ptEnd);
			pdc->SelectObject(pOldPen);                        
			flagsetcapture = 0;
			break;                    
	}
	pdc->SetROP2(nOldROP2);
	m_pView->ReleaseDC(pdc);	
	return 1;
}
