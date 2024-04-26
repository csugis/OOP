#include <iostream>

#include "CustomerCenter.h"
#include "DataLayer.h"
#include "ui.h"
#include "utility.h"
#include "CommonBusiness.h"
#include "CustomerCenter.h"

using namespace std;
Customer::~Customer()
{
	
}
void Customer::GetCustomerAddress(char* na, char* add, UINT64& ph)
{
	strcpy(na, name);
	strcpy(add, address);
	ph = phone;
}

void Customer::ShowBuyMenu()
{
	const char* BuyMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   买家中心	                 *|\n"
		"          |***********************************************|\n"
		"          |*                   购买菜单                  *|\n"
		"          |*               1. 搜索商品                   *|\n"
		"          |*               2. 查询商家                   *|\n"
		"          |*               3. 查看商家商品               *|\n"
		"          |*               4. 现在购买                   *|\n"
		"          |*               0. 返回上一级菜单             *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << BuyMenu;
		cout << "请选择菜单[0-4]：";

		if (!SelectBuyMenu())
			break;
	}
}

bool Customer::SelectBuyMenu()
{
	enum {
		SEARCH_PRODUCT = 1,
		SEARCH_MERCHANT = 2,
		BROWSE_MERCHANT_PRODUCT = 3,
		BUY_NOW = 4,
		TO_CUSTOMER_MENU = 0,
	};

	switch (UI::GetNumber())
	{
	case SEARCH_PRODUCT:
		SearchProduct();
		UI::pause();
		break;

	case SEARCH_MERCHANT:
		SearchMerchant();
		UI::pause();
		break;

	case BROWSE_MERCHANT_PRODUCT:
		BrowseMerchantProducts();
		UI::pause();
		break;

	case BUY_NOW:
		BuyProduct();
		UI::pause();
		break;

	case TO_CUSTOMER_MENU:
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}

void Customer::ShowMyOrderMenu()
{
	const char* MyOrderMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   买家中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                我的订单菜单                 *|\n"
		"          |*               1. 查看历史订单               *|\n"
		"          |*               2. 评价商品                   *|\n"
		"          |*               3. 提交退货申请               *|\n"
		"          |*               0. 返回上一级                 *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << MyOrderMenu;
		cout << "请选择菜单[0-3]：";
		if (!SelectMyOrderMenu())
			break;
	}
}

bool Customer::SelectMyOrderMenu()
{

	enum {
		BROWSE_HISTORY_ORDERS = 1,
		RATE_PRODUCT = 2,
		REFUND_APPLICATION = 3,
		TO_CUSTOMER_MENU = 0,
	};

	switch (UI::GetNumber())
	{
	case BROWSE_HISTORY_ORDERS:
		BrowseHistoryOrders();
		UI::pause();
		break;

	case RATE_PRODUCT:
		RateProduct();
		UI::pause();
		break;

	case REFUND_APPLICATION:
		RefundApplication();
		UI::pause();
		break;

	case TO_CUSTOMER_MENU:
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}


void Customer::ShowMyAccountMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   买家中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 我的账户菜单                *|\n"
		"          |*               1. 浏览账户信息               *|\n"
		"          |*               2. 修改账户信息               *|\n"
		"          |*               3. 修改密码                   *|\n"
		"          |*               4. 查询账户余额               *|\n"
		"          |*               0. 返回上一级菜单             *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-4]：";

		if (!SelectMyAccounMenu())
			break;
	}
}

