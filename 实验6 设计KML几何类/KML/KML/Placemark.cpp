#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Placemark.h"

Placemark::Placemark(void)
:pGeometry(0)
{
}

Placemark::~Placemark(void)
{
}

Placemark& Placemark::operator = (Placemark& mark)
{
	pGeometry = mark.pGeometry;
	setName(mark.getName());
	setDescrription(mark.getDescription());
	if(pGeometry)
		pGeometry->setParentNode(this);
	return *this;
}
Placemark::Placemark(Placemark& mark)
{
	pGeometry = mark.pGeometry;
	if(pGeometry)
		pGeometry->setParentNode(this);
}

ostream& Placemark::output( ostream& out)
{
	return out<<*this;
}

ostream& operator << ( ostream& out, Placemark& mark)
{
//	mark.Object::output(out)<<"<Placemark id="<<mark.getID()<<">"<<endl;
	mark.Object::output(out)<<"<Placemark>"<<endl;
	mark.Object::output(out)<<"\t<name>"<<mark.getName()<<"</name>"<<endl;
	mark.Object::output(out)<<"\t<description>"<<endl;
	mark.Object::output(out)<<"\t\t"<<mark.getDescription()<<endl;
	mark.Object::output(out)<<"\t</description>"<<endl;
	if(mark.getGeometry())
		mark.getGeometry()->output(out);
	mark.Object::output(out)<<"</Placemark>"<<endl;
	return out;
}