// GISDrawView.cpp : implementation of the CGISDrawView class
//

#include "stdafx.h"
#include "GISDraw.h"

#include "GISDrawDoc.h"
#include "GISDrawView.h"
#include "ToolDrawCircle.h"
#include "ToolDrawLine.h"
#include "ToolDrawFillCircle.h"
#include "ToolDrawPolygon.h"
#include "ToolDrawPolyline.h"
#include "ToolEditFillCircle.h"
#include "ToolDelRound.h"
#include "ToolDrawText.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView

IMPLEMENT_DYNCREATE(CGISDrawView, CView)

BEGIN_MESSAGE_MAP(CGISDrawView, CView)
	//{{AFX_MSG_MAP(CGISDrawView)
	ON_COMMAND(ID_DRAW_ARC, OnDrawArc)
	ON_UPDATE_COMMAND_UI(ID_DRAW_ARC, OnUpdateDrawArc)
	ON_COMMAND(ID_DRAW_BEELINE, OnDrawBeeline)
	ON_UPDATE_COMMAND_UI(ID_DRAW_BEELINE, OnUpdateDrawBeeline)
	ON_COMMAND(ID_DRAW_CIRCLE, OnDrawCircle)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE, OnUpdateDrawCircle)
	ON_COMMAND(ID_DRAW_CIRCLE_FILL, OnDrawCircleFill)
	ON_UPDATE_COMMAND_UI(ID_DRAW_CIRCLE_FILL, OnUpdateDrawCircleFill)
	ON_COMMAND(ID_DRAW_POLYGON, OnDrawPolygon)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYGON, OnUpdateDrawPolygon)
	ON_COMMAND(ID_DRAW_POLYLINE, OnDrawPolyline)
	ON_UPDATE_COMMAND_UI(ID_DRAW_POLYLINE, OnUpdateDrawPolyline)
	ON_COMMAND(ID_DRAW_TEXT, OnDrawText)
	ON_UPDATE_COMMAND_UI(ID_DRAW_TEXT, OnUpdateDrawText)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_DELETE_TOOL, OnDeleteTool)
	ON_UPDATE_COMMAND_UI(ID_DELETE_TOOL, OnUpdateDeleteTool)
	ON_COMMAND(ID_EDIT_FILL_CIRCLE, OnEditFillCircle)
	ON_UPDATE_COMMAND_UI(ID_EDIT_FILL_CIRCLE, OnUpdateEditFillCircle)
	ON_COMMAND(ID_TEST, OnTest)
	ON_UPDATE_COMMAND_UI(ID_TEST, OnUpdateTest)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_BK_COLOR, OnBkColor)
	ON_COMMAND(ID_MOVE_CIRCLE, OnMoveCircle)
	ON_UPDATE_COMMAND_UI(ID_MOVE_CIRCLE, OnUpdateMoveCircle)
	ON_COMMAND(ID_DEL_CIRCLE, OnDelCircle)
	ON_UPDATE_COMMAND_UI(ID_DEL_CIRCLE, OnUpdateDelCircle)
	ON_COMMAND(ID_DEL_FILL_CIRCLE, OnDelFillCircle)
	ON_UPDATE_COMMAND_UI(ID_DEL_FILL_CIRCLE, OnUpdateDelFillCircle)
	ON_COMMAND(ID_TEXT, OnText)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView construction/destruction

CGISDrawView::CGISDrawView()
	:m_pCurTool(NULL),m_bkClr(RGB(255,255,255)),m_pClrDlg(NULL)
{
	// TODO: add construction code here

}

CGISDrawView::~CGISDrawView()
{
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	if(m_pClrDlg!=NULL)
		delete m_pClrDlg;
}

BOOL CGISDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView drawing

void CGISDrawView::OnDraw(CDC* pDC)
{
	CGISDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->SetBkMode(TRANSPARENT);
	pDoc->m_objManager.Draw(pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView printing

BOOL CGISDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGISDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGISDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView diagnostics

#ifdef _DEBUG
void CGISDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CGISDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGISDrawDoc* CGISDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGISDrawDoc)));
	return (CGISDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGISDrawView message handlers

void CGISDrawView::OnDrawArc() 
{
	// TODO: Add your command handler code here
	
}

void CGISDrawView::OnUpdateDrawArc(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawArc)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawBeeline() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawLine(this);
}

