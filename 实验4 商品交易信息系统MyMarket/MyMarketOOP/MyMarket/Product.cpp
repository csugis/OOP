#include "Product.h"
#include "ui.h"
#include <iostream>
using namespace std;
void Product::InputProductInfo(char* na, double& p, int& s)
{
	do {
		cout << "请输入商品名称：";
		cin.getline(na, ProdNameBuffSize);
		if (strlen(na) != 0)
			break;
		cout << "商品名称输入错误，请重新输入。" << endl;
	} while (true);
	
	do {
		cout << "请输入商品单价：";
		p = (float)UI::GetCashValue();
		if (p >= 0.0)
			break;
		cout << "商品单价输入错误，请重新输入。" << endl;
	} while (true);
	
	do {
		cout << "请输入库存数量：";
		s = UI::GetNumber();
		if (s >= 0)
			break;
		cout << "商品库存输入错误，请重新输入。" << endl;
	} while (true);
	
}

void Product::UpdateRating(int r)
{
	float ur = (rating * nRatings + r)
		/ (nRatings + 1);
	rating = ur;
	nRatings++;
}

void Product::PrintProducts(Product products[], int nProducts)
{
	// 定义打印的表头结构
	FieldPrintSetting PrintSet[] = { "商品编号", 8,
									 "商品名", 24,
									 "价格", 8,
									 "库存", 8,
									 "评分", 6,
									 "评价次数", 8,
									 "销量", 8,
									 "商家编号", 8
	};

	// 打印表头
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);


	char buffer[32]; // 用于存储字符串截断部分
	string strs[nFields]; // 用于存储各字段截断后的剩余的字符串
	for (int i = 0; i < nProducts; i++) {
		const Product& currentProduct = products[i];

		// 打印各个属性
		cout << '|';
		cout << setw(PrintSet[0].PrintWidth) << std::right
			<< currentProduct.ProductID << '|';
		// 这里针对可能会超出表格范围的字符串，根据表格宽度将其截断，将截断剩下的部分留作
		// 后续打印
		cout << setw(PrintSet[1].PrintWidth) << std::left
			<< Utility::TrimString(currentProduct.name, buffer,
				PrintSet[1].PrintWidth, strs[1])
			<< '|';
		cout << setw(PrintSet[2].PrintWidth) << setiosflags(ios::fixed)
			<< std::right << setprecision(2)
			<< currentProduct.price << '|';
		cout << setw(PrintSet[3].PrintWidth) << std::right
			<< currentProduct.stock << '|';
		cout << setw(PrintSet[4].PrintWidth) << setiosflags(ios::fixed)
			<< std::right << setprecision(2)
			<< currentProduct.rating << '|';
		cout << setw(PrintSet[5].PrintWidth) << std::right
			<< currentProduct.nRatings <<
			'|';
		cout << setw(PrintSet[6].PrintWidth) << std::right
			<< currentProduct.nSales << '|';
		cout << setw(PrintSet[7].PrintWidth) << std::right
			<< currentProduct.AccountID << '|';

		cout << endl;

		// 打印截断后剩下的部分
		Utility::PrintRemaining(PrintSet, nFields, strs);
		// 打印行与行之间的分隔线
		Utility::PrintLine(PrintSet, nFields);
	}

	cout << endl;
}
