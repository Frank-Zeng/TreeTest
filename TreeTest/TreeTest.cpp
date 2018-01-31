// TreeTest.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdlib.h>
#include<iostream>
#include<stack>

using namespace std;

struct Tree
{
	Tree* left;
	Tree* right;
	int value;
};

Tree* CreateTree(Tree* root, int node)
{
	Tree* newNode = new Tree;
	newNode->value = node;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{
		root = newNode;
	}
	else
	{
		Tree* parent = root;
		while (parent != NULL)
		{
			if (parent->value < node)
			{
				if (parent->right != NULL)
				{
					parent = parent->right;
				}
				else 
				{
					break;
				}
			}
			else
			{
				if (parent->left != NULL)
				{
					parent = parent->left;
				}
				else
				{
					break;
				}
			}
		}

		if (parent->value < node)
		{
			parent->right = newNode;
		}
		else
		{
			parent->left = newNode;
		}
	}

	return root;
}

/*前序递归遍历*/
void PreOrder(Tree* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->value << endl;
	PreOrder(root->left);
	PreOrder(root->right);
}

/*中序递归遍历*/
void InOrder(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrder(root->left);
	cout << root->value << endl;
	InOrder(root->right);
}

/*后序递归遍历*/
void PostOrder(Tree* root)
{
	if (root == NULL)
	{
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->value << endl;
}

int main()
{
	Tree* root = NULL;

	int arrays[] = {10,6,14,4,8,12,16};
	for (int i = 0; i < sizeof(arrays)/sizeof(arrays[0]); i++)
	{
		root = CreateTree(root, arrays[i]);
	}
	cout << "PreOrder" << endl;
	PreOrder(root);
	cout << "InOrder" << endl;
	InOrder(root);
	cout << "PostOrder" << endl;
	PostOrder(root);
    return 0;
}

