// Choose.cpp : implementation file
//
#include <iostream.h>
#include <string.h>
#include <stdio.h>
#include "stdafx.h"
#include "Similary.h"
#include "Choose.h"
#include "LeftView.h"
#include "RightView.h"
#include "Xuanze.h"
#include "Xuanze2.h"
#include "Showsim.h"
#include "SimilaryDoc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoose dialog

// CFileDialog m_OpenDialog(TRUE,"txt","*.txt");


CChoose::CChoose(CWnd* pParent /*=NULL*/)
	: CDialog(CChoose::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoose)
	//}}AFX_DATA_INIT
}


void CChoose::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoose)
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoose, CDialog)
	//{{AFX_MSG_MAP(CChoose)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoose message handlers

void CChoose::OnButton1() 
{

    CXuanze1 Buttion1;	
// 	Buttion1.DoModal();

//	CFileDialog aa(TRUE,"txt","*.txt");
//	aa.DoModal();
	// TODO: Add your control notification handler code here

extern	char fileBuffer[5010], rBuffer[5010];
extern	int rBSize;
	//定义一个CFile类,用来处理文件
	CFile in;
	 	//CFile in1;
	//定义一个CFileDialog类,用来显示标准的打开文件对话框
	CFileDialog inDlg(TRUE, NULL, NULL, NULL, _T("自定义文件类型 (*.txt)|*.txt|所有文件 (*.*)|*.*||"), NULL);
	inDlg.m_ofn.lpstrTitle = _T("打开自定义文件");
	//设定一个文件名缓存，因为CFileDialog内置的文件名缓存长度只有200，但是很多时候，文件的路径远大于这个数，为了保险起见，所以要自己设定一个文件名缓存
	inDlg.m_ofn.lpstrFile = fileBuffer;
	//设定缓存长度
	inDlg.m_ofn.nMaxFile = 5000;
	//显示对话框，并处理按了确定按钮的事件
	if(inDlg.DoModal() == IDOK) {
	
		//以只读方式打开文件
		if(in.Open(inDlg.GetPathName(), CFile::modeRead)) {
			//得到文件长度，从而确定读取缓存的大小
			rBSize = in.GetLength();	
			//避免数组越界，当然在这里也可以动态申请缓存空间
			if(rBSize > 5000) rBSize = 5000;
		//	leftview.SerializeRaw( CArchive& ar );
		   //leftview.PrintInsideRect( CDC *pDC, RECT& rectLayout, UINT nIndexStart, UINT nIndexStop );
			//读入数据	
			CString file_title;// ="aa"
			file_title= inDlg.GetPathName();
			CString file_path1;
	    	file_path1=file_title;	
			in.Read(rBuffer, rBSize);//rBuffer里存了文件中的内容；
		//	leftview.PrintInsideRect(file_path1,rBuffer,2);

		//关闭文件
			in.Close();
		//	MessageBox("打开文件成功", "搞定了", MB_ICONEXCLAMATION | MB_OK);
	 	//	MessageBox(file_title);//文件名显示
	
    	//MessageBox(file_path);//文件名显示
		//	m_edit1.ReplaceSel(file_path1);
		m_edit1.SetWindowText(file_path1);
	
		} 
	 else {
			MessageBox("打开文件失败", "失败了", MB_ICONSTOP | MB_OK);
		}
	}

	
}
void CChoose::OnButton2() 
{
	CXuanze2 Buttion2;	
	// 	Buttion2.DoModal();
	
//	CFileDialog file2(TRUE,"txt","*.txt");
//	file2.DoModal();
//	CString str=file2.GetFileName();
	// TODO: Add your control notification handler code here
	
	//打开文件
	//创建文件名缓存(fileBuffer)和文件读取缓存(rBuffer)
	//此处如果不把缓存置0，在后面的设定中就会出错，如果是动态申请的，请用memset或者for循环把数组清零
extern 	char fileBuffer2[5010] , rBuffer2[5010];
extern 	int rBSize2;
	//定义一个CFile类,用来处理文件
	CFile in;
	//定义一个CFileDialog类,用来显示标准的打开文件对话框
	CFileDialog inDlg(TRUE, NULL, NULL, NULL, _T("自定义文件类型 (*.txt)|*.txt|所有文件 (*.*)|*.*||"), NULL);
	inDlg.m_ofn.lpstrTitle = _T("打开自定义文件");
	//设定一个文件名缓存，因为CFileDialog内置的文件名缓存长度只有200，但是很多时候，文件的路径远大于这个数，为了保险起见，所以要自己设定一个文件名缓存
	inDlg.m_ofn.lpstrFile = fileBuffer2;
	//设定缓存长度
	inDlg.m_ofn.nMaxFile = 5000;
	//显示对话框，并处理按了确定按钮的事件
	if(inDlg.DoModal() == IDOK) {
		//以只读方式打开文件
		if(in.Open(inDlg.GetPathName(), CFile::modeRead)) {
			//得到文件长度，从而确定读取缓存的大小
			rBSize2 = in.GetLength();
			//避免数组越界，当然在这里也可以动态申请缓存空间
			if(rBSize2 > 5000) rBSize2 = 5000;
			//读入数据
			in.Read(rBuffer2, rBSize2);
			in.Close();	//关闭文件
			CString file_title2;// ="aa"	
			CString file_path2;
			file_title2= inDlg.GetPathName();
			file_path2=file_title2;
		// 	m_edit2.ReplaceSel(file_path2);
 
           m_edit2.SetWindowText(file_path2); 
			UpdateData(false);
		
    	 //   MessageBox(file_path2);//文件名显示
		   	//有问题		 
		//	MessageBox("打开文件成功", "搞定了", MB_ICONEXCLAMATION | MB_OK);
		} else {
			MessageBox("打开文件失败", "失败了", MB_ICONSTOP | MB_OK);
		}
	}


}
void CChoose::OnOK() 
{
	// TODO: Add extra validation here
/////////////////////////////////////////////////////////////////////////////////
  /*  extern 	char fileBuffer2[5010] , rBuffer2[5010];
    extern 	int rBSize2,AF[5000];
    extern	char fileBuffer[5010],rBuffer[5010];
    extern	int rBSize;
    extern  double similary;
	extern 	double sim;
    int rBSize0;

    CChoose chose;	
	rBSize0=Max(rBSize,rBSize2);
	sim=chose.similarycompare(rBuffer,rBuffer2,rBSize,rBSize2);
	similary=1.0*(sim/rBSize0);
	similary=1.0*(sim/rBSize0);	
	int i=0,j=0;
/*	while(rBuffer[i]!='\0')
	{
		if(AF[i]==1)
		{
			j=rBSize;
		while(j!=i)
		{
			rBuffer[j]=rBuffer[j-1];

			j--;
		}

		rBuffer[j]='&';

		i++;

	}
	}*/
/////////////////////////////////////////////////////////////////////////////////	
	CDialog::OnOK();

}

