// JuziSimilar.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "JuziSimilar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJuziSimilar dialog


CJuziSimilar::CJuziSimilar(CWnd* pParent /*=NULL*/)
	: CDialog(CJuziSimilar::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJuziSimilar)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CJuziSimilar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJuziSimilar)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CJuziSimilar, CDialog)
	//{{AFX_MSG_MAP(CJuziSimilar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJuziSimilar message handlers
