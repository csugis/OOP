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
	BTNode<T>* root;					//���ڵ�
	/*�ɺ�������post[0��n-1]����������in[0��n-1]����һ�ö�����*/
	BTNode<T>* CreateBT(T* post, T* in, int n)	//�ݹ鹹�������
	{
		BTNode<T>* RT = nullptr;
		T r, * p = nullptr;
		int k;
		if (n <= 0) return RT;
		r = *(post + n - 1);				//���ڵ�ֵ
		RT = new BTNode<T>();				//�����������ڵ�RT
		RT->data = r;
		//cout << RT->data << " ";
		for (p = in; p < in + n; p++)		//��in�в��Ҹ��ڵ�
			if (*p == r)
				break;
		k = p - in;							//kΪ�������ڵ���
		RT->lchild = CreateBT(post, in, k);	//�ݹ鹹��������
		RT->rchild = CreateBT(post + k, p + 1, n - k - 1);//�ݹ鹹��������
		return RT;
	}
	void DestoryBT(BTNode<T>* b)	//�ݹ����ٶ�����
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
	BTree(T* post,T* in, int n)			//���������
	{
		root = CreateBT(post,in,n);
	}

	~BTree()							//����������
	{
		DestoryBT(root);
	}
	BTNode<T>* getRoot() { return root; }
	void preOrderTraverse()	//�������������
	{
		stack<BTNode<T>*> s;
		BTNode<T>* p = root;
		while (p != nullptr || !s.empty())
		{
			while (p != nullptr)//��ָ�벻Ϊ�գ�ָ��ָ�������
			{
				cout << p->data << " ";
				s.push(p);
				p = p->lchild;
			}
			if (!s.empty())//��ջ��Ϊ�գ�ָ��ָ���Һ���
			{
				p = s.top();
				s.pop();
				p = p->rchild;
			}
		}
	}
	void preOrderTraverse(BTNode<T>* b)	//�ݹ��������������
	{
		if (b != nullptr)
		{
			cout << b->data << " ";
			preOrderTraverse(b->lchild);
			preOrderTraverse(b->rchild);
		}
	}
	void inOrderTraverse()	//�������������
	{
		inOrderTraverse(root);
	}
	void inOrderTraverse(BTNode<T>* b)	//�ݹ��������������
	{
		if (b != nullptr)
		{
			inOrderTraverse(b->lchild);
			cout << b->data << " ";
			inOrderTraverse(b->rchild);
		}
	}
	void postOrderTraverse() //�������������
	{
		postOrderTraverse(root);
	}
	void postOrderTraverse(BTNode<T>* b) //�ݹ�������������
	{
		if (b != nullptr)
		{
			postOrderTraverse(b->lchild);
			postOrderTraverse(b->rchild);
			cout << b->data << " ";
		}
	}
	void levelOrderTraverse()			//��α���������
	{
		queue<BTNode<T>*> q;
		BTNode<T>* p = root;
		if (p == nullptr)	return;
		q.push(root);					//���ڵ����
		while (!q.empty())
		{
			p = q.front();							//��ȡ��ͷ�ڵ�
			cout << p->data << " ";
			q.pop();								//����һ���ڵ�
			if (p->lchild > 0) q.push(p->lchild);	//��ڵ����
			if (p->rchild > 0) q.push(p->rchild);	//�ҽڵ����
		}
	}
	void DispLeaf()									//��Ҷ�ӽ��
	{
		DispLeaf(root);
	}
	void DispLeaf(BTNode<T>* b)						//�ݹ���Ҷ�ӽ��
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
	/*�������b�е�k��Ľ�������
	����h��ʾb��ָ�Ľ���Σ�n�������Ͳ������������k��Ľ�������
	�ڳ�ʼ����ʱ��bΪ�����ָ�룬hΪ1��n��ֵΪ0�������÷�ʽʱn=0��
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
			LNodeNum(b->lchild, h + 1, k, n);//�ر�ע�ⲻҪ&n
			LNodeNum(b->rchild, h + 1, k, n);
		}
	}
};