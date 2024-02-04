#if !defined(AFX_SIMPART_H__65F33847_5BB2_45B8_B210_DEC10492B780__INCLUDED_)
#define AFX_SIMPART_H__65F33847_5BB2_45B8_B210_DEC10492B780__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SimPart.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSimPart dialog

class CSimPart : public CDialog
{
// Construction
public:
	CSimPart(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSimPart)
	enum { IDD = IDD_SimPart };
	CEdit	m_paredit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimPart)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSimPart)
	afx_msg void OnClickRichedit1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMPART_H__65F33847_5BB2_45B8_B210_DEC10492B780__INCLUDED_)
