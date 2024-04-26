#ifndef _UTILITY_H
#define _UTILITY_H
#include <string>
using namespace std;
#define UsrNameBuffSize 32
#define PwdBuffSize 16

typedef unsigned long long UINT64;

struct FieldPrintSetting
{
	char PrintFieldName[16]; // ��Ҫ��ӡ���ֶ���
	int PrintWidth; // ��ӡ���ֶο��
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

	// �����ֶθ�ʽ����ӡ�����зָ���
	static void PrintLine(FieldPrintSetting PrintSet[], int nFields);
	static void PrintLine(int fieldsWidth, int nFields);
	// �����ֶ��п����ã���ӡ�ضϺ�ʣ����ַ���
	static void PrintRemaining(FieldPrintSetting PrintSet[], int nFields, string strs[]);
	static void PrintTableHead(FieldPrintSetting PrintSet[], int nFields);
	///////////////////////////////////////////////////////////////////////////////
	// ʵ���ַ����Ľض�
	// src -Դ�ַ���
	// dst -�ضϵ�Ŀ���ַ���
	// width -�ضϿ�ȣ������ÿ�����ַ����ض�
	// remaining -�ضϺ�ʣ����ַ���
	///////////////////////////////////////////////////////////////////////////////
	static char* TrimString(const char* src, char* dst, int width, string& remaining);
};

#define GetNextCosumerID() GetNextID(CustomerIdPath)
#define GetNextMerchantID() GetNextID(MerchantIdPath)
#define GetNextProductID() GetNextID(ProductIdPath)
#define GetNextOrderID() GetNextID(OrderIdPath)
#define GetNextAccountID() GetNextID(AccountIdPath)

// �����һ����ţ������������1
int GetNextID(const char* path);

#endif // _UTILITY_H

