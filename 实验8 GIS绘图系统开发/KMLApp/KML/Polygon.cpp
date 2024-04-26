#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Polygon.h"

Polygon::Polygon(void)
{
	outerBoundary.setParentNode(this);
	setType("Polygon");
}
Polygon::Polygon(const Poly& poly)
{
	outerBoundary = poly.outerBoundary;
	outerBoundary.setParentNode(this);
	innerBoundary = poly.innerBoundary;
	for(int i=0; i < innerBoundary.getSize(); i++)
	{
		innerBoundary[i].setParentNode(this);
	}
}

Polygon::~Polygon(void)
{
}

Geometry* Polygon::Clone() const
{
	Geometry* p = new Polygon(*this);
	return p;
}

ostream& Polygon::output( ostream& out)
{
	return out<<*this;
}

Poly& Polygon::operator = (Poly& poly)
{
	outerBoundary = poly.outerBoundary;
	outerBoundary.setParentNode(this);
	innerBoundary = poly.innerBoundary;
	for(int i=0; i < innerBoundary.getSize(); i++)
	{
		innerBoundary[i].setParentNode(this);
	}
	return *this;
}

ostream& operator << ( ostream& out, Poly& polygon)
{
//	polygon.Object::output(out)<<"<Polygon id="<<polygon.getID()<<">"<<endl;
	polygon.Object::output(out)<<"<Polygon>"<<endl;
	polygon.Object::output(out)<<"\t<outerBoundaryIs>"<<endl;
	out<<polygon.getOuterBoundary();
	polygon.Object::output(out)<<"\t</outerBoundaryIs>"<<endl;
	int size = polygon.getInnerBoundary().getSize();
	if(size> 0)
	{
		polygon.Object::output(out)<<"\t<innerBoundaryIs>"<<endl;
		for(int i=0; i< size; i++)
			out<<polygon.getInnerBoundary()[i];
		polygon.Object::output(out)<<"\t</innerBoundaryIs>"<<endl;
	}
	polygon.Object::output(out)<<"</Polygon>"<<endl;
	return out;
}