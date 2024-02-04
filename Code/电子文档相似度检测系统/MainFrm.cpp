// MainFrm.cpp : implementation of the CMainFrame class
//
#include <Afxcview.h>
#include "stdafx.h"
#include "Similary.h"
#include "SimilaryDoc.h"
#include "MainFrm.h"
#include "SimilaryView.h"
#include "LeftView.h"
#include "RightView.h"
#include "Choose.h"
#include "Showsim.h"
#include "SimPart.h"
#include "Splash.h"
#include "Longth.h"
#include "Count.h"
#include "ShowSenSim.h"
#include "OutputSen.h"
#include "JuziSimilar.h"
#include "Paragraph.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_Choose, OnChoose)
	ON_COMMAND(ID_MENUITEM32777, OnSim)
	ON_COMMAND(ID_MENUITEM32778, OnMenuitem32778)
	ON_COMMAND(ID_MENUITEM32779, OnLongth)
	ON_COMMAND(ID_MENUITEM32780, OnColor)
	ON_COMMAND(ID_MENUITEM32781, OnBegin)
	ON_COMMAND(ID_MENUITEM32782, OnBegin2)
	ON_COMMAND(ID_MENUITEM32783, OnCount)
	ON_COMMAND(ID_MENUITEM32784, OnSenSim)
	ON_COMMAND(ID_MENUITEM32785, OnSimsen)
	ON_COMMAND(ID_MENUITEM32787, Onchar)
	ON_COMMAND(ID_MENUITEM32786, Onjuzi)
	ON_COMMAND(ID_MENUITEM32788, OnPDF)
	ON_COMMAND(ID_MENUITEM32789, OnWORD)
	ON_COMMAND(ID_MENUITEM32796, OnCOLor)
	ON_COMMAND(ID_MENUITEM32791, OnNET)
	ON_COMMAND(ID_MENUITEM32792, OnBegin3)
	ON_COMMAND(ID_MENUITEM32793, OnParSim)
	ON_COMMAND(ID_MENUITEM32790, OnLocal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{//分栏
if (!m_wndSplitter.CreateStatic(this, 1, 2))
  {
    TRACE0("Failed to create splitter window\n");
    return FALSE;
  }
     //将CCuteFTPView连接到0行0列窗格上 
     m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CLeftView),CSize(350,100), pContext); 
     //将CView4连接到2行0列
    m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CRightView),CSize(100,100), pContext); 
 
  return TRUE;
  

	    




}

void CMainFrame::OnChoose() 
{//选择文件对话框
	CChoose   xuanze;
	xuanze.DoModal();

	// TODO: Add your command handler code here
	
}

void CMainFrame::OnSim() 
{//显示相似度（字符的）
	Showsim show;	
//	MessageBox("显示相似度！"); 
	show.DoModal();
	


	// TODO: Add your command handler code here
	
}

void CMainFrame::OnMenuitem32778() 
{// TODO: Add your command handler code here
	CSimPart Part;//
	Part.DoModal();
	
}

void CMainFrame::OnLongth() 
{//统计段落和字符长度
	CLongth longth;
	longth.DoModal();// TODO: Add your command handler code here
	
}

