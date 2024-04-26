#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "LineString.h"

LineString::LineString(void)
{
	setType("LineString");
}

LineString::~LineString(void)
{
}

Geometry* LineString::Clone() const
{
	LineString* p = new LineString();
	p->coordinates = this->coordinates;
	return p;
}

ostream& LineString::output( ostream& out)
{
	return out<<*this;
}
ostream& operator << ( ostream& out, LineString& line)
{
//	line.Object::output(out)<<"<LineString id="<<line.getID()<<">"<<endl;
	line.Object::output(out)<<"<LineString>"<<endl;
	line.Object::output(out)<<"\t<coordinates>"<<endl;
	for(int i = 0; i<line.getCoordinates().getSize(); i++)
		line.Object::output(out)<<"\t\t"<<line.getCoordinates()[i].getLongitude()
		<<","<<line.getCoordinates()[i].getLatitude()
		<<","<<line.getCoordinates()[i].getAltitude()<<endl;
	line.Object::output(out)<<"\t</coordinates>"<<endl;
	line.Object::output(out)<<"</LineString>"<<endl;

	return out;
}