// SimPart.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "SimPart.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimPart dialog


CSimPart::CSimPart(CWnd* pParent /*=NULL*/)
	: CDialog(CSimPart::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimPart)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSimPart::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimPart)
	DDX_Control(pDX, IDC_EDIT1, m_paredit);
	//}}AFX_DATA_MAP
	extern char C[5000];
	m_paredit.SetWindowText(C);
}


BEGIN_MESSAGE_MAP(CSimPart, CDialog)
	//{{AFX_MSG_MAP(CSimPart)
//	ON_NOTIFY(NM_CLICK, IDC_RICHEDIT1, OnClickRichedit1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimPart message handlers

void CSimPart::OnClickRichedit1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	*pResult = 0;
}

void CSimPart::OnChangeEdit1() 
{
//	extern char C[5000];
//	m_paredit.SetWindowText("sdjisojolw");
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
