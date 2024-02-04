#if !defined(AFX_LONGTH_H__E35CD0ED_FD0B_4319_A91D_36A8D3C07170__INCLUDED_)
#define AFX_LONGTH_H__E35CD0ED_FD0B_4319_A91D_36A8D3C07170__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Longth.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLongth dialog

class CLongth : public CDialog
{
// Construction
public:
	CLongth(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLongth)
	enum { IDD = IDD_Longth };
	CEdit	m_charnum;
	CEdit	m_unit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLongth)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLongth)
	afx_msg void OnTipy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LONGTH_H__E35CD0ED_FD0B_4319_A91D_36A8D3C07170__INCLUDED_)
