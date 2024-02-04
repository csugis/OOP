#pragma once

class Field
{
	int no;
	string name;
public:
	string& getName(void) {return name;}
	void setName(string& na){name = na;}
	int getNo(void) const {return no;}
	void setNo(int n) {no = n;}
	void operator ()(int n, string& na)	{no = n; name = na;}
	Field(void);
	virtual ~Field(void);
};