bool Customer::SelectMyAccounMenu()
{
	enum {
		My_ACCOUNT_INFO = 1,
		MODIFY_ACCOUNT_INFO = 2,
		MODIFY_PASSWORD = 3,
		INQUIRY_BALANCE = 4,
		TO_CUSTOMER_MENU = 0,
	};

	switch (UI::GetNumber()) {
	case My_ACCOUNT_INFO:
		MyAccountInfo();
		UI::pause();
		break;

	case MODIFY_ACCOUNT_INFO:
		ModifyMyAccount();
		UI::pause();
		break;

	case MODIFY_PASSWORD:
		ChangePassword();
		UI::pause();
		break;

	case INQUIRY_BALANCE:
		InquiryBalance();
		UI::pause();
		break;

	case TO_CUSTOMER_MENU:
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}
bool Customer::CustomerSignIn()
{
	cout << "请输入姓名：";
	cin.getline(name, UsrNameBuffSize);

	while (true) {
		cout << "请输入性别：【0-男性/1-女性】";
		sex = (Sex)UI::GetNumber();
		if (sex == MALE || sex == FEMALE)
			break;
		cout << "性别不合法，请重新输入" << endl;
	}

	while (true) {
		cout << "请输入出生年：";
		birthday.year = UI::GetNumber();
		cout << "请输入出生月：";
		birthday.month = UI::GetNumber();
		cout << "请输入出生日：";
		birthday.day = UI::GetNumber();
		if (Utility::CheckDate(birthday))
			break;
		cout << "出生年月日不合法，请重新输入" << endl;
	}

	cout << "请输入地址：";
	cin.getline(address, AddressBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	cout << "请输入电话：";
	cin.getline(PhoneStr, MaxPhoneDigit);
	phone = Utility::StringToPhone(PhoneStr);

	char password[PwdBuffSize];
	Utility::GeneratePassword(password, 6);

	Customer::PrintCustomers(this, 1);
	cout << "是否确认创建该买家【按Y键确认，按任意键取消】：";
	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return false;
	return true;
}
void Customer::ShowMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   买家中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 主 菜 单                    *|\n"
		"          |*               1. 我要购物                   *|\n"
		"          |*               2. 我的订单                   *|\n"
		"          |*               3. 我的账户                   *|\n"
		"          |*               0. 退出系统                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-3]：";

		if (!SelectCustomerMenu())
			break;
	}
}

bool Customer::SelectCustomerMenu()
{
	enum {
		BUY = 1,
		MY_ORDER = 2,
		MY_ACCOUNT = 3,
		EXIT = 0,
	};

	switch (UI::GetNumber())
	{
	case BUY:
		ShowBuyMenu();
		break;

	case MY_ORDER:
		ShowMyOrderMenu();
		break;

	case MY_ACCOUNT:
		ShowMyAccountMenu();
		break;

	case EXIT:
		//*(pDL->GetAccount(ID)) = *((Account*)this);
		//*(pDL->GetCustomer(ID)) = *this;
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}

void Customer::SearchProduct()
{
	cout << "请输入搜索关键词：";
	char keyword[ProdNameBuffSize];
	//cin.ignore();
	cin.getline(keyword, ProdNameBuffSize);

	ProductArray* pProductList = pDL->getProductList();

	ProductArray SearchedProductList;

	int nProducts = pProductList->size();
	for (int i = 0; i < nProducts; i++) {
		Product &CurrentProduct = (*pProductList)[i];
		
		if (strstr(CurrentProduct.getName(), keyword) != NULL)
			SearchedProductList.push_back(CurrentProduct);
	}

	int nSearchedProducts = SearchedProductList.size();
	if (nSearchedProducts > 0) {

		Product temp;
		for (int j = 1; j < nSearchedProducts; j++) {
			for (int i = 0; i < nSearchedProducts-j; i++) {
				if (SearchedProductList[i].getPrice() >
					SearchedProductList[i+1].getPrice()) {
					temp = SearchedProductList[i];
					SearchedProductList[i] = SearchedProductList[i+1];
					SearchedProductList[i+1] = temp;
				}
			}
		}

		Product::PrintProducts(&SearchedProductList[0], nSearchedProducts);
	} else {
		cout << "没有找到关于" << keyword << "的相关商品！" << endl;
	}
}

void Customer::SearchMerchant()
{
	cout << "请输入要查询的商家编号：";
	int id = UI::GetNumber();
	BrowseMerchant(id);
}

void Customer::BrowseMerchantProducts()
{
	cout << "请输入要查询的商家编号：";
	int id = UI::GetNumber();
	BrowseProducts(id);
}

void Customer::BuyProduct()
{
	cout << "请输入要购买的商品编号：";
	int TargetProductID = UI::GetNumber();

	Product *pProductRecord = pDL->GetProduct(TargetProductID);

	if (pProductRecord == NULL) {
		cout << "无此商品！" << endl;
		return;
	}
	Product::PrintProducts(pProductRecord, 1);

	cout << "请输入要购买的商品数量：";
	int nRequirement = UI::GetNumber();
	if (nRequirement > pProductRecord->getStock()) {
		cout << "商家库存不足！" << endl;
		return;
	}

	double price = pProductRecord->getPrice() * nRequirement;
	cout << "商品共计" << price << "元，请输入密码确认购买：";

	char pwd[PwdBuffSize];
	UI::GetPass(pwd);

	if (!CheckPassword(pwd)) {
		cout << "密码错误！" << endl;
		return;
	}

	double curMoney = GetAccountMoney();
	if (curMoney < price) {
		cout << "用户余额不足！" << endl;
		return;
	}
	
	char name[UsrNameBuffSize];
	char address[AddressBuffSize];
	UINT64 phone;
	GetCustomerAddress(name, address, phone);
	int oid = pDL->AddOrder(ID, pProductRecord->getAccountID(),
		pProductRecord->getProductID(), pProductRecord->getName(), nRequirement,
		price, name, address, phone);
	UpdateAccountMoney(-price);
	Merchant* pm = pDL->GetMerchant(pProductRecord->getAccountID());
	if (pm != nullptr)
	{
		pm->UpdateAccountMoney(price);
		pm->UpdateMerchantSales(price);
	}

	pProductRecord->UpdateProductStock( -nRequirement);
	pProductRecord->UpdateProductNSales( nRequirement);
	
	cout << "\n购买成功！\n" ;
}

void Customer::BrowseHistoryOrders()
{
	OrderArray* pOrderList = pDL->getOrderList();

	OrderArray MyOrderList;
	int nOrders = pOrderList->size();
	for (int i = 0; i < nOrders; i++) {
		const Order &CurrentOrder = (*pOrderList)[i];

		if (CurrentOrder.getCustomerID() == ID)
			MyOrderList.push_back(CurrentOrder);
	}

	nOrders = MyOrderList.size();
	if (MyOrderList.size() > 0) {
		Utility::ReverseOrders(&MyOrderList[0], nOrders);
		Order::PrintOrders(&MyOrderList[0], nOrders);
	} else {
		cout << "未查询到相关订单！" << endl;
	}
}

void Customer::RateProduct()
{
	cout << "请输入要评价的订单编号：";
	int TargetOrderID = UI::GetNumber();

	Order *pOrderRecord = pDL->GetOrder(TargetOrderID);
	if (pOrderRecord == NULL || pOrderRecord->getCustomerID() != ID) {
		cout << "未发现相关订单！" << endl;
		return;
	}
	
	if (pOrderRecord->getStatus() != SUCCESS) {
		cout << "未发现相关订单！" << endl;
		return;
	}

	Order::PrintOrders(pOrderRecord, 1);

	cout << "请输入评分：";
	int rating = UI::GetNumber();
	if (rating < 0 && rating > 100) {
		cout << "评分应在0-100区间！" << endl;
		return;
	}

	Product* pProduct = pDL->GetProduct(pOrderRecord->getProductID());
	if (pProduct != NULL) {
		pProduct->UpdateRating(rating);
	}
	Merchant* pMerchant = pDL->GetMerchant(pOrderRecord->getMerchantID());
	if (pMerchant != NULL) {
		pMerchant->UpdateRating(rating);
	}

	cout << "商品评价成功！" << endl;
}

void Customer::RefundApplication()
{
	cout << "请输入要退货的订单编号：";
	int TargetOrderID = UI::GetNumber();

	Order* pOrderRecord = pDL->GetOrder(TargetOrderID);
	if (pOrderRecord == NULL || pOrderRecord->getCustomerID() != ID) {
		cout << "未发现相关订单！" << endl;
		return;
	}
	pOrderRecord->RefundApplication();
}
void Customer::PrintCustomers(Customer customers[], int nCustomers)
{
	FieldPrintSetting PrintSet[] = {
									 "账户编号", 8,
									 "姓名", 12,
									 "性别", 8,
									 "生日", 10,
									 "住址", 20,
									 "电话", 12,
	};
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);

	const char* SexLabel[] = { "男", "女" };
	char buffer[32];
	string strs[nFields];
	for (int i = 0; i < nCustomers; i++) {
		const Customer& CurrentCustomer = customers[i];
		const Date& birthday = CurrentCustomer.birthday;

		cout << '|';
		cout << setw(PrintSet[0].PrintWidth) << std::right
			<< CurrentCustomer.ID << '|';
		cout << setw(PrintSet[1].PrintWidth) << std::left
			<< Utility::TrimString(CurrentCustomer.name, buffer,
				PrintSet[1].PrintWidth, strs[i])
			<< '|';
		cout << setw(PrintSet[2].PrintWidth) << std::right
			<< SexLabel[CurrentCustomer.sex] << '|';
		cout << setw(PrintSet[3].PrintWidth) << std::right
			<< Utility::DateToString(CurrentCustomer.birthday, buffer) << '|';
		cout << setw(PrintSet[4].PrintWidth) << std::left
			<< Utility::TrimString(CurrentCustomer.address, buffer,
				PrintSet[4].PrintWidth, strs[4])
			<< '|';
		cout << setw(PrintSet[5].PrintWidth) << std::right
			<< CurrentCustomer.phone << '|';

		cout << endl;

		Utility::PrintRemaining(PrintSet, nFields, strs);
		Utility::PrintLine(PrintSet, nFields);
	}

	cout << endl;
}

