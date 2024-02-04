// LeftView.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "LeftView.h"
#include "Choose.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CView)

CLeftView::CLeftView()
{
}

CLeftView::~CLeftView()
{
}


BEGIN_MESSAGE_MAP(CLeftView, CView)
	//{{AFX_MSG_MAP(CLeftView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftView drawing

void CLeftView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here   
	extern	char fileBuffer[5010], rBuffer[5010],rBuffer00[5010],rBuffer000[5010];
    extern	int rBSize;	
	CRect   rect;   
	m_Color=RGB(255,0,0);
	/////////////////////////////////////////////////////////////////////////
	//去掉多余的空格！
	//CString ready1 = Replace(rBuffer, @"\n(\r\n)+|[\0020\t]{2,}", "\0020");
	/////////////////////////////////////////////////////////////////////////
	pDC->SetTextColor(m_Color);
	pDC->DrawText(rBuffer,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK); 
	//AddColor();
	m_Color=RGB(0,0,0);
	pDC->SetTextColor(m_Color);


	pDC->DrawText(rBuffer00,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK); 
	pDC->DrawText(rBuffer000,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK); 
	/////////////////////////////加标题
	CRect rcClient;
	GetClientRect(rcClient);
	//获取颜色值
	COLORREF crLight = GetSysColor(COLOR_BTNHIGHLIGHT);
	COLORREF crShadow = GetSysColor(COLOR_BTNSHADOW);
	COLORREF crBtnFace = GetSysColor(COLOR_BTNFACE);
	//设置透明模式
	pDC->SetBkMode(TRANSPARENT);
	CGdiObject *pOldFont = pDC->SelectStockObject(OEM_FIXED_FONT);
	
	rect = rcClient;
	//标题栏部分
	m_Color=RGB(0,0,255);
	pDC->SetTextColor(m_Color);
	rect.bottom = rect.top +20;
	pDC->FillSolidRect(rect,crBtnFace);
	pDC->Draw3dRect(rect,crLight,crShadow);
	pDC->DrawText("文件1",rect,DT_SINGLELINE|DT_VCENTER|DT_CENTER);

}


/////////////////////////////////////////////////////////////////////////////
// CLeftView diagnostics

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CLeftView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);

}


#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftView message handlers

/*void CLeftView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTreeView::OnChar(nChar, nRepCnt, nFlags);
}*/

/*BOOL CLeftView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}*/

void CLeftView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{

// TODO: Add your specialized code here and/or call the base class
	Invalidate(); 
	
	
}

void CLeftView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	
}

int CLeftView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	SetTimer(1,100,NULL);

	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CLeftView::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this);
	CRect rect;
    rect.top=0;
    rect.left=0;
    rect.bottom=600;
    rect.right=700;
    extern	char fileBuffer[5010], rBuffer[5010];
	m_Color=RGB(255,0,0);
	dc.SetTextColor(m_Color);
//    dc.DrawText(rBuffer,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK);

// TODO: Add your message handler code here and/or call default
	
	CView::OnTimer(nIDEvent);
}

void CLeftView::AddColor()//加括号
{
/*	extern	char fileBuffer[5010], rBuffer[5010];
    extern	int rBSize;	
	extern int AF[5000],BF[5000];
	CString strBuffer;
	CString newstrBuffer="";
	for(int i=0;i<rBSize;i++)
		strBuffer=strBuffer+rBuffer[i];
//	AfxMessageBox(strBuffer);
	for(int j=0;j<strBuffer.GetLength();j++)
	{
	
		if(AF[j]==1&&AF[j-1]!=1)
		{
			newstrBuffer=newstrBuffer+"{"+rBuffer[j];
		}
		else
			if(AF[j]==1&&AF[j+1]!=1)
				newstrBuffer=newstrBuffer+rBuffer[j]+"}";
			else
			newstrBuffer=newstrBuffer+rBuffer[j];			
	}
//	AfxMessageBox(newstrBuffer);
	for(int ii=0;ii<newstrBuffer.GetLength();ii++)
	{
		rBuffer[ii]=newstrBuffer[ii];
	}
	*/

}
