#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Placemark.h"

Placemark::Placemark(void)
:pGeometry(nullptr)
{
}

Placemark::~Placemark(void)
{
	if (pGeometry != nullptr)
	{
		delete pGeometry;
	}
}

const Placemark& Placemark::operator = (const Placemark& mark)
{
	if (pGeometry == mark.pGeometry)
		return *this;
	if (pGeometry != nullptr)
		delete pGeometry;
	pGeometry = mark.pGeometry->Clone();//Éî¿½±´

	setName(mark.getName());
	setDescription(mark.getDescription());
	if(pGeometry)
		pGeometry->setParentNode(this);
	return *this;
}
Placemark::Placemark(const Placemark& mark)
{
	if (pGeometry == mark.pGeometry)
		return;
	pGeometry = mark.pGeometry->Clone();//Éî¿½±´

	setName(mark.getName());
	setDescription(mark.getDescription());
	if(pGeometry)
		pGeometry->setParentNode(this);
}
void Placemark::setGeometry(const Geometry* pGeo)
{
	if (pGeometry == pGeo)
		return;
	if (pGeometry != nullptr)
		delete pGeometry;
	pGeometry = pGeo->Clone();
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