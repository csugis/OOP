#if !defined(AFX_LEFTVIEW_H__F806FB29_9B40_4432_84C9_765833F8FA3D__INCLUDED_)
#define AFX_LEFTVIEW_H__F806FB29_9B40_4432_84C9_765833F8FA3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftView.h : header file
//
#include <Afxcview.h>
/////////////////////////////////////////////////////////////////////////////
// CLeftView view

class CLeftView : public CTreeView
{
protected:
	//CLeftView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftView)

// Attributes
public:
  CLeftView(); 
// Operations
public:
	void AddColor();
	COLORREF m_Color;
	virtual ~CLeftView();

//	m_str CString;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL
// Implementation
protected:
	//virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CLeftView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTVIEW_H__F806FB29_9B40_4432_84C9_765833F8FA3D__INCLUDED_)
