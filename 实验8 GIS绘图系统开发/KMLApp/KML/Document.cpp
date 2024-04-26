#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Document.h"

Document::Document(void)
{
}

Document::~Document(void)
{
}
Document::Document(const Document& doc)
{
	setPlacemarks(doc.marks);
}
const Document& Document::operator = (const Document& doc)
{
	setPlacemarks(doc.marks);
	return(*this);
}
void Document::setPlacemarks(const tArray<Placemark>& pms)
{
	marks = pms;
	for (int i = 0; i < marks.getSize(); i++)
	{
		marks[i].setParentNode(this);
	}
}
Placemark& Document::nextPlacemark()
{
	int i = marks.getSize();
	marks[i].setParentNode(this);
	return marks[i];
}

ostream& operator << ( ostream& out, Document& doc)
{
//	doc.Object::output(out)<<"<Document id="<<doc.getID()<<">"<<endl;
	doc.Object::output(out)<<"<Document>"<<endl;
	doc.Object::output(out)<<"\t<name>"<<doc.getName()<<"</name>"<<endl;
	for(int i=0;i<doc.getPlacemarks().getSize(); i++)
		out<<doc.getPlacemarks()[i];
	doc.Object::output(out)<<"</Document>"<<endl;
	return out;
}