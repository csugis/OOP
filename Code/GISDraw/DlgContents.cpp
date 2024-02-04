// DlgContents.cpp : implementation file
//

#include "stdafx.h"
#include "GISDraw.h"
#include "DlgContents.h"
#include "MainFrm.h"
#include "GISDrawDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgContents dialog


CDlgContents::CDlgContents(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgContents::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgContents)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgContents::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgContents)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgContents, CDialog)
	//{{AFX_MSG_MAP(CDlgContents)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgContents message handlers
CString GetStrByGeoType(unsigned char type)
{
	CString sType;
	switch(type) {
	case geoTypeLine:
		sType = "ֱ��";
		break;
	case geoTypePolyline:
		sType = "����";
		break;
	case geoTypePolygon:
		sType = "�����";
		break;
	case geoTypeCircle:
		sType = "Բ��";
		break;
	case geoTypeRound:
		sType = "Բ��";
		break;
	case geoTypeArc:
		sType = "Բ��";
		break;
	case geoTypeLabel:
		sType = "ע��";
		break;
	default:
		sType = "δ֪";
		break;
	}
	return sType;
}
BOOL CDlgContents::OnInitDialog() {
	CDialog::OnInitDialog();
	HTREEITEM   hRoot, hLevel1, hLevel2; 
    CString sLayer = _T(""), sGeo = _T("");
	CTreeCtrl*     pTree = (CTreeCtrl*) GetDlgItem( IDC_TREE_CONTENTS );     
	hRoot  = pTree->InsertItem( "Table of Contents", TVI_ROOT, TVI_SORT );	
	CMainFrame *pMainFrm = (CMainFrame*)AfxGetMainWnd();
	CGISDrawDoc *pDoc = (CGISDrawDoc*)pMainFrm->GetActiveDocument();
	CLayer * pLayer = NULL;
	CGeometry * pGeo = NULL;
	for(int i=0; i<pDoc->m_objManager.GetLayerNum(); i++){
		pLayer = pDoc->m_objManager.GetLayer(i);
		sLayer.Format("%sͼ��%d",
			GetStrByGeoType(pLayer->GetGeometryType()),
			pLayer->GetID());
		hLevel1 = pTree->InsertItem( sLayer , hRoot);
		for(int j=0; j<pLayer->GetGeometryNum(); j++){
			pGeo = pLayer->GetGeometry(j);
			sGeo.Format("%s%d",
				GetStrByGeoType(pGeo->GetGeoType()),
				pGeo->GetID());
			hLevel2 = pTree->InsertItem( sGeo , hLevel1);
		}
	}
	return TRUE; 
}
