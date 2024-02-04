// Xuanze2.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Xuanze2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXuanze2 dialog


CXuanze2::CXuanze2(CWnd* pParent /*=NULL*/)
	: CDialog(CXuanze2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXuanze2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CXuanze2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXuanze2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CXuanze2, CDialog)
	//{{AFX_MSG_MAP(CXuanze2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXuanze2 message handlers
