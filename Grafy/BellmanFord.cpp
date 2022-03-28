#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 1000000005
#define N 1005

int n, m;
int a, b, c;
vector<pair<int, int>> adj[N];
int dist[N];

bool bellmanford(int st){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}

	dist[st] = 0;

	for(int i=0;i<n-1;i++){
		for(int v=0;v<n;v++){
			for(auto e : adj[v]){
				int u = e.first;
				int d = e.second;
				dist[u] = min(dist[u], dist[v] + d);
			}
		}
	}

	for(int v=0;v<n;v++){
		for(auto e : adj[v]){
			int u = e.first;
			int d = e.second;
			if(dist[u] > dist[v] + d) return false;
		}
	}

	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({b, c});
	}

	if(!bellmanford(0)) cout << "negative cycle";
	else{
		for(int i=0;i<n;i++){
			cout << i+1 << ": " << dist[i] << "\n";
		}
	}

	return 0;
}