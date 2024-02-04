// DlgSetBkColor.cpp : implementation file
//

#include "stdafx.h"
#include "GISDraw.h"
#include "DlgSetBkColor.h"
#include "MainFrm.h"
#include "GISDrawDoc.h"
#include "GISDrawView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetBkColor dialog


CDlgSetBkColor::CDlgSetBkColor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetBkColor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetBkColor)
	m_nBlue = 0;
	m_nGreen = 0;
	m_nRed = 0;
	m_strBlue = _T("");
	m_strGreen = _T("");
	m_strRed = _T("");
	//}}AFX_DATA_INIT
}


void CDlgSetBkColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetBkColor)
	DDX_Slider(pDX, IDC_SLIDER_BLUE, m_nBlue);
	DDX_Slider(pDX, IDC_SLIDER_GREEN, m_nGreen);
	DDX_Slider(pDX, IDC_SLIDER_RED, m_nRed);
	DDX_Text(pDX, IDC_STATIC_BLUE, m_strBlue);
	DDX_Text(pDX, IDC_STATIC_GREEN, m_strGreen);
	DDX_Text(pDX, IDC_STATIC_RED, m_strRed);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetBkColor, CDialog)
	//{{AFX_MSG_MAP(CDlgSetBkColor)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetBkColor message handlers

BOOL CDlgSetBkColor::OnInitDialog(){
	CDialog::OnInitDialog();	
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_RED))->SetRange(0,255);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_GREEN))->SetRange(0,255);
	((CSliderCtrl*)GetDlgItem(IDC_SLIDER_BLUE))->SetRange(0,255);	
	CGISDrawView *pView = (CGISDrawView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView();
	m_nRed = GetRValue(pView->m_bkClr);
	m_nGreen = GetGValue(pView->m_bkClr);
	m_nBlue = GetBValue(pView->m_bkClr);
	UpdateData(FALSE);
	CString strClrValue;
	strClrValue.Format("%d",m_nRed);
	SetDlgItemText(IDC_STATIC_RED,strClrValue);
	strClrValue.Format("%d",m_nGreen);
	SetDlgItemText(IDC_STATIC_GREEN,strClrValue);
	strClrValue.Format("%d",m_nBlue);
	SetDlgItemText(IDC_STATIC_BLUE,strClrValue);
	SetIcon( AfxGetApp()->LoadIcon( AFX_IDI_STD_FRAME ), FALSE );
	return TRUE;
}

void CDlgSetBkColor::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar){
	UpdateData(TRUE);
	CString strClrValue;
	strClrValue.Format("%d",m_nRed);
	SetDlgItemText(IDC_STATIC_RED,strClrValue);
	strClrValue.Format("%d",m_nGreen);
	SetDlgItemText(IDC_STATIC_GREEN,strClrValue);
	strClrValue.Format("%d",m_nBlue);
	SetDlgItemText(IDC_STATIC_BLUE,strClrValue);
	CGISDrawView *pView = (CGISDrawView*)((CMainFrame*)AfxGetMainWnd())->GetActiveView();
	pView->m_bkClr=RGB((BYTE)m_nRed,(BYTE)m_nGreen,(BYTE)m_nBlue);	
	pView->Invalidate();
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDlgSetBkColor::OnOK() 
{
	// TODO: Add extra validation here
	ShowWindow(SW_HIDE);
	//CDialog::OnOK();
}
