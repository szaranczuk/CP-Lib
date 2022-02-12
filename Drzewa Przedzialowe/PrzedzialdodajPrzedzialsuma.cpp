#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int n, q;
int z, a, b, c;
int t[2*N];
int la[2*N];

void push(int v, int tl, int tr){
	int tm = (tl+tr)/2;
	int left = v + 1;
	int right = v + (tm-tl+1)*2;
	t[left] += (tm-tl+1) * la[v];
	t[right] += (tr-tm) * la[v];
	la[left] += la[v];
	la[right] += la[v];
	la[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int d){
	if(l > r) return;
	if(tl == l && tr == r){
		t[v] += d;
		la[v] += d;
	}
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		push(v, tl, tr);
		add(left, tl, tm, l, min(r, tm), d);
		add(right, tm+1, tr, max(l, tm+1), r, d);
		t[v] = t[right] + t[left];
	}
}

int sum(int v, int tl, int tr, int l, int r){
	if(l > r) return 0;
	if(tl == l && tr == r) return t[v];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		push(v, tl, tr);
		return sum(left, tl, tm, l, min(r, tm)) + sum(right, tm+1, tr, max(l, tm+1), r);
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
			cin >> a >> b;
			a--; b--;
			cout << sum(1, 0, n-1, a, b) << "\n";
		}
	}
}