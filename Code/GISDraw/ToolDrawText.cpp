// ToolDrawText.cpp: implementation of the CToolDrawText class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolDrawText.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolDrawText::CToolDrawText(CView * ownerObj)
					:CBaseTool(ownerObj)
{

}

CToolDrawText::~CToolDrawText()
{

}

//在此可作交互处理
short CToolDrawText::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags)
{
	CDC *pdc = m_pView->GetDC();

	switch(msg)
	{
	    case WM_LBUTTONDOWN:
			pdc->TextOut(xy->x,xy->y,"hhhh");
			break;
		default:
			break;
	}
	m_pView->ReleaseDC(pdc);	
	return 1;
}

