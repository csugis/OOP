// KML.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "document.h"
#include "tArray.h"
#include "point.h"
#include "multigeometry.h"
//#include "Csv2Kml.h"


int main()
{
    cout << "Hello KML World!\n";
    //Csv2Kml obj;
    //obj.output(obj.getOutfile());
    ofstream outfile;
    outfile.open(_T("data//Travel.kml"));
    //
    Document doc;
    string docName = "MyTravel";
    doc.setName(docName);
    tArray<Placemark>   pa;
    //点，封装成函数
    Point pt;
    pt.setLongitude(123.85);
    pt.setLatitude(42.28);
    pa[0].setGeometry(&pt);
    string des = "<![CDATA[ \n";
    des += "<table border=\"1\" padding=\"3\" width=\"300\">\n";
    //第一行
    des += "<tr>";
    des += "<td> Name </td>";
    des += "<td> Travel </td>";
    des += "</tr>";
    //第二行
    des += "<tr>";
    des += "<td> Year </td>";
    des += "<td> From 2022 </td>";
    des += "</tr>";

    des += "</table>\n";
    des += "]]>\n";
    string name = "Point Placemark";
    pa[0].setDescrription(des);
    pa[0].setName(name);
    //线，封装成函数
    LineString ls;
    
    
    //多边形，封装成函数
    Poly poly;

    //几何组合，封装成函数
    MultiGeometry mg;

    doc.setPlacemarks(pa);

    outfile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    outfile << "<kml xmlns=\"http:/" << "/www.opengis.net/kml/2.2\"" << endl;
    outfile << "xmlns:gx=\"http:/" << "/www.google.com/kml/ext/2.2\">" << endl;
    //<!-- required when using gx-prefixed elements -->
    outfile << doc;
    outfile << "</kml>" << endl;
    outfile.close();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
