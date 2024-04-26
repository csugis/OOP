#include "Product.h"
#include "ui.h"
#include <iostream>
using namespace std;
void Product::InputProductInfo(char* na, double& p, int& s)
{
	do {
		cout << "��������Ʒ���ƣ�";
		cin.getline(na, ProdNameBuffSize);
		if (strlen(na) != 0)
			break;
		cout << "��Ʒ��������������������롣" << endl;
	} while (true);
	
	do {
		cout << "��������Ʒ���ۣ�";
		p = (float)UI::GetCashValue();
		if (p >= 0.0)
			break;
		cout << "��Ʒ��������������������롣" << endl;
	} while (true);
	
	do {
		cout << "��������������";
		s = UI::GetNumber();
		if (s >= 0)
			break;
		cout << "��Ʒ�������������������롣" << endl;
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
	// �����ӡ�ı�ͷ�ṹ
	FieldPrintSetting PrintSet[] = { "��Ʒ���", 8,
									 "��Ʒ��", 24,
									 "�۸�", 8,
									 "���", 8,
									 "����", 6,
									 "���۴���", 8,
									 "����", 8,
									 "�̼ұ��", 8
	};

	// ��ӡ��ͷ
	const int nFields = sizeof(PrintSet) / sizeof(FieldPrintSetting);
	Utility::PrintTableHead(PrintSet, nFields);


	char buffer[32]; // ���ڴ洢�ַ����ضϲ���
	string strs[nFields]; // ���ڴ洢���ֶνضϺ��ʣ����ַ���
	for (int i = 0; i < nProducts; i++) {
		const Product& currentProduct = products[i];

		// ��ӡ��������
		cout << '|';
		cout << setw(PrintSet[0].PrintWidth) << std::right
			<< currentProduct.ProductID << '|';
		// ������Կ��ܻᳬ�����Χ���ַ��������ݱ���Ƚ���ضϣ����ض�ʣ�µĲ�������
		// ������ӡ
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

		// ��ӡ�ضϺ�ʣ�µĲ���
		Utility::PrintRemaining(PrintSet, nFields, strs);
		// ��ӡ������֮��ķָ���
		Utility::PrintLine(PrintSet, nFields);
	}

	cout << endl;
}
