
// KMLAppDoc.cpp: CKMLAppDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "KMLApp.h"
#endif

#include "KMLAppDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKMLAppDoc

IMPLEMENT_DYNCREATE(CKMLAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CKMLAppDoc, CDocument)
END_MESSAGE_MAP()


// CKMLAppDoc 构造/析构

CKMLAppDoc::CKMLAppDoc() noexcept
{
	// TODO: 在此添加一次性构造代码
	pKML = new KML();
	//ifstream infile;
	//infile.open(_T("..//data//Travel.bkml"), ios::binary);
	//if (infile.is_open())
	//{
	//	infile.read((char*)pKML, sizeof(KML));
	//	infile.close();
	//}
	string str = "Travel";
	pKML->setName(str);
}

CKMLAppDoc::~CKMLAppDoc()
{
	if (pKML != nullptr)
	{
		outputKML();
		delete pKML;
	}
}

void CKMLAppDoc::outputKML()
{
	ofstream outfile;
	outfile.open(_T("..//data//Travel.kml"));
	outfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
	outfile << "<kml xmlns=\"http:/" << "/www.opengis.net/kml/2.2\"" << endl;
	outfile << "xmlns:gx=\"http:/" << "/www.google.com/kml/ext/2.2\">" << endl;
	//<!-- required when using gx-prefixed elements -->
	outfile << *pKML;
	outfile << "</kml>" << endl;
	outfile.close();
	outfile.open(_T("..//data//Travel.bkml"),ios::binary);
	outfile.write((char*)pKML, sizeof(KML));
	outfile.close();
}
BOOL CKMLAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CKMLAppDoc 序列化

void CKMLAppDoc::Serialize(CArchive& ar)
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

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CKMLAppDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CKMLAppDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CKMLAppDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CKMLAppDoc 诊断

#ifdef _DEBUG
void CKMLAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKMLAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKMLAppDoc 命令
