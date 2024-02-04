#if !defined(AFX_HEXVIEW_H__766B3C3F_577B_4B5B_A5A5_742781EBE539__INCLUDED_)
#define AFX_HEXVIEW_H__766B3C3F_577B_4B5B_A5A5_742781EBE539__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HexView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHexView view

class CHexView : public CView
{
protected:
	CHexView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CHexView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CHexView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CHexView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXVIEW_H__766B3C3F_577B_4B5B_A5A5_742781EBE539__INCLUDED_)
