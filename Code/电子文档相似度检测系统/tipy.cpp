// tipy.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "tipy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Ctipy dialog


Ctipy::Ctipy(CWnd* pParent /*=NULL*/)
	: CDialog(Ctipy::IDD, pParent)
{
	//{{AFX_DATA_INIT(Ctipy)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Ctipy::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(Ctipy)
	DDX_Control(pDX, IDC_EDIT4, m_other);
	DDX_Control(pDX, IDC_EDIT3, m_space);
	DDX_Control(pDX, IDC_EDIT2, m_mark);
	DDX_Control(pDX, IDC_EDIT1, m_english);
	//}}AFX_DATA_MAP
	CDialog::DoDataExchange(pDX);
	extern char C[5000];
	extern int charnum;
	int i=0,eng=0,mark=0,space=0,other=0;
	CString Eng,Engf,Mark,Markf,Space,Spacef,Other,Otherf;
	while(C[i]!='\0')
	{
		if(C[i]==32)
			space++;
	    if((C[i]>=65&&C[i]<=90)||(C[i]>=97&&C[i]<=122))
			eng++;
		if((C[i]>=33&&C[i]<=64)||C[i]==96||(C[i]>=248&&C[i]<=250))
			mark++;
		other=charnum-space-eng-mark;
			i++;
	}
	Eng.Format("%d",eng);
	Mark.Format("%d",mark);
	Space.Format("%d",space);
	Other.Format("%d",other);
	Engf=Eng;
	Markf=Mark;
	Spacef=Space;
	Otherf=Other;
	m_english.SetWindowText(Engf);
	m_mark.SetWindowText(Markf);
	m_space.SetWindowText(Spacef);
	m_other.SetWindowText(Otherf);



	
}


BEGIN_MESSAGE_MAP(Ctipy, CDialog)
	//{{AFX_MSG_MAP(Ctipy)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Ctipy message handlers
