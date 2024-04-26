#ifndef _MERCHANT_CENTER_H
#define _MERCHANT_CENTER_H
#include "utility.h"
#include "CommonBusiness.h"

class Order;
class Product;
class Merchant : public Account
{
	friend class DataLayer;
private:
	//int ID;
	char name[UsrNameBuffSize];
	UINT64 phone;
	double TotalSales;
	int nRatings;
	float rating;
public:
	Merchant() {}
	Merchant(const Account&a):Account(a) {}
	~Merchant();
	virtual void ShowMenu();
	void PutMerchantRecord(ofstream& ofs)
	{
		ofs << ID << ',';
		ofs << name << ',';
		ofs << phone << ',';
		ofs << setiosflags(ios::fixed) << setprecision(2) << TotalSales << ',';
		ofs << nRatings << ',';
		ofs << rating << endl;
	}
	void UpdateMerchantSales(double SaleChange) { TotalSales += SaleChange; }
	void UpdateRating(int rating);
	static void PrintMerchants(Merchant merchants[], int nMerchants);
	bool MerchantSignIn();
	void RemoveAllProducts();
private:
	bool IsCurrentMerchant(const Order& order);
	bool IsCurrentMerchantThisYear(const Order& order);
	bool IsCurrentMerchantThisMonth(const Order& order);

	bool SelectMerchantMenu();

	void ShowProductManageMenu();
	bool SelectProductManageMenu();

	void ShowOrderManageMerchantMenu();
	bool SelectOrderManagewMerchantMenu();

	void ShowAccountInfoMerchantMenu();
	bool SelectAccountInfoMerchantMenu();

	void BrowseAllProducts();

	void AddNewProduct();

	void RemoveProduct();

	void ModifiyProduct();

	void BrowseAllOrders();

	void BrowseOrdersThisYear();

	void BrowseOrdersThisMonth();

	void refund();

	virtual void MyAccountInfo();

	virtual void ModifyAccountInfo();
};


#endif // _MERCHANT_CENTER_H
