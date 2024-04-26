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
		"          |*                   �������	                 *|\n"
		"          |***********************************************|\n"
		"          |*                   ����˵�                  *|\n"
		"          |*               1. ������Ʒ                   *|\n"
		"          |*               2. ��ѯ�̼�                   *|\n"
		"          |*               3. �鿴�̼���Ʒ               *|\n"
		"          |*               4. ���ڹ���                   *|\n"
		"          |*               0. ������һ���˵�             *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << BuyMenu;
		cout << "��ѡ��˵�[0-4]��";

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
		cout << "����ָ���������������룡" << endl;
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
		"          |*                   �������                  *|\n"
		"          |***********************************************|\n"
		"          |*                �ҵĶ����˵�                 *|\n"
		"          |*               1. �鿴��ʷ����               *|\n"
		"          |*               2. ������Ʒ                   *|\n"
		"          |*               3. �ύ�˻�����               *|\n"
		"          |*               0. ������һ��                 *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << MyOrderMenu;
		cout << "��ѡ��˵�[0-3]��";
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
		cout << "����ָ���������������룡" << endl;
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
		"          |*                   �������                  *|\n"
		"          |***********************************************|\n"
		"          |*                 �ҵ��˻��˵�                *|\n"
		"          |*               1. ����˻���Ϣ               *|\n"
		"          |*               2. �޸��˻���Ϣ               *|\n"
		"          |*               3. �޸�����                   *|\n"
		"          |*               4. ��ѯ�˻����               *|\n"
		"          |*               0. ������һ���˵�             *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-4]��";

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
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}
bool Customer::CustomerSignIn()
{
	cout << "������������";
	cin.getline(name, UsrNameBuffSize);

	while (true) {
		cout << "�������Ա𣺡�0-����/1-Ů�ԡ�";
		sex = (Sex)UI::GetNumber();
		if (sex == MALE || sex == FEMALE)
			break;
		cout << "�Ա𲻺Ϸ�������������" << endl;
	}

	while (true) {
		cout << "����������꣺";
		birthday.year = UI::GetNumber();
		cout << "����������£�";
		birthday.month = UI::GetNumber();
		cout << "����������գ�";
		birthday.day = UI::GetNumber();
		if (Utility::CheckDate(birthday))
			break;
		cout << "���������ղ��Ϸ�������������" << endl;
	}

	cout << "�������ַ��";
	cin.getline(address, AddressBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	cout << "������绰��";
	cin.getline(PhoneStr, MaxPhoneDigit);
	phone = Utility::StringToPhone(PhoneStr);

	char password[PwdBuffSize];
	Utility::GeneratePassword(password, 6);

	Customer::PrintCustomers(this, 1);
	cout << "�Ƿ�ȷ�ϴ�������ҡ���Y��ȷ�ϣ��������ȡ������";
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
		"          |*                   �������                  *|\n"
		"          |***********************************************|\n"
		"          |*                 �� �� ��                    *|\n"
		"          |*               1. ��Ҫ����                   *|\n"
		"          |*               2. �ҵĶ���                   *|\n"
		"          |*               3. �ҵ��˻�                   *|\n"
		"          |*               0. �˳�ϵͳ                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-3]��";

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
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}

void Customer::SearchProduct()
{
	cout << "�����������ؼ��ʣ�";
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
		cout << "û���ҵ�����" << keyword << "�������Ʒ��" << endl;
	}
}

void Customer::SearchMerchant()
{
	cout << "������Ҫ��ѯ���̼ұ�ţ�";
	int id = UI::GetNumber();
	BrowseMerchant(id);
}

void Customer::BrowseMerchantProducts()
{
	cout << "������Ҫ��ѯ���̼ұ�ţ�";
	int id = UI::GetNumber();
	BrowseProducts(id);
}

