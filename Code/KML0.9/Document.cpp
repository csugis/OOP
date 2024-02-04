#include "StdAfx.h"
#include "Document.h"

Document::Document(void)
{
}

Document::~Document(void)
{
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