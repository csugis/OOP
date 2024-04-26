#include <fstream>

#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "ui.h"
#include "DataLayer.h"
#include "utility.h"

using namespace std;

#define NumOfCustomerAttrib 6
#define NumOfMerchantAttrib 6
#define NumOfProductAttrib 8
#define NumOfOrderAttrib 12
#define NumOfAccountAttrib 5


/** 登录提示 */
bool DataLayer::loginPrompt()
{
	bool login = false;
	char LoginName[UsrNameBuffSize], password[PwdBuffSize];
	int LoginedAccountID;
	const int MaxTestTimes = 5;
	int nTestTimes = 0;

	while (nTestTimes++ < MaxTestTimes) {
		cout << "请输入用户名:";
		cin.getline(LoginName, UsrNameBuffSize);
		cout << "请输入密码:";
		UI::GetPass(password);

		if ((LoginedAccountID = CheckLoginInfo(LoginName, password)) != -1) {

			UserType type;
			int nAccounts = AccountList.size();
			GetAccountType(LoginedAccountID, type);

			switch (type) {
			case ADMIN:
				
				for (int i = 0; i < nAccounts; i++) {
					if (AccountList[i].ID == LoginedAccountID) {
						pAccount = new Admin(AccountList[i]);
						break;
					}
				}
				break;
			case MERCHANT:
				pAccount = new Merchant(*GetMerchant(LoginedAccountID));
				break;
			case CUSTOMER:
				pAccount = new Customer(*GetCustomer(LoginedAccountID));
				break;
			default:
				cout << "用户角色错误!";
				UI::pause();
				return login;
			}
			login = true;
			pAccount->setDataLayer(this);
			pAccount->ShowMenu();
			UI::pause();	
			return login;
		}
		else {
			cout << "用户名不存在或密码错误！" << endl;
		}
	}

	return login;
}

bool DataLayer::LoadCustomerList()
{
	ifstream  ifs(CustomerDataPath);
	if (!ifs) {
		cerr << "Customer file open error." << endl;
		return false;
	}

	const int MaxWordSize = 8;
	char *word[MaxWordSize];

	const int BufferSize = 1024;
	char LineBuffer[BufferSize];
	CustomerList.clear();
	while (ifs.getline(LineBuffer, BufferSize)) {
		int nWords = Utility::ParseString(LineBuffer, word);
		
		if (nWords != NumOfCustomerAttrib) {
			cerr << "Customer data error." << endl;
			ifs.close();
			return false;
		}

		int id = atoi(word[0]);
		Account* pa = GetAccount(id);
		if (pa == nullptr)
		{
			cerr << "Customer ID error." << endl;
			cerr << LineBuffer << endl;
			continue;
		}
		Customer customer(*pa);
		customer.setDataLayer(this);
		customer.ID = id;
		strcpy(customer.name, word[1]);
		customer.sex = (Sex) atoi(word[2]);
		Utility::StringToDate(word[3], customer.birthday);
		strcpy(customer.address, word[4]);
		customer.phone = Utility::StringToPhone(word[5]);

		CustomerList.push_back(customer);
	}
	ifs.close();

	return true;
}



bool DataLayer::SaveCustomerList(const CustomerArray &CustomerList)
{
	ofstream ofs(CustomerDataPath);
	if (!ofs) {
		cerr << "Customer file open error." << endl;
		return false;
	}

	int nCustomers = CustomerList.size();
	for (int i = 0; i < nCustomers; i++)
	{
		Customer& CurrrentCostomer = (Customer &) CustomerList[i];
		//将顾客的账户信息更新回AccountList
		//*(GetAccount(CurrrentCostomer.getID())) = *((Account*)&CurrrentCostomer);
		CurrrentCostomer.PutCustomerRecord(ofs);
	}

	ofs.close();

	return true;
}

//Customer* DataLayer::GetCustomerIt(int ID) const
//{
//	Customer* pc = nullptr;
//	for (auto it = CustomerList.cbegin();
//		it != CustomerList.cend(); ++it)
//	{
//		if ((*it).ID == ID)
//		{
//			pc = (Customer*)&(*it);
//			break;
//		}
//
//	}
//	return pc;
//}

Customer* DataLayer::GetCustomer(int ID) 
{
	Customer* pc = nullptr;
	int nCustomers = CustomerList.size();
	for (int i = 0; i < nCustomers; i++) {
		if (CustomerList[i].ID == ID) {
			pc = (Customer*)&CustomerList[i];
			break;
		}
	}
	return pc;
}

