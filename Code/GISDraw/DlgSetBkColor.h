#if !defined(AFX_DLGSETBKCOLOR_H__FF6920B5_9DAF_4CBE_A323_B44A2C7AAC8C__INCLUDED_)
#define AFX_DLGSETBKCOLOR_H__FF6920B5_9DAF_4CBE_A323_B44A2C7AAC8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetBkColor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetBkColor dialog

class CDlgSetBkColor : public CDialog
{
// Construction
public:
	CDlgSetBkColor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetBkColor)
	enum { IDD = IDD_BKCOLOR };
	int		m_nBlue;
	int		m_nGreen;
	int		m_nRed;
	CString	m_strBlue;
	CString	m_strGreen;
	CString	m_strRed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetBkColor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetBkColor)
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETBKCOLOR_H__FF6920B5_9DAF_4CBE_A323_B44A2C7AAC8C__INCLUDED_)
