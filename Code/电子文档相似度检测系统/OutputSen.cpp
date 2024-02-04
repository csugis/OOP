// OutputSen.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "OutputSen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputSen dialog


COutputSen::COutputSen(CWnd* pParent /*=NULL*/)
	: CDialog(COutputSen::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutputSen)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COutputSen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutputSen)
	DDX_Control(pDX, IDC_EDIT1, m_outsen);
	//}}AFX_DATA_MAP
	extern CString Simsentence,CSen[200];
	extern double SentensNum;
	//MessageBox(Simsentence);
	m_outsen.SetWindowText(Simsentence); 
}


BEGIN_MESSAGE_MAP(COutputSen, CDialog)
	//{{AFX_MSG_MAP(COutputSen)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputSen message handlers
