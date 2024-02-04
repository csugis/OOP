// GISDrawDoc.h : interface of the CGISDrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GISDRAWDOC_H__D762C54E_FDB5_4755_AC6F_E15F2BDDED00__INCLUDED_)
#define AFX_GISDRAWDOC_H__D762C54E_FDB5_4755_AC6F_E15F2BDDED00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Manager.h"

class CGISDrawDoc : public CDocument
{
protected: // create from serialization only
	CGISDrawDoc();
	DECLARE_DYNCREATE(CGISDrawDoc)

// Attributes
public:
	CManager	m_objManager;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGISDrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGISDrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGISDrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GISDRAWDOC_H__D762C54E_FDB5_4755_AC6F_E15F2BDDED00__INCLUDED_)
