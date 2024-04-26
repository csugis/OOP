// Yanghui.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void Yanghui(int n);	//输出杨辉三角 
int main()
{
    std::cout << "Hello Yanghui World!\n";
	Yanghui(10);
}

void Yanghui(int n) {
	queue<int> q;
	q.push(1);		//首先在队列中存第一行元素1
	int s = 0;
	for (int i = 0; i <= n; i++) {
		cout << endl;	//对于每一行输出换行
		cout << setw((n - i) * 2) << " ";	//设置输出格式
		q.push(0);		//在每一行数据中间添加0
		for (int j = 1; j <= i + 2; j++) {	//对于每一行的输出i+2项元素
			int t = q.front();	//获取队首元素
			q.pop();
			q.push(s + t);	//保存两项之和		
			s = t;
			if (j != i + 2)cout << setw(4) << s;//不打印i+2项的0
		}
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