int CChoose::Max(int a,int b)
{
	int result=0;
	if(a>=b)
		result=a;
	else
		result=b;
	return result;

}
int p=0,q1=0,q2=0;char C[5000];
int CChoose::similarycompare(char A[], char B[], int m, int n)
{//递归的！
	CChoose h1;
	extern 	int AF[5000],BF[5000],Add;
	int i,k,max,found,count,subcount;
	extern char rBuffer20[5010],rBuffer00[5010];//记下相同的地方
    count=0;max=0;
    for(i=0;(i<m)&&(i<n);i++)
	{	if(A[i]==B[i])
		{
			C[p]=A[i];
			AF[i]=1;BF[i]=1;
			Add=1;
			rBuffer20[q1]=A[i];	
			rBuffer00[q2]=B[i];
			p++;
			count++;//相同的应该改变颜色！
		q1++;q2++;
		}
        else
		{
			found=0 ;
			for(k=i+1;k<n;k++)//遇到不一样的就向后错一个继续比
				if(A[i]==B[k])
				{q1++;//相同的应该改变颜色				
					found=1;
					subcount=h1.similarycompare((char *)&A[i],(char *)&B[k],m-i,n-k);
					if (max<subcount)
						max=subcount;
				}
			for (k=i+1;k<m;k++)
				if(A[k]==B[i])
				{ //相同的应该改变颜色
					
					found=1;
					subcount=h1.similarycompare((char *)&A[k],(char *)&B[i],m-k,n-i);
					if(max<subcount)
						max=subcount;
				}
			if(found)
			{
				p++;q2++;
				subcount=h1.similarycompare((char *)&A[i+1],(char *)&B[i+1],m-i-1,n-i-1);
				if(max<subcount) 
					max=subcount;
				break;
			}
		}
	
	}
		q1++;q2++;
		C[p]='\0';
    	//MessageBox(C);
		return(count+max);
			
}

