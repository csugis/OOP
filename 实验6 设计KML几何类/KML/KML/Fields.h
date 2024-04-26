#pragma once
#include "Field.h"
#include "tArray.h"
#include "point.h"
#include "multigeometry.h"
class Fields
{
	bool IsDDDMMSS;
	bool IsRange;
	int fldName;
	int fldID;
	int fldLongitude;
	int fldLatitude;
	int fldAltitude;
	tArray<Field> flds;
	tArray<Point> pnts;
	tArray<MultiGeometry> multis;
public:
	double DMS2D(string&);
	void geometry(string& lon,string& lat,string& alt,Point& pt);
	void geometry(string& lon,string& lat,string& alt,MultiGeometry& mg);
	void getFieldValue(string&,int,string&);
	void name(string& row,string& na) {getFieldValue(row,fldName,na);}
	void ID(string& row,string& id) {getFieldValue(row,fldID,id);}
	void description(string&,string&);
	Geometry* geometry(string&,tArray<Point>** pnts,
		tArray<MultiGeometry>** multis, int& n);
	void operator()(string&);
	tArray<Field>& getFields(void) {return flds;}
	void setFields(tArray<Field>& fields) {flds=fields;}
	Fields(void);
	virtual ~Fields(void);
};
