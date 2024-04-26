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
		"          |*                 商家中心                    *|\n"
		"          |***********************************************|\n"
		"          |*                商品管理菜单                 *|\n"
		"          |*             1. 浏览商品                     *|\n"
		"          |*             2. 输入商品                     *|\n"
		"          |*             3. 删除商品                     *|\n"
		"          |*             4. 修改商品                     *|\n"
		"          |*             0. 返回上一级                   *|\n"
		"          |***********************************************|\n"
		"\n";


	while (true) {
		cout << ProductManageMenu;
		cout << "请选择菜单[0-4]：";

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
		cout << "输入指令有误，请重新输入！" << endl;
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
		"          |*                   商家中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 订单管理菜单                *|\n"
		"          |*               1. 查询所有订单               *|\n"
		"          |*               2. 查询本年订单               *|\n"
		"          |*               3. 查询本月订单               *|\n"
		"          |*               4. 退款管理                   *|\n"
		"          |*               0. 返回上一级菜单             *|\n"
		"          |***********************************************|\n"
		"\n";


	while (true) {
		cout << CustomerMenu;
		cout << "请选择菜单[0-4]：";

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
		cout << "输入指令有误，请重新输入！" << endl;
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
		"          |*                   商家中心                  *|\n"
		"          |***********************************************|\n"
		"          |*                 账户信息菜单                *|\n"
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
		cout << "输入指令有误，请重新输入！" << endl;
		break;
	}

	return true;
}

void Merchant::ShowMenu()
{
	const char* MerchantMenu =
		"\n"
		"          |***********************************************|\n"
		"          |*                 商家中心                    *|\n"
		"          |***********************************************|\n"
		"          |*                 主 菜 单                    *|\n"
		"          |*               1. 商品管理                   *|\n"
		"          |*               2. 订单管理                   *|\n"
		"          |*               3. 账户信息                   *|\n"
		"          |*               0. 退出系统                   *|\n"
		"          |***********************************************|\n"
		"\n";

	while (true) {
		cout << MerchantMenu;
		cout << "请选择菜单[0-3]：";

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
		cout << "输入指令有误，请重新输入！" << endl;
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
			cout << "是否确认输入商品？【按Y键确认，按N键取消】" << endl;
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

			// 将新的商品信息结构体变量，放在vector数组ProductList的尾部

			pp->push_back(product);

			cout << "商品录入成功！" << endl;
			Product::PrintProducts(pa, 1);
		}

		cout << "是否继续录入？【按N键退出录入，按任意键继续录入】" << endl;
		ch = UI::GetKey();
		if (ch == 'N' || ch == 'n')
			break;
	}
}
bool Merchant::MerchantSignIn()
{
	cout << "请输入商户名：";
	cin.getline(name, UsrNameBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	while (true) {
		cout << "请输入电话：";
		cin.getline(PhoneStr, MaxPhoneDigit);
		if ((phone = Utility::StringToPhone(PhoneStr)) != -1)
			break;
		cout << "电话格式错误，请重新输入：" << endl;
	}

	TotalSales = 0;
	rating = 0;
	nRatings = 0;

	Merchant::PrintMerchants(this, 1);
	cout << "是否确认创建该商家【按Y键确认，按任意键取消】：";
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
	cout << "请输入要删除的商品编号：";
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
		cout << "未能找到要删除的商品编号" << endl;
		return;
	}

	Product::PrintProducts(&((*pProductList)[TargetProductIndex]), 1);

	cout << "是否确认删除该商品【按Y键确认，按任意键取消】？" ;
	char ch = UI::GetKey();
	if (ch == 'Y' || ch == 'y') {
		pProductList->erase(pProductList->begin()+TargetProductIndex);
		cout << "删除商品成功。" << endl;
	}
}

