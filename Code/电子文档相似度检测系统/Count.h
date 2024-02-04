#if !defined(AFX_COUNT_H__85F97189_587F_470D_8F4E_8F0F65D2203A__INCLUDED_)
#define AFX_COUNT_H__85F97189_587F_470D_8F4E_8F0F65D2203A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Count.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCount dialog

class CCount : public CDialog
{
// Construction
public:
	CCount(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCount)
	enum { IDD = IDD_Count };
	CEdit	m_sentence;
	CEdit	m_cou2;
	CEdit	m_cout1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCount)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCount)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COUNT_H__85F97189_587F_470D_8F4E_8F0F65D2203A__INCLUDED_)
