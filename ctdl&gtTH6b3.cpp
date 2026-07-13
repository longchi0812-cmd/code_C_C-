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

//a
bool in(int x, Node *S)
{
	if (!S)
		return false;
	else if (S->key == x)
		return true;
	else if (S->key > x)
		return in(x, S->left);
	else
		return in(x, S->right);
}

//b
void print(Node *S)
{
	if (S){
		print(S->left);
		cout << S->key << " ";
		print(S->right);
	}
	//cout << endl;
}

//c
bool subset(Node* S1, Node* S2)
{
	if (!S1)
		return true;
	else
		return subset(S1->left, S2) && 
			subset(S1->right, S2) && 
			in(S1->key,S2);
}

//d
Node* intersectionSet(Node* S1, Node* S2, Node* S3)
{
	if (S1){
		if (in(S1->key, S2))
			S3 = insert(S3, S1->key);
	S3 = intersectionSet(S1->left, S2, S3);
	S3 = intersectionSet(S1->right, S2, S3);
	}
	return S3;
}

//e
//Append a set into another set
Node* append(Node* S1, Node* S2)
{
	if (S1){
		S2 = insert(S2, S1->key);
		S2 = append(S1->left, S2);
		S2 = append(S1->right, S2);
	}
	return S2;
}
//Union of two sets
Node* unionSet(Node* S1, Node*S2)
{
	Node* S3 = NULL;
	S3 = append(S1, S3);
	S3 = append(S2, S3);
	return S3;
}

//i
Node* differenceSet(Node* S1, Node* S2, Node* S3){
    if(S1){
        if(!in(S1->key, S2)){
            S3 = insert(S3, S1->key);
    	}
        S3 = differenceSet(S1->left, S2, S3);
        S3 = differenceSet(S1->right, S2, S3);
    }
    return S3;
}

//j
Node* arrToSet(int arr[], int n)
{
    Node* root = NULL;
    for(int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

//


int main()
{
	Node *S1 = NULL, *S2 = NULL, *S3 = NULL, *S3i = NULL;
	int i, n = 100;
	//Insert to S1
	for(i = 1; i <= n; i++){
		S1 = insert(S1, i);
	}
	cout << "S1: " ; print(S1); cout << endl;

	//Insert to S2
	for(i = n/2; i <= 2*n; i++){
		S2 = insert(S2, i);
	}
	cout << "S2: " ; print(S2); cout << endl;
	bool b = subset(S1, S2);
	if (b) 
		cout << "S1 is a subset of S2" << endl;
	else
		cout << "S1 is not a subset of S2" << endl;
		
	S3 = intersectionSet(S1, S2, S3);
	cout << "S3: " ; print(S3); cout << endl;
	
	//i
	S3i = differenceSet(S1, S2, S3i);
	cout << "S3i: " ; print(S3i); cout << endl;
	
	//j
	int arr[] = {5, 2, 7, 2, 9, 5};
	int nj = 6;
	Node* S = arrToSet(arr, nj);
	cout << "Set: "; print(S); cout << endl;
}
