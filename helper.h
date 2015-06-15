#ifndef __HELPER_H__
#define __HELPER_H__

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

struct BSTNode{
	int val;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int v):val(v), left(NULL), right(NULL){}
};

struct SLLNode{
	int val;
	SLLNode *next;
	SLLNode(int v):val(v), next(NULL){}
};

struct DLLNode{
	int val;
	DLLNode *prev;
	DLLNode *next;
	DLLNode(int v):val(v), prev(NULL), next(NULL){}
};


void PrintDLL(DLLNode *root){
	if(root == NULL){
		cout<<"[]"<<endl;
	}
	DLLNode *cur = root;
	cout<<"[";
	while(cur != NULL){
		cout<<cur->val<<" ";
		cur = cur->next;
	}
	cout<<"]"<<endl;
}

#endif //__HELPER_H__