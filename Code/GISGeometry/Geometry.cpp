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

//##ModelId=4918445C0206
CGeometry::~CGeometry()
{

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
