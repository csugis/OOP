#include <iostream>
#include <iomanip>
#include "utility.h"
#include "ui.h"
#include "DataLayer.h"
#include "CommonBusiness.h"
#include "MerchantCenter.h"

using namespace std;
Merchant::~Merchant()
{

}

void Merchant::ShowProductManageMenu()
{
	const char* ProductManageMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                 �̼�����                    *|\n"
		"          |***********************************************|\n"
		"          |*                ��Ʒ����˵�                 *|\n"
		"          |*             1. �����Ʒ                     *|\n"
		"          |*             2. ������Ʒ                     *|\n"
		"          |*             3. ɾ����Ʒ                     *|\n"
		"          |*             4. �޸���Ʒ                     *|\n"
		"          |*             0. ������һ��                   *|\n"
		"          |***********************************************|\n"
		"\n";


	while (true) {
		cout << ProductManageMenu;
		cout << "��ѡ��˵�[0-4]��";

		if (!SelectProductManageMenu())
			break;
	}
}

bool Merchant::SelectProductManageMenu()
{
	enum {
		BROWSE_ALL_PRODUCTS = 1,
		ADD_PRODUCT = 2,
		REMOVE_PRODUCT = 3,
		MODIFY_PRODUCT = 4,
		TO_MERCHANT_MENU = 0,
	};

	switch (UI::GetNumber())
	{
	case BROWSE_ALL_PRODUCTS:
		BrowseAllProducts();
		UI::pause();
		break;

	case ADD_PRODUCT:
		AddNewProduct();
		UI::pause();
		break;

	case REMOVE_PRODUCT:
		RemoveProduct();
		UI::pause();
		break;

	case MODIFY_PRODUCT:
		ModifiyProduct();
		UI::pause();
		break;

	case TO_MERCHANT_MENU:
		return false;

	default:
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}


void Merchant::ShowOrderManageMerchantMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   �̼�����                  *|\n"
		"          |***********************************************|\n"
		"          |*                 ��������˵�                *|\n"
		"          |*               1. ��ѯ���ж���               *|\n"
		"          |*               2. ��ѯ���궩��               *|\n"
		"          |*               3. ��ѯ���¶���               *|\n"
		"          |*               4. �˿����                   *|\n"
		"          |*               0. ������һ���˵�             *|\n"
		"          |***********************************************|\n"
		"\n";


	while (true) {
		cout << CustomerMenu;
		cout << "��ѡ��˵�[0-4]��";

		if (!SelectOrderManagewMerchantMenu())
			break;
	}
}

bool Merchant::SelectOrderManagewMerchantMenu()
{
	enum {
		BROWSE_ALL_ORDERS = 1,
		BROWSE_ORDER_THIS_YEAR = 2,
		BROWSE_ORDER_THIS_MONTH = 3,
		REFUND_MANAGEMENT = 4,
		TO_MERCHANT_MENU = 0,
	};

	switch (UI::GetNumber())
	{
	case BROWSE_ALL_ORDERS:
		BrowseAllOrders();
		UI::pause();
		break;

	case BROWSE_ORDER_THIS_YEAR:
		BrowseOrdersThisYear();
		UI::pause();
		break;

	case BROWSE_ORDER_THIS_MONTH:
		BrowseOrdersThisMonth();
		UI::pause();
		break;

	case REFUND_MANAGEMENT:
		refund();
		UI::pause();
		break;

	case TO_MERCHANT_MENU:
		return false;

	default:
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}

void Merchant::ShowAccountInfoMerchantMenu()
{
	const char* CustomerMenu =
		"\n"
		"\n"
		"          |***********************************************|\n"
		"          |*                   �̼�����                  *|\n"
		"          |***********************************************|\n"
		"          |*                 �˻���Ϣ�˵�                *|\n"
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

		if (!SelectAccountInfoMerchantMenu())
			break;
	}
}

