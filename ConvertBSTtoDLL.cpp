#include "helper.h"

BSTNode* ConvertBSTtoDLL(BSTNode *root);
void convert(BSTNode *node, BSTNode* &cur);

BSTNode* ConvertBSTtoDLL(BSTNode *root){
	//check corner case
	if(root == NULL)
		return NULL;

	//create dumpy header
	BSTNode dump(-1);
	BSTNode *cur = &dump;
	convert(root, cur);
	return dump.right;
}

//cur constantly point to the tail of double linked list
//left === prev && right === next
void convert(BSTNode *node, BSTNode* &cur){
	if(node == NULL)
		return;
	//go left
	convert(node->left, cur);

	//change pointer
	cur->right = node;
	node->left = cur;
	cur = node;

	//go right
	convert(node->right, cur);
}

int main(){
	//test
	BSTNode n1(5);
	BSTNode n2(1);
	BSTNode n3(7);
	BSTNode n4(4);
	n1.right = &n3;
	n1.left = &n2;
	n2.right = &n4;

	auto r = ConvertBSTtoDLL(&n1);
	while(r != NULL){
		cout<<r->val<<endl;
		r = r->right;
	}
}