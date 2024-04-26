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

	cout << "����������룺";
	UI::GetPass(OldPassword);
	cout << "�����������룺";
	UI::GetPass(NewPassword);
	cout << "���ٴ�ȷ�������룺";
	UI::GetPass(PasswordCopy);

	if (strcmp(NewPassword, PasswordCopy) != 0) {
		cout << "�������������벻һ�£�" << endl;
		return;
	}

	cout << "�Ƿ�ȷ���޸����룿����Y��ȷ�ϣ��������ȡ����";

	char ch = UI::GetKey();
	if (ch != 'Y' && ch != 'y')
		return;


	if (ResetPassword(OldPassword, NewPassword))
		cout << "�����޸ĳɹ���" << endl;
	else
		cout << "�����޸�ʧ�ܣ�" << endl;
}

void Account::InquiryBalance()
{
	double curMoney = GetAccountMoney();

	ios_base::fmtflags flag(cout.flags());

	cout << "��ǰ�˻����Ϊ��";
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << curMoney << "Ԫ��\n" << endl;

	cout.flags(flag);
}

void Account::BrowseMerchant(int id)
{
	Merchant *pTargetMerchant = pDL->GetMerchant(id);
	Merchant Merchants[1] = {*pTargetMerchant};


	if (pTargetMerchant != NULL)
		Merchant::PrintMerchants(Merchants, 1);
	else
		cout << "���ݴ���δ�ҵ��˻���Ϣ��" << endl;

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

// ����̼ұ��ΪAccountID��������Ʒ���������Ӵ�С��ʾ
void Account::BrowseProducts(int AccountID)
{
	// ��ȡ��Ʒ�б�
	ProductArray* pProductList= pDL->getProductList();

	int nProducts = pProductList->size();

	// ����Ʒ�б����������̼ұ��ΪAccountID��������Ʒ
	ProductArray FoundProductList;
	for (int i = 0; i < nProducts; i++) {
		const Product& CurrentProduct = (*pProductList)[i];

		if (CurrentProduct.getAccountID() == AccountID)
			FoundProductList.push_back(CurrentProduct);
	}

	int nFoundProducts = FoundProductList.size();
	if (nFoundProducts > 0) {
		// �������������Ʒ��������0��������ð���㷨������������Ʒ�����������
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

		// ��ӡ����������������Ʒ
		Product::PrintProducts(&FoundProductList[0], nFoundProducts);
	}
	else {
		cout << "�����ڸ��̼һ���̼�δ������Ʒ��" << endl;
	}
}

