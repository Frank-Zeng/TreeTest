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

int main()
{
	Tree* root = NULL;

	int arrays[] = {10,6,14,4,8,12,16};
	for (int i = 0; i < sizeof(arrays)/sizeof(arrays[0]); i++)
	{
		root = CreateTree(root, arrays[i]);
	}
    return 0;
}

