#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
vector<int> topo;
bool vis[N];
int in[N];
queue<int> q;

void topo_sort(){
	for(int i=0;i<n;i++){
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()){
		int v = q.front(); q.pop();
		topo.push_back(v);

		for(auto u : adj[v]){
			in[u]--;
			if(in[u] == 0) q.push(u);
		}
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
		in[b]++;
	}

	topo_sort();

	for(auto v : topo) cout << v+1 << " ";

	return 0;
}