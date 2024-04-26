#ifndef _ADMIN_CENTER_H
#define _ADMIN_CENTER_H
#include "CommonBusiness.h"

class Admin : public Account
{
public:
	Admin(const Account& a):Account(a) {}
	virtual void ShowMenu();
private:	

	bool SelectAdminMenu();

	void ShowAccountManageMenu();
	bool SelectAccountManageMenu();

	void ShowChargeWithdrawMangement();
	bool SelectChargeWithdrawMenu();

	void CustomerSignIn();
	void MerchantSignIn();
	void RemoveAccount();
	void Charge();
	void WithDraw();
	void BrowseCustomerInfo();
	void BrowseMerchantInfo();
	int AddAccount(const char* name, char* password, UserType type);
	bool DeleteAccount(int ID);
	bool DeleteCustomer(int ID);
	bool DeleteMerchant(int ID);
	int GetAccountID(const char* LoginName);
};


#endif // _ADMIN_CENTER_H
