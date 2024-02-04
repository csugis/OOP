#if !defined(AFX_PARAGRAPH_H__ECBD43CC_1E97_4375_8B1C_86E060DAC2CD__INCLUDED_)
#define AFX_PARAGRAPH_H__ECBD43CC_1E97_4375_8B1C_86E060DAC2CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Paragraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CParagraph dialog

class CParagraph : public CDialog
{
// Construction
public:
	CParagraph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CParagraph)
	enum { IDD = IDD_Paragraph };
	CEdit	m_para;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParagraph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParagraph)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARAGRAPH_H__ECBD43CC_1E97_4375_8B1C_86E060DAC2CD__INCLUDED_)
