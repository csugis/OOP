// DlgCsv2Kml.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KML.h"
#include "DlgCsv2Kml.h"


// DlgCsv2Kml �Ի���

IMPLEMENT_DYNAMIC(DlgCsv2Kml, CDialog)

DlgCsv2Kml::DlgCsv2Kml(CWnd* pParent /*=NULL*/)
	: CDialog(DlgCsv2Kml::IDD, pParent)
	, id(0)
	, name(0)
	, lon(0)
	, lat(0)
{

}

DlgCsv2Kml::~DlgCsv2Kml()
{
}

void DlgCsv2Kml::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO_ID, id);
	DDX_CBIndex(pDX, IDC_COMBO_NAME, name);
	DDX_CBIndex(pDX, IDC_COMBO_LON, lon);
	DDX_CBIndex(pDX, IDC_COMBO_LAT, lat);
}


BEGIN_MESSAGE_MAP(DlgCsv2Kml, CDialog)
END_MESSAGE_MAP()


// DlgCsv2Kml ��Ϣ�������

void DlgCsv2Kml::AddString(const char* s)
{
	((CComboBox*)GetDlgItem(IDC_COMBO_ID))->AddString(s);
	((CComboBox*)GetDlgItem(IDC_COMBO_NAME))->AddString(s);
	((CComboBox*)GetDlgItem(IDC_COMBO_LON))->AddString(s);
	((CComboBox*)GetDlgItem(IDC_COMBO_LAT))->AddString(s);
}

BOOL DlgCsv2Kml::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for(int i = 0; i<pflds->getSize(); i++)
	{
		AddString((*pflds)[i].getName().c_str());
		//cout<<flds[i].getNo()<<":"<<flds[i].getName()<<endl;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