void CChoose::bijiao()
{
	extern 	char fileBuffer2[5010] , rBuffer2[5010];
    extern 	int rBSize2,AF[5000];
    extern	char fileBuffer[5010],rBuffer[5010];
    extern	int rBSize;
    extern  double similary;
	extern 	double sim;
    int rBSize0;
    CChoose chose;	
	rBSize0=Max(rBSize,rBSize2);
	sim=chose.similarycompare(rBuffer,rBuffer2,rBSize,rBSize2);
	similary=1.0*(sim/rBSize0);
	similary=1.0*(sim/rBSize0);	

}

void CChoose::SentensiCompare()//句子比较
{
	extern	char fileBuffer[5010],rBuffer[5010];
    extern	int rBSize,Add;//文档一的变量
	extern 	char fileBuffer2[5010] , rBuffer2[5010];
    extern 	int rBSize2,AF[5000];//文档二的变量
	CString str1="",str2="",juhao="。"; 
	extern double count1;//文档一的句子个数
	extern double count2;//文档二的句子个数
	extern CString Simsentence,CSen[200];//相同的句子
	extern int AFS[200],BFS[200];
	Simsentence="";
	int i=0,m=0;
	int j=0;
	int flag=2;
	int con1=0,con2=0;
	count1=0;
	count2=0;
	extern  double SentensNum;
	while(rBuffer[i]!='\0')
	{
		j=0;
		if(rBuffer[i]!=44&&rBuffer[i]!=46&&rBuffer[i]!=33&&rBuffer[i]!=5)
			str1=str1+rBuffer[i];
		else
		{
			count1++;
			while(rBuffer2[j]!='\0')
			{	
				if(rBuffer2[j]!=44&&rBuffer2[j]!=46&&rBuffer2[j]!=33&&rBuffer2[j]!=59)
				{
					str2=str2+rBuffer2[j];
					j++;
				}
			    if(rBuffer2[j]==44||rBuffer2[j]==46||rBuffer2[j]==33||rBuffer2[j]==59)
				{   //AfxMessageBox(str2);
				    count2++;
					flag=str1.Compare(str2);
					if(flag==0)//两个句子相同
					{ 
						SentensNum++;
						Simsentence=Simsentence+str1+" "+juhao;
						CSen[m]=CSen[m]+str1+".";//把相同的句子记下来
						m++;
						con1=count1-1;
						con2=count2-1;
						AFS[con1]=1;//记录位置
						BFS[con2]=1;	
					//AfxMessageBox("加了一次");
			        }
					str2="";
					j++;	
				}
			}
		}
		if(rBuffer[i]==44||rBuffer[i]==46||rBuffer[i]==33||rBuffer[i]==59)
		{
			
			str1="";

		}
			i++;
			
	}
//	for(int p=0;p<m;p++)
	//	AfxMessageBox(CSen[p]);


//	AfxMessageBox(Simsentence);
	if(count1==0&&count2!=0)
		AfxMessageBox("文档1没有以句号或句点结尾的句子！");
	if(count2==0&&count1!=0)
		AfxMessageBox("文档1没有以句号或句点结尾的句子！");
	if(count1==0&&count2==0)
		AfxMessageBox("两文档没有以句号或句点结尾的句子！");
	if(count1!=0&&count2!=0)
	{
		count2=count2/count1;
    	SentensNum=SentensNum;
	}

}

double CChoose::ParaCompare()//段落比较
{

	extern 	char rBuffer[5010];
	extern 	char rBuffer2[5010];
	extern double ParaSim;
	CString par1="",par2="";
	int i=0,j=0;
	int flag=2;
	while(rBuffer[i]!='\0')
	{
	    par1=par1+rBuffer[i];
		i++;
		j=0;
		if(rBuffer[i]==13)
		{
			while(rBuffer2[j])
			{	
				par2=par2+rBuffer2[j];
			    j++;
				if(rBuffer2[j]==13)
				{
					flag=par1.Compare(par2);
					par2="";
					if(flag==0)
						ParaSim++;
				}
			}
			par1="";
		}
			

	}
	return ParaSim;


}
