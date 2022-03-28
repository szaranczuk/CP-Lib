#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N 1005

int n, m;
int a, b;
vector<int> adj[N];
bool vis[N];
int dist[N];
queue<int> q;

void bfs(int st){
	for(int i=0;i<n;i++){
		dist[i] = N;
	}

	dist[st] = 0;
	q.push(st);

	while(!q.empty()){
		int v = q.front(); q.pop();

		for(int u : adj[v]){
			if(!vis[u]){
				vis[u] = true;
				dist[u] = dist[v] + 1;
				q.push(u);
			}
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
		adj[b].push_back(a);
	}

	bfs(0);

	return 0;
}