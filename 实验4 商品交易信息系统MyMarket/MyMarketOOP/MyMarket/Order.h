#pragma once
#include "CustomerCenter.h"
#include "MerchantCenter.h"
#include "Product.h"

enum OrderStatus {
	SUCCESS,
	REFUND_REQUIRED,
	REFUNDED,
	REFUND_REJECTED
};

class Order
{
	friend class DataLayer;
private:
	int OrderID;
	int CustomerID;
	int MerchantID;
	int ProductID;
	char ProductName[ProdNameBuffSize];
	int number;
	Time OrderTime;
	double price;
	char CustomerName[UsrNameBuffSize];
	char address[AddressBuffSize];
	UINT64 phone;
	OrderStatus status;
public:
	void RefundApplication();
	bool IsCurrentOrderThisYear() const;
	bool IsCurrentOrderThisMonth() const;
	int getMerchantID() const { return MerchantID; }
	int getCustomerID() const { return CustomerID; }
	int getProductID() const { return ProductID; }
	OrderStatus getStatus() const { return status; }
	void setStatus(OrderStatus os) { status = os; }
	double getPrice()const { return price; }
	int getNumber() const { return number; }
	void PutOrderRecord(ofstream& ofs)
	{
		ofs << OrderID << ',';
		ofs << CustomerID << ',';
		ofs << MerchantID << ',';
		ofs << ProductID << ',';
		ofs << ProductName << ',';
		ofs << number << ',';
		ofs << OrderTime.date.year << '-';
		ofs << OrderTime.date.month << '-';
		ofs << OrderTime.date.day << ' ';
		ofs << OrderTime.hour << ':';
		ofs << OrderTime.minute << ':';
		ofs << OrderTime.second << ',';
		ofs << price << ',';
		ofs << CustomerName << ',';
		ofs << address << ',';
		ofs << setprecision(12) << phone << ',';
		ofs << status << endl;
	}
	static void PrintOrders(Order orders[], int nOrders);
};

