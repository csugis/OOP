// KMLDoc.cpp : CKMLDoc 类的实现
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


// CKMLDoc 构造/析构

CKMLDoc::CKMLDoc()
{
	// TODO: 在此添加一次性构造代码

}

CKMLDoc::~CKMLDoc()
{
}

BOOL CKMLDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CKMLDoc 序列化

void CKMLDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CKMLDoc 诊断

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


// CKMLDoc 命令

void CKMLDoc::OnCsv2kml()
{
	// TODO: 在此添加命令处理程序代码
	Csv2Kml obj;

}
