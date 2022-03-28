#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005
#define M 10005

int n, m;
int a, b;
vector<pair<int, int>> adj[N];
bool vis[N];
int tim;
int tin[N];
int low[N];
int is_bridge[M];

void dfs(int v, int p){
	vis[v] = true;
	low[v] = tin[v] = tim++;

	for(auto e : adj[v]){
		int u = e.first;
		int idx = e.second;
		if(u == p) continue;
		if(!vis[u]){
			dfs(u, v);
			low[v] = min(low[v], low[u]);
		}
		else{
			low[v] = min(low[v], tin[u]);
		}
		if(low[u] > tin[v]) is_bridge[idx] = true;
	}
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

	dfs(0, -1);

	for(int i=0;i<m;i++){
		cout << i+1 << ": " << is_bridge[i] << "\n";
	}

	return 0;
}