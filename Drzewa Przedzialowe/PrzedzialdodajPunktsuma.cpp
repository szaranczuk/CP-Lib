#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int n, q;
int z, a, b, c;
int t[2*N];

void add(int v, int tl, int tr, int l, int r, int d){
	if(l > r) return;
	if(tl == l && tr == r) t[v] += d;
	else{
		t[v] += d;
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		add(left, tl, tm, l, min(tm, r), d);
		add(right, tm+1, tr, max(tm+1, l), r, d);
	}
}

int sum(int v, int tl, int tr, int p){
	if(tl == tr) return t[v];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		if(p <= tm) return t[v] + sum(left, tl, tm, p);
		else return t[v] + sum(right, tm+1, tr, p);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> q;

	for(int i=0;i<q;i++){
		cin >> z;
		if(z == 1){ // dodaj
			cin >> a >> b >> c;
			a--; b--;
			add(1, 0, n-1, a, b, c);
		}
		if(z == 2){ // suma
			cin >> a;
			a--;
			cout << sum(1, 0, n-1, a) << "\n";
		}
	}

	return 0;
}