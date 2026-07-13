#include <iostream>

using namespace std;

struct Node{
	int coso;
	int somu;
	Node *next;
};
typedef struct Node* node;

void themdau(node &head, int co, int so){
	node newn = new Node;
	newn->coso = co;
	newn->somu = so;
	newn->next = head;
	head = newn;
}

void themcuoi(node &head, int co, int so){
	node newn = new Node;
	newn->coso = co;
	newn->somu = so;
	newn->next = NULL;
	if(head == NULL){
		head = newn;
	} else{
		node tmp = head;
		while (tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next =newn;
	}
	 
}

void in(node head){
	//cout << "The polynomial is: ";
	while(head != NULL){
		if(head->coso < 0){
			cout << "-" << abs(head->coso);
		}else{
			cout << "+" << head->coso;
		}
		cout << "x^" << head->somu;
		head = head->next;
	}
	cout << endl;
}

node daoham(node poly){
	node dtdh = NULL;
	
	while(poly != NULL){
		if(poly->somu > 0){
			poly->coso = poly->somu * poly->coso;
			poly->somu -= 1;
			themcuoi(dtdh, poly->coso, poly->somu);
		}
		poly = poly->next;
	}
	return dtdh;
}

node nhandathu(node poly1, node poly2){
	node kq = NULL;
	node head2 = poly2;
	while(poly1 != NULL){
		while(poly2 != NULL){
			node tmp = kq;
			bool vttt = false;
			 while (tmp != NULL) {
                if (tmp->somu == poly1->somu+poly2->somu) {
                    tmp->coso += poly1->coso*poly2->coso; 
                    vttt = true;
                    break;
                }
                tmp = tmp->next;
            }
            
            if (!vttt) {
                themcuoi(kq, poly1->coso*poly2->coso, poly1->somu+poly2->somu);
            }
            
			poly2 = poly2->next;
		}
		poly1 = poly1->next;
		poly2 = head2;
	}
	return kq;
}

int main(){
	Node* poly1 = NULL;
	themdau(poly1, 7, 0);
	themdau(poly1, 6, 3);
	themdau(poly1, 5, 4);
	
	Node* poly2 = NULL;
	themdau(poly2, 3, 1);
	themdau(poly2, -7, 2);
	themdau(poly2, 2, 3);
	
	cout << "Da thuc ban dau poly1: ";
    in(poly1);

    cout << "Da thuc ban dau poly2: ";
    in(poly2);

    node kq = nhandathu(poly1, poly2);
    cout << "Da thuc sau khi nhan: ";
    in(kq);

    node dtdh = daoham(poly1);
    cout << "Da thuc sau khi dao ham poly1': ";
    in(dtdh);

}
