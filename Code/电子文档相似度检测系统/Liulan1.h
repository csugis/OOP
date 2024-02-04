#if !defined(AFX_LIULAN1_H__97EACCE6_1D84_47C3_9B4D_2EFA357F50C6__INCLUDED_)
#define AFX_LIULAN1_H__97EACCE6_1D84_47C3_9B4D_2EFA357F50C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Liulan1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLiulan1 dialog

class CLiulan1 : public CFileDialog
{
	DECLARE_DYNAMIC(CLiulan1)

public:
	CLiulan1(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);

protected:
	//{{AFX_MSG(CLiulan1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIULAN1_H__97EACCE6_1D84_47C3_9B4D_2EFA357F50C6__INCLUDED_)