bool Merchant::SelectAccountInfoMerchantMenu()
{
	enum {
		BROWSE_ACCOUNT_INFO = 1,
		MODIFY_ACCOUNT_INFO = 2,
		MODIFY_PASSWORD = 3,
		INQUIRY_BALANCE = 4,
		TO_MERCHANT_MENU = 0,
	};

	switch (UI::GetNumber()) {
	case BROWSE_ACCOUNT_INFO:
		MyAccountInfo();
		UI::pause();
		break;

	case MODIFY_ACCOUNT_INFO:
		ModifyAccountInfo();
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

	case TO_MERCHANT_MENU:
		return false;

	default:
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}

void Merchant::ShowMenu()
{
	const char* MerchantMenu =
		"\n"
		"          |***********************************************|\n"
		"          |*                 �̼�����                    *|\n"
		"          |***********************************************|\n"
		"          |*                 �� �� ��                    *|\n"
		"          |*               1. ��Ʒ����                   *|\n"
		"          |*               2. ��������                   *|\n"
		"          |*               3. �˻���Ϣ                   *|\n"
		"          |*               0. �˳�ϵͳ                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << MerchantMenu;
		cout << "��ѡ��˵�[0-3]��";

		if (!SelectMerchantMenu())
			break;
	}
}

bool Merchant::SelectMerchantMenu()
{
	enum {
		PRODUCT_MANAGEMENT = 1,
		BROWSE_ORDERS = 2,
		ACCOUNT_INFO = 3,
		EXIT = 0,
	};

	switch (UI::GetNumber())
	{
	case PRODUCT_MANAGEMENT:
		ShowProductManageMenu();
		break;

	case BROWSE_ORDERS:
		ShowOrderManageMerchantMenu();
		break;

	case ACCOUNT_INFO:
		ShowAccountInfoMerchantMenu();
		break;

	case EXIT:
		//*(pDL->GetAccount(ID)) = *((Account*)this);
		//*(pDL->GetMerchant(ID)) = *this;
		return false;

	default:
		cout << "����ָ���������������룡" << endl;
		break;
	}

	return true;
}

void Merchant::BrowseAllProducts()
{
	BrowseProducts(ID);
}

