#include <iostream>
#include <deque>
#include <vector>

using namespace std;

#define INF 1000000005
#define N 1005

int n, m;
int a, b, c;
vector<pair<int, int>> adj[N];
bool vis[N];
int dist[N];
deque<int> q;

void bfs(int st){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}

	vis[st] = true;
	dist[st] = 0;
	q.push_back(st);

	while(!q.empty()){
		int v = q.front(); q.pop_front();

		for(auto e : adj[v]){
			int u = e.first;
			int d = e.second;
			if(vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[v] + d;
			if(d == 0) q.push_front(u);
			else q.push_back(u);
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	bfs(0);

	for(int i=0;i<n;i++){
		cout << i+1 << " " << dist[i] << "\n";
	}

	return 0;
}