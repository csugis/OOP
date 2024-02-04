// Curve.cpp: implementation of the CCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Curve.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CCurve::~CCurve()
{
	DeletePoints();
}

//设置折线点坐标
void CCurve::SetCurvePoints(PointStruct* pPoints, int num)
{
	DeletePoints();
	for(int i=0; i<num; i++) m_vPoints.push_back(pPoints[i]);
}

void CCurve::GetPoints(PointStruct *pPoints) const//数组由调用者申请
{
	for(int i=0; i<GetPointsNum(); i++)
		pPoints[i] = m_vPoints[i];
}

void CCurve::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CGeometry::PutToFile(outfile);
		outfile<<(*this);
	}
}

void CCurve::GetFromFile(ifstream& infile)
{
	CGeometry::GetFromFile(infile);
	infile>>(*this);
}

void CCurve::Draw(CDC* pDC)
{
	CPoint *pPoints = new CPoint[GetPointsNum()];
	for(int i=0; i<GetPointsNum(); i++)
	{
		pPoints[i].x=GetPoints(i).x;
		pPoints[i].y=GetPoints(i).y;
	}
	CPen pen,*pOldPen=NULL;
	pen.CreatePen(GetLineType(),GetLineWidth(),GetPenColor());
	pOldPen = pDC->SelectObject(&pen);
	if(IsFill())
	{
		CBrush brush,*pOldBrush=NULL;
		brush.CreateSolidBrush(GetBrushColor());
		pOldBrush=pDC->SelectObject(&brush);
		pDC->Polygon(pPoints,GetPointsNum());
		pDC->SelectObject(pOldBrush);
	}
	else
		pDC->Polyline(pPoints,GetPointsNum());
	pDC->SelectObject(pOldPen);
	delete [] pPoints;
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