void Merchant::AddNewProduct()
{
	char name[ProdNameBuffSize];
	double price=0.0;	
	int stock=0;
	char ch;
	while (true) {
		Product::InputProductInfo(name, price, stock);
		Product product(GetNextProductID(), ID, name, price, stock);

		Product pa[1] = { product };
		Product::PrintProducts(pa, 1);

		bool confirm = false;
		while (true) {
			cout << "�Ƿ�ȷ��������Ʒ������Y��ȷ�ϣ���N��ȡ����" << endl;
			ch = UI::GetKey();
			if (ch == 'Y' || ch == 'y') {
				confirm = true;
				break;
			}
			if (ch == 'N' || ch == 'n')
				break;
		}

		ProductArray* pp = pDL->getProductList();
		if (confirm && pp!=nullptr) {
			//product.setMerchant(this);

			// ���µ���Ʒ��Ϣ�ṹ�����������vector����ProductList��β��

			pp->push_back(product);

			cout << "��Ʒ¼��ɹ���" << endl;
			Product::PrintProducts(pa, 1);
		}

		cout << "�Ƿ����¼�룿����N���˳�¼�룬�����������¼�롿" << endl;
		ch = UI::GetKey();
		if (ch == 'N' || ch == 'n')
			break;
	}
}
bool Merchant::MerchantSignIn()
{
	cout << "�������̻�����";
	cin.getline(name, UsrNameBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	while (true) {
		cout << "������绰��";
		cin.getline(PhoneStr, MaxPhoneDigit);
		if ((phone = Utility::StringToPhone(PhoneStr)) != -1)
			break;
		cout << "�绰��ʽ�������������룺" << endl;
	}

	TotalSales = 0;
	rating = 0;
	nRatings = 0;

	Merchant::PrintMerchants(this, 1);
	cout << "�Ƿ�ȷ�ϴ������̼ҡ���Y��ȷ�ϣ��������ȡ������";
	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return false;
	return true;
}
void Merchant::RemoveAllProducts()
{
	ProductArray* pProductList = pDL->getProductList();

	int nOriginalProducts = pProductList->size();
	ProductArray::const_iterator it = pProductList->begin();
	while (it != pProductList->end()) {

		if (it->getAccountID() == ID)
			it = pProductList->erase(it);
		else
			it++;
	}
}

void Merchant::RemoveProduct()
{
	cout << "������Ҫɾ������Ʒ��ţ�";
	int ProductID = UI::GetNumber();

	ProductArray* pProductList = pDL->getProductList();

	int TargetProductIndex = -1;
	int nProducts = pProductList->size();
	for (int i = 0; i < nProducts; i++) {
		const Product &CurrentProduct = (*pProductList)[i];

		if (CurrentProduct.getProductID() == ProductID &&
			CurrentProduct.getAccountID() == ID) {
			TargetProductIndex = i;
			break;
		}
	}

	if (TargetProductIndex == -1) {
		cout << "δ���ҵ�Ҫɾ������Ʒ���" << endl;
		return;
	}

	Product::PrintProducts(&((*pProductList)[TargetProductIndex]), 1);

	cout << "�Ƿ�ȷ��ɾ������Ʒ����Y��ȷ�ϣ��������ȡ������" ;
	char ch = UI::GetKey();
	if (ch == 'Y' || ch == 'y') {
		pProductList->erase(pProductList->begin()+TargetProductIndex);
		cout << "ɾ����Ʒ�ɹ���" << endl;
	}
}

void Merchant::ModifiyProduct()
{
	cout << "������Ҫ�޸ĵ���Ʒ��ţ�";
	int ProductID = UI::GetNumber();
	Product *pTargetProduct = pDL->GetProduct(ProductID);

	char name[ProdNameBuffSize];
	double price;
	int stock;
	if (pTargetProduct != NULL && pTargetProduct->getAccountID() == ID) {
		cout << "���޸���Ʒ���£�" << endl;
		Product::PrintProducts(pTargetProduct, 1);

		cout << "������������Ʒ�޸���Ϣ��" << endl;
		Product::InputProductInfo(name, price,stock);
		
		Product::PrintProducts(pTargetProduct, 1);

		cout << "�Ƿ�ȷ���޸ĸ���Ʒ����Y��ȷ�ϣ��������ȡ������";
		char ch = UI::GetKey();
		if (ch == 'Y' || ch == 'y') {
			pTargetProduct->UpdateProductInfo(name, price, stock);
			cout << "��Ʒ��Ϣ�޸ĳɹ���" << endl;
		}

	} else {
		cout << "δ���ҵ�Ҫ�޸ĵ���Ʒ���" << endl;
		return;
	}
	
}

//void Merchant::BrowseOrdersIf(bool(Merchant::*condition)(const Order &))
//{
//	OrderArray& OrderList = pDL->getOrderList();
//
//	OrderArray FoundOrderList;
//	int nOrders = OrderList.size();
//	for (int i = 0; i < nOrders; i++) {
//		const Order &CurrentOrder = OrderList[i];
//
//		if (this->condition(CurrentOrder))
//			FoundOrderList.push_back(CurrentOrder);
//	}
//
//	int nFoundOrders = FoundOrderList.size();
//	if (nFoundOrders > 0) {
//		Utility::ReverseOrders(&FoundOrderList[0], nFoundOrders);
//		Order::PrintOrders(&FoundOrderList[0], nFoundOrders);
//	} else {
//		cout << "δ��ѯ����ض�����" << endl;
//	}
//}

void Merchant::UpdateRating(int r)
{
	rating = (rating * nRatings + r) /
		(nRatings + 1);
	nRatings++;
}

bool Merchant::IsCurrentMerchant(const Order &order)
{
	return order.getMerchantID() == ID;
}

bool Merchant::IsCurrentMerchantThisYear(const Order &order)
{
	Time time;
	Utility::GetCurrentTime(time);
	
	return order.getMerchantID() == ID &&
		order.IsCurrentOrderThisYear();
}

bool Merchant::IsCurrentMerchantThisMonth(const Order &order)
{
	Time time;
	Utility::GetCurrentTime(time);

	return order.getMerchantID() == ID &&
		order.IsCurrentOrderThisMonth();
}

void Merchant::BrowseAllOrders()
{
	OrderArray* pOrderList = pDL->getOrderList();

	OrderArray FoundOrderList;
	int nOrders = pOrderList->size();
	for (int i = 0; i < nOrders; i++) {
		const Order& CurrentOrder = (*pOrderList)[i];

		if (IsCurrentMerchant(CurrentOrder))
			FoundOrderList.push_back(CurrentOrder);
	}

	int nFoundOrders = FoundOrderList.size();
	if (nFoundOrders > 0) {
		Utility::ReverseOrders(&FoundOrderList[0], nFoundOrders);
		Order::PrintOrders(&FoundOrderList[0], nFoundOrders);
	}
	else {
		cout << "δ��ѯ����ض�����" << endl;
	}
}

void Merchant::BrowseOrdersThisYear()
{
	OrderArray* pOrderList = pDL->getOrderList();

	OrderArray FoundOrderList;
	int nOrders = pOrderList->size();
	for (int i = 0; i < nOrders; i++) {
		const Order& CurrentOrder = (*pOrderList)[i];

		if (IsCurrentMerchantThisYear(CurrentOrder))
			FoundOrderList.push_back(CurrentOrder);
	}

	int nFoundOrders = FoundOrderList.size();
	if (nFoundOrders > 0) {
		Utility::ReverseOrders(&FoundOrderList[0], nFoundOrders);
		Order::PrintOrders(&FoundOrderList[0], nFoundOrders);
	}
	else {
		cout << "δ��ѯ����ض�����" << endl;
	}
}

void Merchant::BrowseOrdersThisMonth()
{
	OrderArray* pOrderList = pDL->getOrderList();

	OrderArray FoundOrderList;
	int nOrders = pOrderList->size();
	for (int i = 0; i < nOrders; i++) {
		const Order& CurrentOrder = (*pOrderList)[i];

		if (IsCurrentMerchantThisMonth(CurrentOrder))
			FoundOrderList.push_back(CurrentOrder);
	}

	int nFoundOrders = FoundOrderList.size();
	if (nFoundOrders > 0) {
		Utility::ReverseOrders(&FoundOrderList[0], nFoundOrders);
		Order::PrintOrders(&FoundOrderList[0], nFoundOrders);
	}
	else {
		cout << "δ��ѯ����ض�����" << endl;
	}
}

void Merchant::refund()
{
	cout << "������Ҫ�����˻��Ķ�����ţ�";
	int TargetOrderID = UI::GetNumber();

	Order *pOrderRecord = pDL->GetOrder(TargetOrderID);
	
	if (pOrderRecord == NULL || pOrderRecord->getMerchantID() != ID) {
		cout << "�޴˶�����" << endl;
		return;
	}

	Order::PrintOrders(pOrderRecord, 1);

	if (pOrderRecord->getStatus() != REFUND_REQUIRED) {
		cout << "δ���ֶ������˻�����" << endl;
		return;
	}
	//Merchant* pMerchant = pDL->GetMerchant(pOrderRecord->getMerchantID());
	Customer* pCustomer = pDL->GetCustomer(pOrderRecord->getCustomerID());
	Product* pProduct = pDL->GetProduct(pOrderRecord->getProductID());
	cout << "�ͻ������˿�Ƿ�ͬ���˿��Y��ͬ���˿��N���ܾ��˿��";
	char ch = UI::GetKey();
	if (ch == 'Y' || ch == 'y') {
		cout << "����������ͬ���˿";

		char password[PwdBuffSize];
		UI::GetPass(password);
		if (!CheckPassword(password)) {
			cout << "�����������" << endl;
			return;
		}

		UpdateAccountMoney(-pOrderRecord->getPrice() * pOrderRecord->getNumber());
		pCustomer->UpdateAccountMoney(pOrderRecord->getPrice() * pOrderRecord->getNumber());
		UpdateMerchantSales(-pOrderRecord->getPrice() * pOrderRecord->getNumber());

		if (pProduct != NULL) {
			pProduct->UpdateProductNSales(-pOrderRecord->getNumber());
			pProduct->UpdateProductStock(pOrderRecord->getNumber());
		}

		pOrderRecord->setStatus(REFUNDED);

		cout << "�˿�ɹ���" << endl;

		Order::PrintOrders(pOrderRecord, 1);
	}
	else {
		pOrderRecord->setStatus(REFUND_REJECTED);

		cout << "�Ѿܾ������˿�����" << endl;
	}
}

void Merchant::MyAccountInfo()
{
	BrowseMerchant(ID);
}

void Merchant::PrintMerchants(Merchant merchants[], int nMerchants)
{
	FieldPrintSetting PrintSet[] = {
									 "�˻����", 8,
									 "�̻���", 20,
									 "�绰", 12,
									 "���۶�", 12,
									 "���۴���", 8,
									 "����", 8,
	};
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);

	char buffer[32];
	string strs[nFields];
	for (int i = 0; i < nMerchants; i++) {
		const Merchant& CurrentMerchant = merchants[i];

		cout << '|';
		cout << setw(PrintSet[0].PrintWidth) << std::right
			<< CurrentMerchant.ID << '|';
		cout << setw(PrintSet[1].PrintWidth) << std::left
			<< Utility::TrimString(CurrentMerchant.name, buffer,
				PrintSet[1].PrintWidth, strs[1])
			<< '|';
		cout << setw(PrintSet[2].PrintWidth) << std::right
			<< CurrentMerchant.phone << '|';
		cout << setw(PrintSet[3].PrintWidth) << std::right
			<< setiosflags(ios::fixed) << setprecision(2) <<
			CurrentMerchant.TotalSales << '|';
		cout << setw(PrintSet[4].PrintWidth) << std::right
			<< CurrentMerchant.nRatings << '|';
		cout << setw(PrintSet[5].PrintWidth) << std::right
			<< CurrentMerchant.rating << '|';


		cout << endl;

		Utility::PrintRemaining(PrintSet, nFields, strs);
		Utility::PrintLine(PrintSet, nFields);
	}

	cout << endl;
}

void Merchant::ModifyAccountInfo()
{

	Merchant* pTargetMerchant = this;

	if (pTargetMerchant == NULL) {
		cout << "���ݴ���δ�ҵ��˻���Ϣ��" << endl;
		return;
	}

	cout << "���޸ĵ��˻���Ϣ���£�" << endl;
	PrintMerchants(pTargetMerchant, 1);

	cout << "�������޸ĺ���̻�����";
	cin.getline(pTargetMerchant->name, UsrNameBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	while (true) {
		cout << "�������޸ĺ�ĵ绰��";
		cin.getline(PhoneStr, MaxPhoneDigit);
		if ((pTargetMerchant->phone = Utility::StringToPhone(PhoneStr)) != -1)
			break;
		cout << "�绰��ʽ�������������룺" << endl;
	}
		
	cout << "��ȷ���޸�Ϊ�����˻���Ϣ������Y��ȷ�ϣ��������ȡ����";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	if (true) {
		cout << "�̼���Ϣ�޸ĳɹ���" << endl;
		PrintMerchants(pTargetMerchant, 1);
	} else {
		cout << "�̼���Ϣ�޸�ʧ�ܡ�" << endl;
	}
}
