// Round.cpp: implementation of the CRound class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Round.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//##ModelId=4918445C0002
CRound::~CRound()
{

}

//##ModelId=4918445C0023
void CRound::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CGeometry::PutToFile(outfile);
		outfile<<(*this);
	}
}

//##ModelId=4918445C002F
void CRound::GetFromFile(ifstream& infile)
{
	CGeometry::GetFromFile(infile);
	infile>>(*this);
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