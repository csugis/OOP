#pragma once

#include "document.h"
#include "fields.h"

struct indexGeometry{
	tArray<Point>* pnts;
	tArray<MultiGeometry>* multis;
	int n;
};

class Csv2Kml
{
	Fields fields;
	ifstream infile;
	ofstream outfile;
	Document document;
	tArray<string> rows;
	tArray<indexGeometry> pIndex;
protected:
	void InitFields(void);
	void InitRows(void);
	void Rows2Features(void);
public:
	ofstream& getOutfile(void) {return outfile;}
	ostream& output(ostream& out);
	Csv2Kml(void);
	virtual ~Csv2Kml(void);
};
