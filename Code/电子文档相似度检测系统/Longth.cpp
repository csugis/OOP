// Longth.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Longth.h"
#include "tipy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLongth dialog


CLongth::CLongth(CWnd* pParent /*=NULL*/)
	: CDialog(CLongth::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLongth)
	//}}AFX_DATA_INIT
	

}


void CLongth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLongth)
	DDX_Control(pDX, IDC_EDIT2, m_unit);
	DDX_Control(pDX, IDC_EDIT1, m_charnum);
	//}}AFX_DATA_MAP
	extern char C[5000];
	int unit=0; 
	extern int charnum;
	int i=0;
	for(i=0;i<5000;i++)
	{
		
		if(C[i]==10)
			unit++;
			if(C[i]=='\0')
		{
			charnum=i;
			break;
		}
	}
	if(C[0]!='\0')
	unit++;
	CString cnum,CNUM,unitnum,UNIT;
	CNUM.Format("%d",charnum);
	cnum=CNUM;
	m_charnum.SetWindowText(cnum);
	UNIT.Format("%d",unit);
	unitnum=UNIT;
	m_unit.SetWindowText(unitnum);
	
}


BEGIN_MESSAGE_MAP(CLongth, CDialog)
	//{{AFX_MSG_MAP(CLongth)
	ON_BN_CLICKED(IDC_BUTTON1, OnTipy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLongth message handlers

void CLongth::OnTipy() 
{
	Ctipy onok;
	onok.DoModal();// TODO: Add your control notification handler code here
	
}
