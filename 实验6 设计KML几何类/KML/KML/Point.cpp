#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Point.h"

Point::Point(void)
{
	setType("Point");
}

Point::~Point(void)
{
}

ostream& Point::output( ostream& out)
{
	return out<<*this;
}

ostream& operator << ( ostream& out, Point& p) 
{
//	p.Object::output(out)<<"<Point id="<<p.getID()<<">"<<endl;
	out<<"<Point>"<<endl;
	out<<"\t<coordinates>"<<endl;
	double lon = p.getLongitude();
	double lat = p.getLatitude();
	out.setf(ios::fixed);
	out.precision(6);
	out<<"\t\t"<<lon<<","<<lat<<","<<p.getAltitude()<<endl;
	out<<"\t</coordinates>"<<endl;
	out<<"</Point>"<<endl;
	return out;
}
/*friend function
istream& operator >> ( istream& in, Point& p) 
{
	return in;
}*/