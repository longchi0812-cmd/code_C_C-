#include <iostream>
#include <string>
using namespace std;

struct CayTM {
    string ten;          // Tên t?p ho?c thu m?c
    int kichThuoc;       // -1 n?u là thu m?c, >=0 n?u là t?p
    CayTM *con;          // Con d?u tiên
    CayTM *em;           // Anh em k? ti?p
};

// T?o node m?i
CayTM* TaoNode(string ten, int kichThuoc) {
    CayTM *p = new CayTM;
    p->ten = ten;
    p->kichThuoc = kichThuoc;
    p->con = nullptr;
    p->em = nullptr;
    return p;
}

bool TimThuMuc(CayTM *root, string x) {
    if (root == nullptr)
        return false;

    // N?u là thu m?c và trùng tên
    if (root->kichThuoc == -1 && root->ten == x)
        return true;

    // Tìm trong cây con
    if (TimThuMuc(root->con, x))
        return true;

    // Tìm trong cây anh em
    return TimThuMuc(root->em, x);
}

int TimCapTep(CayTM *root, string x){
	if(!root) return 0;
	if(root->ten == x && root->kichThuoc != 1) return 1;
	
	CayTM *p = root->con;
	while(p){
		int h = TimCapTep(p, x);
		if(h >0) return h +1;
		p = p->em;
	}
	return 0;	
}

void printTM(CayTM *root){
	if(root){
		cout << root->ten << " " << root->kichThuoc << endl;
		printTM(root->con);
		printTM(root->em);
	}
}

int tong(CayTM *root){
	if(!root) return 0;
	
	int sum = 0;
	if(root->kichThuoc != -1){
		sum += root->kichThuoc;
	}
	
	sum += tongKichThuoc(root->con);
	sum += tongKichThuoc(root->em);
	
	return sum;
}

int timMax(CayTM *root){
	if(!root) return;
	int max = -1
	if(max < root->kichThuoc)
		max = root->kichThuoc;
	
	timMax(root->con);
	timMax(root->em);
}

int main() {
	CayTM *root = TaoNode("Root", -1);

    CayTM *taiLieu = TaoNode("TaiLieu", -1);
    CayTM *anh = TaoNode("Anh", -1);
    CayTM *readme = TaoNode("Readme.md", 5);

    root->con = taiLieu;
    taiLieu->em = anh;
    anh->em = readme;

    CayTM *hoc = TaoNode("abc.txt", 10);
    CayTM *bai = TaoNode("bai.pdf", 20);
    taiLieu->con = hoc;
    hoc->em = bai;

    CayTM *hinh = TaoNode("hinh.jpg", 15);
    anh->con = hinh;
	
	printTM(root);
	
    // a)
    if (TimThuMuc(root, "TaiLieu"))
        cout << "Co thu muc TaiLieu\n";
    else
        cout << "Khong co thu muc TaiLieu\n";
//	cout << "Tim thu muc 'TaiLieu': ";
//   cout << (TimThuMuc(root, "TaiLieu") ? "CO\n" : "KHONG\n");

    // b)
    int cap = TimCapTep(root, "Readme.md");
    cout << "Cap cua tep abc.txt: " << cap << endl;

	cout << tongKichThuoc(root);
	
    return 0;
}

