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

void dfs(int v){
	vis[v] = true;

	for(auto u : adj[v]){
		if(!vis[u]) dfs(u);
	}

	topo.push_back(v);
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
	}

	for(int i=0;i<n;i++){
		if(!vis[i]) dfs(i);
	}

	reverse(topo.begin(), topo.end());

	for(auto v : topo) cout << v+1 << " ";

	return 0;
}