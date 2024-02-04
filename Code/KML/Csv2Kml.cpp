#include "StdAfx.h"
#include "Csv2Kml.h"

Csv2Kml::Csv2Kml(void)
:pIndex(0)
{
	CString strFilter = _T("Excel¶ººÅ·Ö¸ô·ûÎÄ¼þ (*.csv)|*.csv||");
	CFileDialog inf(TRUE,NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if(inf.DoModal())
	{
		CString pathname = inf.GetPathName();
		infile.open(pathname.GetBuffer(0));
		CString filename = inf.GetFileName();
		string docName = filename.GetBuffer(0);
		document.setName(docName);
		InitFields();
		InitRows();
		Rows2Features();
		//save 
		CString fileext = inf.GetFileExt();
		filename.Replace(fileext,"");
		filename += "kml";
		outfile.open(filename);
		output(outfile);
	}
}


Csv2Kml::~Csv2Kml(void)
{
	if(infile) infile.close();
	if(outfile) outfile.close();
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
