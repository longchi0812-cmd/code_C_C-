#include <iostream>

using namespace std;

struct Node{
	string id;
	string ten;
	float dtb;
	Node* next;
};

typedef struct Node* node;

// Node* head = NULL; 1 con tro tro den phan tu dau tiên cua danh sách — goi là head.
void nhapSV(node &head){
	node sv = new Node;// tao node moi
	cout << "Nhap thong tin sinh vien: \n";
	cout << "Nhap ID: "; cin >> sv->id;
	cout << "Nhap ten: "; cin.ignore();
	getline(cin, sv->ten);
	cout << "Nhap dtb: "; cin >> sv->dtb;
	
	sv->next = head;
	head = sv;
}

void inSV(node head){
	while(head != NULL){
		cout << "-------------------------------\n";
		cout << "ID: " << head->id << endl;
		cout << "Ten: " << head->ten << endl;
		cout << "DTB: " << head->dtb << endl;
		cout << "-------------------------------\n";
		head = head->next;
	}
}

int dem(node head){
	int dem = 0; 
	while(head != NULL){
		dem++;
		head = head->next;
	}
	return dem;
}

void themcuoi(node &head){
	node sv = new Node;
	cout << "\nNhap thong tin sinh vien: \n";
	cout << "Nhap ID: "; cin >> sv->id;
	cout << "Nhap ten: "; cin.ignore();
	getline(cin, sv->ten);
	cout << "Nhap dtb: "; cin >> sv->dtb;
	
	sv->next = NULL;
	if(head == NULL){
		head = sv;
	}else{
		node tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = sv;
	}
}

node svGioi(node head){
	node svg = NULL;
	while(head != NULL){
		if(head->dtb >= 8){
			node tmp = new Node;
			tmp->id = head->id;
			tmp->ten = head->ten;
			tmp->dtb = head->dtb;
			
			tmp->next = svg;
			svg = tmp;
		}
		head = head->next;
	}
	return svg;
}

node xoaSVTT(node &head, string name){
	if(head == NULL) return head;
	if(head->ten == name){
		node tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}else{
		node p = head;
		node q = head->next;
		while(q != NULL){
			if(q->ten == name){
				p->next = q->next;
				delete q;
				break;
			}else{
				p = q;
				q = q->next;
			}
		}
	}
	return head;
}

void themvtk(node &head, int k){
    node sv = new Node;
    cout << "Nhap thong tin sinh vien moi:\n";
    cout << "Nhap ID: "; cin >> sv->id;
    cout << "Nhap ten: "; cin.ignore();
    getline(cin, sv->ten);
    cout << "Nhap dtb: "; cin >> sv->dtb;
    sv->next = NULL;

    if (head == NULL || k == 0){
        sv->next = head;
        head = sv;
        return;
    }
    
    node p = head;
    int dem = 0;
    while (p->next != NULL && dem < k - 1){
        p = p->next;
        dem++;
    }
    sv->next = p->next;
    p->next = sv;
}

node xoaVTk(node &head, int k){
	if(head == NULL) return head;
	if(k == 0){
		node tmp = head;
		head = head->next;
		delete tmp;
		return head;
	} 
	 node p = head;
    int dem = 0;

    while (p != NULL && dem < k - 1) {
        p = p->next;
        dem++;
    }

    if (p == NULL || p->next == NULL) {
        cout << "Vi tri khong hop le!\n";
        return head;
    }
    node q = p->next;
    p->next = q->next;
    delete q;
}

void chenSauTen(node &l1, node l2, string t) {
    if (l1 == NULL) {
        l1 = l2;
        return;
    }
    node p = l1;
    while (p != NULL && p->ten != t) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Khong tim thay sinh vien co ten: " << t << endl;
        return;
    }
    node tail2 = l2;
    while (tail2 != NULL && tail2->next != NULL) {
        tail2 = tail2->next;
    }
    tail2->next = p->next;
    p->next = l2;
}
 
node taoNode(string id, string ten, float dtb) {
    node sv = new Node();
    sv->id = id;
    sv->ten = ten;
    sv->dtb = dtb;
    sv->next = NULL;
    return sv;
}

void taoDanhSachMau(node &head) {
    head = taoNode("SV01", "An", 8.5);
    head->next = taoNode("SV02", "Binh", 7.0);
    head->next->next = taoNode("SV03", "Chi", 9.0);
}

int main(){
	Node* sv = NULL;
//	nhapSV(sv);
//	nhapSV(sv);
//	nhapSV(sv);
	taoDanhSachMau(sv);
	inSV(sv);
	
	//Cau a
	cout << "So luong sinh vien: " << dem(sv);
	
	//Cau b
	themcuoi(sv);
	inSV(sv);
	
	//Cau c
	cout << "\nDanh sach svg:\n";
	inSV(svGioi(sv));
	
	//Cau d
	cout << "\nDanh sach sau khi xoa:\n";
	inSV(xoaSVTT(sv, "Binh"));
	
	//Cau e
	themvtk(sv, 1);
	cout << "\nDanh sach sau khi them:\n";
	inSV(sv);
	
	//Cau f
	cout << "\nDanh sach sau khi xoa:\n";
	inSV(xoaVTk(sv, 1));
}
