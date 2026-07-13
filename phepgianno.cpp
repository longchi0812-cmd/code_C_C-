#include <iostream>
using namespace std;

int main(){
	int m, n, k;
	cin >> m >> n >> k;
	
	int x[100][100];
	
	int y[100][100];
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> x[i][j];
			y[i][j] = x[i][j];
		}
	}
	
	for(int s = 0; s < k; s++){
		int tam[100][100];
		for( int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				tam[i][j] = y[i][j];
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(y[i][j] == 1){
					if(i > 0) tam[i-1][j] = 1;
					if(i < m-1) tam[i+1][j] = 1;
					if(j > 0) tam[i][j-1] = 1;
					if(j < n-1) tam[i][j+1] = 1;
				}
			}
		}
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				y[i][j] = tam[i][j];
			}
		}
	}
	for(int i = 0; i< m; i++){
		for(int j = 0; j < n; j++){
			cout << y[i][j] << " ";
		}
		cout << endl;
	}
}
