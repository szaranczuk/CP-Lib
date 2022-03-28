#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
bool vis[N];
int tim;
int tin[N];
int low[N];
bool is_art[N];

void dfs(int v, int p){
	vis[v] = true;
	low[v] = tin[v] = tim++;
	int children = 0;

	for(int u : adj[v]){
		if(u == p) continue;
		if(!vis[u]){
			dfs(u, v);
			children++;

			low[v] = min(low[v], low[u]);
		}
		else{
			low[v] = min(low[v], tin[u]);
		}
		if(p != -1 && low[u] >= tin[v]) is_art[v] = true;
	}

	if(p == -1 && children > 1) is_art[v] = true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);

	for(int i=0;i<n;i++){
		cout << i+1 << " " << is_art[i] << "\n";
	}

	return 0;
}