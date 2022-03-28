#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
bool vis[N];
vector<int> topo;
int sccs;
int scc[N];

void dfs1(int v){
	vis[v] = true;

	for(int u : adj[v]){
		if(!vis[u]) dfs1(u);
	}

	topo.push_back(v);
}

void dfs2(int v){
	vis[v] = true;
	scc[v] = sccs;

	for(int u : adj[v]){
		if(!vis[u]) dfs2(u);
	}
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

	for(int i=0;i<n;i++){
		if(!vis[i]) dfs1(i);
	}

	reverse(topo.begin(), topo.end());

	for(int i=0;i<n;i++){
		vis[i] = false;
	}

	for(int v : topo){
		if(!vis[v]) dfs2(v);
	}

	for(int i=0;i<n;i++){
		cout << i+1 << " " << scc[i] << "\n";
	}

	return 0;
}