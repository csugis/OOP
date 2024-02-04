// Round.cpp: implementation of the CRound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Round.h"
#include <cmath>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CRound::~CRound()
{

}

void CRound::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CGeometry::PutToFile(outfile);
		outfile<<(*this);
	}
}

void CRound::GetFromFile(ifstream& infile)
{
	CGeometry::GetFromFile(infile);
	infile>>(*this);
}

void CRound::Draw(CDC* pDC)
{
	CRect rect;
	rect.left = m_ptXY.x - m_fRadius;
	rect.right = m_ptXY.x + m_fRadius;
	rect.top = m_ptXY.y - m_fRadius;
	rect.bottom = m_ptXY.y + m_fRadius;
	CBrush brush,*pOldBrush=NULL;
	CPen pen,*pOldPen=NULL;
	pen.CreatePen(GetLineType(),GetLineWidth(),GetPenColor());
	pOldPen = pDC->SelectObject(&pen);
	if(IsFill())
		brush.CreateSolidBrush(GetBrushColor());
	else
		brush.CreateStockObject(HOLLOW_BRUSH);
	pOldBrush=pDC->SelectObject(&brush);
	pDC->Ellipse(&rect);
	pDC->SelectObject(pOldBrush);
	pDC->SelectObject(pOldPen);
	CGeometry::Draw(pDC);
}

void CRound::GetRect(PointStruct& min, PointStruct& max) const
{
	min.x = m_ptXY.x - m_fRadius;
	min.y = m_ptXY.y - m_fRadius;
	max.x = m_ptXY.x + m_fRadius;
	max.y = m_ptXY.y + m_fRadius;
}

void CRound::Move(const PointStruct& off)
{
	m_ptXY.x += off.x;
	m_ptXY.y += off.y;
}

void CRound::MoveTo(const PointStruct& pt)
{
	m_ptXY=pt;
}

double CRound::DistanceToPoint(const PointStruct& pt) const
{
	double dist=0.0f;
	dist=sqrt(pow(pt.x-m_ptXY.x,2)+pow(pt.y-m_ptXY.y,2));
	dist -= m_fRadius;//<0圆环内 =0圆环上 >0圆环外
	return dist;
}

ifstream& operator >> (ifstream& infile, CRound& geo)
{
	infile>>geo.m_ptXY.x>>geo.m_ptXY.y>>geo.m_fRadius;
	return infile;
}

ofstream& operator << (ofstream& outfile, const CRound& geo)
{
	outfile<<geo.m_ptXY.x<<" "<<geo.m_ptXY.y<<" "<<geo.m_fRadius<<endl;
	return outfile;
}

