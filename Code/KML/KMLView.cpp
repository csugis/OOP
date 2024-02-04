// KMLView.cpp : CKMLView 类的实现
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

// CKMLView 构造/析构

CKMLView::CKMLView()
{
	// TODO: 在此处添加构造代码

}

CKMLView::~CKMLView()
{
}

BOOL CKMLView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CTreeView::PreCreateWindow(cs);
}

void CKMLView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

}


// CKMLView 诊断

#ifdef _DEBUG
void CKMLView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CKMLView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CKMLDoc* CKMLView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKMLDoc)));
	return (CKMLDoc*)m_pDocument;
}
#endif //_DEBUG


// CKMLView 消息处理程序