bool DataLayer::LoadMerchantList()
{
	ifstream  ifs(MerchantDataPath);
	if (!ifs) {
		cerr << "Merchant file open error." << endl;
		return false;
	}

	char *word[NumOfProductAttrib];

	const int BufferSize = 1024;
	char LineBuffer[BufferSize];
	MerchantList.clear();
	while (ifs.getline(LineBuffer, BufferSize)) {
		int nWords = Utility::ParseString(LineBuffer, word);

		if (nWords != NumOfMerchantAttrib) {
			cerr << "Merchant data error." << endl;
			ifs.close();
			return false;
		}

		int id = atoi(word[0]);
		Account* pa = GetAccount(id);
		if (pa == nullptr)
		{
			cerr << "Merchant ID "<<id<<" error." << endl;
			continue;
		}
		Merchant merchant(*pa);
		merchant.setDataLayer(this);
		merchant.ID = id;
		strcpy(merchant.name, word[1]);
		merchant.phone = Utility::StringToPhone(word[2]);
		merchant.TotalSales = atof(word[3]);
		merchant.nRatings = atoi(word[4]);
		merchant.rating = atof(word[5]); 

		MerchantList.push_back(merchant);
	}
	ifs.close();

	return true;
}



bool DataLayer::SaveMerchantList(const MerchantArray &MerchantList)
{
	ofstream ofs(MerchantDataPath);
	if (!ofs) {
		cerr << "Merchant file open error." << endl;
		return false;
	}

	int nMerchants = MerchantList.size();
	for (int i = 0; i < nMerchants; i++)
	{
		Merchant& CurrentMerchant = (Merchant&) MerchantList[i];
		//将商家的账户信息更新回AccountList
		//*(GetAccount(CurrentMerchant.getID())) = *((Account*)&CurrentMerchant);
		CurrentMerchant.PutMerchantRecord(ofs);
	}		

	ofs.close();

	return true;
}

//Merchant* DataLayer::GetMerchantIt(int ID) const
//{
//	Merchant* pm = nullptr;
//	for (auto it = MerchantList.cbegin();
//		it != MerchantList.cend(); ++it)
//	{
//		if ((*it).ID == ID)
//		{
//			pm = (Merchant*)&(*it);
//			break;
//		}
//
//	}
//	return pm;
//}
Merchant* DataLayer::GetMerchant(int ID) 
{
	Merchant* pm = nullptr;
	int nMerchants = MerchantList.size();
	for (int i = 0; i < nMerchants; i++) {
		if (MerchantList[i].ID == ID) {
			pm = (Merchant*)&MerchantList[i];
			break;
		}
	}
	return pm;
}

// 读取商品信息表
bool DataLayer::LoadProductList()
{
	ifstream  ifs(ProductDataPath);
	if (!ifs) {
		cerr << "Product file open error." << endl;
		return false;
	}

	// 用于存储行字符串分解后得到的各属性字符串数组
	const int MaxWordSize = 8;
	char *word[MaxWordSize];

	// 逐行读取文件，存储在字符串LineBuffer之中
	const int BufferSize = 4096;
	char LineBuffer[BufferSize];
	ProductList.clear();
	while (ifs.getline(LineBuffer, BufferSize)) {
		// 分解字符串为各字符串子串，存储在字符串数组之中
		int nWords = Utility::ParseString(LineBuffer, word);

		if (nWords != NumOfProductAttrib) {
			cerr << "Product data error." << endl;
			ifs.close();
			return false;
		}

		int mid = atoi(word[1]);
		Merchant* pm = GetMerchant(mid);
		if (pm == nullptr)
		{
			cerr << "Merchant ID error." << endl;
			cerr << LineBuffer << endl;
			continue;
		}
		// 定义结构体变量，根据分解得到的字符串子串，给结构体变量的各属性赋值
		Product product;
		product.ProductID = atoi(word[0]);
		product.AccountID = mid;
		//product.setMerchant(pm);		
		strcpy(product.name, word[2]);
		product.price = atof(word[3]);
		product.stock = atoi(word[4]);
		product.rating = atof(word[5]);
		product.nRatings = atoi(word[6]);
		product.nSales = atoi(word[7]);

		// 将新读入的商品信息结构体变量，放在vector数组ProductList的尾部
		ProductList.push_back(product);
	}
	ifs.close();

	return true;
}

