#include <iostream>
#include <iomanip>

#include "AdminCenter.h"
#include "DataLayer.h"
#include "ui.h"
#include "utility.h"
#include "AdminCenter.h"

using namespace std;

void Admin::ShowMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                 管理员中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 主 菜 单                    *|\n"
		"          |*               1. 账户管理                   *|\n"
		"          |*               2. 充值提现管理               *|\n"
		"          |*               0. 退出系统                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-2]：";

		if (!SelectAdminMenu())
			break;
	}
}

bool Admin::SelectAdminMenu()
{
	enum {
		ACCOUT_MANAGEMENT = 1,
		RECHARGE_AND_WITHDRAW = 2,
		EXIT = 0
	};

	switch (UI::GetNumber())
	{
	case ACCOUT_MANAGEMENT:
		ShowAccountManageMenu();
		break;

	case RECHARGE_AND_WITHDRAW:
		ShowChargeWithdrawMangement();
		break;

	case EXIT:
		
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}

void Admin::ShowAccountManageMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                 管理员中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 账户管理                    *|\n"
		"          |*               1. 买家注册                   *|\n"
		"          |*               2. 商户注册                   *|\n"
		"          |*               3. 查看买家信息               *|\n"
		"          |*               4. 查看商户信息               *|\n"
		"          |*               5. 注销账户                   *|\n"
		"          |*               0. 返回上一级                 *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-6]：";

		if (!SelectAccountManageMenu())
			break;
	}
}

bool Admin::SelectAccountManageMenu()
{
	enum {
		CUSTOMER_SIGN_IN = 1,
		MERCHANT_SIGN_IN = 2,
		BROWSE_CUSTOMER_INFO = 3,
		BROWSE_MERCHANT_INFO = 4,
		REMOVE_ACCOUNT = 5,
		TO_ADMIN_MENU = 0
	};

	switch (UI::GetNumber())
	{
	case CUSTOMER_SIGN_IN:
		CustomerSignIn();
		UI::pause();
		break;

	case MERCHANT_SIGN_IN:
		MerchantSignIn();
		break;

	case BROWSE_CUSTOMER_INFO:
		BrowseCustomerInfo();
		UI::pause();
		break;

	case BROWSE_MERCHANT_INFO:
		BrowseMerchantInfo();
		UI::pause();
		break;

	case REMOVE_ACCOUNT:
		RemoveAccount();
		UI::pause();
		break;

	case TO_ADMIN_MENU:
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;

	}

	return true;
}

void Admin::ShowChargeWithdrawMangement()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                 管理员中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                充值提现管理                 *|\n"
		"          |*               1. 充值管理                   *|\n"
		"          |*               2. 提现管理                   *|\n"
		"          |*               0. 返回上一级子菜单           *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-2]：";

		if (!SelectChargeWithdrawMenu())
			break;
	}
}

bool Admin::SelectChargeWithdrawMenu()
{
	enum {
		CHARGE = 1,
		WITHDRAW = 2,
		TO_ADMIN_MENU = 0
	};

	switch (UI::GetNumber())
	{
	case CHARGE:
		Charge();
		UI::pause();
		break;

	case WITHDRAW:
		WithDraw();
		UI::pause();
		break;

	case TO_ADMIN_MENU:
		return false;

	default:
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}

int Admin::AddAccount(const char* name, char* password, UserType type)
{
	if (!CheckAccoutName(name))
	{
		return -1;
	}
	int aID = GetNextAccountID();
	UserType atype = type;
	double amoney = 0.0;

	Account account(aID,name,password,atype,amoney);
	AccountArray* pAccountList = pDL->getAccountList();
	pAccountList->push_back(account);

	return aID;
}

bool Admin::DeleteAccount(int ID)
{
	AccountArray* pAccountList = pDL->getAccountList();
	bool IsDelete = false;
	int nAccounts = pAccountList->size();
	for (int i = 0; i < nAccounts; i++) {
		if ((*pAccountList)[i].getID() == ID) {
			pAccountList->erase(pAccountList->begin() + i);
			IsDelete = true;
			break;
		}
	}
	return IsDelete;
}

void Admin::CustomerSignIn()
{
	char AccountName[UsrNameBuffSize];
	while (true) {
		cout << "请输入登录名：";
		cin.getline(AccountName, UsrNameBuffSize);
		if (CheckAccoutName(AccountName))
			break;
		cout << "登录名不合法或登录名已存在，请重新输入" << endl;
	}
	char pw[PwdBuffSize];
	Utility::GeneratePassword(pw, 6);
	int AccountID = AddAccount(AccountName, pw, CUSTOMER);
	if (AccountID < 0) {
		cout << "已存在该用户名，账户创建失败！" << endl;
		return;
	}

	Customer customer(*(pDL->GetAccount(AccountID)));
	if (customer.CustomerSignIn())
	{
		CustomerArray* pCustomerList = pDL->getCustomerList();
		pCustomerList->push_back(customer);

		Customer::PrintCustomers(&customer, 1);
		cout << "账户创建成功！" << endl;
		cout << "账户初始密码为：" << pw << endl;
	}
}

void Admin::MerchantSignIn()
{
	char AccountName[UsrNameBuffSize];
	while (true) {
		cout << "请输入登录名：";
		cin.getline(AccountName, UsrNameBuffSize);
		if (CheckAccoutName(AccountName))
			break;
		cout << "登录名不合法或登录名已存在，请重新输入" << endl;
	}

	char pw[PwdBuffSize];
	Utility::GeneratePassword(pw, 6);

	int AccountID = AddAccount(AccountName, pw, MERCHANT);
	if (AccountID < 0) {
		cout << "已存在该用户名，账户创建失败！" << endl;
		return;
	}
	Merchant merchant(*(pDL->GetAccount(AccountID)));
	if (merchant.MerchantSignIn())
	{
		MerchantArray* pMerchantList = pDL->getMerchantList();
		pMerchantList->push_back(merchant);

		Merchant::PrintMerchants(&merchant, 1);

		cout << "账户创建成功！" << endl;
		cout << "账户初始密码为：" << pw << endl;
	}
}

void Admin::BrowseCustomerInfo()
{
	CustomerArray* pCustomerList = pDL->getCustomerList();

	if (pCustomerList->size() > 0)
		Customer::PrintCustomers(&((*pCustomerList)[0]), pCustomerList->size());
	else
		cout << "未能找到相关买家信息。" << endl;
}

void Admin::BrowseMerchantInfo()
{
	MerchantArray* pMerchantList = pDL->getMerchantList();

	if (pMerchantList->size() > 0)
		Merchant::PrintMerchants(&((*pMerchantList)[0]), pMerchantList->size());
	else
		cout << "未能找到相关买家信息。" << endl;
}

int Admin::GetAccountID(const char* LoginName)
{
	return pDL->CheckLoginName(LoginName);
}
bool Admin::DeleteCustomer(int ID)
{
	bool IsDelete = false;
	CustomerArray* pCustomerList = pDL->getCustomerList();
	int nCustomers = pCustomerList->size();
	for (int i = 0; i < nCustomers; i++) {
		if ((*pCustomerList)[i].getID() == ID) {
			pCustomerList->erase(pCustomerList->begin() + i);
			IsDelete = true;
			break;
		}
	}
	return false;
}

bool Admin::DeleteMerchant(int ID)
{
	MerchantArray* pMerchantList=pDL->getMerchantList();

	bool IsDelete = false;
	int nMerchants = pMerchantList->size();
	for (int i = 0; i < nMerchants; i++) {
		if ((*pMerchantList)[i].getID() == ID) {
			(*pMerchantList)[i].RemoveAllProducts();
			pMerchantList->erase(pMerchantList->begin() + i);
			IsDelete = true;
			break;
		}
	}

	return false;
}

void Admin::RemoveAccount()
{
	cout << "请输入要注销的账户名：";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "未找到账户名！" << endl;
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	double money = pa->GetAccountMoney();
	if (money != 0.0) {
		cout << "该账户尚有余额未结清！" << endl;
		return;
	}

	char password[PwdBuffSize];
	cout << "请输入该账户密码确认删除账户！" << endl;
	UI::GetPass(password);
	if (!pa->CheckPassword(password)) {
		cout << "账户名密码错误！" << endl;
		return;
	}

	UserType type = pa->GetAccountType();
	if (type == CUSTOMER)
		DeleteCustomer(TargetAccountID);
	else if (type == MERCHANT) {
		DeleteMerchant(TargetAccountID);
	}

	if (DeleteAccount(TargetAccountID))
		cout << "账户删除成功。" << endl;
	else
		cout << "数据错误！" << endl;
}

void Admin::Charge()
{
	cout << "请输入要充值的账户名：";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "未找到账户名！" << endl;
		return;
	}

	cout << "请输入要充值的金额：";
	double cash = UI::GetCashValue();
	cash = (int)(cash * 100) / 100.0;

	if (cash <= 0.0) {
		cout << "输入金额错误！\n" << endl;
		return;
	}

	char password[PwdBuffSize];

	cout << "请输入管理员密码：";
	UI::GetPass(password);
	
	if (!CheckPassword(password)) {
		cout << "管理员密码错误。\n";
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	cout << "请输入充值账户密码：";
	UI::GetPass(password);

	if (!pa->CheckPassword(password)) {
		cout << "充值账户密码错误。\n";
		return;
	}

	double money = 0.0;
	pa->UpdateAccountMoney(cash);
	money = pa->GetAccountMoney();
	cout << "\n充值成功！\n";
	cout << "充值金额为" << setiosflags(ios::fixed) << setprecision(2)
		<< cash << "元。\n";
	cout << "当前账户余额为" << setiosflags(ios::fixed) << setprecision(2)
		<< money << "元。\n";
}

void Admin::WithDraw()
{
	cout << "请输入要提现的账户名：";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "未找到账户名！" << endl;
		return;
	}
	
	char password[PwdBuffSize];

	cout << "请输入管理员密码：";
	UI::GetPass(password);

	if (!CheckPassword(password)) {
		cout << "管理员密码错误。\n";
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	cout << "请输入提现账户密码：";
	UI::GetPass(password);

	if (!pa->CheckPassword(password)) {
		cout << "提现账户密码错误。\n";
		return;
	}

	cout << "请输入要提现的金额：";
	double cash = UI::GetCashValue();
	
	double money = pa->GetAccountMoney();
	if (cash <= 0.0 && cash > money) {
		cout << "输入金额错误或超出现有金额，请重新输入。\n" << endl;
		return;
	}

	pa->UpdateAccountMoney(-cash);
	money = pa->GetAccountMoney();
	cout << "\n提现成功！\n";
	cout << "提现金额为" << setiosflags(ios::fixed) << setprecision(2)
		<< cash << "元。\n";
	cout << "当前账户余额为" << setiosflags(ios::fixed) << setprecision(2)
		<< money << "元。\n";
}