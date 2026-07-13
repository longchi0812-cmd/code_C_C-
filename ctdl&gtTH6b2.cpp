#include <iostream>

using namespace std;

struct Node{
	int key;
	Node *left, *right;
	int height;
};

//tinh chieu cao cua mot nut
int height(struct Node* node)
{
	if (node == NULL)
		return 0;
	return node->height;
}

//tinh do can bang
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

//xoay trai
struct Node* leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;
	// Perform rotation
	y->left = x;
	x->right = T2;
	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	// Return new root
	return y;
}

//xoay phai
struct Node* rightRotate(struct Node *y)
{
	struct Node *x = y->left;

	struct Node *T2 = x->right;
	// Perform rotation
	x->right = y;
	y->left = T2;
	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;
	// Return new root
	return x;
}

//ham chen
struct Node* insert(struct Node* root, int key)
{
/* 1. Perform the normal BST insertion */
	if (root == NULL)
		return(new Node{key, NULL, NULL, 1});
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	else // Equal keys are not allowed in BST
		return root;
/* 2. Update height of this ancestor node */
	root->height = 1 + max(height(root->left),
	height(root->right));
/* 3. Get the balance factor of this ancestor
node to check whether this node became
unbalanced */
	int balance = getBalance(root);

// If this node becomes unbalanced, then
// there are 4 cases
// Left Left Case
	if (balance > 1 && key < root->left->key)
		return rightRotate(root);
// Right Right Case
	if (balance < -1 && key > root->right->key)
		return leftRotate(root);
// Left Right Case
	if (balance > 1 && key > root->left->key)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
// Right Left Case
	if (balance < -1 && key < root->right->key)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
/* return the (unchanged) node pointer */
	return root;
}

bool tim(Node* root, int key){
    if(root == NULL){
    	return false;
	}
    if(key == root->key){
    	return true;
	}
    else if(key < root->key){
    	return tim(root->left, key);
	}
    else{
    	return tim(root->right, key);
	}
}

int main(){
	struct Node *root = NULL;
	int n = 1000000;
	
	//Insert to tree
	for(int i = 1; i <= n; i++){
		root = insert(root, i);
	}
	cout << "Chieu cao cua cay sau khi chen: " << root->height << endl;
	
	int key = 110925;

    bool kq = tim(root, key);
    if(kq)
        cout << "Tim thay so " << key << " trong cay" << endl;
    else
        cout << "Khong tim thay so " << key << " trong cay" << endl;
}
