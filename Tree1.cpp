#include <iostream>

using namespace std;

struct TreeNode{
	int data;
	TreeNode *left, *right;
	
};

//cap phat dong node de luu gia tri can lua
TreeNode* taoRoot(int vale){
	TreeNode* p = new TreeNode;
	p->data = vale;
	//(*p).data = vale;
	p->left = NULL;
	p->right = NULL;
	
	return p;
}

//khoi tao cay 
void 

void print(TreeNode *root){
	if(root != NULL){
		cout << root->data << endl;
		print(root->left);
		print(root->right);
	}
}

int main(){
	TreeNode* root = NULL;
	
	
	print(root);
	return 0;
}
