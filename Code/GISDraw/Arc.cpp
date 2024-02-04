// Arc.cpp: implementation of the CArc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Arc.h"
#include <cmath>
#include "Manager.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CArc::~CArc()
{

}

void CArc::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CRound::PutToFile(outfile);
		outfile<<(*this);
	}
}
void CArc::GetFromFile(ifstream& infile)
{
	CRound::GetFromFile(infile);
	infile>>(*this);
}

void CArc::Draw(CDC* pDC)
{
	CRect rect;
	PointStruct pt;
	CPoint ptStart,ptEnd;
	double r=GetRadius();
	GetCenter(pt);
	rect.left = pt.x - r;
	rect.right = pt.x + r;
	rect.top = pt.y - r;
	rect.bottom = pt.y + r;
	ptStart.x = pt.x + cos(m_fStart)*r;
	ptStart.y = pt.x + sin(m_fStart)*r;
	ptStart.x = pt.x + cos(m_fEnd)*r;
	ptStart.y = pt.x + sin(m_fEnd)*r;
	CPen pen,*pOldPen=NULL;
	pen.CreatePen(GetLineType(),GetLineWidth(),GetPenColor());
	pOldPen=pDC->SelectObject(&pen);
	pDC->Arc(&rect,ptStart,ptEnd);
	pDC->SelectObject(pOldPen);
}

ifstream& operator >> (ifstream& infile, CArc& geo)
{
	infile>>geo.m_fStart>>geo.m_fEnd;
	return infile;
}

ofstream& operator << (ofstream& outfile, const CArc& geo)
{
	outfile<<geo.m_fStart<<" "<<geo.m_fEnd<<endl;
	return outfile;
}

