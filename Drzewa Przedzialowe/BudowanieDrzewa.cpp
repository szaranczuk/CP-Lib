#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int n;
int a[N];
int t[2*N];

void build(int v, int tl, int tr){
	if(tl == tr) t[v] = a[tl];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		build(left, tl, tm);
		build(right, tm+1, tr);
		t[v] = t[left] + t[right]; // operacja laczenia wezlow jest do zmiany
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	build(1, 0, n-1);

	return 0;
}