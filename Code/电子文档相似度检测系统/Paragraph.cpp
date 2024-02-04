// Paragraph.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "Paragraph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CParagraph dialog


CParagraph::CParagraph(CWnd* pParent /*=NULL*/)
	: CDialog(CParagraph::IDD, pParent)
{
	//{{AFX_DATA_INIT(CParagraph)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CParagraph::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CParagraph)
	DDX_Control(pDX, IDC_EDIT1, m_para);
	//}}AFX_DATA_MAP
	extern double ParaSim;
	CString PAR,PAR1;
	PAR.Format("%f",ParaSim); 
	PAR1=PAR;
	m_para.SetWindowText(PAR1); 
}


BEGIN_MESSAGE_MAP(CParagraph, CDialog)
	//{{AFX_MSG_MAP(CParagraph)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CParagraph message handlers
