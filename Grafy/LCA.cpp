#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1000000005
#define N 1005

int n, q;
int a, b;
vector<int> adj[N];
vector<int> eu;
int tim;
int tin[N];
int t[4*N];

void dfs(int v, int p){
	tin[v] = tim++;
	eu.push_back(v);

	for(int u : adj[v]){
		if(u == p) continue;
		dfs(u, v);
		tim++;
		eu.push_back(v);
	}
}

inline int higher(int a, int b){
	if(a == -1) return b;
	if(b == -1) return a;
	return tin[a] < tin[b] ? a : b;
}

void build(int v, int tl, int tr){
	if(tl == tr) t[v] = eu[tl];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		build(left, tl, tm);
		build(right, tm+1, tr);
		t[v] = higher(t[left], t[right]);
	}
}

int mini(int v, int tl, int tr, int l, int r){
	if(l > r) return -1;
	if(tl == l && tr == r) return t[v];
	else{
		int tm = (tl+tr)/2;
		int left = v + 1;
		int right = v + (tm-tl+1)*2;
		int a = mini(left, tl, tm, l, min(r, tm));
		int b = mini(right, tm+1, tr, max(l, tm+1), r);

		return higher(a, b);
	}
}

int lca(int a, int b){
	if(tin[a] > tin[b]) swap(a, b);
	return mini(1, 0, eu.size()-1, tin[a], tin[b]);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);

	build(1, 0, eu.size()-1);

	cin >> q;

	for(int i=0;i<q;i++){
		cin >> a >> b;
		a--; b--;
		cout << lca(a, b)+1 << "\n";
	}

	return 0;
}