void CGISDrawView::OnUpdateDrawBeeline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawLine)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawCircle() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawCircle(this);
}

void CGISDrawView::OnUpdateDrawCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawCircleFill() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawFillCircle(this);
}

void CGISDrawView::OnUpdateDrawCircleFill(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawFillCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawPolygon() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawPolygon(this);
}

void CGISDrawView::OnUpdateDrawPolygon(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawPolygon)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawPolyline() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawPolyline(this);
}

void CGISDrawView::OnUpdateDrawPolyline(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawPolyline)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDrawText() 
{
	// TODO: Add your command handler code here
	
}

void CGISDrawView::OnUpdateDrawText(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDrawText)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_LBUTTONDOWN,&point,nFlags);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CGISDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_LBUTTONUP,&point,nFlags);
	}
	CView::OnLButtonUp(nFlags, point);
}

void CGISDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_MOUSEMOVE,&point,nFlags);
	}
	CView::OnMouseMove(nFlags, point);
}

void CGISDrawView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_RBUTTONDOWN,&point,nFlags);
	}
	CView::OnRButtonDown(nFlags, point);
}

void CGISDrawView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_RBUTTONUP,&point,nFlags);
	}
	CView::OnRButtonUp(nFlags, point);
}

void CGISDrawView::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_RBUTTONDBLCLK,&point,nFlags);
	}
	CView::OnRButtonDblClk(nFlags, point);
}

void CGISDrawView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pCurTool!=NULL)
	{
		m_pCurTool->ProcMouse(WM_LBUTTONDBLCLK,&point,nFlags);
	}
	CView::OnLButtonDblClk(nFlags, point);
}

void CGISDrawView::OnDeleteTool() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
	{
		delete m_pCurTool;
		m_pCurTool = NULL;
	}
}

void CGISDrawView::OnUpdateDeleteTool(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_pCurTool!=NULL);
}

void CGISDrawView::OnEditFillCircle() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolMoveRound(this);
	m_pCurTool->SetGeometryType(geoTypeRound);
}

void CGISDrawView::OnUpdateEditFillCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeMoveFillCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
	
}

void CGISDrawView::OnTest() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
	{
		CString strToolInfo="";
		strToolInfo.Format("当前使用的工具类型：%d",m_pCurTool->GetToolType());
		AfxMessageBox(strToolInfo);
	}
}

void CGISDrawView::OnUpdateTest(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_pCurTool!=NULL);
}

BOOL CGISDrawView::OnEraseBkgnd(CDC* pDC) {
	CBrush brush;
	brush.CreateSolidBrush(m_bkClr);
	CRect rect;
	GetClientRect(&rect);
	pDC->FillRect( rect, &brush );
	return TRUE/*CView::OnEraseBkgnd(pDC)*/;
}
void CGISDrawView::OnBkColor(){
	// TODO: Add your command handler code here
	if(m_pClrDlg==NULL){
		m_pClrDlg = new CDlgSetBkColor;
		m_pClrDlg->Create(IDD_BKCOLOR,this);
	}
	m_pClrDlg->ShowWindow(SW_SHOW);
}

void CGISDrawView::OnMoveCircle() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolMoveRound(this);
	m_pCurTool->SetGeometryType(geoTypeCircle);
}

void CGISDrawView::OnUpdateMoveCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeMoveCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDelCircle() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDelRound(this);
	m_pCurTool->SetGeometryType(geoTypeCircle);
}

void CGISDrawView::OnUpdateDelCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDelCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnDelFillCircle() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDelRound(this);
	m_pCurTool->SetGeometryType(geoTypeRound);
}

void CGISDrawView::OnUpdateDelFillCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	BOOL bCheck=FALSE;
	if(m_pCurTool!=NULL)
	{
		bCheck=(m_pCurTool->GetToolType()==toolTypeDelFillCircle)?TRUE:FALSE;
	}
	pCmdUI->SetCheck(bCheck);
}

void CGISDrawView::OnText() 
{
	// TODO: Add your command handler code here
	if(m_pCurTool!=NULL)
		delete m_pCurTool;
	m_pCurTool = new CToolDrawText(this);	
}
