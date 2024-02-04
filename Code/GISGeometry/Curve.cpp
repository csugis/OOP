// Curve.cpp: implementation of the CCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Curve.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//##ModelId=4918445C0263
CCurve::~CCurve()
{
	DeletePoints();
}

//设置折线点坐标
//##ModelId=4918445C028C
void CCurve::SetCurvePoints(PointStruct* pPoints, int num)
{
	DeletePoints();
	for(int i=0; i<num; i++) m_vPoints.push_back(pPoints[i]);
}

//##ModelId=4918445C0283
void CCurve::GetPoints(PointStruct *pPoints) const//数组由调用者申请
{
	for(int i=0; i<GetPointsNum(); i++)
		pPoints[i] = m_vPoints[i];
}

//##ModelId=4918445C0273
void CCurve::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CGeometry::PutToFile(outfile);
		outfile<<(*this);
	}
}

//##ModelId=4918445C0276
void CCurve::GetFromFile(ifstream& infile)
{
	CGeometry::GetFromFile(infile);
	infile>>(*this);
}

ifstream& operator >> (ifstream& infile, CCurve& geo)
{
	int num = 0;
	infile>>num;
	PointStruct pt;
	for(int i=0; i<num; i++)
	{
		infile>>pt.x>>pt.y;
		geo.InsertPoints(pt);
	}
	return infile;
}

ofstream& operator << (ofstream& outfile, const CCurve& geo)
{
	outfile<<geo.GetPointsNum()<<endl;
	for(int i=0; i<geo.GetPointsNum(); i++)
	{
		outfile<<geo.m_vPoints[i].x<<" "<<geo.m_vPoints[i].y<<endl;
	}
	return outfile;
}
