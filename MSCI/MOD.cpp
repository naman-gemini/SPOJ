#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int N = 1000;
const int MaxH = 1000;
int A[N];
int a, b, p;



struct HashTable{
	int index[MaxH], head[MaxH], next[MaxH], sz;
	int key[MaxH];

	inline void clear() {
		sz = 0;
		memset(head, -1, sizeof(head));
	}
	inline void insert(int id, int val) {
		int x = id % MaxH;
		index[sz] = id, key[sz] = val;
		next[sz] = head[x];
		head[x] = sz++;
	}
	inline int search(int id){
		int x = id % MaxH;
		for ( int it = head[x] ; it != -1 ; it = next[it] )
			if ( index[it] == id ) return key[it];
		return -1;
	}
} hash;



inline int _M(int a){
	if (a < 0) return a + p;
	return a;
}

inline int _I(int b){
	int a = p;
	int x1 = 0, x2 = 1, q;
	while (true){
		q = a / b, a %= b;
		if (!a) return _M(x2);
		x1 -= q * x2;
		q = b / a, b %= a;
		if (!b) return _M(x1);
		x2 -= q * x1;
	}
}

int Dlog(){

	// Baby-Step ...
	int m = ceil(sqrt(p)); //??

	A[0] = 1;
	for (int i=1;i<=m;i++){
		A[i] = (A[i-1] * a) % p;
		if (A[i] == b) return i;
	}

	hash.clear();
	for (int i=0;i<m;i++)
		hash.insert(i, A[i]);


	// Giant-Step ...
	int I0 = _I(a), I;
	for (int i=1;i<m;i++){
		int j = hash.search(I);
		if (j!=-1) return i*m + j;
		else I = (I * I0) % p;
	}
	return -1;
}



int main(){
	while (cin >> a >> b >> p){
		cout << Dlog() << endl;
	}
}
