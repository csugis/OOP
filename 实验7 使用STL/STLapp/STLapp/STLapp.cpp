// STLapp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include "BTree.h"
using namespace std;

void solve(string str, vector<string>& words);
int main()
{
    string str = "The following code solves a sentence into a string array";
    cout << str << endl;
    vector<string> words;
    solve(str, words);
    vector<string>::iterator it;
    for (it = words.begin(); it != words.end(); it++) cout << *it << endl;

    char in[] = "DGBAECF", post[] = "GDBEFCA";
    BTree<char> t(post, in, 7);
    cout << "preOrderTraverse stack: "; t.preOrderTraverse(); cout << endl;
    cout << "preOrderTraverse recurrent: "; t.preOrderTraverse(t.getRoot()); cout << endl;
    cout << "inOrderTraverse: "; t.inOrderTraverse(); cout << endl;
    cout << "postOrderTraverse: "; t.postOrderTraverse(); cout << endl;
    cout << "levelOrderTraverse: "; t.levelOrderTraverse(); cout << endl;
    cout << "DispLeaf: "; t.DispLeaf(); cout << endl;
    for (int k = 1; k <= 4; k++)
    {
        int n = 0;
        t.LNodeNum(t.getRoot(), 1, k, &n);
        cout << "LNodeNum of "<<k<<" layers: "<<n<< endl;
    }
}

void solve(string str, vector<string>& words)
{
    string w;
    int i = 0;
    int j = str.find(" ");
    while (j != -1)
    {
        w = str.substr(i, j - i);
        words.push_back(w);
        i = j + 1;
        j = str.find(" ",i);
    }
    if (i < str.length() - 1)
    {
        w = str.substr(i);
        words.push_back(w);
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
