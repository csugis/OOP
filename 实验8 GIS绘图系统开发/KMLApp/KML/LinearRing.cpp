#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "LinearRing.h"

LinearRing::LinearRing(void)
{
	setType("LinearRing");
}

LinearRing::~LinearRing(void)
{
}

Geometry* LinearRing::Clone() const
{
	LinearRing* p = new LinearRing();
	p->coordinates = this->coordinates;
	return p;
}
ostream& LinearRing::output( ostream& out)
{
	return out<<*this;
}
ostream& operator << ( ostream& out, LinearRing& ring)
{
//	ring.Object::output(out)<<"<LinearRing id="<<ring.getID()<<">"<<endl;
	ring.Object::output(out)<<"<LinearRing>"<<endl;
	ring.Object::output(out)<<"\t<coordinates>"<<endl;
	for(int i = 0; i<ring.getCoordinates().getSize(); i++)
		ring.Object::output(out)<<"\t\t"<<ring.getCoordinates()[i].getLongitude()
		<<","<<ring.getCoordinates()[i].getLatitude()
		<<","<<ring.getCoordinates()[i].getAltitude()<<endl;
	ring.Object::output(out)<<"\t</coordinates>"<<endl;
	ring.Object::output(out)<<"</LinearRing>"<<endl;
	return out;
}