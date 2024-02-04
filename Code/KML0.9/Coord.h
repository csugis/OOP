#pragma once


/**/
class Coord
{
	double Longitude;
	double Latitude;
	double Altitude;
//	friend ostream& operator << ( ostream& , Coord& ); 
//	friend istream& operator >> ( istream& , Coord& ); 
public:
	double getLongitude(void) {return Longitude;}
	double getLatitude(void) {return Latitude;}
	double getAltitude(void) {return Altitude;}
	void setLongitude(double lon) {Longitude = lon;}
	void setLatitude(double lat) {Latitude = lat;}
	void setAltitude(double alt) {Altitude = alt;}
	void operator ()(double lon, double lat, double alt=0)
	{
		Longitude = lon; Latitude = lat; Altitude = alt;
	}
	Coord(void);
	virtual ~Coord(void);
};

//ostream& operator << ( ostream& , Coord& ); 
//istream& operator >> ( istream& , Coord& ); 
