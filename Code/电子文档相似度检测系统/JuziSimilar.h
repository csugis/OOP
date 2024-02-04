#if !defined(AFX_JUZISIMILAR_H__60132FB5_E1B2_431B_96E4_D141A5149CA1__INCLUDED_)
#define AFX_JUZISIMILAR_H__60132FB5_E1B2_431B_96E4_D141A5149CA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JuziSimilar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJuziSimilar dialog

class CJuziSimilar : public CDialog
{
// Construction
public:
	CJuziSimilar(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CJuziSimilar)
	enum { IDD = IDD_juzihelp };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJuziSimilar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CJuziSimilar)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JUZISIMILAR_H__60132FB5_E1B2_431B_96E4_D141A5149CA1__INCLUDED_)
