#pragma once
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
struct BTNode
{
	T data;
	BTNode* lchild;
	BTNode* rchild;
};

template <class T>
class BTree
{
	BTNode<T>* root;					//根节点
	/*由后序序列post[0…n-1]和中序序列in[0…n-1]构造一棵二叉树*/
	BTNode<T>* CreateBT(T* post, T* in, int n)	//递归构造二叉树
	{
		BTNode<T>* RT = nullptr;
		T r, * p = nullptr;
		int k;
		if (n <= 0) return RT;
		r = *(post + n - 1);				//根节点值
		RT = new BTNode<T>();				//创建二叉树节点RT
		RT->data = r;
		//cout << RT->data << " ";
		for (p = in; p < in + n; p++)		//在in中查找根节点
			if (*p == r)
				break;
		k = p - in;							//k为左子树节点数
		RT->lchild = CreateBT(post, in, k);	//递归构造左子树
		RT->rchild = CreateBT(post + k, p + 1, n - k - 1);//递归构造右子树
		return RT;
	}
	void DestoryBT(BTNode<T>* b)	//递归销毁二叉树
	{
		if (b != nullptr)
		{
			DestoryBT(b->lchild);
			DestoryBT(b->rchild);
			//cout << b->data << " ";
			delete b;
		}
	}
public:
	BTree(T* post,T* in, int n)			//构造二叉树
	{
		root = CreateBT(post,in,n);
	}

	~BTree()							//析构二叉树
	{
		DestoryBT(root);
	}
	BTNode<T>* getRoot() { return root; }
	void preOrderTraverse()	//先序遍历二叉树
	{
		stack<BTNode<T>*> s;
		BTNode<T>* p = root;
		while (p != nullptr || !s.empty())
		{
			while (p != nullptr)//当指针不为空，指针指向最左端
			{
				cout << p->data << " ";
				s.push(p);
				p = p->lchild;
			}
			if (!s.empty())//当栈不为空，指针指向右孩子
			{
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
	void preOrderTraverse(BTNode<T>* b)	//递归先序遍历二叉树
	{
		if (b != nullptr)
		{
			cout << b->data << " ";
			preOrderTraverse(b->lchild);
			preOrderTraverse(b->rchild);
		}
	}
	void inOrderTraverse()	//中序遍历二叉树
	{
		inOrderTraverse(root);
	}
	void inOrderTraverse(BTNode<T>* b)	//递归中序遍历二叉树
	{
		if (b != nullptr)
		{
			inOrderTraverse(b->lchild);
			cout << b->data << " ";
			inOrderTraverse(b->rchild);
		}
	}
	void postOrderTraverse() //后序遍历二叉树
	{
		postOrderTraverse(root);
	}
	void postOrderTraverse(BTNode<T>* b) //递归后序遍历二叉树
	{
		if (b != nullptr)
		{
			postOrderTraverse(b->lchild);
			postOrderTraverse(b->rchild);
			cout << b->data << " ";
		}
	}
	void levelOrderTraverse()			//层次遍历二叉树
	{
		queue<BTNode<T>*> q;
		BTNode<T>* p = root;
		if (p == nullptr)	return;
		q.push(root);					//根节点入队
		while (!q.empty())
		{
			p = q.front();							//获取队头节点
			cout << p->data << " ";
			q.pop();								//出队一个节点
			if (p->lchild > 0) q.push(p->lchild);	//左节点入队
			if (p->rchild > 0) q.push(p->rchild);	//右节点入队
		}
	}
	void DispLeaf()									//求叶子结点
	{
		DispLeaf(root);
	}
	void DispLeaf(BTNode<T>* b)						//递归求叶子结点
	{
		if (b != nullptr)
		{
			if (b->lchild == nullptr && b->rchild == nullptr)
			{
				cout<<b->data <<" ";
			}
			DispLeaf(b->lchild);
			DispLeaf(b->rchild);
		}
	}
	/*求二叉树b中第k层的结点个数。
	其中h表示b所指的结点层次，n是引用型参数，由于求第k层的结点个数，
	在初始调用时，b为根结点指针，h为1，n赋值为0，即调用方式时n=0；
	*/
	void LNodeNum(BTNode<T>* b, int h, int k, int* n)
	{
		if (b == nullptr)
		{
			return;
		}
		else if (h == k)
		{
			if (b->data != ' ') *n +=  1;
			return;
		}
		else if (h < k)
		{
			LNodeNum(b->lchild, h + 1, k, n);//特别注意不要&n
			LNodeNum(b->rchild, h + 1, k, n);
		}
	}
};