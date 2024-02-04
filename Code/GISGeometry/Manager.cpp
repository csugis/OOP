// Manager.cpp: implementation of the CManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Manager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//##ModelId=4918445C00B0
CManager::CManager()
{

}


//从文件中读取一个图层
//##ModelId=4918445C00D1
void CManager::OpenMap(const char* szFileName)
{
	ifstream infile(szFileName,ios::in);
	CLayer *layer = new CLayer;
	layer->GetFromFile(infile);
	infile.close();
	InsertLayers(layer);
}
//保存一个图层到文件中
//##ModelId=4918445C00D3
void CManager::SaveMap(int index, const char* szFileName)
{
	if(index>=0&&index<GetLayerNum())
	{
		ofstream outfile(szFileName,ios::out);
		GetLayer(index)->PutToFile(outfile);
		outfile.close();
	}
}

ifstream& operator >> (ifstream& infile, ColorStruct& clr)
{
	infile>>clr.r>>clr.g>>clr.b;
	return infile;
}
ofstream& operator << (ofstream& outfile, const ColorStruct& clr)
{
	outfile<<clr.r<<" "<<clr.g<<" "<<clr.b<<endl;
	return outfile;
}

//从文件中读取一个图层
//##ModelId=4918445C00F0
void CManager::OpenClrTable(const char* szFileName)
{
	ifstream infile(szFileName,ios::in);
	ColorStruct clr;
	while(infile>>clr)
		InsertColors(clr);
	infile.close();
}
//保存一个图层到文件中
//##ModelId=4918445C00F2
void CManager::SaveClrTable(const char* szFileName)
{
	ofstream outfile(szFileName,ios::out);
	for(int i=0; i<GetColorNum(); i++)
		outfile<<GetColor(i);
	outfile.close();
}

void writeclr(ofstream &outfile, const ColorStruct* pClrs,long num)
{
	outfile.seekp(0,ios::beg);
	outfile.write((char*)&num,sizeof(long));
	outfile.write((char*)pClrs,sizeof(ColorStruct)*num);
}

void writeclr(ofstream &outfile, const ColorStruct& clr, long no)
{
	outfile.seekp(sizeof(long),ios::beg);
	outfile.seekp(sizeof(ColorStruct)*(no-1),ios::cur);
	outfile.write((char*)&clr,sizeof(ColorStruct));
}

void readclr(ifstream &infile,long& num)
{
	infile.seekg(0,ios::beg);
	infile.read((char*)&num,sizeof(long));
}

void readclr(ifstream &infile,ColorStruct* pClrs)
{
	long num = 0;
	infile.seekg(0,ios::beg);
	infile.read((char*)&num,sizeof(long));
	infile.read((char*)pClrs,sizeof(ColorStruct)*num);
}

void readclr(ifstream &infile,ColorStruct& clr,long no)
{
	infile.seekg(sizeof(long),ios::beg);
	infile.seekg(sizeof(ColorStruct)*(no-1),ios::beg);
	infile.read((char*)&clr,sizeof(ColorStruct));		
}

void insertclr(fstream &file,long no,const ColorStruct* pClrs,long num)
{
	long cnt=0;
	file.seekg(0,ios::beg);
	file.read((char*)&cnt,sizeof(long));
	file.seekg(sizeof(ColorStruct)*(no-1),ios::cur);
	ColorStruct *ptr = new ColorStruct[cnt-no+1];
	file.read((char*)ptr,sizeof(ColorStruct)*(cnt-no+1));
	file.seekp(-sizeof(ColorStruct)*(cnt-no+1),ios::end);
	file.write((char*)pClrs,sizeof(ColorStruct)*num);
	file.write((char*)ptr,sizeof(ColorStruct)*(cnt-no+1));
	delete [] ptr;
	file.seekp(0,ios::beg);
	cnt+=num;
	file.write((char*)&cnt,sizeof(long));
}
