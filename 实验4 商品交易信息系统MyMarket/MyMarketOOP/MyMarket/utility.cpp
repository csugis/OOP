#include <cstring>
#include <cstdlib>
#include <ctime>
#include <strstream>
#include <iomanip>
#include <iostream>
#include "utility.h"
#include "Order.h"
using namespace std;

// �����һ����ţ������������1
int GetNextID(const char* path)
{
	// ��ȡ�ļ��������һ�����
	int id;
	ifstream ifs(path);
	if (!ifs) {
		cerr << "id file " << path << " open error." << endl;
		return -1;
	}
	ifs >> id;
	ifs.close();

	// �������1�����µ�����ļ�֮�У����´κ�������ʱʹ��
	id++;
	ofstream ofs(path);
	if (!ofs) {
		cerr << "id file " << path << " open error." << endl;
		return -1;
	}
	ofs << id;
	ofs.close();

	return id;
}

void MakeRegular(char str[])
{
	char *pch = str;
	while (*pch != '\0') {
		if (*pch == '\"' && *(pch + 1) == '\"') {
			char *pch2 = pch + 1;

			while (*pch2 != '\0') {
				*pch = *pch2;
				pch++;
				pch2++;
			}
			*pch = '\0';
			pch = str;
		}
		else
			pch++;
	}
}

