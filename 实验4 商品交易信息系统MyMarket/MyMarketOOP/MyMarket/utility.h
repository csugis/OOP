#ifndef _UTILITY_H
#define _UTILITY_H
#include <string>
using namespace std;
#define UsrNameBuffSize 32
#define PwdBuffSize 16

typedef unsigned long long UINT64;

struct FieldPrintSetting
{
	char PrintFieldName[16]; // 需要打印的字段名
	int PrintWidth; // 打印的字段宽度
};

struct Date
{
	int month;
	int day;
	int year;
};

struct Time
{
	Date date;
	int hour;
	int minute;
	int second;
};

class Order;
class Utility
{
public:
	static int ParseString(const char *str, char *word[], const char delim = ',');

	static void StringToDate(const char *str, Date &date);

	static void StringToTime(const char *str, Time &time);

	static UINT64 StringToPhone(const char *str);

	static void ReverseOrders(Order orders[], int nOrders);

	static void GetCurrentTime(Time &time);

	static bool CheckDate(const Date &date);

	static char* TimeToString(const Time &time, char *buffer, int BufferSize = 20);

	static char* DateToString(const Date &date, char *buffer, int BufferSize = 11);

	static void GeneratePassword(char *pwd, int len);

	// 根据字段格式，打印表格的行分割线
	static void PrintLine(FieldPrintSetting PrintSet[], int nFields);
	static void PrintLine(int fieldsWidth, int nFields);
	// 根据字段列宽设置，打印截断后剩余的字符串
	static void PrintRemaining(FieldPrintSetting PrintSet[], int nFields, string strs[]);
	static void PrintTableHead(FieldPrintSetting PrintSet[], int nFields);
	///////////////////////////////////////////////////////////////////////////////
	// 实现字符串的截断
	// src -源字符串
	// dst -截断的目标字符串
	// width -截断宽度，超出该宽度则字符串截断
	// remaining -截断后剩余的字符串
	///////////////////////////////////////////////////////////////////////////////
	static char* TrimString(const char* src, char* dst, int width, string& remaining);
};

#define GetNextCosumerID() GetNextID(CustomerIdPath)
#define GetNextMerchantID() GetNextID(MerchantIdPath)
#define GetNextProductID() GetNextID(ProductIdPath)
#define GetNextOrderID() GetNextID(OrderIdPath)
#define GetNextAccountID() GetNextID(AccountIdPath)

// 获得下一个编号，并将编号自增1
int GetNextID(const char* path);

#endif // _UTILITY_H