void CMainFrame::OnColor() 
{//添加颜色
/*	CLeftView  left;
	left.AddColor();
	//left.OnInitialUpdate();
	CRightView right;
	right.AddColor();
	*/
	
	
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnBegin() 
{//开始按字符比较
		CChoose ter;
	    ter.bijiao();	// TODO: Add your command handler code here
// TODO: Add your command handler code here
	
}

void CMainFrame::OnBegin2() 
{//开始按句子比较
	CChoose ter2;
	ter2.SentensiCompare();// TODO: Add your command handler code here
	
}

void CMainFrame::OnCount() 
{//统计句子个数
	CCount cou;
	cou.DoModal();// TODO: Add your command handler code here
	
}

void CMainFrame::OnSenSim() //
{//显示句子相似度
	CShowSenSim show;
	show.DoModal();// TODO: Add your command handler code here
	
}

void CMainFrame::OnSimsen() //相似句子输出
{//相似句子输出
	COutputSen outputS;
	extern double SentensNum;
	if(SentensNum==0)
		AfxMessageBox("没有完全相同的句子！");
	else
	outputS.DoModal();
	// TODO: Add your command handler code here
	
}

void CMainFrame::Onchar() 
{//关于字符的相似度
	// TODO: Add your command handler code here
	
}

void CMainFrame::Onjuzi() 
{//关于句子的相似度
	// TODO: Add your command handler code here
	CJuziSimilar juzi;
	juzi.DoModal();
}

void CMainFrame::OnPDF() 
{
	WinExec("D:\\pdf转化txt工具\\PDF2TXT.exe", SW_SHOW);
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnWORD() 
{
		WinExec("D:\\word转换为txt\\ultradocumenttotextconverter\\Ultra Document To Text Converter\\PDF2TXT.exe", SW_SHOW);
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnCOLor() 
{
	extern	char fileBuffer[5010],rBuffer[5010],rBuffer000[5010];
    extern	int rBSize,Add;//文档一的变量
	extern 	char fileBuffer2[5010] , rBuffer2[5010],rBuffer200[5010];
    extern 	int rBSize2,AF[5000];//文档二的变量
	CString str1="",str2="",juhao="。"; 
	extern double count1;//文档一的句子个数
	extern double count2;//文档二的句子个数
	extern CString Simsentence,CSen[200],A;//相同的句子
	extern int AFS[200],BFS[200];
	Simsentence="";
	int i=0,m=0,n=0;
	int j=0;
	int flag=0;
	A="";
	extern  double SentensNum;
		while(rBuffer[i]!='\0')
		{
			if(AFS[m]==1)
			{
				while(rBuffer[i]!='.'&&rBuffer[i]!=-93)
				{
					rBuffer000[i]=rBuffer[i];
					i++;
				}
				if(rBuffer[i]=='.'||rBuffer[i]==-93)
				{
					m++;
					rBuffer000[i]=32;
				}
			}
			else
			{
				while(rBuffer[i]!='.'&&rBuffer[i]!=-93)
				{
				rBuffer000[i]=32;
			    i++;
				}
				if(rBuffer[i]=='.'||rBuffer[i]==-93)
				{
					m++;
					rBuffer000[i]=32;
				}
			}
			i++;
		}
		AfxMessageBox(rBuffer000);
		while(rBuffer2[i]!='\0')
		{
			if(BFS[n]==1)
			{
				while(rBuffer2[j]!='.'&&rBuffer2[j]!=-93)
				{
					rBuffer200[j]=rBuffer2[j];
					j++;
				}
				if(rBuffer2[j]=='.'||rBuffer2[j]==-93)
				{
					n++;
					rBuffer200[j]=32;
				}
			}
			else
			{
				while(rBuffer2[j]!='.'&&rBuffer2[j]!=-93)
				{
				rBuffer200[j]=32;
			    j++;
				}
				if(rBuffer2[j]=='.'||rBuffer2[j]==-93)
				{
					n++;
					rBuffer200[j]=32;
				}
			}
			j++;
		}
//		rBuffer000[0]='1';	rBuffer000[0]=32;	
//    	rBuffer000[0]=32;	rBuffer000[0]=32;
//	   rBuffer000[0]='3';
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnNET() 
{

	ShellExecute(NULL,   _T("open"),   "http://localhost/myweb/index.asp",   NULL,NULL,   SW_SHOW);
	// TODO: Add your command handler code here
	
}

void CMainFrame::OnBegin3() 
{

	CChoose par;
	par.ParaCompare();// TODO: Add your command handler code here
	
}

void CMainFrame::OnParSim() 
{
	CParagraph para;
	para.DoModal();// TODO: Add your command handler code here
	
}

void CMainFrame::OnLocal() 
{
	ShellExecute(NULL,   _T("open"),   "http://localhost/myweb/file.asp",   NULL,NULL,   SW_SHOW);// TODO: Add your command handler code here
	
}
