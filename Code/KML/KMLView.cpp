// KMLView.cpp : CKMLView ���ʵ��
//

#include "stdafx.h"
#include "KML.h"

#include "KMLDoc.h"
#include "KMLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKMLView

IMPLEMENT_DYNCREATE(CKMLView, CTreeView)

BEGIN_MESSAGE_MAP(CKMLView, CTreeView)
END_MESSAGE_MAP()

// CKMLView ����/����

CKMLView::CKMLView()
{
	// TODO: �ڴ˴���ӹ������

}

CKMLView::~CKMLView()
{
}

BOOL CKMLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CTreeView::PreCreateWindow(cs);
}

void CKMLView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// CKMLView ���

#ifdef _DEBUG
void CKMLView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CKMLView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CKMLDoc* CKMLView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKMLDoc)));
	return (CKMLDoc*)m_pDocument;
}
#endif //_DEBUG


// CKMLView ��Ϣ�������
