#include<iostream>
#include"ProRandomFloatData.h"
#include <random>
#include <time.h>
using namespace std;


void ProRandomFloatData(double* a, int n)
{	
	/////////////////////////////////////////////////////////////////////////////////////
	cout << endl << endl;
	cout << "\t||===============================================================||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||-----------------------正在生成"<<n<<"个随机数！" << endl;
	//产生多个随机数
	default_random_engine s((unsigned int)time(0)); //种子
	uniform_real_distribution<double> u(0.115751172,10000.8562489);
	for (int i = 0; i < n; i++)a[i] = u(s);
	cout << "\t||------------------------生成随机数结束-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}

float ProARandomFloat(float m, float s)
{
	//产生1个随机数
	random_device rd; // Non-de terrains tic seed source
	normal_distribution<float> u(m,s);
	return u(rd);
}