void Customer::BuyProduct()
{
	cout << "������Ҫ�������Ʒ��ţ�";
	int TargetProductID = UI::GetNumber();

	Product *pProductRecord = pDL->GetProduct(TargetProductID);

	if (pProductRecord == NULL) {
		cout << "�޴���Ʒ��" << endl;
		return;
	}
	Product::PrintProducts(pProductRecord, 1);

	cout << "������Ҫ�������Ʒ������";
	int nRequirement = UI::GetNumber();
	if (nRequirement > pProductRecord->getStock()) {
		cout << "�̼ҿ�治�㣡" << endl;
		return;
	}

	double price = pProductRecord->getPrice() * nRequirement;
	cout << "��Ʒ����" << price << "Ԫ������������ȷ�Ϲ���";

	char pwd[PwdBuffSize];
	UI::GetPass(pwd);

	if (!CheckPassword(pwd)) {
		cout << "�������" << endl;
		return;
	}

	double curMoney = GetAccountMoney();
	if (curMoney < price) {
		cout << "�û����㣡" << endl;
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
	
	cout << "\n����ɹ���\n" ;
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
		cout << "δ��ѯ����ض�����" << endl;
	}
}

void Customer::RateProduct()
{
	cout << "������Ҫ���۵Ķ�����ţ�";
	int TargetOrderID = UI::GetNumber();

	Order *pOrderRecord = pDL->GetOrder(TargetOrderID);
	if (pOrderRecord == NULL || pOrderRecord->getCustomerID() != ID) {
		cout << "δ������ض�����" << endl;
		return;
	}
	
	if (pOrderRecord->getStatus() != SUCCESS) {
		cout << "δ������ض�����" << endl;
		return;
	}

	Order::PrintOrders(pOrderRecord, 1);

	cout << "���������֣�";
	int rating = UI::GetNumber();
	if (rating < 0 && rating > 100) {
		cout << "����Ӧ��0-100���䣡" << endl;
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

	cout << "��Ʒ���۳ɹ���" << endl;
}

void Customer::RefundApplication()
{
	cout << "������Ҫ�˻��Ķ�����ţ�";
	int TargetOrderID = UI::GetNumber();

	Order* pOrderRecord = pDL->GetOrder(TargetOrderID);
	if (pOrderRecord == NULL || pOrderRecord->getCustomerID() != ID) {
		cout << "δ������ض�����" << endl;
		return;
	}
	pOrderRecord->RefundApplication();
}
void Customer::PrintCustomers(Customer customers[], int nCustomers)
{
	FieldPrintSetting PrintSet[] = {
									 "�˻����", 8,
									 "����", 12,
									 "�Ա�", 8,
									 "����", 10,
									 "סַ", 20,
									 "�绰", 12,
	};
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);

	const char* SexLabel[] = { "��", "Ů" };
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
		cout << "���ݴ���δ�ҵ��˻���Ϣ��" << endl;
}

void Customer::ModifyMyAccount()
{
	Customer *pTargetCustomer = this;

	if (pTargetCustomer == NULL) {
		cout << "���ݴ���δ�ҵ��˻���Ϣ��" << endl;
		return;
	}

	cout << "���޸ĵ��˻���Ϣ���£�" << endl;
	PrintCustomers(pTargetCustomer, 1);

	cout << "������������";
	cin.getline(pTargetCustomer->name, UsrNameBuffSize);

	while (true) {
		cout << "�������Ա𣺡�0-����/1-Ů�ԡ�";
		pTargetCustomer->sex = (Sex)UI::GetNumber();
		if (pTargetCustomer->sex == MALE || pTargetCustomer->sex == FEMALE)
			break;
		cout << "�Ա𲻺Ϸ�������������" << endl;
	}

	while (true) {
		cout << "����������꣺";
		pTargetCustomer->birthday.year = UI::GetNumber();
		cout << "����������£�";
		pTargetCustomer->birthday.month = UI::GetNumber();
		cout << "����������գ�";
		pTargetCustomer->birthday.day = UI::GetNumber();
		if (Utility::CheckDate(pTargetCustomer->birthday))
			break;
		cout << "���������ղ��Ϸ�������������" << endl;
	}

	cout << "�������ַ��";
	cin.getline(pTargetCustomer->address, AddressBuffSize);
	
	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	cout << "������绰��";
	cin.getline(PhoneStr, MaxPhoneDigit);
	pTargetCustomer->phone = Utility::StringToPhone(PhoneStr);

	PrintCustomers(pTargetCustomer, 1);
	cout << "��ȷ���޸�Ϊ�����˻���Ϣ������Y��ȷ�ϣ��������ȡ����";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	if (true) {
		cout << "�˻���Ϣ�޸ĳɹ���" << endl;
	} else {
		cout << "�˻���Ϣ�޸�ʧ�ܡ�" << endl;
	}
}