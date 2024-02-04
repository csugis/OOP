#if !defined(AFX_OUTPUTSEN_H__7EE41E98_BB12_465F_A3EF_EB884568BC2B__INCLUDED_)
#define AFX_OUTPUTSEN_H__7EE41E98_BB12_465F_A3EF_EB884568BC2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputSen.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputSen dialog

class COutputSen : public CDialog
{
// Construction
public:
	COutputSen(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputSen)
	enum { IDD = IDD_Simsen };
	CEdit	m_outsen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputSen)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutputSen)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTSEN_H__7EE41E98_BB12_465F_A3EF_EB884568BC2B__INCLUDED_)
