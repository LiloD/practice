#include "helper.h"

vector<vector<int>> PrintAllPaths(BSTNode *root, int val);
void dfs(BSTNode* node, int val, int sum, vector<int> &path, vector<vector<int>> &ret);

vector<vector<int>> PrintAllPaths(BSTNode *root, int val){
	vector<int> path;
	vector<vector<int>> ret;
	if(root == NULL)
		return ret;
	dfs(root, val, 0, path, ret);
	return ret;
}

void dfs(BSTNode* node, int val, int sum, vector<int> &path, vector<vector<int>> &ret){
	if(node == 0)
		return;
	
	sum += node->val;
	path.push_back(node->val);
	if(sum == val){
		ret.push_back(path);
		path.pop_back();
		return;
	}

	if(node->left)
		dfs(node->left, val, sum, path, ret);

	if(node->right)
		dfs(node->right, val, sum, path, ret);

	path.pop_back();
}

int main(){
	//test
	BSTNode n1(4);
	BSTNode n2(5);
	BSTNode n3(7);
	BSTNode n4(10);
	BSTNode n5(12);

	n4.left = &n2;
	n4.right = &n5;
	n2.right = &n3;
	n2.left = &n1;

	auto ret = PrintAllPaths(&n4, 22);
	for(auto v : ret){
		PrintVector(v);
	}
	return 0;
}