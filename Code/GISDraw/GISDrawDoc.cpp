// GISDrawDoc.cpp : implementation of the CGISDrawDoc class
//

#include "stdafx.h"
#include "GISDraw.h"

#include "GISDrawDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGISDrawDoc

IMPLEMENT_DYNCREATE(CGISDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CGISDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CGISDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGISDrawDoc construction/destruction

CGISDrawDoc::CGISDrawDoc()
{
	// TODO: add one-time construction code here

}

CGISDrawDoc::~CGISDrawDoc()
{
}

BOOL CGISDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	CLayer *lay=NULL;

	lay = new CLayer;
	lay->SetGeometryType(geoTypeLine);
	m_objManager.InsertLayers(lay);
	
	lay = new CLayer;
	lay->SetGeometryType(geoTypePolyline);
	m_objManager.InsertLayers(0,lay);
	
	lay = new CLayer;
	lay->SetGeometryType(geoTypePolygon);
	m_objManager.InsertLayers(0,lay);

	lay = new CLayer;
	lay->SetGeometryType(geoTypeCircle);
	m_objManager.InsertLayers(lay);
	
	lay = new CLayer;
	lay->SetGeometryType(geoTypeRound);
	m_objManager.InsertLayers(1,lay);

	lay = new CLayer;
	lay->SetGeometryType(geoTypeArc);
	m_objManager.InsertLayers(lay);

	lay = new CLayer;
	lay->SetGeometryType(geoTypeLabel);
	m_objManager.InsertLayers(lay);

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGISDrawDoc serialization

void CGISDrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<m_objManager;
	}
	else
	{
		// TODO: add loading code here
		ar>>m_objManager;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGISDrawDoc diagnostics

#ifdef _DEBUG
void CGISDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGISDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGISDrawDoc commands

BOOL CGISDrawDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	m_objManager.DeleteLayers();
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	return TRUE;
}
