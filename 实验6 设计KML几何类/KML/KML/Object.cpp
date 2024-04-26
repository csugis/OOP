#include "Object.h"
#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
���ݶ��壬UUID��Universally Unique IDentifier��Ҳ��GUID����ʱ���
�ռ䶼��Ψһ�ġ�Ϊ��֤�ռ��Ψһ�ԣ�ÿ��UUIDʹ����һ��48λ��ֵ��
��¼��һ���Ǽ������������ַ��Ϊ��֤ʱ���ϵ�Ψһ�ԣ�ÿ��UUID����
һ��60λ��ʱ�����timestamp�������ʱ�����ʾ�Թ�Ԫ1582��10��15��
00��00��00��00������ʱ�䣬����100����Ϊ��λ��ʱ������
1���루ns��=10-9�루s����UUID�㷨���Ա�֤����Լ��Ԫ3400����ȻΨһ��
UUID��C���Խṹ�������£�
 
typedef struct _GUID
{
     unsigned long      data1;       
     unsigned short     data2;
     unsigned short     data3;
     unsigned char      data4[8];
} GUID,
UUID;
 
���Ľṹ��СΪ16���ֽڡ���sizeof(uuid_t)==16ΪTRUE��д��16����
�ַ����ĸ�ʽ��һ��Ϊ��
"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"
 
������ַ�����ʽ��ռ��36���ַ�����������β���ַ���\0�������ԣ�
Ҫ������һ��UUID�ַ�������������Ϊһ��char[36+1]���ַ����顣
*/
Object::Object(void)
:ID(""),Type(""),pParentNode(0),OwnerDocument(0)
{
	static char buf[64] = {0};
	GUID   guid;
	::CoCreateGuid(&guid);
	_snprintf_s(buf, sizeof(buf)
	   , "{%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X}"
	   , guid.Data1
	   , guid.Data2
	   , guid.Data3
	   , guid.Data4[0], guid.Data4[1]
	   , guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5]
	   , guid.Data4[6], guid.Data4[7]
	   );
	ID = buf;
}

Object::~Object(void)
{
}

ostream& Object::output( ostream& out)
{
	Object * pParent = pParentNode;
	while(pParent)
	{
		out<<"\t";
		pParent = pParent->pParentNode;
	}
	return out;
}
