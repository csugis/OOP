// HexView.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "HexView.h"
#include "SimilaryDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHexView

IMPLEMENT_DYNCREATE(CHexView, CView)

CHexView::CHexView()
{
}

CHexView::~CHexView()
{
}


BEGIN_MESSAGE_MAP(CHexView, CView)
	//{{AFX_MSG_MAP(CHexView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHexView drawing

void CHexView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();

	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CHexView diagnostics

#ifdef _DEBUG
void CHexView::AssertValid() const
{
	CView::AssertValid();
}

void CHexView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHexView message handlers
