#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int n, q;
int z, a, b;
int t[2*N];

void add(int v, int tl, int tr, int p, int d){
	if(tl == tr){
		t[v] += d;
	}
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		if(p <= tm) add(left, tl, tm, p, d);
		else add(right, tm+1, tr, p, d);
		t[v] = t[left] + t[right];
	}
}

int sum(int v, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(tl == l && tr == r) return t[v];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		return sum(left, tl, tm, l, min(tm, r)) + sum(right, tm+1, tr, max(tm+1, l), r);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> q;

	for(int i=0;i<q;i++){
		cin >> z;
		if(z == 1){ // dodaj
			cin >> a >> b;
			a--;
			add(1, 0, n-1, a, b);
		}
		if(z == 2){ // suma
			cin >> a >> b;
			a--; b--;
			cout << sum(1, 0, n-1, a, b) << "\n";
		}
	}

	return 0;
}
