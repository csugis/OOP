#include "Object.h"
#include <stdio.h>
#include <tchar.h>
#include <ole2.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
根据定义，UUID（Universally Unique IDentifier，也称GUID）在时间和
空间都是唯一的。为保证空间的唯一性，每个UUID使用了一个48位的值来
记录，一般是计算机的网卡地址。为保证时间上的唯一性，每个UUID具有
一个60位的时间戳（timestamp）。这个时间戳表示自公元1582年10月15号
00：00：00：00以来的时间，是以100纳秒为单位的时间间隔。
1纳秒（ns）=10-9秒（s）。UUID算法可以保证至大约公元3400年仍然唯一。
UUID的C语言结构定义如下：
 
typedef struct _GUID
{
     unsigned long      data1;       
     unsigned short     data2;
     unsigned short     data3;
     unsigned char      data4[8];
} GUID,
UUID;
 
它的结构大小为16个字节。即sizeof(uuid_t)==16为TRUE。写成16进制
字符串的格式，一般为：
"xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx"
 
上面的字符串形式，占用36个字符，不包括结尾空字符’\0’。所以，
要想容纳一个UUID字符串，必须声明为一个char[36+1]的字符数组。
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
