#include "Order.h"
#include "utility.h"
#include "ui.h"
#include <iostream>

using namespace std;

void Order::PrintOrders(Order orders[], int nOrders)
{
	FieldPrintSetting PrintSet[] = {
									 "������", 6,
									 "�̼Һ�", 6,
									 "��Ʒ��", 16,
									 "����", 4,
									 "ʱ��", 18,
									 "�۸�", 8,
									 "����", 8,
									 "��ַ", 16,
									 "�绰", 12,
									 "״̬", 8
	};
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);


	const char* StatusLabel[] = { "�ɹ�", "Ҫ���˿�", "���˿�", "�˿�ܾ�" };
	char buffer[32];
	string strs[nFields];

	for (int i = 0; i < nOrders; i++) {
		const Order& CurrentOrder = orders[i];
		const Time& time = CurrentOrder.OrderTime;
		const Date& date = time.date;

		cout << '|';
		cout << setw(PrintSet[0].PrintWidth) << std::right
			<< CurrentOrder.OrderID << '|';
		cout << setw(PrintSet[1].PrintWidth) << std::right
			<< CurrentOrder.MerchantID << '|';
		cout << setw(PrintSet[2].PrintWidth) << std::left
			<< Utility::TrimString(CurrentOrder.ProductName, buffer,
				PrintSet[2].PrintWidth, strs[2])
			<< '|';
		cout << setw(PrintSet[3].PrintWidth) << std::right
			<< CurrentOrder.number << '|';
		cout << setw(PrintSet[4].PrintWidth) << std::right
			<< Utility::TimeToString(CurrentOrder.OrderTime, buffer) << '|';
		cout << setw(PrintSet[5].PrintWidth) << std::right
			<< setiosflags(ios::fixed) << setprecision(2)
			<< CurrentOrder.price << '|';
		cout << setw(PrintSet[6].PrintWidth) << std::left
			<< Utility::TrimString(CurrentOrder.CustomerName, buffer,
				PrintSet[6].PrintWidth, strs[6])
			<< '|';
		cout << setw(PrintSet[7].PrintWidth) << std::left
			<< Utility::TrimString(CurrentOrder.address, buffer,
				PrintSet[7].PrintWidth, strs[7])
			<< '|';
		cout << setw(PrintSet[8].PrintWidth) << std::right
			<< CurrentOrder.phone << '|';
		cout << setw(PrintSet[9].PrintWidth) << std::right
			<< StatusLabel[CurrentOrder.status] << '|';

		cout << endl;

		Utility::PrintRemaining(PrintSet, nFields, strs);
		Utility::PrintLine(PrintSet, nFields);
	}

	cout << endl;
}


bool Order::IsCurrentOrderThisYear() const
{
	Time time;
	Utility::GetCurrentTime(time);

	return OrderTime.date.year == time.date.year;
}

bool Order::IsCurrentOrderThisMonth() const
{
	Time time;
	Utility::GetCurrentTime(time);

	return OrderTime.date.year == time.date.year &&
		OrderTime.date.month == time.date.month;
}



void Order::RefundApplication()
{

	Order::PrintOrders(this, 1);

	bool RefundValid = status != REFUND_REQUIRED &&
		status != REFUNDED;
	if (!RefundValid) {
		cout << "�˶����������˿�Ҫ��" << endl;
		return;
	}

	cout << "�Ƿ������˿��Y��ȷ�ϣ��������ȡ��.";
	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	status = REFUND_REQUIRED;

	cout << "�˿�����ɹ���" << endl;
	Order::PrintOrders(this, 1);
}