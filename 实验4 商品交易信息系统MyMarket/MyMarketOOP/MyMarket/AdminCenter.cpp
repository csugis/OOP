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
		"          |*                 ����Ա����                  *|\n"
		"          |***********************************************|\n"
		"          |*                 �� �� ��                    *|\n"
		"          |*               1. �˻�����                   *|\n"
		"          |*               2. ��ֵ���ֹ���               *|\n"
		"          |*               0. �˳�ϵͳ                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-2]��";

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
		cout << "����ָ���������������룡" << endl;
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
		"          |*                 ����Ա����                  *|\n"
		"          |***********************************************|\n"
		"          |*                 �˻�����                    *|\n"
		"          |*               1. ���ע��                   *|\n"
		"          |*               2. �̻�ע��                   *|\n"
		"          |*               3. �鿴�����Ϣ               *|\n"
		"          |*               4. �鿴�̻���Ϣ               *|\n"
		"          |*               5. ע���˻�                   *|\n"
		"          |*               0. ������һ��                 *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-6]��";

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
		cout << "����ָ���������������룡" << endl;
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
		"          |*                 ����Ա����                  *|\n"
		"          |***********************************************|\n"
		"          |*                ��ֵ���ֹ���                 *|\n"
		"          |*               1. ��ֵ����                   *|\n"
		"          |*               2. ���ֹ���                   *|\n"
		"          |*               0. ������һ���Ӳ˵�           *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-2]��";

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
		cout << "����ָ���������������룡" << endl;
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
		cout << "�������¼����";
		cin.getline(AccountName, UsrNameBuffSize);
		if (CheckAccoutName(AccountName))
			break;
		cout << "��¼�����Ϸ����¼���Ѵ��ڣ�����������" << endl;
	}
	char pw[PwdBuffSize];
	Utility::GeneratePassword(pw, 6);
	int AccountID = AddAccount(AccountName, pw, CUSTOMER);
	if (AccountID < 0) {
		cout << "�Ѵ��ڸ��û������˻�����ʧ�ܣ�" << endl;
		return;
	}

	Customer customer(*(pDL->GetAccount(AccountID)));
	if (customer.CustomerSignIn())
	{
		CustomerArray* pCustomerList = pDL->getCustomerList();
		pCustomerList->push_back(customer);

		Customer::PrintCustomers(&customer, 1);
		cout << "�˻������ɹ���" << endl;
		cout << "�˻���ʼ����Ϊ��" << pw << endl;
	}
}

void Admin::MerchantSignIn()
{
	char AccountName[UsrNameBuffSize];
	while (true) {
		cout << "�������¼����";
		cin.getline(AccountName, UsrNameBuffSize);
		if (CheckAccoutName(AccountName))
			break;
		cout << "��¼�����Ϸ����¼���Ѵ��ڣ�����������" << endl;
	}

	char pw[PwdBuffSize];
	Utility::GeneratePassword(pw, 6);

	int AccountID = AddAccount(AccountName, pw, MERCHANT);
	if (AccountID < 0) {
		cout << "�Ѵ��ڸ��û������˻�����ʧ�ܣ�" << endl;
		return;
	}
	Merchant merchant(*(pDL->GetAccount(AccountID)));
	if (merchant.MerchantSignIn())
	{
		MerchantArray* pMerchantList = pDL->getMerchantList();
		pMerchantList->push_back(merchant);

		Merchant::PrintMerchants(&merchant, 1);

		cout << "�˻������ɹ���" << endl;
		cout << "�˻���ʼ����Ϊ��" << pw << endl;
	}
}

void Admin::BrowseCustomerInfo()
{
	CustomerArray* pCustomerList = pDL->getCustomerList();

	if (pCustomerList->size() > 0)
		Customer::PrintCustomers(&((*pCustomerList)[0]), pCustomerList->size());
	else
		cout << "δ���ҵ���������Ϣ��" << endl;
}

