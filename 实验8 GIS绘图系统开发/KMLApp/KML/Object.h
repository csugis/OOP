#pragma once
#include <string>
using namespace std;

/*
<Object>
语法
<!-- abstract element; do not create -->
<!-- Object id="ID" targetId="NCName" -->
<!-- /Object> -->
说明
这是抽象基础类，不能直接用在 KML 文件中。它提供使 KML 元素具有
唯一标识的 id 属性，并提供 targetId 属性，用于引用已载入 
Google 地球中的对象。如果使用 <Update> 机制，则必须指定该 id 属性。
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

