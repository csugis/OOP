#include <iostream>
#include <iomanip>

#include "DataLayer.h"
#include "ui.h"
#include "CommonBusiness.h"

using namespace std;
Account::~Account()
{
	
}

bool Account::CheckPassword(const char* pw)
{
	bool found = false;		
	if (strcmp(password, pw) == 0) {
			found = true;
		}
	return found;
}

bool Account::ResetPassword(const char* OldPassword, const char* NewPassword)
{
	bool reset = false;
	if (strcmp(password, OldPassword) == 0) {
		strcpy(password, NewPassword);
		reset = true;
	}
	return reset;
}

void Account::ChangePassword()
{
	char OldPassword[PwdBuffSize];
	char NewPassword[PwdBuffSize];
	char PasswordCopy[PwdBuffSize];

	cout << "请输入旧密码：";
	UI::GetPass(OldPassword);
	cout << "请输入新密码：";
	UI::GetPass(NewPassword);
	cout << "请再次确认新密码：";
	UI::GetPass(PasswordCopy);

	if (strcmp(NewPassword, PasswordCopy) != 0) {
		cout << "两次输入新密码不一致！" << endl;
		return;
	}

	cout << "是否确认修改密码？【按Y键确认，按任意键取消】";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;


	if (ResetPassword(OldPassword, NewPassword))
		cout << "密码修改成功。" << endl;
	else
		cout << "密码修改失败！" << endl;
}

void Account::InquiryBalance()
{
	double curMoney = GetAccountMoney();

	ios_base::fmtflags flag(cout.flags());

	cout << "当前账户金额为：";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << curMoney << "元。\n" << endl;

	cout.flags(flag);
}

void Account::BrowseMerchant(int id)
{
	Merchant *pTargetMerchant = pDL->GetMerchant(id);
	Merchant Merchants[1] = {*pTargetMerchant};


	if (pTargetMerchant != NULL)
		Merchant::PrintMerchants(Merchants, 1);
	else
		cout << "数据错误：未找到账户信息！" << endl;

}
bool Account::CheckAccoutName(const char* name)
{
	for (const char* pch = name; *pch != '\0'; pch++) {
		bool IsDigit = *pch >= '0' && *pch <= '9';
		bool IsUpperCase = *pch >= 'A' && *pch <= 'Z';
		bool IsLowerCase = *pch >= 'a' && *pch <= 'z';
		bool IsUnderline = *pch == '_';

		bool IsValid = IsDigit || IsUpperCase || IsLowerCase || IsUnderline;
		if (!IsValid)
			return false;
	}

	AccountArray* pAccountList = pDL->getAccountList();
	int nCustomers = pAccountList->size();
	for (int i = 0; i < nCustomers; i++) {
		if (strcmp((*pAccountList)[i].LoginName, name) == 0)
			return false;
	}

	return true;
}

// 浏览商家编号为AccountID的所有商品，按销量从大到小显示
void Account::BrowseProducts(int AccountID)
{
	// 读取商品列表
	ProductArray* pProductList= pDL->getProductList();

	int nProducts = pProductList->size();

	// 从商品列表中搜索出商家编号为AccountID的所有商品
	ProductArray FoundProductList;
	for (int i = 0; i < nProducts; i++) {
		const Product& CurrentProduct = (*pProductList)[i];

		if (CurrentProduct.getAccountID() == AccountID)
			FoundProductList.push_back(CurrentProduct);
	}

	int nFoundProducts = FoundProductList.size();
	if (nFoundProducts > 0) {
		// 如果搜索出的商品个数大于0，则利用冒泡算法，按销量对商品进行排序操作
		Product temp;
		for (int j = 1; j < nFoundProducts; j++) {
			for (int i = 0; i < nFoundProducts - j; i++) {
				if (FoundProductList[i].getNSales() < FoundProductList[i + 1].getNSales()) {
					temp = FoundProductList[i];
					FoundProductList[i] = FoundProductList[i + 1];
					FoundProductList[i + 1] = temp;
				}
			}
		}

		// 打印输出搜索并排序的商品
		Product::PrintProducts(&FoundProductList[0], nFoundProducts);
	}
	else {
		cout << "不存在该商家或该商家未发布商品！" << endl;
	}
}