void Merchant::ModifiyProduct()
{
	cout << "请输入要修改的商品编号：";
	int ProductID = UI::GetNumber();
	Product *pTargetProduct = pDL->GetProduct(ProductID);

	char name[ProdNameBuffSize];
	double price;
	int stock;
	if (pTargetProduct != NULL && pTargetProduct->getAccountID() == ID) {
		cout << "待修改商品如下：" << endl;
		Product::PrintProducts(pTargetProduct, 1);

		cout << "请输入如下商品修改信息：" << endl;
		Product::InputProductInfo(name, price,stock);
		
		Product::PrintProducts(pTargetProduct, 1);

		cout << "是否确认修改该商品【按Y键确认，按任意键取消】？";
		char ch = UI::GetKey();
		if (ch == 'Y' || ch == 'y') {
			pTargetProduct->UpdateProductInfo(name, price, stock);
			cout << "商品信息修改成功。" << endl;
		}

	} else {
		cout << "未能找到要修改的商品编号" << endl;
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
//		cout << "未查询到相关订单！" << endl;
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
		cout << "未查询到相关订单！" << endl;
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
		cout << "未查询到相关订单！" << endl;
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
		cout << "未查询到相关订单！" << endl;
	}
}

void Merchant::refund()
{
	cout << "请输入要处理退货的订单编号：";
	int TargetOrderID = UI::GetNumber();

	Order *pOrderRecord = pDL->GetOrder(TargetOrderID);
	
	if (pOrderRecord == NULL || pOrderRecord->getMerchantID() != ID) {
		cout << "无此订单！" << endl;
		return;
	}

	Order::PrintOrders(pOrderRecord, 1);

	if (pOrderRecord->getStatus() != REFUND_REQUIRED) {
		cout << "未发现订单的退货请求！" << endl;
		return;
	}
	//Merchant* pMerchant = pDL->GetMerchant(pOrderRecord->getMerchantID());
	Customer* pCustomer = pDL->GetCustomer(pOrderRecord->getCustomerID());
	Product* pProduct = pDL->GetProduct(pOrderRecord->getProductID());
	cout << "客户请求退款，是否同意退款【按Y键同意退款，按N键拒绝退款】？";
	char ch = UI::GetKey();
	if (ch == 'Y' || ch == 'y') {
		cout << "请输入密码同意退款：";

		char password[PwdBuffSize];
		UI::GetPass(password);
		if (!CheckPassword(password)) {
			cout << "密码输入错误！" << endl;
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

		cout << "退款成功。" << endl;

		Order::PrintOrders(pOrderRecord, 1);
	}
	else {
		pOrderRecord->setStatus(REFUND_REJECTED);

		cout << "已拒绝该项退款请求。" << endl;
	}
}

void Merchant::MyAccountInfo()
{
	BrowseMerchant(ID);
}

void Merchant::PrintMerchants(Merchant merchants[], int nMerchants)
{
	FieldPrintSetting PrintSet[] = {
									 "账户编号", 8,
									 "商户名", 20,
									 "电话", 12,
									 "销售额", 12,
									 "评价次数", 8,
									 "评分", 8,
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
		cout << "数据错误：未找到账户信息！" << endl;
		return;
	}

	cout << "待修改的账户信息如下：" << endl;
	PrintMerchants(pTargetMerchant, 1);

	cout << "请输入修改后的商户名：";
	cin.getline(pTargetMerchant->name, UsrNameBuffSize);

	const int MaxPhoneDigit = 32;
	char PhoneStr[MaxPhoneDigit];
	while (true) {
		cout << "请输入修改后的电话：";
		cin.getline(PhoneStr, MaxPhoneDigit);
		if ((pTargetMerchant->phone = Utility::StringToPhone(PhoneStr)) != -1)
			break;
		cout << "电话格式错误，请重新输入：" << endl;
	}
		
	cout << "请确认修改为以上账户信息？【按Y键确认，按任意键取消】";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;

	if (true) {
		cout << "商家信息修改成功。" << endl;
		PrintMerchants(pTargetMerchant, 1);
	} else {
		cout << "商家信息修改失败。" << endl;
	}
}
