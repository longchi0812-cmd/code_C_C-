#include <iostream>

using namespace std;

struct Person{
	string name;
	int namsinh;
};

struct BFT{
	Person data;
	BFT *left, *right;
};

//a
BFT* createNode(Person p, BFT* left, BFT* right){
	return new BFT{p, left, right};
}

BFT* createBFT(){
	BFT *n1, *n2, *n3, *n4, *n5, *n6;
	n1 = createNode({"Nguyen D", 1960}, nullptr, nullptr);
	n2 = createNode({"Nguyen B", 1930}, nullptr, n1);
	n3 = createNode({"Nguyen E", 1965}, nullptr, nullptr);
	n4 = createNode({"Nguyen F", 1970}, nullptr, nullptr);
	n5 = createNode({"Nguyen C", 1935}, n3, n4);
	n6 = createNode({"Nguyen A", 1900}, n2, n5);
	return n6;
}

//b
void printBFT(BFT* root){
	if(root != NULL){
	cout << root->data.name << " " << root->data.namsinh << endl;
	printBFT(root->left);
	printBFT(root->right);
	}
}

//f
BFT* findPerson(BFT* root, string x){
	if(!root) return nullptr;
	if(root->data.name == x) return root;
	BFT* left = findPerson(root->left, x);
	if(left) return left;
	return findPerson(root->right, x);
}

//h
int levelOfPerson(BFT* root, string name){
	if(root == nullptr) return 0;
	if(root->data.name == name) return 1;
	int h1 = levelOfPerson(root->left, name);
	if(h1 != 0){
		return h1 + 1;
	}
	int h2 = levelOfPerson(root->right, name);
	if(h2 != 0){
		return h2 + 1;
	}
}

//i
bool isDescendants(BFT* root, string x, string y){
	BFT* nodeX = findPerson(root, x);
    if(nodeX == NULL) return false; 
    BFT* nodeY = findPerson(nodeX, y);
    if(nodeY && nodeY != nodeX) return true;
    else return false;
}

//j
void printDescendants(BFT* root, string x){
	BFT* tmp = findPerson(root, x);
	if(tmp == nullptr){
		cout << "Khong tim thay" << endl;
		return;
	}
	if(tmp->left != nullptr) printBFT(tmp->left);
	if(tmp->right != nullptr) printBFT(tmp->right);
}

//k
void setPerson(BFT* root, string x, Person p){
	BFT* tmp = findPerson(root, x);
	if(tmp == nullptr){
		cout << "Khong tim thay" << endl;
		return;
	}
	tmp->data = p;	
}

//l
bool isSibling(BFT* root, string x, string y){
	if(!root) return false;
	if(root->left && root->right){
		string leftn = root->left->data.name;
		string rightn = root->right->data.name;
		if((leftn == x && rightn == y) || (leftn == y && rightn == x)){
			return true;
		}
	}
	return isSibling(root->left, x, y) || isSibling(root->right, x, y);
}

//m 
void printPersonsAtLevel(BFT* root, int k, int currLevel){
	if(!root) return;
	if(currLevel == k){
		cout << root->data.name << " " << root->data.namsinh << endl;
		return;
	}
	else{
		currLevel++;
		printPersonsAtLevel(root->left, k, currLevel);
		printPersonsAtLevel(root->right, k, currLevel);
	}
}

//n 
bool isSameBFT(BFT * root1, BFT* root2){
	if(!root1 && !root2){
		return true;
	}
	if(!root1 || !root2){
		return false;
	}
	return (root1->data.name == root2->data.name && 
			root1->data.namsinh == root2->data.namsinh && 
			isSameBFT(root1->left, root2->left) && 
			isSameBFT(root1->right, root2->right));
}

//o
bool addPreson(BFT* root, string x, Person p){
	BFT* nodeX =findPerson(root, x);
	if(!nodeX) return false;
	if(nodeX->left && nodeX->right) return false;
	BFT* nodeM = new BFT{p, nullptr, nullptr};
	if(!nodeX->left){
		nodeX->left = nodeM;
	} else{
		nodeX->right = nodeM;
	}
	return true;
}

int main(){
	
	BFT *root;
	root = createBFT();
	
	//b
	printBFT(root);
	
	//h)
	string xh = "Nguyen E";
	cout << endl << xh << " thuoc the he thu: " << levelOfPerson(root, xh) << endl;
	
	//i)
	string xi = "Nguyen A", yi = "Nguyen B";
	if(isDescendants(root, xi, yi)){
		cout << "\nNguoi ten " << yi <<" la con chau nguoi ten " << xi << endl;
	} else {
		cout << "\nKhong la con chau" << endl;
	}
	
	//j
	string xj = "Nguyen A";
	cout << "\nCon chau cua " << xj <<" la: " << endl;
	printDescendants(root, xj);
	
	//k
	Person p;
	p.name = "Nguyen BB";
	p.namsinh = 1999;
	string xk = "Nguyen B";
	cout << "\nCay sau khi thay "<< xk <<": " << endl;
	setPerson(root, xk, p);
	printBFT(root);
	
	Person p1;
	p1.name = "Nguyen B";
	p1.namsinh = 1930;
	setPerson(root, "Nguyen BB", p1);
	
	//l
	string xl = "Nguyen B", yl ="Nguyen C";
	if(isSibling(root, xl, yl)){
		cout << endl << xl << " " << yl <<" la anh em." << endl;
	} else {
		cout << "\nKhong la anh em" << endl;
	}
	
	//m
	int k = 3;
	cout << "\nNhung nguoi trong cay thuoc the he thu " << k << " la: " << endl;
	printPersonsAtLevel(root, k, 1);
	
	//n
	BFT* root1 = createBFT();
	BFT* root2 = createBFT();
	if(isSameBFT(root1, root2))
    	cout << "\nHai cay giong nhau" << endl;
	else
    	cout << "\nHai cay khac nhau" << endl;
	
	//o
	Person po;
	po.name = "Nguyen ng";
	po.namsinh = 1963;
	string xo = "Nguyen B";
	if(addPreson(root, xo, po)){
		cout << "\nCay sau khi them " << po.name << " la con " << xo << endl;
		printBFT(root);
	}else {
		cout << "\nKhong the them" << endl;
	}
	
	return 0;
}

