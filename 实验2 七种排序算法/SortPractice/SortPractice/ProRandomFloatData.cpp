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
	cout << "\t||-----------------------��������"<<n<<"���������" << endl;
	//������������
	default_random_engine s((unsigned int)time(0)); //����
	uniform_real_distribution<double> u(0.115751172,10000.8562489);
	for (int i = 0; i < n; i++)a[i] = u(s);
	cout << "\t||------------------------�������������-------------------------||" << endl;
	cout << "\t||---------------------------------------------------------------||" << endl;
	cout << "\t||===============================================================||" << endl;
}

float ProARandomFloat(float m, float s)
{
	//����1�������
	random_device rd; // Non-de terrains tic seed source
	normal_distribution<float> u(m,s);
	return u(rd);
}