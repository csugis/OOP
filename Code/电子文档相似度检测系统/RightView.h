#if !defined(AFX_RIGHTVIEW_H__2422C50F_1635_4FA8_A012_99DC92952B1F__INCLUDED_)
#define AFX_RIGHTVIEW_H__2422C50F_1635_4FA8_A012_99DC92952B1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RightView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRightView view

class CRightView : public CView
{
protected:
//	CRightView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CRightView)

// Attributes
public:
CRightView();    
// Operations
public:
	void AddColor();
	COLORREF m_Color1;
    virtual ~CRightView();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRightView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	//virtual ~CRightView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CRightView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RIGHTVIEW_H__2422C50F_1635_4FA8_A012_99DC92952B1F__INCLUDED_)
