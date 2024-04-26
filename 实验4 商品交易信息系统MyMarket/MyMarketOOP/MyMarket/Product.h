#pragma once
#include <fstream>
#include "MerchantCenter.h"
using namespace std;

#define ProdNameBuffSize 128

class Product
{
	friend class DataLayer;
public:
	Product() {}
	Product(int ID, int MerchantID, char na[], double p, int s):
		ProductID(ID),AccountID(MerchantID),price(p),stock(s)
	{
		strcpy(name, na);
		rating = 100.0f;
		nRatings = 0;
		nSales = 0;
	}
	// 将商品结构体变量写为文件的一行
	void PutProductRecord(ofstream& ofs)
	{
		ofs << ProductID << ',';
		ofs << AccountID << ',';
		ofs << name << ',';
		ofs << price << ',';
		ofs << stock << ',';
		ofs << rating << ',';
		ofs << nRatings << ',';
		ofs << nSales << endl;
	}
	static void PrintProducts(Product products[], int nProduct);
	//避免在外部保存vector对象的指针
	//void setMerchant(Merchant* pm) { pMerchant = pm; }
	void UpdateRating(int rating);
	static void InputProductInfo(char* name, double& price, int& stock);
	void UpdateProductInfo(char* na, double p, int s)
	{ strcpy(name, na); price = p; stock = s;	}
	void UpdateProductNSales(int number) { nSales += number; }
	void UpdateProductStock(int number) { stock += number; }
	int getAccountID() const { return AccountID; }
	int getNSales() const { return nSales; }
	double getPrice() const { return price; }
	int getProductID() const { return ProductID; }
	int getStock() const { return stock; }
	char* getName() { return name; }
private:
	int ProductID;
	int AccountID;
	char name[ProdNameBuffSize];
	double price;
	int stock;
	float rating;
	int nRatings;
	int nSales;
};