Product* DataLayer::GetProduct(int ID) 
{
	Product* pp = nullptr;
	// 对数组中的每个元素
	int nProducts = ProductList.size();
	for (int i = 0; i < nProducts; i++)
	{
		if (ProductList[i].ProductID == ID)
		{
			pp = (Product *)&ProductList[i];
			break;
		}
	}
	return pp;
}

bool DataLayer::SaveProductList(ProductArray &ProductList)
{
	ofstream ofs(ProductDataPath);
	if (!ofs) {
		cerr << "Product file open error." << endl;
		return false;
	}

	// 对数组中的每个元素将其写为数据表中的一行
	int nProducts = ProductList.size();
	for (int i = 0; i < nProducts; i++)
	{
		Product& CurrentProduct = (Product&) ProductList[i];
		CurrentProduct.PutProductRecord(ofs);
	}

	ofs.close();

	return true;
}

Order* DataLayer::GetOrder(int ID) 
{
	Order* po = nullptr;
	int nOrders = OrderList.size();
	for (int i = 0; i < nOrders; i++) {
		const Order& CurrentOrder = OrderList[i];

		if (CurrentOrder.OrderID == ID ) {
			po = (Order*)&OrderList[i];
		}
	}
	return po;
}
bool DataLayer::LoadOrderList()
{
	ifstream  ifs(OrderDataPath);
	if (!ifs) {
		cerr << "Order file open error." << endl;
		return false;
	}

	const int MaxWordSize = NumOfOrderAttrib;
	char *word[MaxWordSize];

	const int BufferSize = 1024;
	char LineBuffer[BufferSize];
	OrderList.clear();
	while (ifs.getline(LineBuffer, BufferSize)) {
		int nWords = Utility::ParseString(LineBuffer, word);

		if (nWords != NumOfOrderAttrib) {
			cerr << "Order data error." << endl;
			ifs.close();
			return false;
		}

		int mid = atoi(word[2]),cid = atoi(word[1]),pid = atoi(word[3]);
		Merchant* pm = GetMerchant(mid);
		if (pm == nullptr)
		{
			cerr << "Merchant ID "<<mid<<" error." << endl;
			continue;
		}
		Customer* pc = GetCustomer(cid);
		if (pc == nullptr)
		{
			cerr << "Customer ID "<<cid<<"error." << endl;
			continue;
		}
		Product* pp = GetProduct(pid);
		if (pp == nullptr)
		{
			cerr << "Product ID "<<pid<<" error." << endl;
			continue;
		}

		Order order;
		order.OrderID = atoi(word[0]);
		order.CustomerID = cid;
		//order.setCustomer(pc);
		order.MerchantID = mid;
		//order.setMerchant(pm);
		order.ProductID = pid;
		//order.setProduct(pp);		
		strcpy(order.ProductName, word[4]);
		order.number = atoi(word[5]);
		Utility::StringToTime(word[6], order.OrderTime);
		order.price = atof(word[7]);
		strcpy(order.CustomerName, word[8]);
		strcpy(order.address, word[9]);
		order.phone = Utility::StringToPhone(word[10]);
		order.status = (OrderStatus) atoi(word[11]);
		OrderList.push_back(order);
	}
	ifs.close();

	return true;
}


bool DataLayer::SaveOrderList(const OrderArray &OrderList)
{
	ofstream ofs(OrderDataPath);
	if (!ofs) {
		cerr << "Order file open error." << endl;
		return false;
	}

	int nOrders = OrderList.size();
	for (int i = 0; i < nOrders; i++)
	{
		Order& CurrentOrder = (Order&)OrderList[i];
		CurrentOrder.PutOrderRecord(ofs);
	}
		
	
	ofs.close();

	return true;
}

int DataLayer::AddOrder(int CustomerID, int MerchantID, int ProductID,
	const char *ProductName, int number, double price, const char *CustomerName, 
	const char *address, UINT64 phone)
{
	Order order;
	order.OrderID = GetNextOrderID();
	order.CustomerID = CustomerID;
	//order.setCustomer(GetCustomer(CustomerID));
	order.MerchantID = MerchantID;
	//order.setMerchant(GetMerchant(MerchantID));
	order.ProductID = ProductID;
	//order.setProduct(GetProduct(ProductID));
	strcpy(order.ProductName, ProductName);
	order.number = number;
	order.price = price;
	Utility::GetCurrentTime(order.OrderTime);
	strcpy(order.CustomerName, CustomerName);
	strcpy(order.address, address);
	order.phone = phone;
	order.status = SUCCESS;
	
	OrderList.push_back(order);
	Order::PrintOrders(&order, 1);
	return order.OrderID;
}

