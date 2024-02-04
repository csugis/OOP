#if !defined(AFX_SHOWSENSIM_H__7273CBB8_C0B6_45F0_8FC1_9205E1B8A659__INCLUDED_)
#define AFX_SHOWSENSIM_H__7273CBB8_C0B6_45F0_8FC1_9205E1B8A659__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowSenSim.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowSenSim dialog

class CShowSenSim : public CDialog
{
// Construction
public:
	CShowSenSim(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowSenSim)
	enum { IDD = IDD_ShowSenSim };
	CEdit	m_SenSim;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowSenSim)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowSenSim)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWSENSIM_H__7273CBB8_C0B6_45F0_8FC1_9205E1B8A659__INCLUDED_)
