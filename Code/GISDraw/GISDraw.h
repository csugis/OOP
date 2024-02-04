// GISDraw.h : main header file for the GISDRAW application
//

#if !defined(AFX_GISDRAW_H__BAA41B88_0D07_4F85_B324_1CC3BAEC955C__INCLUDED_)
#define AFX_GISDRAW_H__BAA41B88_0D07_4F85_B324_1CC3BAEC955C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGISDrawApp:
// See GISDraw.cpp for the implementation of this class
//

class CGISDrawApp : public CWinApp
{
public:
	CGISDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGISDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGISDrawApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GISDRAW_H__BAA41B88_0D07_4F85_B324_1CC3BAEC955C__INCLUDED_)
