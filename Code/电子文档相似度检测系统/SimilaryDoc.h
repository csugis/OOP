// SimilaryDoc.h : interface of the CSimilaryDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIMILARYDOC_H__6FFE1E38_0451_4F34_B0EB_EDDAA368DBC2__INCLUDED_)
#define AFX_SIMILARYDOC_H__6FFE1E38_0451_4F34_B0EB_EDDAA368DBC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSimilaryDoc : public CDocument
{
protected: // create from serialization only
	CSimilaryDoc();
	DECLARE_DYNCREATE(CSimilaryDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimilaryDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSimilaryDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSimilaryDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMILARYDOC_H__6FFE1E38_0451_4F34_B0EB_EDDAA368DBC2__INCLUDED_)
