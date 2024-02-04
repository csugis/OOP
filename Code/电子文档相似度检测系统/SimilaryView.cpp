// SimilaryView.cpp : implementation of the CSimilaryView class
//

#include "stdafx.h"
#include "Similary.h"

#include "SimilaryDoc.h"
#include "SimilaryView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView

IMPLEMENT_DYNCREATE(CSimilaryView, CView)

BEGIN_MESSAGE_MAP(CSimilaryView, CView)
	//{{AFX_MSG_MAP(CSimilaryView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView construction/destruction

CSimilaryView::CSimilaryView()
{
	// TODO: add construction code here

}

CSimilaryView::~CSimilaryView()
{
}

BOOL CSimilaryView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView drawing

void CSimilaryView::OnDraw(CDC* pDC)
{
	CSimilaryDoc* pDoc=GetDocument();
	ASSERT_VALID(pDoc);
 	// TODO: add draw code for native data here
	//	pDC->TextOut(0,0,"hello");
}

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView printing

BOOL CSimilaryView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSimilaryView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSimilaryView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView diagnostics

#ifdef _DEBUG
void CSimilaryView::AssertValid() const
{
	CView::AssertValid();
}

void CSimilaryView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSimilaryDoc* CSimilaryView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSimilaryDoc)));
	return (CSimilaryDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimilaryView message handlers

void CSimilaryView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
}
