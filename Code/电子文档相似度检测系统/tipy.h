#if !defined(AFX_TIPY_H__7E332719_366C_45F0_A6B1_C3F109AC2003__INCLUDED_)
#define AFX_TIPY_H__7E332719_366C_45F0_A6B1_C3F109AC2003__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// tipy.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Ctipy dialog

class Ctipy : public CDialog
{
// Construction
public:
	Ctipy(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Ctipy)
	enum { IDD = IDD_Tipy };
	CEdit	m_other;
	CEdit	m_space;
	CEdit	m_mark;
	CEdit	m_english;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Ctipy)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Ctipy)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIPY_H__7E332719_366C_45F0_A6B1_C3F109AC2003__INCLUDED_)
