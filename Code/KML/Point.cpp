#include "StdAfx.h"
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
	p.Object::output(out)<<"<Point>"<<endl;
	p.Object::output(out)<<"\t<coordinates>"<<endl;
	p.Object::output(out)<<"\t\t"<<p.getLongitude()<<","<<p.getLatitude()<<","<<p.getAltitude()<<endl;
	p.Object::output(out)<<"\t</coordinates>"<<endl;
	p.Object::output(out)<<"</Point>"<<endl;
	return out;
}
/*friend function
istream& operator >> ( istream& in, Point& p) 
{
	return in;
}*/