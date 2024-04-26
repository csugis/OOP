#include "Order.h"
#include "utility.h"
#include "ui.h"
#include <iostream>

using namespace std;

void Order::PrintOrders(Order orders[], int nOrders)
{
	FieldPrintSetting PrintSet[] = {
									 "订单号", 6,
									 "商家号", 6,
									 "商品名", 16,
									 "数量", 4,
									 "时间", 18,
									 "价格", 8,
									 "姓名", 8,
									 "地址", 16,
									 "电话", 12,
									 "状态", 8
	};
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);


	const char* StatusLabel[] = { "成功", "要求退款", "已退款", "退款拒绝" };
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
		cout << "此订单不符合退款要求！" << endl;
		return;
	}

	cout << "是否请求退款，按Y键确认，按任意键取消.";
	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	status = REFUND_REQUIRED;

	cout << "退款申请成功。" << endl;
	Order::PrintOrders(this, 1);
}