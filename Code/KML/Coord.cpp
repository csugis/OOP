#include "StdAfx.h"
#include "Coord.h"

Coord::Coord(void)
:Altitude(0)
{
}

Coord::~Coord(void)
{
}
/*friend function
ostream& operator << ( ostream& out, Coord& c) 
{
	out<<c.Longitude<<","<<c.Latitude<<","<<c.Altitude;
	return out;
}

istream& operator >> ( istream& in, Coord& c) 
{
	in>>c.Longitude>>c.Latitude>>c.Altitude;
	return in;
}*/