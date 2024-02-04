#if !defined(AFX_DLGSETGEO_H__64287BDF_D058_4211_BCD8_6EF8867C4B2C__INCLUDED_)
#define AFX_DLGSETGEO_H__64287BDF_D058_4211_BCD8_6EF8867C4B2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetGeo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetGeo dialog

class CDlgSetGeo : public CDialog
{
// Construction
public:
	unsigned char GetPenStyle();
	int GetPenWidth();
	COLORREF GetBrushColor();
	COLORREF GetPenColor();
	CDlgSetGeo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetGeo)
	enum { IDD = IDD_SETGEOMETRY };
	CComboBox	m_ctrlStyle;
	int		m_nBrushBlue;
	int		m_nBrushGreen;
	int		m_nBrushRed;
	int		m_nPenBlue;
	int		m_nPenGreen;
	int		m_nPenRed;
	int		m_nWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetGeo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetGeo)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETGEO_H__64287BDF_D058_4211_BCD8_6EF8867C4B2C__INCLUDED_)