void Customer::MyAccountInfo()
{
	Customer *pTargetCustomer = this;

	if (pTargetCustomer != NULL)
		PrintCustomers(pTargetCustomer, 1);
	else
		cout << "数据错误：未找到账户信息！" << endl;
}

void Customer::ModifyMyAccount()
{
	Customer *pTargetCustomer = this;

	if (pTargetCustomer == NULL) {
		cout << "数据错误：未找到账户信息！" << endl;
		return;
	}

	cout << "待修改的账户信息如下：" << endl;
	PrintCustomers(pTargetCustomer, 1);

	cout << "请输入姓名：";
	cin.getline(pTargetCustomer->name, UsrNameBuffSize);

	while (true) {
		cout << "请输入性别：【0-男性/1-女性】";
		pTargetCustomer->sex = (Sex)UI::GetNumber();
		if (pTargetCustomer->sex == MALE || pTargetCustomer->sex == FEMALE)
			break;
		cout << "性别不合法，请重新输入" << endl;
	}

	while (true) {
		cout << "请输入出生年：";
		pTargetCustomer->birthday.year = UI::GetNumber();
		cout << "请输入出生月：";
		pTargetCustomer->birthday.month = UI::GetNumber();
		cout << "请输入出生日：";
		pTargetCustomer->birthday.day = UI::GetNumber();
		if (Utility::CheckDate(pTargetCustomer->birthday))
			break;
		cout << "出生年月日不合法，请重新输入" << endl;
	}

	cout << "请输入地址：";
	cin.getline(pTargetCustomer->address, AddressBuffSize);
	
	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	cout << "请输入电话：";
	cin.getline(PhoneStr, MaxPhoneDigit);
	pTargetCustomer->phone = Utility::StringToPhone(PhoneStr);

	PrintCustomers(pTargetCustomer, 1);
	cout << "请确认修改为以上账户信息？【按Y键确认，按任意键取消】";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	if (true) {
		cout << "账户信息修改成功。" << endl;
	} else {
		cout << "账户信息修改失败。" << endl;
	}
}