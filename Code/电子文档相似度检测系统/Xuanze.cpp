// Xuanze.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Xuanze.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXuanze dialog


CXuanze1::CXuanze1(CWnd* pParent /*=NULL*/)
	: CDialog(CXuanze1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXuanze)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CXuanze1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXuanze)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXuanze1, CDialog)
	//{{AFX_MSG_MAP(CXuanze)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXuanze message handlers
