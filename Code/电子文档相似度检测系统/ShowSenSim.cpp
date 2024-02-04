// ShowSenSim.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "ShowSenSim.h"
#include "Choose.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowSenSim dialog


CShowSenSim::CShowSenSim(CWnd* pParent /*=NULL*/)
	: CDialog(CShowSenSim::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowSenSim)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowSenSim::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowSenSim)
	DDX_Control(pDX, IDC_EDIT1, m_SenSim);
	//}}AFX_DATA_MAP
	extern double SentensNum;
    extern double count1;//文档一的句子个数
    extern double count2;//文档二的句子个数
	CChoose dou;
	int Maxcount;
	double SenSim;

	Maxcount=dou.Max(count1,count2); 
	if(SentensNum==0)
	SenSim=0;
	else	
	SenSim=1.0*(SentensNum/Maxcount);
	CString Sensim1,Sensim2;
	Sensim1.Format("%f",SenSim);
	Sensim2=Sensim1;
	m_SenSim.SetWindowText(Sensim2);
	
}


BEGIN_MESSAGE_MAP(CShowSenSim, CDialog)
	//{{AFX_MSG_MAP(CShowSenSim)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowSenSim message handlers
