// GISDrawView.h : interface of the CGISDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GISDRAWVIEW_H__CB6D2C8C_6A17_4BB6_8560_90B39FE9B263__INCLUDED_)
#define AFX_GISDRAWVIEW_H__CB6D2C8C_6A17_4BB6_8560_90B39FE9B263__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "BaseTool.h"
#include "DlgSetBkColor.h"

class CGISDrawView : public CView
{
protected: // create from serialization only
	CGISDrawView();
	DECLARE_DYNCREATE(CGISDrawView)

// Attributes
public:
	CGISDrawDoc* GetDocument();
	CBaseTool*	m_pCurTool;
	COLORREF m_bkClr;
	CDlgSetBkColor* m_pClrDlg;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGISDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGISDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGISDrawView)
	afx_msg void OnDrawArc();
	afx_msg void OnUpdateDrawArc(CCmdUI* pCmdUI);
	afx_msg void OnDrawBeeline();
	afx_msg void OnUpdateDrawBeeline(CCmdUI* pCmdUI);
	afx_msg void OnDrawCircle();
	afx_msg void OnUpdateDrawCircle(CCmdUI* pCmdUI);
	afx_msg void OnDrawCircleFill();
	afx_msg void OnUpdateDrawCircleFill(CCmdUI* pCmdUI);
	afx_msg void OnDrawPolygon();
	afx_msg void OnUpdateDrawPolygon(CCmdUI* pCmdUI);
	afx_msg void OnDrawPolyline();
	afx_msg void OnUpdateDrawPolyline(CCmdUI* pCmdUI);
	afx_msg void OnDrawText();
	afx_msg void OnUpdateDrawText(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnDeleteTool();
	afx_msg void OnUpdateDeleteTool(CCmdUI* pCmdUI);
	afx_msg void OnEditFillCircle();
	afx_msg void OnUpdateEditFillCircle(CCmdUI* pCmdUI);
	afx_msg void OnTest();
	afx_msg void OnUpdateTest(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnBkColor();
	afx_msg void OnMoveCircle();
	afx_msg void OnUpdateMoveCircle(CCmdUI* pCmdUI);
	afx_msg void OnDelCircle();
	afx_msg void OnUpdateDelCircle(CCmdUI* pCmdUI);
	afx_msg void OnDelFillCircle();
	afx_msg void OnUpdateDelFillCircle(CCmdUI* pCmdUI);
	afx_msg void OnText();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GISDrawView.cpp
inline CGISDrawDoc* CGISDrawView::GetDocument()
   { return (CGISDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GISDRAWVIEW_H__CB6D2C8C_6A17_4BB6_8560_90B39FE9B263__INCLUDED_)
