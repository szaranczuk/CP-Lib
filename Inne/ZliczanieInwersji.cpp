#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1005

int n;
int a[N];
vector<pair<int, int>> queries;
long long ans;
int t[2*N];

void add(int v, int tl, int tr, int p){
	if(tl == tr) t[v]++;
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		if(p <= tm) add(left, tl, tm, p);
		else add(right, tm+1, tr, p);
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
		return sum(left, tl, tm, l, min(r, tm)) +
		sum(right, tm+1, tr, max(tm+1, l), r);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
		queries.push_back({a[i], i});
	}

	sort(queries.begin(), queries.end());

	for(int i=0;i<n;i++){
		ans += sum(1, 0, n-1, queries[i].second, n-1);
		add(1, 0, n-1, queries[i].second);
	}

	cout << ans;

	return 0;
}