// Arc.cpp: implementation of the CArc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Arc.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


//##ModelId=4918445C02E0
CArc::~CArc()
{

}

//##ModelId=4918445C02EE
void CArc::PutToFile(ofstream& outfile) const
{
	if(!IsDelete())
	{
		CRound::PutToFile(outfile);
		outfile<<(*this);
	}
}
//##ModelId=4918445C02F1
void CArc::GetFromFile(ifstream& infile)
{
	CRound::GetFromFile(infile);
	infile>>(*this);
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
