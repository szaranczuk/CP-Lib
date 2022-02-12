#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000005
#define N 1005

int n, q;
int z, a, b;
int t[2*N];

void add(int v, int tl, int tr, int p, int d){
	if(tl == tr) t[v] += d;
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		if(p <= tm) add(left, tl, tm, p, d);
		else add(right, tm+1, tr, p, d);
		t[v] = max(t[left], t[right]);
	}
}

int maxi(int v, int tl, int tr, int l, int r){
	if(l > r) return -INF;
	if(tl == l && tr == r) return t[v];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v = (tm-tl+1)*2;
		return max(maxi(left, tl, tm, l, min(r, tm)), maxi(right, tm+1, tr, max(l, tm+1), r));
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
		if(z == 2){ // max
			cout << maxi(1, 0, n-1, a, b) << "\n";
		}
	}

	return 0;
}