///////////////////////////////////////////////////////////////////////////////
// ʵ���ַ����Ľض�
// src -Դ�ַ���
// dst -�ضϵ�Ŀ���ַ���
// width -�ضϿ�ȣ������ÿ�����ַ����ض�
// remaining -�ضϺ�ʣ����ַ���
///////////////////////////////////////////////////////////////////////////////
char* Utility::TrimString(const char* src, char* dst, int width, string& remaining)
{
	// �ҵ��ض�λ��
	int i = 0;
	while (i < width && src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	// �����ַ���������ʵ���ַ����Ľض�
	dst[i] = '\0';

	// ��ʣ���ַ�����ֵ
	remaining = src + i;

	return dst;
}

void Utility::PrintLine(int fieldsWidth, int nFields)
{
	if (fieldsWidth < 0 || nFields < 0)
		return;

	cout << '|';
	int k = 0;
	while (true) {
		for (int i = 0; i < fieldsWidth; i++)
			cout << '-';

		if (++k == nFields)
			break;

		cout << '+';
	}
	cout << '|';

	cout << endl;
}

// �����ֶθ�ʽ����ӡ�����зָ���
void Utility::PrintLine(FieldPrintSetting PrintSet[], int nFields)
{
	cout << '|';
	int k = 0;
	while (true) {
		for (int i = 0; i < PrintSet[k].PrintWidth; i++)
			cout << '-';

		if (++k == nFields)
			break;

		cout << '+';
	}
	cout << '|';

	cout << endl;
}

// �����ֶ��п����ã���ӡ�ضϺ�ʣ����ַ���
void Utility::PrintRemaining(FieldPrintSetting PrintSet[], int nFields, string strs[])
{
	char buffer[32];
	string remaining;

	while (true) {
		// �ж��Ƿ�����ʣ���ַ�����Ϊ���ַ���
		bool IsEmpty = true;
		for (int i = 0; i < nFields; i++) {
			IsEmpty = strs[i].length() == 0 && IsEmpty;
		}

		if (IsEmpty)
			break;


		// �������ʣ���ַ������������ӡ����ʣ���ַ�����������ָ���п���нضϣ�
		// ����Ϊ��Ϣ��ʣ���ַ���
		cout << '|';
		for (int i = 0; i < nFields; i++) {
			const char* CurrentString = strs[i].c_str();
			int CurrentWidth = PrintSet[i].PrintWidth;

			cout << setw(CurrentWidth) << std::left;
			cout << TrimString(CurrentString, buffer, CurrentWidth, remaining)
				<< "|";

			strs[i] = remaining;
		}
		cout << endl;
	}
}

void Utility::PrintTableHead(FieldPrintSetting PrintSet[], int nFields)
{
	// ��ʾ��ͷ
	PrintLine(PrintSet, nFields);
	cout << '|';
	for (int i = 0; i < nFields; i++) {
		const FieldPrintSetting& CurrentPrintSet = PrintSet[i];

		cout << setw(CurrentPrintSet.PrintWidth) << std::right;
		cout << CurrentPrintSet.PrintFieldName << "|";
	}
	cout << endl;

	PrintLine(PrintSet, nFields);
}

// ���ַ������ָ����ָ�Ϊ������ַ���
int Utility::ParseString(const char *str, char *word[], const char delim)
{
	int count = 0;
	char *pch = (char *)str;

	while (true) {
		// ��count�����ַ�������ʼλ��
		word[count++] = pch;

		// ͨ�����Ѱ�ҷָ���delim�����ַ�������������õ�count�����ַ����Ľ���λ��
		while (*pch != delim && *pch != '\0')
			pch++;

		// ��������������ַ��������˳�
		if (*pch == '\0')
			break;

		// �����ַ�������
		*pch = '\0';

		// ���Ѱ���������ַ���
		do pch++;
		while (*pch == delim);
	}

	return count;
}

void Utility::StringToDate(const char *str, Date &date)
{
	char *word[3];
	ParseString(str, word, '-');

	date.year = atoi(word[0]);
	date.month = atoi(word[1]);
	date.day = atoi(word[2]);
}

void Utility::StringToTime(const char *str, Time &time)
{
	char *SubStr[2];
	ParseString(str, SubStr, ' ');

	StringToDate(SubStr[0], time.date);

	char *word[3];
	ParseString(SubStr[1], word, ':');
	time.hour = atoi(word[0]);
	time.minute = atoi(word[1]);
	time.second = atoi(word[2]);
}


UINT64 Utility::StringToPhone(const char *str)
{
	UINT64 number = 0;
	char *pch = (char *)str;
	UINT64 digit = 1;

	int len = strlen(str);
	if (len == 0)
		return 0;

	pch = (char *)(str + len - 1);
	while (true) {
		if (*pch < '0' || *pch > '9')
			return -1;

		UINT64 i = *pch - 48;
		number += i * digit;

		if (pch == str)
			break;

		pch--;
		digit *= 10;
	}

	return number;
}

void Utility::ReverseOrders(Order orders[], int nOrders)
{
	int HalfSize = nOrders / 2;

	Order temp;
	for (int i = 0; i < HalfSize; i++) {
		temp = orders[i];
		orders[i] = orders[nOrders-i-1];
		orders[nOrders-i-1] = temp;
	}
}

void Utility::GetCurrentTime(Time &time)
{
	std::time_t t = std::time(0);   // get time now
	std::tm* now = std::localtime(&t);

	time.date.year = now->tm_year + 1900;
	time.date.month = now->tm_mon + 1;
	time.date.day = now->tm_mday;
	time.hour = now->tm_hour;
	time.minute = now->tm_min;
	time.second = now->tm_sec;
}


bool Utility::CheckDate(const Date &date)
{
	const int EndDay[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	int year = date.year;
	int month = date.month;
	int day = date.day;

	bool IsYearValid = year >= 1900 && year <= 2020;
	bool IsmonthValid = month >= 0 && month <= 12;
	bool IsLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int MaxDay = (month == 2 && IsLeapYear) ? 29 : EndDay[month];
	bool IsDayValid = day >= 0 && day <= MaxDay;

	bool IsDateValid = IsYearValid && IsmonthValid && IsDayValid;

	return IsDateValid;
}

char* Utility::TimeToString(const Time &time, char *buffer, int BufferSize)
{
	const Date &date = time.date;

	ostrstream ostrs(buffer, BufferSize);
	ostrs << date.year << '-' << date.month << '-' << date.day << ' ' <<
		setprecision(2) << setw(2) << setfill('0') << time.hour << ':' <<
		setprecision(2) << setw(2) << setfill('0') << time.minute << ':' <<
		setprecision(2) << setw(2) << setfill('0') << time.second << '\0';

	return buffer;
}

char* Utility::DateToString(const Date &date, char *buffer, int BufferSize)
{
	ostrstream ostrs(buffer, BufferSize);
	ostrs << date.year << '-' << date.month << '-' << date.day << '\0';

	return buffer;
}

void Utility::GeneratePassword(char *pwd, int len)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
		pwd[i] = '0' + rand() % 10;
	pwd[len] = '\0';
}