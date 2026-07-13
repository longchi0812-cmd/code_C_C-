#include <bits/stdc++.h>

using namespace std;

struct Person{
	string name;
	int namsinh;
};

struct FT{
	Person data;
	FT *child, *sibling;// cau truc de quy
};

//taoNode
FT* createNode(Person p, FT* child, FT* sibling)
{
	return new FT{p, child, sibling};
}

//taoCay
FT* createFT(){
	FT *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	
	n1 = createNode({"Nguyen F", 1965}, nullptr, nullptr);
	n2 = createNode({"Nguyen E", 1960}, nullptr, n1);
	n3 = createNode({"Nguyen D", 1955}, nullptr, n2);
	n4 = createNode({"Nguyen H", 1970}, nullptr, nullptr);
	n5 = createNode({"Nguyen G", 1965}, nullptr, n4);
	n6 = createNode({"Nguyen C", 1935}, n5, nullptr);
	n7 = createNode({"Nguyen B", 1930}, n3, n6);
	n8 = createNode({"Nguyen A", 1900}, n7, nullptr);
	return n8;
}

//in
void printFT(FT* root){
	if(root){
		cout << root->data.name << " " << root->data.namsinh << endl;
		printFT(root->child);
		printFT(root->sibling);
	}
}

//a dem so nguoi trong cay
int demnguoi(FT* root){
	if(!root){
		return 0;
	}else{
		int dem = 1;/*khai bao con tro p kieu gia tri FT va gan bang root->child*/
		FT *p = root->child;/*Con tr? p tr? d?n con d?u tiên c?a root. Chúng ta s? duy?t t?t c? các con thông qua sibling.*/
		while(p){
			dem = dem + demnguoi(p);
			p = p->sibling;/*di den node tiep theo*/
		}
		return dem;
	}
}

//b tinh so the he
int height(FT* root){
	if(!root){
		return 0;
	}else{
		int h, max = 0;
		FT *p = root->child;
		while(p){
			h = height(p);
			if(h > max) max = h;
			p = p->sibling;
		}
		return max + 1;
	}
}

//c tim nguoi ten x
FT* search(FT *root, string name){
	FT *p, *result; 
	if(!root) return nullptr;
	else
		if(root->data.name == name)
			return root;//tra ve root
		else{
			p = root->child;
			while(p){
				result = search(p, name);
				if(result)
					return result;
				else
					p = p->sibling;
			}
			return nullptr;
	}
}

//d kiem tra y co phai la con x
bool isParent(FT* root, string x, string y){
	FT *r;
	r = search(root, x);
	if (!r) return false;
	else{
		FT *p = r->child;
		while (p){
			if (p->data.name == y) return true;
			else p = p->sibling;
		}
		return false;
	}
}

//e tinh the he x
int level(FT *root, string x){
	if(!root) return 0;
	else{
		if(root->data.name == x)
			return 1;
		else{
			FT *p = root->child;
			while(p){
				int h = level(p, x);
				if(h > 0) return h+1;
				else p = p->sibling;
			}
		}
	}
}

//f liet ke con cua x
void printChildren(FT *root, string x){
	if(!root) return;
	FT *r = search(root, x);
	if(r){
		FT *p = r->child;
		while (p != nullptr){
			cout << p->data.name << endl;
			p = p->sibling;
		}	
	}
}

//g liet ke nhung nguoi thuoc the he thu k
void printByLevel(FT* root, int k){
    if(!root) return;
    if(k == 1){
        cout << root->data.name << " " << root->data.namsinh << endl;
        return;
    }
    FT* p = root->child;
    while(p){
        printByLevel(p, k - 1);
        p = p->sibling;
    }
}

//h cho biet x va y co phai anh em khong
bool isSibling(FT* root, string x, string y){
    if(!root) return false;
    FT* p = root->child;
    bool f1 = false, f2 = false;
    while(p){
        if(p->data.name == x) f1 = true;
        if(p->data.name == y) f2 = true;
        if(f1 && f2) return true;
        p = p->sibling;
    }
    p = root->child;
    while(p){
        if(isSibling(p, x, y)) return true;
        p = p->sibling;
    }
}

//i them mot q la con nguoi x
void insertChild(FT* root, Person q, string x){
	FT* r = search(root, x);
	if(r != nullptr){
		FT* newNode = createNode(q, nullptr, nullptr);
		FT* p1 = nullptr, *p = r->child;
		while (p!=nullptr && p->data.namsinh < q.namsinh){
			p1 = p; p = p->sibling;
		}
		if (p1 == nullptr){ 
			newNode->sibling = p->child;
			p->child = newNode;
		}else{
			newNode->sibling = p;
			p1->sibling = newNode;
		}
	}
}

int degree(FT* root)
{
    if(!root) return 0;

    int cnt = 0;
    FT* p = root->child;
    while(p)
    {
        cnt++;
        p = p->sibling;
    }

    int best = cnt;

    p = root->child;
    while(p)
    {
        best = max(best, degree(p));
        p = p->sibling;
    }
    return best;
}

int main(){
	FT *root;
	root = createFT();
	
	printFT(root);
	
	//a
	cout << "\nSo nguoi trong cay la: " << demnguoi(root) << endl;
	
	//b
	cout << "\nSo the he trong cay: " << height(root) << endl;
	
	//c
	FT *kq = search(root, "Nguyen H");
	if(kq){
		cout << "\nTen:" << kq->data.name << "\tNam sinh:" << kq->data.namsinh << endl;
	}else{
		cout << "\nKhong tim thay!." << endl;
	}
	
	//d
	string xd = "Nguyen B", yd = "Nguyen D";
	cout << endl;
	if(isParent(root, xd, yd)){
		cout << xd << " la cha cua " << yd << endl;
	}else{
		cout << xd << " khong la cha cua " << yd << endl;
	}
	
	//e
	string xe = "Nguyen E";
	cout << "\nThe he " << xe <<" trong cay la: " << level(root, xe) << endl;
	
	//f
	string xf = "Nguyen B";
	cout << "\nCon cua " << xf << ":"<< endl;
	printChildren(root, xf);
	
	//g
	int kg = 2;
	cout << "\nNhung nguoi thuoc the he thu " << kg << " :" << endl;
	printByLevel(root, kg);
	
	//h
	string xh = "Nguyen B", yh = "Nguyen D";
	if(isSibling(root, xh, yh)){
		cout << endl << xh << " " << yh << " la anh em" << endl;
	}else{
		cout << endl << xh << " " << yh << " khong la anh em" << endl;
	}
	
	//i
	Person q;
	q.name = "Nguyen Bb";
	q.namsinh = 1955;
	cout << "\nThem con moi cho Nguyen B: ";
    insertChild(root, q, "Nguyen B");
	printFT(root);
	
	//
	cout << "\nBac cua cay: " << degree(root) << endl;
}
