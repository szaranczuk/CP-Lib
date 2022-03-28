#include <iostream>
#include <vector>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
bool vis[N];

void dfs(int v){
	vis[v] = true;

	for(int u : adj[v]){
		if(!vis[u]) dfs(u);
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

	dfs(0);

	return 0;
}