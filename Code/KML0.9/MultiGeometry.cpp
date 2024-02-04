#include "StdAfx.h"
#include "MultiGeometry.h"

MultiGeometry::MultiGeometry(void)
{
	setType("MultiGeometry");
}

MultiGeometry::~MultiGeometry(void)
{
}

ostream& MultiGeometry::output( ostream& out)
{
	return out<<*this;
}

ostream& operator << ( ostream& out, MultiGeometry& geos)
{
//	geos.Object::output(out)<<"<MultiGeometry id="<<geos.getID()<<">"<<endl;
	geos.Object::output(out)<<"<MultiGeometry>"<<endl;
	for(int i=0; i<geos.getPoints().getSize();i++)
		out<<geos.getPoints()[i];
	for(int i=0; i<geos.getLineStrings().getSize();i++)
		out<<geos.getLineStrings()[i];
	for(int i=0; i<geos.getPolygons().getSize();i++)
		out<<geos.getPolygons()[i];
	geos.Object::output(out)<<"</MultiGeometry>"<<endl;
	return out;
}