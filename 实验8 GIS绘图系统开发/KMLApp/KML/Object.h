#pragma once
#include <string>
using namespace std;

/*
<Object>
�﷨
<!-- abstract element; do not create -->
<!-- Object id="ID" targetId="NCName" -->
<!-- /Object> -->
˵��
���ǳ�������࣬����ֱ������ KML �ļ��С����ṩʹ KML Ԫ�ؾ���
Ψһ��ʶ�� id ���ԣ����ṩ targetId ���ԣ��������������� 
Google �����еĶ������ʹ�� <Update> ���ƣ������ָ���� id ���ԡ�
*/
class Document;
class Object
{
	string Type;
	string ID;
	Object* pParentNode;
	Document * OwnerDocument;
protected:
	void setType(const char * type) {Type = type;}
public:
	virtual ostream& output( ostream& out);
	virtual bool IsAbstract(void) = 0;
	Document * getOwnerDocument(void) {return OwnerDocument;}
	void setOwnerDocument(Document * owner) {OwnerDocument = owner;}
	Object* getParentNode(void) {return pParentNode;}
	void setParentNode(Object* parent) {pParentNode = parent;}
	string getID(void) {return ID;}
	void setID(string& id) {ID=id;}
	string getType(void) const {return Type;}
	Object(void);
	virtual ~Object(void);	
};

