// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__04619D73_FCF7_42C2_90D6_BCD1C98A9825__INCLUDED_)
#define AFX_MAINFRM_H__04619D73_FCF7_42C2_90D6_BCD1C98A9825__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	CSplitterWnd m_wndSplitter;
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChoose();
	afx_msg void OnSim();
	afx_msg void OnMenuitem32778();
	afx_msg void OnLongth();
	afx_msg void OnColor();
	afx_msg void OnBegin();
	afx_msg void OnBegin2();
	afx_msg void OnCount();
	afx_msg void OnSenSim();
	afx_msg void OnSimsen();
	afx_msg void Onchar();
	afx_msg void Onjuzi();
	afx_msg void OnPDF();
	afx_msg void OnWORD();
	afx_msg void OnCOLor();
	afx_msg void OnNET();
	afx_msg void OnBegin3();
	afx_msg void OnParSim();
	afx_msg void OnLocal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__04619D73_FCF7_42C2_90D6_BCD1C98A9825__INCLUDED_)
