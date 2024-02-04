// Geometry.cpp: implementation of the CGeometry class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Geometry.h"
#include <cmath>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool operator == (const PointStruct& pt1, const PointStruct& pt2)
{
	if(fabs(pt1.x-pt2.x) <= 1.0E-4 
		&& fabs(pt1.y-pt2.y) <= 1.0E-4 
		/*&& fabs(pt1.z-pt2.z) <= 1.0E-4*/)
	{
		return true;
	}
	return false;
}
bool operator > (const PointStruct& pt1, const PointStruct& pt2)
{
	return ((pt1.x>pt2.x)&&(pt1.y>pt2.y))?true:false;
}
bool operator < (const PointStruct& pt1, const PointStruct& pt2)
{
	return ((pt1.x<pt2.x)&&(pt1.y<pt2.y))?true:false;
}

//ifstream& operator >> (ifstream& infile, ColorStruct& clr)
//{
//	infile>>clr.r>>clr.g>>clr.b;
//	return infile;
//}

//ofstream& operator << (ofstream& outfile, const ColorStruct& clr)
//{
//	outfile<<clr.r<<" "<<clr.g<<" "<<clr.b<<endl;
//	return outfile;
//}

//从文件中读取一个图层
//void CColorTable::OpenClrTable(const char* szFileName)
//{
//	ifstream infile(szFileName,ios::in);
//	ColorStruct clr;
//	while(infile>>clr)
//		InsertColors(clr);
//	infile.close();
//}

//保存一个图层到文件中
//void CColorTable::SaveClrTable(const char* szFileName)
//{
//	ofstream outfile(szFileName,ios::out);
//	for(int i=0; i<GetColorNum(); i++)
//		outfile<<GetColor(i);
//	outfile.close();
//}

////////////////////////////////////////////////////////////////////////////////////////////////////

CGeometry::~CGeometry()
{

}

void CGeometry::Draw(CDC* pDC)
{
	PointStruct ptMin, ptMax;
	//如果是选中状态绘制外框
	if(IsSelected())
	{
		GetRect(ptMin,ptMax);
		CRect rect;
		rect.left = ptMin.x;
		rect.right = ptMax.x;
		rect.top = ptMin.y;
		rect.bottom = ptMax.y;
		CBrush brush,*pOldBrush=NULL;
		CPen pen,*pOldPen=NULL;
		pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
		pOldPen = pDC->SelectObject(&pen);
		brush.CreateStockObject(HOLLOW_BRUSH);
		pOldBrush=pDC->SelectObject(&brush);
		pDC->Rectangle(&rect);
		pDC->SelectObject(pOldBrush);
		pDC->SelectObject(pOldPen);
	}
}

ifstream& operator >> (ifstream& infile, CGeometry& geo)
{
	infile>>geo.m_sColorPen;	//笔色
	infile>>geo.m_sColorBrush;	//填充刷颜色
	infile>>geo.m_sLineWidth;	//线宽（像素）
	infile>>geo.m_sLineType;	//线型（像素）
	infile>>geo.m_idOnly;		//图形元素唯一的识别号
	return infile;
}

ofstream& operator << (ofstream& outfile, const CGeometry& geo)
{
	outfile<<geo.m_sColorPen<<" ";	//笔色
	outfile<<geo.m_sColorBrush<<" ";	//填充刷颜色
	outfile<<geo.m_sLineWidth<<" ";	//线宽（像素）
	outfile<<geo.m_sLineType<<" ";	//线型（像素）
	outfile<<geo.m_idOnly<<" ";		//图形元素唯一的识别号
	return outfile;
}
