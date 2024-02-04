// Similary.h : main header file for the SIMILARY application
//

#if !defined(AFX_SIMILARY_H__66DAE046_28DC_4D2E_8665_4687D406FC23__INCLUDED_)
#define AFX_SIMILARY_H__66DAE046_28DC_4D2E_8665_4687D406FC23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimilaryApp:
// See Similary.cpp for the implementation of this class
//

class CSimilaryApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CSimilaryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimilaryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSimilaryApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////
////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMILARY_H__66DAE046_28DC_4D2E_8665_4687D406FC23__INCLUDED_)
