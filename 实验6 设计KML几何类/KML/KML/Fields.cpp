#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Fields.h"

Fields::Fields(void)
:IsDDDMMSS(false)
,IsRange(true)
,fldID(-1)
,fldLongitude(-1)
,fldLatitude(-1)
,fldAltitude(-1)
,fldName(-1)
{

}

Fields::~Fields(void)
{
}
double Fields::DMS2D(string& dms)
{
	double d = 0.0f;
	if(dms.empty())
		return d;
	string sd = "",sm = "", ss = "";
	sd = dms.substr(0,dms.length()-4);
	sm = dms.substr(dms.length()-4,2);
	ss = dms.substr(dms.length()-6,2);
	d = atof(sd.c_str()) + atof(sm.c_str())/60.0f + atof(ss.c_str())/3600.0f;
	return d;
}
void Fields::geometry(string& lon,string& lat,string& alt,Point& pt)
{
	double longitude = 0;
	double latitude = 0;
	double altitude = 0;

	if(IsDDDMMSS)
	{
		longitude = DMS2D(lon);
		latitude = DMS2D(lat);
		altitude = 0;
	}
	else
	{
		longitude = atof(lon.c_str());
		latitude = atof(lat.c_str());
		altitude = 0;
	}
	pt(longitude,latitude,altitude);
}
void Fields::geometry(string& lon,string& lat,string& alt,MultiGeometry& mg)
{
	const string strsrc = "-";
	string lon0="",lon1="";
	string lat0="",lat1="";
	double longitude0,latitude0,altitude =0;
	double longitude1,latitude1;
	string::size_type pos=0;
	const string::size_type srclen=strsrc.size();
	if( (pos=lon.find(strsrc)) != string::npos)
	{
		lon0 = lon.substr(0,pos);
		longitude0 = DMS2D(lon0);
		lon1 = lon.substr(pos+srclen,pos);
		longitude1 = DMS2D(lon1);
	}
	pos=0;
	if( (pos=lat.find(strsrc)) != string::npos)
	{
		lat0 = lat.substr(0,pos);
		latitude0 = DMS2D(lat0);
		lat1 = lat.substr(pos+srclen,pos);
		latitude1 = DMS2D(lat1);
	}
	//添加一个点
	mg.getPoints()(1);
	mg.getPoints()[0].setParentNode(&mg);
	mg.getPoints()[0](((longitude0+longitude1)/2.0f)
		,((latitude0+latitude1)/2.0f));
	//添加两条对角线，第一条
	mg.getLineStrings()(2);
	mg.getLineStrings()[0].setParentNode(&mg);
	mg.getLineStrings()[0].getCoordinates()(2);
	mg.getLineStrings()[0].getCoordinates()[0](
		longitude0,latitude0);
	mg.getLineStrings()[0].getCoordinates()[1](
		longitude1,latitude1);
	//添加第二条
	mg.getLineStrings()[1].setParentNode(&mg);
	mg.getLineStrings()[1].getCoordinates()(2);
	mg.getLineStrings()[1].getCoordinates()[0](
		longitude0,latitude1);
	mg.getLineStrings()[1].getCoordinates()[1](
		longitude1,latitude0);
	//添加一个多边形
	mg.getPolygons()(1);
	mg.getPolygons()[0].setParentNode(&mg);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()(5);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()[0](
		longitude0,latitude0);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()[1](
		longitude1,latitude0);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()[2](
		longitude1,latitude1);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()[3](
		longitude0,latitude1);
	mg.getPolygons()[0].getOuterBoundary().getCoordinates()[4](
		longitude0,latitude0);	
}

Geometry* Fields::geometry(string& row,tArray<Point>** ppnts,
		tArray<MultiGeometry>** pmultis, int& n)
{
	*ppnts = 0;
	*pmultis = 0;
	n = -1;
	Geometry* pGeo = 0;
	const string strsrc = "-";
	string lon = "",lat="", alt="";
	getFieldValue(row,fldLongitude,lon);
	getFieldValue(row,fldLatitude,lat);
	string::size_type pos=0;
	if(((pos=lon.find(strsrc)) != string::npos)
		||((pos=lat.find(strsrc)) != string::npos))
	{
		geometry(lon,lat,alt,multis[multis.getSize()]);
		pGeo = &(multis[multis.getSize()-1]);
		*pmultis = &multis;
		n = multis.getSize()-1;
	}
	else
	{
		geometry(lon,lat,alt,pnts[pnts.getSize()]);
		pGeo = &(pnts[pnts.getSize()-1]);
		*ppnts = &pnts;
		n = pnts.getSize()-1;
	}
		
	return pGeo;
}

void Fields::description(string& row,string& des)
{
	des = "<![CDATA[ \n";
    des+= "<table border=\"1\" padding=\"3\" width=\"300\">\n";
	string value = "";
	for(int i=0;i<flds.getSize();i++)
	{
		des+="<tr>";
		des+="<td>"+flds[i].getName()+"</td>";
		getFieldValue(row,i,value);
		des+="<td>"+value+"</td>";
		des+="</tr>";
	}
    des+= "</table>\n";
	des+= "]]>\n";
}

void Fields::getFieldValue(string& row,int no,string& value)
{
	const string strsrc = ",";
	long fldNum = 0;
	value = "";
	string str = "";
	string::size_type tmp=0;
	string::size_type pos=0;
	const string::size_type srclen=strsrc.size();
	while( (pos=row.find(strsrc, tmp)) != string::npos)
	{	
		str = row.substr(tmp,pos-tmp);
		if(fldNum == no)
		{
			value = str;
			return;
		}
		tmp = pos+srclen;
		fldNum++;
	}
	if(fldNum == no)
	{
		value = row.substr(tmp,row.length()-tmp);
	}
}

void Fields::operator()(string& strFlds)
{
	const string strsrc = ",";
	long fldNum = 0;
	string str = "";
	string::size_type tmp=0;
	string::size_type pos=0;
	const string::size_type srclen=strsrc.size();
	while( (pos=strFlds.find(strsrc, tmp)) != string::npos)
	{	
		str = strFlds.substr(tmp,pos-tmp);
		if(str.empty())
			break;
		tmp = pos+srclen;
		fldNum++;
	}
	flds(fldNum);
	fldNum = 0;
	tmp=0;
	pos=0;
	while( (pos=strFlds.find(strsrc, tmp)) != string::npos)
	{	
		str = strFlds.substr(tmp,pos-tmp);
		if(str.empty())
			break;
		flds[fldNum].setNo(fldNum);
		flds[fldNum].setName(str);
		tmp = pos+srclen;
		fldNum++;
	}
	for(int i = 0; i<flds.getSize(); i++)
		cout<<flds[i].getNo()<<":"<<flds[i].getName()<<endl;
	cout<<"pls select ID field (default = -1):";
	cin>>fldID;
	cout<<"pls select Name field:";
	cin>>fldName;
	cout<<"pls select Longitude field:";
	cin>>fldLongitude;
	cout<<"pls select Latitude field:";
	cin>>fldLatitude;
//	cout<<"pls select Altitude field (default = -1):";
//	cin>>fldAltitude;
//	cout<<"Longitude & Latitude is DDDMMSS format (yes=1/no=0):";
//	cin>>IsDDDMMSS;
//	cout<<"Longitude & Latitude include range (yes=1/no=0):";
//	cin>>IsRange;
}
