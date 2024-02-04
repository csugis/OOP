#include "StdAfx.h"
#include "Csv2Kml.h"

Csv2Kml::Csv2Kml(void)
:pIndex(0)
{
	infile.open(_T("中南大学WGS-84.csv"));
	string docName = "中南大学WGS-84";
	document.setName(docName);
	InitFields();
	InitRows();
	Rows2Features();
	outfile.open(_T("gps.kml"));
}

Csv2Kml::~Csv2Kml(void)
{
	infile.close();
	outfile.close();
}

void Csv2Kml::InitFields(void)
{
 	if ( !infile ) {
	 	cerr<<"Unable to open the file.\n";
		return;
	}
	string strBuf = "";
	getline(infile,strBuf);
	fields(strBuf);
}

void Csv2Kml::InitRows(void)
{
	int nrows = 0;
	string strBuf = "";
	while(getline(infile,strBuf))
	{
		rows[nrows] = strBuf;
		nrows++;
	}
}

void Csv2Kml::Rows2Features(void)
{
	pIndex(rows.getSize());
	document.getPlacemarks()(rows.getSize());
	string buf = "";
	for(int i=0;i<rows.getSize();i++)
	{
		document.getPlacemarks()[i].setParentNode(&document);
		fields.ID(rows[i],buf);
		document.getPlacemarks()[i].setID(buf);
		fields.name(rows[i],buf);
		document.getPlacemarks()[i].setName(buf);
		fields.description(rows[i],buf);
		document.getPlacemarks()[i].setDescrription(buf);
		document.getPlacemarks()[i].setGeometry(
			fields.geometry(rows[i],&pIndex[i].pnts,&pIndex[i].multis,pIndex[i].n));
	}
	for(int i=0;i<document.getPlacemarks().getSize();i++)
	{
		if(pIndex[i].n<0)
			cerr<<"Create failed!"<<endl;
		if(pIndex[i].pnts==0 && pIndex[i].multis==0)
			cerr<<"Memory distroy!"<<endl;
		if(pIndex[i].pnts!=0)
		{
			document.getPlacemarks()[i].setGeometry(
				&((*(pIndex[i].pnts))[pIndex[i].n]));
		}
		else if(pIndex[i].multis!=0)
		{
			document.getPlacemarks()[i].setGeometry(
				&((*(pIndex[i].multis))[pIndex[i].n]));
		}
	}
}

ostream& Csv2Kml::output(ostream& out)
{
	out<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl;
	out<<"<kml xmlns=\"http:/"<<"/www.opengis.net/kml/2.2\""<<endl;
	out<<"xmlns:gx=\"http:/"<<"/www.google.com/kml/ext/2.2\">"<<endl;
    //<!-- required when using gx-prefixed elements -->
	out<<document;
	out<<"</kml>"<<endl;
	return out;
}
