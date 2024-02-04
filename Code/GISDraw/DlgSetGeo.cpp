// DlgSetGeo.cpp : implementation file
//

#include "stdafx.h"
#include "GISDraw.h"
#include "DlgSetGeo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGeo dialog


CDlgSetGeo::CDlgSetGeo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetGeo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetGeo)
	m_nBrushBlue = 0;
	m_nBrushGreen = 0;
	m_nBrushRed = 0;
	m_nPenBlue = 0;
	m_nPenGreen = 0;
	m_nPenRed = 0;
	m_nWidth = 1;
	//}}AFX_DATA_INIT
}


void CDlgSetGeo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetGeo)
	DDX_Control(pDX, IDC_STYLE, m_ctrlStyle);
	DDX_Text(pDX, IDC_BRUSH_BLUE, m_nBrushBlue);
	DDV_MinMaxInt(pDX, m_nBrushBlue, 0, 255);
	DDX_Text(pDX, IDC_BRUSH_GREEN, m_nBrushGreen);
	DDV_MinMaxInt(pDX, m_nBrushGreen, 0, 255);
	DDX_Text(pDX, IDC_BRUSH_RED, m_nBrushRed);
	DDV_MinMaxInt(pDX, m_nBrushRed, 0, 255);
	DDX_Text(pDX, IDC_PEN_BLUE, m_nPenBlue);
	DDV_MinMaxInt(pDX, m_nPenBlue, 0, 255);
	DDX_Text(pDX, IDC_PEN_GREEN, m_nPenGreen);
	DDX_Text(pDX, IDC_PEN_RED, m_nPenRed);
	DDX_Text(pDX, IDC_WIDTH, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetGeo, CDialog)
	//{{AFX_MSG_MAP(CDlgSetGeo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGeo message handlers
unsigned char cStyle[]={
	PS_SOLID            ,
	PS_DASH             ,
	PS_DOT              ,
	PS_DASHDOT          ,
	PS_DASHDOTDOT       ,
	PS_NULL             ,
	PS_INSIDEFRAME      ,
	PS_USERSTYLE        ,
	PS_ALTERNATE        
};

BOOL CDlgSetGeo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CSpinButtonCtrl* spin=NULL;
	CComboBox* pBox=(CComboBox*)GetDlgItem(IDC_STYLE);
	pBox->InsertString(0,"PS_SOLID");
	pBox->InsertString(1,"PS_DASH");
	pBox->InsertString(2,"PS_DOT");
	pBox->InsertString(3,"PS_DASHDOT");
	pBox->InsertString(4,"PS_DASHDOTDOT");
	pBox->InsertString(5,"PS_NULL");
	pBox->InsertString(6,"PS_INSIDEFRAME");
	pBox->InsertString(7,"PS_USERSTYLE");
	pBox->InsertString(8,"PS_ALTERNATE");
	pBox->SetCurSel(0);
	//pen
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_PEN_RED );
	spin->SetBuddy(GetDlgItem(IDC_PEN_RED));
	spin->SetRange(0,255);
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_PEN_GREEN );
	spin->SetBuddy(GetDlgItem(IDC_PEN_GREEN));
	spin->SetRange(0,255);
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_PEN_BLUE );
	spin->SetBuddy(GetDlgItem(IDC_PEN_BLUE));
	spin->SetRange(0,255);
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_WIDTH );
	spin->SetBuddy(GetDlgItem(IDC_WIDTH));
	spin->SetRange(0,100);
	
	//brush
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_BRUSH_RED );
	spin->SetBuddy(GetDlgItem(IDC_BRUSH_RED));
	spin->SetRange(0,255);
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_BRUSH_GREEN );
	spin->SetBuddy(GetDlgItem(IDC_BRUSH_GREEN));
	spin->SetRange(0,255);
	spin = (CSpinButtonCtrl *) GetDlgItem( IDC_SPIN_BRUSH_BLUE );
	spin->SetBuddy(GetDlgItem(IDC_BRUSH_BLUE));
	spin->SetRange(0,255);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

COLORREF CDlgSetGeo::GetPenColor()
{
	UpdateData(TRUE);
	return RGB(m_nPenRed,m_nPenGreen,m_nPenBlue);
}

COLORREF CDlgSetGeo::GetBrushColor()
{
	UpdateData(TRUE);
	return RGB(m_nBrushRed,m_nBrushGreen,m_nBrushBlue);
}

int CDlgSetGeo::GetPenWidth()
{
	UpdateData(TRUE);
	return m_nWidth;
}

unsigned char CDlgSetGeo::GetPenStyle()
{
	UpdateData(TRUE);
	CComboBox* pBox=(CComboBox*)GetDlgItem(IDC_STYLE);
	int index=pBox->GetCurSel();
	return cStyle[index];
}
