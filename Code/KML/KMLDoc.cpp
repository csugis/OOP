// KMLDoc.cpp : CKMLDoc ���ʵ��
//

#include "stdafx.h"
#include "KML.h"

#include "KMLDoc.h"
#include "Csv2Kml.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKMLDoc

IMPLEMENT_DYNCREATE(CKMLDoc, CDocument)

BEGIN_MESSAGE_MAP(CKMLDoc, CDocument)
	ON_COMMAND(ID_CSV2KML, &CKMLDoc::OnCsv2kml)
END_MESSAGE_MAP()


// CKMLDoc ����/����

CKMLDoc::CKMLDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CKMLDoc::~CKMLDoc()
{
}

BOOL CKMLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CKMLDoc ���л�

void CKMLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CKMLDoc ���

#ifdef _DEBUG
void CKMLDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKMLDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKMLDoc ����

void CKMLDoc::OnCsv2kml()
{
	// TODO: �ڴ���������������
	Csv2Kml obj;

}
