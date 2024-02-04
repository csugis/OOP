// SimilaryDoc.cpp : implementation of the CSimilaryDoc class
//

#include "stdafx.h"
#include "Similary.h"

#include "SimilaryDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimilaryDoc

IMPLEMENT_DYNCREATE(CSimilaryDoc, CDocument)

BEGIN_MESSAGE_MAP(CSimilaryDoc, CDocument)
	//{{AFX_MSG_MAP(CSimilaryDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimilaryDoc construction/destruction

CSimilaryDoc::CSimilaryDoc()
{
	
//	strcpy(m_string,"i am");// TODO: add one-time construction code here

}

CSimilaryDoc::~CSimilaryDoc()
{
}

BOOL CSimilaryDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
    UpdateAllViews(NULL);	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSimilaryDoc serialization

void CSimilaryDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
		
}

/////////////////////////////////////////////////////////////////////////////
// CSimilaryDoc diagnostics

#ifdef _DEBUG
void CSimilaryDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSimilaryDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
	
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSimilaryDoc commands
