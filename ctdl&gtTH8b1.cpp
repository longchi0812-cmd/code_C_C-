#include <bits/stdc++.h>

using namespace std;
#define max 100
struct Element{// yeu to
	char data;
	int priority;//su uu tien
};
struct PriorityQueue{
	Element arr[max];
	int size;
};

//a
void siftUp(PriorityQueue &q){//chuyen Max-Heap
	int i,p; 
	Element tmp;
	i = q.size-1;
	while(i > 0){
		p = (i-1)/2;
		if (q.arr[p].priority < q.arr[i].priority){//Min-Heap doi dau < thanh >
			tmp = q.arr[p];
			q.arr[p] = q.arr[i];
			q.arr[i] = tmp;
			i = p;
		}else return;
	}
}

void add(PriorityQueue &q, Element x){
	q.arr[q.size] = x;
	q.size++;
	siftUp(q);
}

//b
void siftDown(PriorityQueue &q){//chuyen Max heap
	int p = 0, i = 2*p + 1;
	while (i < q.size){
		if (i+1 < q.size && q.arr[i].priority < q.arr[i+1].priority)
			i = i + 1;
		if(q.arr[p].priority < q.arr[i].priority){
			Element tmp = q.arr[p];
			q.arr[p] = q.arr[i];
			q.arr[i] = tmp;
			p = i;
			i = 2*p + 1;
		}else return;
	}
}

Element remove(PriorityQueue &q){
	int n; Element x;
	n = q.size;
	x = q.arr[0];
	q.arr[0] = q.arr[n-1];
	q.size--;
	siftDown(q);
	return x;
}

//c
bool isEmpty(PriorityQueue q){
	if(q.size == 0){
		return true;
	}else return false;
}

//d
Element top(PriorityQueue q){
	if(isEmpty(q)){
		cout << "\nHang doi uu tien rong" << endl;
	}
	return q.arr[0];
}

int main(){
	PriorityQueue q; Element x;
	q.size = 0;
	add(q, {'A', 3});
	add(q, {'B', 4});
	add(q, {'C', 1});
	x = remove(q);
	cout << x.data << " " << x.priority << endl;
	x = remove(q);
	cout << x.data << " " << x.priority << endl;
	
	if(isEmpty(q)){
		cout << "\nHang doi uu tien rong" << endl;
	}else{
		cout << "\nHang doi uu tien khong rong" << endl;
	}
	x = top(q);
	cout << "\nPhan tu dau tien trong hang doi:";
	cout << x.data << " " << x.priority << endl;
}
