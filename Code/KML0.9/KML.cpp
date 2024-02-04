// KML.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "placemark.h"
#include "linearring.h"
#include "point.h"
#include "LineString.h"
#include "polygon.h"
#include "MultiGeometry.h"
#include "csv2kml.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//--COM
//	CoInitialize(NULL);
	Csv2Kml obj;
	obj.output(obj.getOutfile());
	//--COM
//	CoUninitialize();
	return 0;
}