void Admin::BrowseMerchantInfo()
{
	MerchantArray* pMerchantList = pDL->getMerchantList();

	if (pMerchantList->size() > 0)
		Merchant::PrintMerchants(&((*pMerchantList)[0]), pMerchantList->size());
	else
		cout << "δ���ҵ���������Ϣ��" << endl;
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
	cout << "������Ҫע�����˻�����";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "δ�ҵ��˻�����" << endl;
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	double money = pa->GetAccountMoney();
	if (money != 0.0) {
		cout << "���˻��������δ���壡" << endl;
		return;
	}

	char password[PwdBuffSize];
	cout << "��������˻�����ȷ��ɾ���˻���" << endl;
	UI::GetPass(password);
	if (!pa->CheckPassword(password)) {
		cout << "�˻����������" << endl;
		return;
	}

	UserType type = pa->GetAccountType();
	if (type == CUSTOMER)
		DeleteCustomer(TargetAccountID);
	else if (type == MERCHANT) {
		DeleteMerchant(TargetAccountID);
	}

	if (DeleteAccount(TargetAccountID))
		cout << "�˻�ɾ���ɹ���" << endl;
	else
		cout << "���ݴ���" << endl;
}

void Admin::Charge()
{
	cout << "������Ҫ��ֵ���˻�����";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "δ�ҵ��˻�����" << endl;
		return;
	}

	cout << "������Ҫ��ֵ�Ľ�";
	double cash = UI::GetCashValue();
	cash = (int)(cash * 100) / 100.0;

	if (cash <= 0.0) {
		cout << "���������\n" << endl;
		return;
	}

	char password[PwdBuffSize];

	cout << "���������Ա���룺";
	UI::GetPass(password);
	
	if (!CheckPassword(password)) {
		cout << "����Ա�������\n";
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	cout << "�������ֵ�˻����룺";
	UI::GetPass(password);

	if (!pa->CheckPassword(password)) {
		cout << "��ֵ�˻��������\n";
		return;
	}

	double money = 0.0;
	pa->UpdateAccountMoney(cash);
	money = pa->GetAccountMoney();
	cout << "\n��ֵ�ɹ���\n";
	cout << "��ֵ���Ϊ" << setiosflags(ios::fixed) << setprecision(2)
		<< cash << "Ԫ��\n";
	cout << "��ǰ�˻����Ϊ" << setiosflags(ios::fixed) << setprecision(2)
		<< money << "Ԫ��\n";
}

void Admin::WithDraw()
{
	cout << "������Ҫ���ֵ��˻�����";
	char AccountName[UsrNameBuffSize];
	cin.getline(AccountName, UsrNameBuffSize);

	int TargetAccountID = GetAccountID(AccountName);
	if (TargetAccountID == -1) {
		cout << "δ�ҵ��˻�����" << endl;
		return;
	}
	
	char password[PwdBuffSize];

	cout << "���������Ա���룺";
	UI::GetPass(password);

	if (!CheckPassword(password)) {
		cout << "����Ա�������\n";
		return;
	}
	Account* pa = pDL->GetAccount(TargetAccountID);
	cout << "�����������˻����룺";
	UI::GetPass(password);

	if (!pa->CheckPassword(password)) {
		cout << "�����˻��������\n";
		return;
	}

	cout << "������Ҫ���ֵĽ�";
	double cash = UI::GetCashValue();
	
	double money = pa->GetAccountMoney();
	if (cash <= 0.0 && cash > money) {
		cout << "���������򳬳����н����������롣\n" << endl;
		return;
	}

	pa->UpdateAccountMoney(-cash);
	money = pa->GetAccountMoney();
	cout << "\n���ֳɹ���\n";
	cout << "���ֽ��Ϊ" << setiosflags(ios::fixed) << setprecision(2)
		<< cash << "Ԫ��\n";
	cout << "��ǰ�˻����Ϊ" << setiosflags(ios::fixed) << setprecision(2)
		<< money << "Ԫ��\n";
}