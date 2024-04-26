#ifndef _CUSTOMER_CENTER_H
#define _CUSTOMER_CENTER_H
#include "CommonBusiness.h"
#include "utility.h"

#define AddressBuffSize	256

enum Sex { MALE, FEMALE };

class Customer : public Account
{
	friend class DataLayer;
private:
	char name[UsrNameBuffSize];
	Sex sex;
	Date birthday;
	char address[AddressBuffSize];
	UINT64 phone;
public:
	Customer() {}
	Customer(const Account& a) :Account(a) {}
	~Customer();
	bool CustomerSignIn();
	virtual void ShowMenu();
	void PutCustomerRecord(ofstream& ofs)
	{
		ofs << ID << ',';
		ofs << name << ',';
		ofs << sex << ',';
		ofs << birthday.year << '-';
		ofs << birthday.month << '-';
		ofs << birthday.day << ',';
		ofs << address << ',';
		ofs << phone << endl;
	}
	void GetCustomerAddress(char* name, char* address, UINT64& phone);
	static void PrintCustomers(Customer customers[], int nCustomers);
private:
	void ShowBuyMenu();
	bool SelectBuyMenu();

	void ShowMyOrderMenu();
	bool SelectMyOrderMenu();

	void ShowMyAccountMenu();
	bool SelectMyAccounMenu();

	bool SelectCustomerMenu();

	void SearchProduct();

	void SearchMerchant();

	void BrowseMerchantProducts();

	void BuyProduct();

	void BrowseHistoryOrders();

	void RateProduct();

	void RefundApplication();

	virtual void MyAccountInfo();

	virtual void ModifyMyAccount();
};



#endif // _CUSTOMER_CENTER_H
