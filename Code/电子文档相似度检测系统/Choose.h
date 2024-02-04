#if !defined(AFX_CHOOSE_H__8027040B_5808_470D_BAFB_468A6AADB704__INCLUDED_)
#define AFX_CHOOSE_H__8027040B_5808_470D_BAFB_468A6AADB704__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Choose.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoose dialog

class CChoose : public CDialog
{
// Construction
public:
	double ParaCompare();
	void SentensiCompare();
	void bijiao();
	int similarycompare(char A[],char B[],int m,int n);
	int Max(int a,int b);
	CChoose(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChoose)
	enum { IDD = IDD_Choose };
	CEdit	m_edit2;
	CEdit	m_edit1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoose)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoose)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSE_H__8027040B_5808_470D_BAFB_468A6AADB704__INCLUDED_)