//bool DeleteOrderIf(bool(*condition)(const Order &, int))
//{
//	bool flag = false;
//
//	OrderArray OrderList;
//	LoadOrderList(OrderList);
//
//	int nOrders = OrderList.size();
//	for (int i = 0; i < nOrders; i++) {
//		if (condition(OrderList[i], i)) {
//			OrderList.erase(OrderList.begin() + i);
//			flag = true;
//			break;
//		}
//	}
//
//	SaveOrderList(OrderList);
//
//	return flag;
//}

bool DataLayer::LoadAccountList()
{
	ifstream  ifs(AccountDataPath);
	if (!ifs) {
		cerr << "Account file open error." << endl;
		return false;
	}

	const int MaxWordSize = 8;
	char *word[MaxWordSize];

	const int BufferSize = 1024;
	char LineBuffer[BufferSize];
	AccountList.clear();
	while (ifs.getline(LineBuffer, BufferSize)) {
		int nWords = Utility::ParseString(LineBuffer, word);

		if (nWords != NumOfAccountAttrib) {
			cerr << "Account data error." << endl;
			ifs.close();
			return false;
		}

		Account account;
		account.setDataLayer(this);
		account.ID = atoi(word[0]);
		strcpy(account.LoginName, word[1]); 
		strcpy(account.password, word[2]);
		account.type = (UserType) atoi(word[3]);
		account.money = atof(word[4]);

		AccountList.push_back(account);
	}
	ifs.close();

	return true;
}

Account* DataLayer::GetAccount(int ID) 
{
	Account* pa = nullptr;
	int nAccounts = AccountList.size();
	for (int i = 0; i < nAccounts; i++)
	{
		if (AccountList[i].ID == ID)
		{
			pa = (Account*) &AccountList[i];
			break;
		}
	}
	return pa;
}
bool DataLayer::SaveAccountList(const AccountArray &AccountList)
{
	ofstream ofs(AccountDataPath);
	if (!ofs) {
		cerr << "Order file open error." << endl;
		return false;
	}
	
	int nAccounts = AccountList.size();
	for (int i = 0; i < nAccounts; i++)
	{
		Account& CurrentAccout = (Account &) AccountList[i];
		Account* pa = nullptr;
		//更新当前账户信息到数据列表			
		switch (CurrentAccout.type)
		{
		case ADMIN:
			break;
		case MERCHANT:
			pa = (Account*)GetMerchant(CurrentAccout.getID());
			if(pa != nullptr)
				CurrentAccout = *(pa);
			break;
		case CUSTOMER:
			pa = (Account*)GetCustomer(CurrentAccout.getID());
			if (pa != nullptr)
				CurrentAccout = *(pa);
			break;
		default:
			cout << "用户角色错误!";
			UI::pause();
		}
		CurrentAccout.PutAccountRecord(ofs);
	}

	ofs.close();

	return true;
}

bool DataLayer::GetAccountType(int AccountID, UserType &type)
{
	bool found = false;
	int nAccounts = AccountList.size();
	for (int i = 0; i < nAccounts; i++) {
		if (AccountList[i].ID == AccountID) {
			type = AccountList[i].type;
			found = true;
			break;
		}
	}

	return found;
}




int DataLayer::CheckLoginName(const char* LoginName)
{
	int nAccounts = AccountList.size();
	for (int i = 0; i < nAccounts; i++) {
		const Account& CurrentAccount = AccountList[i];

		if (strcmp(CurrentAccount.LoginName, LoginName) == 0) {
			return CurrentAccount.ID;
		}
	}

	return -1;
}
int DataLayer::CheckLoginInfo(const char *LoginName, const char *password)
{
	int nAccounts = AccountList.size();
	for (int i = 0; i < nAccounts; i++) {
		const Account &CurrentAccount = AccountList[i];

		if (strcmp(CurrentAccount.LoginName, LoginName) == 0 &&
			strcmp(CurrentAccount.password, password) == 0) {
			return CurrentAccount.ID;
		}
	}

	return -1;
}


