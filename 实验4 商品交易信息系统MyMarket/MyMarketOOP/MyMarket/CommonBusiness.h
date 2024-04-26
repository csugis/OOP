#ifndef _COMMON_BUSINESS_H
#define _COMMON_BUSINESS_H
#include <fstream>
#include <iomanip>
#include "utility.h"
using namespace std;

enum UserType
{
	ADMIN,
	MERCHANT,
	CUSTOMER,
};

class Account
{
	friend class DataLayer;
protected:
	int ID;
	char LoginName[UsrNameBuffSize];
	char password[PwdBuffSize];	
	UserType type;
	double money;
	DataLayer* pDL;
public:
	Account() {}
	Account(const Account& a):ID(a.ID),type(a.type),pDL(a.pDL),money(a.money)
	{
		strcpy(LoginName, a.LoginName);
		strcpy(password, a.password);
	}
	Account(int aID, const char *aLN, const char* apw, UserType at, double am)
		:ID(aID),type(at),money(am)
	{
		strcpy(LoginName, aLN);
		strcpy(password, apw);
	}
	~Account();
	int getID() const { return ID; }
	void PutAccountRecord(ofstream& ofs)
	{
		ofs << ID << ',';
		ofs << LoginName << ',';
		ofs << password << ',';
		ofs << type << ',';
		ofs << setiosflags(ios::fixed) << setprecision(2)
			<< money << endl;
	}
	void UpdateAccountMoney(double change) { money += change; }
	double GetAccountMoney() { return money; }
	UserType GetAccountType() {	return type; }
	bool CheckPassword(const char* Password);
	bool ResetPassword(const char* OldPassword,	const char* NewPassword);

	void ChangePassword();
	void InquiryBalance();
	void BrowseMerchant(int id);
	virtual void ShowMenu() {}
	virtual void MyAccountInfo() {}
	virtual void ModifyMyAccount() {}
	bool CheckAccoutName(const char* name);
	// 浏览商家编号为AccountID的所有商品，按销量从大到小显示
	void BrowseProducts(int AccountID);
	void setDataLayer(DataLayer* p) { pDL = p; }
};


#endif // _COMMON_BUSINESS_H
