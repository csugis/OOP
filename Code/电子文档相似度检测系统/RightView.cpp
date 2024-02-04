// RightView.cpp : implementation file
//

#include "stdafx.h"
#include "Similary.h"
#include "RightView.h"
#include "Choose.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRightView

IMPLEMENT_DYNCREATE(CRightView, CView)

CRightView::CRightView()
{
}

CRightView::~CRightView()
{
}


BEGIN_MESSAGE_MAP(CRightView, CView)
	//{{AFX_MSG_MAP(CRightView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRightView drawing

void CRightView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	extern	char fileBuffer2[5010], rBuffer2[5010],rBuffer20[5010],rBuffer200[5010];
    extern	int rBSize2,Add;
	CRect   rect;   
	////////////////////////////////////////////////////////////////////////
	m_Color1=RGB(255,0,0);
	pDC->SetTextColor(m_Color1);


	/////////////////////////////////////////////////////////////////////////
    pDC->DrawText(rBuffer2,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK); 
	m_Color1=RGB(0,0,0);
	pDC->SetTextColor(m_Color1);
	pDC->DrawText(rBuffer20,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK);
	pDC->DrawText(rBuffer200,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK); 

//	pDC->TextOut(0,0, rBuffer2);
//	pDoc->UpdateAllViews(NULL);

AddColor();
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
	m_Color1=RGB(0,0,255);
	pDC->SetTextColor(m_Color1);
	rect.bottom = rect.top +20;
	pDC->FillSolidRect(rect,crBtnFace);
	pDC->Draw3dRect(rect,crLight,crShadow);
	pDC->DrawText("文件2",rect,DT_SINGLELINE|DT_VCENTER|DT_CENTER);


	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CRightView diagnostics

#ifdef _DEBUG
void CRightView::AssertValid() const
{
	CView::AssertValid();
}

void CRightView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRightView message handlers

void CRightView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	Invalidate(); 
	
	
}

int CRightView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
		SetTimer(1,100,NULL);
// TODO: Add your specialized creation code here
	
	return 0;
}

void CRightView::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this);
	CRect rect;
    rect.top=0;
    rect.left=0;
    rect.bottom=600;
    rect.right=700;
    extern	char fileBuffer2[5010], rBuffer2[5010];
	m_Color1=RGB(255,0,0);
	dc.SetTextColor(m_Color1);
 //   dc.DrawText(rBuffer2,CRect(0,20,600,700),DT_LEFT|DT_WORDBREAK);//TODO: Add your message handler code here and/or call default	
	CView::OnTimer(nIDEvent);
}

void CRightView::AddColor()
{
/*	extern	char  rBuffer2[5010];
    extern	int rBSize2;	
	extern int BF[5000];
	CString strBuffer;
	CString newstrBuffer="";
	for(int i=0;i<rBSize2;i++)
		strBuffer=strBuffer+rBuffer2[i];
//	AfxMessageBox(strBuffer);
	for(int j=0;j<strBuffer.GetLength();j++)
	{
		/*if(BF[j]==1)
		{
			newstrBuffer=newstrBuffer+"&"+rBuffer2[j];
		}
		else
			newstrBuffer=newstrBuffer+rBuffer2[j];	
		if(BF[j]==1&&BF[j-1]!=1)
		{
			newstrBuffer=newstrBuffer+"{"+rBuffer2[j];
		}
		else
			if(BF[j]==1&&BF[j+1]!=1)
				newstrBuffer=newstrBuffer+rBuffer2[j]+"}";
			else
			newstrBuffer=newstrBuffer+rBuffer2[j];
	}
//	AfxMessageBox(newstrBuffer);
	for(int ii=0;ii<newstrBuffer.GetLength();ii++)
	{
		rBuffer2[ii]=newstrBuffer[ii];
	}*/
}
