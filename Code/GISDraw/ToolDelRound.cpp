// ToolDelRound.cpp: implementation of the CToolDelRound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GISDraw.h"
#include "ToolDelRound.h"
#include "GISDrawDoc.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CToolDelRound::CToolDelRound(CView * ownerObj)
					:CBaseTool(ownerObj),m_pSelected(NULL),m_pCurLyr(NULL)
{
}

void CToolDelRound::SetGeometryType(unsigned char type)
{
	switch(type)
	{
	case geoTypeCircle:
		SetToolType(toolTypeDelCircle);
		break;
	case geoTypeRound:
		SetToolType(toolTypeDelFillCircle);
		break;
	}
	//�õ�ѡ���ͼ��
	CGISDrawDoc *pDoc=(CGISDrawDoc*)m_pView->GetDocument();
	m_pCurLyr=pDoc->m_objManager.GetLayerByType(type);
	CBaseTool::SetGeometryType(type);
}

CToolDelRound::~CToolDelRound()
{
	if(m_pSelected != NULL)
		m_pSelected->UnSelect();
}

//�ڴ˿�����������
short CToolDelRound::ProcMouse(UINT msg,CPoint * xy,UINT keyFlags) {
	CDC *pDC = m_pView->GetDC();
	switch(msg) {
	case WM_LBUTTONDOWN:
		//�����û��ѡ��
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
			if(AfxMessageBox("�Ƿ�ɾ����ͼ�Σ�\n",MB_YESNO) == IDYES)
				m_pSelected->Delete();
			m_pSelected->UnSelect();
			m_pSelected=NULL;
			m_pView->Invalidate();
		}
		break;
	}
	m_pView->ReleaseDC(pDC);	
	return 1;
}
