#ifndef _DATA_LAYER_H
#define _DATA_LAYER_H

#include <vector>
#include "ui.h"
#include "AdminCenter.h"
#include "CustomerCenter.h"
#include "MerchantCenter.h"
#include "Product.h"
#include "Order.h"

#define CustomerDataPath "data\\customer.csv"
#define MerchantDataPath "data\\merchant.csv"
#define ProductDataPath "data\\product.csv"
#define OrderDataPath "data\\order.csv"
#define AccountDataPath "data\\account.csv"
#define CustomerIdPath "data\\customer.id"
#define MerchantIdPath "data\\merchant.id"
#define ProductIdPath "data\\product.id"
#define OrderIdPath "data\\order.id"
#define AccountIdPath "data\\account.id"

class Customer;
class Merchant;
class Product;
class Order;
class Account;
typedef std::vector<Customer> CustomerArray;
typedef std::vector<Merchant> MerchantArray;
typedef std::vector<Product> ProductArray;
typedef std::vector<Order> OrderArray;
typedef std::vector<Account> AccountArray;

class DataLayer
{
private:
	CustomerArray CustomerList;
	MerchantArray MerchantList;
	ProductArray ProductList;
	OrderArray OrderList;
	AccountArray AccountList;
	Account* pAccount;
public:
	DataLayer(): pAccount(nullptr)
	{
		LoadAccountList();		
		LoadCustomerList();
		LoadMerchantList();
		LoadProductList();
		LoadOrderList();
	}
	~DataLayer()
	{
		if (pAccount != nullptr)
		{
			//更新当前账户信息到数据列表
			Account* pa = nullptr;
			Merchant* pm = nullptr;
			Customer* pc = nullptr;
			switch (pAccount->type)
			{
			case ADMIN:
				pa = GetAccount(pAccount->getID());
				if(pa != nullptr)
					*(pa) = *(pAccount);
				break;
			case MERCHANT:
				pa = GetAccount(pAccount->getID());
				if (pa != nullptr)
					*(pa) = *(pAccount);
				pm = GetMerchant(pAccount->getID());
				if(pm != nullptr)
					*(pm) = *((Merchant*)pAccount);
				break;
			case CUSTOMER:
				pa = GetAccount(pAccount->getID());
				if (pa != nullptr)
					*(pa) = *(pAccount);
				pc = GetCustomer(pAccount->getID());
				if(pc != nullptr)
					*(pc) = *((Customer*)pAccount);
				break;
			default:
				cout << "用户角色错误!";
				UI::pause();
			}
			delete pAccount;
		}
		SaveOrderList(OrderList);
		SaveProductList(ProductList);		
		SaveCustomerList(CustomerList);
		SaveMerchantList(MerchantList);
		SaveAccountList(AccountList);
	}
	/** 登录提示 */
	bool loginPrompt();
	//
	CustomerArray* getCustomerList()  { return &CustomerList; }
	MerchantArray* getMerchantList()  { return &MerchantList; }
	ProductArray* getProductList()  { return &ProductList; }
	OrderArray* getOrderList()  { return &OrderList; }
	AccountArray* getAccountList()  { return &AccountList; }

	//bool AddOrder(const Order& order);
	int AddOrder(int CustomerID, int MerchantID, int ProductID,
		const char* ProductName, int number, double price,
		const char* CustomerName, const char* address, UINT64 phone);
	int CheckLoginName(const char* LoginName);
	bool GetAccountType(int AccountID, UserType& type);
	int CheckLoginInfo(const char* LoginName, const char* password);

	//不要在DataLayer外部保存下列指针，因为它们指向了vector中的元素，地址会变动
	Account* GetAccount(int ID) ;	
	Product* GetProduct(int ID) ;
	Order* GetOrder(int ID) ;	
	Customer* GetCustomer(int ID) ;
	Merchant* GetMerchant(int ID) ;	
private:

	bool LoadCustomerList();
	bool SaveCustomerList(const CustomerArray &CustomerList);

	bool LoadMerchantList();
	bool SaveMerchantList(const MerchantArray &MerchantList);

	bool LoadProductList();
	bool SaveProductList(ProductArray &ProductList);

	bool LoadOrderList();
	bool SaveOrderList(const OrderArray &OrderList);

	bool LoadAccountList();
	bool SaveAccountList(const AccountArray &AccountList);
};

#endif // _DATA_LAYER_H
