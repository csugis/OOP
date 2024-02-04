// GISGeometry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Curve.h"
#include "Round.h"
#include "Arc.h"
#include "Manager.h"
#include "Layer.h"
#include <cmath>
#include <iostream>
using namespace std;

void binmain()
{
	ColorStruct clrs[5];
	long i=0;
	for(i=0; i<5; i++)
		clrs[i].r=clrs[i].g=clrs[i].b = i;
	ofstream outfile("clr.dat",ios::binary|ios::out);
	if(!outfile){
		cerr<<"open binary out file error!"<<endl;
		abort();
	}
	writeclr(outfile,clrs,5);
	ColorStruct clr={255,255,255};
	writeclr(outfile,clr,2);
	outfile.close();

	fstream iofile("clr.dat", ios::in|ios::out|ios::binary);
	if(!iofile){
		cerr<<"open binary i//o file error!"<<endl;
		abort();
	}
	ColorStruct clrs2[3];
	for(i=0;i<3;i++)
		clrs2[i].r=clrs2[i].g=clrs2[i].b = (i+1)*10;
	insertclr(iofile,3,clrs2,3);
	iofile.close();

	ifstream infile("clr.dat",ios::binary|ios::in);
	if(!infile){
		cerr<<"open binary in file error!" << endl;
		abort();
	}
	readclr(infile,clr,2);
	cout<<"no 2 clr: ";
	cout<<" r = "<<clr.r;
	cout<<" g = "<<clr.g;
	cout<<" b = "<<clr.b<<endl;
	long num=0;
	readclr(infile,num);
	ColorStruct *ptr=new ColorStruct[num];
	readclr(infile,ptr);
	cout<<"all "<<num<<" clrs:"<<endl;
	for(i=0;i<num;i++)
	{
		cout<<" r = "<<ptr[i].r;
		cout<<" g = "<<ptr[i].g;
		cout<<" b = "<<ptr[i].b<<endl;
	}
	infile.close();
}
int main(int argc, char* argv[])
{
	CManager ma;
	CLayer *lay1,*lay2,*lay3;
	CGeometry *p1,*p2,*p3;
	PointStruct pt;
	ColorStruct clr;
	lay1 = new CLayer;
	lay1->SetGeometryType(geoTypeCircle);
	lay1->SetID(10);
	lay2 = new CLayer;
	lay2->SetGeometryType(geoTypeRound);
	lay2->SetID(11);
	lay3 = new CLayer;
	lay3->SetGeometryType(geoTypeArc);
	lay3->SetID(12);
	for(int i=0;i<100;i++)
	{
		clr.r = i;
		clr.g = i+1;
		clr.b = (i+1)*2;
		ma.InsertColors(clr);

		p1 = new CRound;
		p1->SetID(i+1);
		p1->SetPenColor(i*i+1);
		p1->SetBrushColor((i+1)*(i+1));
		pt.x = sin(i); pt.y = cos(i);
		((CRound*)p1)->SetCenter(pt);
		((CRound*)p1)->SetRadius(pow(i,1));
		lay1->InsertGeometry(p1);

		p2 = new CRound;
		p2->SetID(i+1);
		p2->SetPenColor(i*i+1);
		p2->SetBrushColor((i+1)*(i+1));
		pt.x = sin(i); pt.y = cos(i);
		((CRound*)p2)->SetCenter(pt);
		((CRound*)p2)->Fill();
		((CRound*)p2)->SetRadius(pow(i,2));
		lay2->InsertGeometry(p2);

		p3 = new CArc;
		p3->SetID(i+1);
		p3->SetPenColor(i*i+1);
		p3->SetBrushColor((i+1)*(i+1));
		pt.x = sin(i); pt.y = cos(i);
		((CRound*)p3)->SetCenter(pt);
		((CRound*)p3)->SetRadius(pow(i,3));
		((CArc*)p3)->SetRange(atan(i),atan(i+1));
		lay3->InsertGeometry(p3);
	}
	ma.InsertLayers(lay1);
	ma.InsertLayers(lay2);
	ma.InsertLayers(lay3);
	ma.OpenMap("polygon.txt");
	ma.OpenMap("polyline.txt");

	ma.SaveClrTable();
	ma.SaveMapByID(10,"circle.txt");
	ma.SaveMapByID(11,"round.txt");
	ma.SaveMapByID(12,"arc.txt");
	return 0;
}
