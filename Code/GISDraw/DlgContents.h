#if !defined(AFX_DLGCONTENTS_H__D44A168C_124F_4798_92E2_C556C2998B5B__INCLUDED_)
#define AFX_DLGCONTENTS_H__D44A168C_124F_4798_92E2_C556C2998B5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgContents.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgContents dialog

class CDlgContents : public CDialog
{
// Construction
public:
	CDlgContents(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgContents)
	enum { IDD = IDD_CONTENTS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgContents)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgContents)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONTENTS_H__D44A168C_124F_4798_92E2_C556C2998B5B__INCLUDED_)
