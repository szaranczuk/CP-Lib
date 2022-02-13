#include <iostream>
#include <vector>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
bool vis[N];
int col[N];

bool dfs(int v, int c){
	vis[v] = true;
	col[v] = c;

	for(int u : adj[v]){
		if(!vis[u]){
			if(!dfs(u, c^1)) return false;
		}
		else if(col[u] != (col[v] ^ 1)) return false;
	}

	return true;
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

	cout << (dfs(0, 0) ? "" : "nie") << "dwukolorowalny";

	return 0;
}