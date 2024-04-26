#pragma once
#include <string>
using namespace std;

//随机获得数字<0,9>
char GetDigit();
//随机获得小写字母<a,z>
char GetLower();
//随机获得大写字母<A,Z>
char GetUpper();
//产生随机字符串
void ProRandomStringData(string* a, int n);