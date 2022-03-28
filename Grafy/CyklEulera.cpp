#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005
#define M 10005

int n, m;
int a, b;
vector<pair<int, int>> adj[N];
int it[N];
bool vis[M];
vector<int> eu_cycle;

void dfs(int v){
	for(;it[v]<(int)adj[v].size();it[v]++){
		int u = adj[v][it[v]].first;
		int idx = adj[v][it[v]].second;
		if(!vis[idx]){
			vis[idx] = true;
			dfs(u);
		}
	}

	eu_cycle.push_back(v);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a >> b;
		a--; b--;
		adj[a].push_back({b, i});
		adj[b].push_back({a, i});
	}

	for(int i=0;i<n;i++){
		if(adj[i].size() % 2 != 0){
			cout << "Cykl Eulera nie istnieje";
			return 0;
		}
	}

	dfs(0);

	reverse(eu_cycle.begin(), eu_cycle.end());

	for(int v : eu_cycle) cout << v+1 << " ";

	return 0;
}