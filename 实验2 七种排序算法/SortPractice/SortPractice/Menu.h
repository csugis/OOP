#pragma once
#include<string>
using namespace std;
#include "Student.h"

//��ʾ������
void ProgramMainWindow();
//�����������
void ProgramManipWindow();
//ѧ�������������
void ProgramStudentManipWindow();
//ѡ���ȡ���ݵķ���
void GetDataMethod(int&);

//����������ĸ���
void InputRandomNum(int& n);
//���뱣����������ļ���
void InputRandomFileName(string& str);
//�������������ļ���
void InputSortResultFileName(string& str);
//ѡ�����򷽷�
void SelectSortMethod(int&);
//ѡ�������ֶ�
void SelectSortField(SortFld&);
//��������ķ�ʽ(�������)
void SetSortMode(char& SortMode);
//�������������㷨
void AllSortMethod(string FileName, string* ra,int rn,char SortMode);
