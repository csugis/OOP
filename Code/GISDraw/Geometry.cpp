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

//���ļ��ж�ȡһ��ͼ��
//void CColorTable::OpenClrTable(const char* szFileName)
//{
//	ifstream infile(szFileName,ios::in);
//	ColorStruct clr;
//	while(infile>>clr)
//		InsertColors(clr);
//	infile.close();
//}

//����һ��ͼ�㵽�ļ���
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
	//�����ѡ��״̬�������
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
	infile>>geo.m_sColorPen;	//��ɫ
	infile>>geo.m_sColorBrush;	//���ˢ��ɫ
	infile>>geo.m_sLineWidth;	//�߿����أ�
	infile>>geo.m_sLineType;	//���ͣ����أ�
	infile>>geo.m_idOnly;		//ͼ��Ԫ��Ψһ��ʶ���
	return infile;
}

ofstream& operator << (ofstream& outfile, const CGeometry& geo)
{
	outfile<<geo.m_sColorPen<<" ";	//��ɫ
	outfile<<geo.m_sColorBrush<<" ";	//���ˢ��ɫ
	outfile<<geo.m_sLineWidth<<" ";	//�߿����أ�
	outfile<<geo.m_sLineType<<" ";	//���ͣ����أ�
	outfile<<geo.m_idOnly<<" ";		//ͼ��Ԫ��Ψһ��ʶ���
	return outfile;
}
