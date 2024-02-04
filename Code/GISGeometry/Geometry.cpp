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
