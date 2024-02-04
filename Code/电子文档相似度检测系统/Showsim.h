#if !defined(AFX_SHOWSIM_H__0AEF51C0_0692_47F3_99D5_9AE3B7134521__INCLUDED_)
#define AFX_SHOWSIM_H__0AEF51C0_0692_47F3_99D5_9AE3B7134521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Showsim.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Showsim dialog

class Showsim : public CDialog
{
// Construction
public:
	void OutputSim();
	Showsim(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Showsim)
	enum { IDD = IDD_Showsim };
	CEdit	m_CSize2;
	CEdit	m_CSize;
	CEdit	m_Sim;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Showsim)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Showsim)
	afx_msg void OnAppAbout();
	afx_msg void OnChangeEdit1();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSIM_H__0AEF51C0_0692_47F3_99D5_9AE3B7134521__INCLUDED_)
