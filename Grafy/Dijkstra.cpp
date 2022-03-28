#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

#define INF 1000000005
#define N 1005

int n, m;
int a, b, c;
vector<pair<int, int>> adj[N];
int dist[N];

auto cmp = [] (int a, int b) {
	return make_pair(dist[a], a) < make_pair(dist[b], b);
};

set<int, decltype(cmp)> s(cmp);

void dijkstra(int st){
	for(int i=0;i<n;i++){
		dist[i] = INF;
	}

	dist[st] = 0;
	s.insert(st);

	while(!s.empty()){
		int v = *(s.begin());
		s.erase(s.begin());

		for(auto e : adj[v]){
			int u = e.first;
			int d = e.second;

			if(dist[u] > dist[v] + d){
				s.erase(u);
				dist[u] = dist[v] + d;
				s.insert(u);
			}
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

	dijkstra(0);

	for(int i=0;i<n;i++){
		cout << i+1 << ": " << dist[i] << "\n";
	}

	return 0;
}