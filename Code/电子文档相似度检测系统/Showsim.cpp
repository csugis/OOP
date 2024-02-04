// Showsim.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Showsim.h"
//#include "Choose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Showsim dialog


Showsim::Showsim(CWnd* pParent /*=NULL*/)
	: CDialog(Showsim::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(Showsim)
	//}}AFX_DATA_INIT
}


void Showsim::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Showsim)
	DDX_Control(pDX, IDC_EDIT3, m_CSize2);
	DDX_Control(pDX, IDC_EDIT2, m_CSize);
	DDX_Control(pDX, IDC_EDIT1, m_Sim);
	//}}AFX_DATA_MAP
	extern 	double sim;
	extern  double similary;
	extern int rBSize;
	extern int rBSize2;
	extern char C[5000];
	CString Strsim,CS,CP,CP2,STRCsize,STRCsize2,CQ;
	CP.Format("%d",rBSize);
	CP2.Format("%d",rBSize2);
    CS.Format("%f",similary);
	CQ.Format("%f",sim);
	Strsim=CS;
	STRCsize=CP;
	STRCsize2=CP2;
    m_Sim.SetWindowText(Strsim);
	m_CSize.SetWindowText(STRCsize);
    m_CSize2.SetWindowText(STRCsize2);
}


BEGIN_MESSAGE_MAP(Showsim, CDialog)
	//{{AFX_MSG_MAP(Showsim)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Showsim message handlers

void Showsim::OnAppAbout() 
{
// TODO: Add your command handler code here	
}

void Showsim::OnChangeEdit1() 
{	
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO: Add your control notification handler code here	
}

void Showsim::OutputSim()
{
    
}

void Showsim::OnButton1() 
{
/*	extern 	double sim;
	extern  double similary;
	extern int rBSize;
	extern int rBSize2;
	extern char C[5000];
	CString Strsim,CS,CP,CP2,STRCsize,STRCsize2,CQ;
	CP.Format("%d",rBSize);
	CP2.Format("%d",rBSize2);
    CS.Format("%f",similary);
	CQ.Format("%f",sim);
	Strsim=CS;
	STRCsize=CP;
	STRCsize2=CP2;
    m_Sim.SetWindowText(Strsim);
	m_CSize.SetWindowText(STRCsize);
    m_CSize2.SetWindowText(STRCsize2);
	//MessageBox(C);*/
	// TODO: Add your control notification handler code here
}
