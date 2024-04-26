#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "ReadWriteFile.h"



void WriteFile(string FileName, string* a, int n)
{
	/////////////////////////////////////////////////////////////////////////////////////
	//将排序结果输出到文件
	cout << endl << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||--------------------------正在保存文件-------------------------||" << endl;
	ofstream output;
	output.open(FileName, ios::out);
	
	for (int i = 0; i < n; i++)
	{		
		output << setw(20) << i + 1 << setw(30) << a[i] << endl;
	}
	output.close();
	cout << "\t||----------------数据保存在 " << FileName << " 文件中" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
	/////////////////////////////////////////////////////////////////////////////////////	
}

