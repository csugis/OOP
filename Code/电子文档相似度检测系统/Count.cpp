// Count.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Count.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCount dialog


CCount::CCount(CWnd* pParent /*=NULL*/)
	: CDialog(CCount::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCount)
	//}}AFX_DATA_INIT
}


void CCount::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCount)
	DDX_Control(pDX, IDC_EDIT3, m_sentence);
	DDX_Control(pDX, IDC_EDIT2, m_cou2);
	DDX_Control(pDX, IDC_EDIT1, m_cout1);
	//}}AFX_DATA_MAP
		extern double SentensNum;
	CString Sen,Sen2,Cou1,Couf1,Cou2,Couf2;
	extern double count1;//文档一的句子个数
	extern double count2;//文档二的句子个数
	Sen.Format("%.0f",SentensNum); 
	Cou1.Format("%.0f",count1);
	Cou2.Format("%.0f",count2);
	Sen2=Sen;
	Couf1=Cou1;
	Couf2=Cou2;
	m_sentence.SetWindowText(Sen2);
	m_cout1.SetWindowText(Couf1);
	m_cou2.SetWindowText(Couf2);

}


BEGIN_MESSAGE_MAP(CCount, CDialog)
	//{{AFX_MSG_MAP(CCount)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCount message handlers
