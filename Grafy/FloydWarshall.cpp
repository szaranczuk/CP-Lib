#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000005
#define N 55

int n, m;
int a, b, c;
int adj[N][N];
int dist[N][N];

void FloydWarshall(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dist[i][j] = INF;
		}
	}

	for(int i=0;i<n;i++){
		dist[i][i] = 0;
	}

	for(int k=0;k<n;k++){
		for(int v=0;v<n;v++){
			for(int u=0;u<n;u++){
				dist[v][u] = min(dist[v][u], dist[v][k], dist[k][u]);
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			adj[i][j] = INF;
		}
	}

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		a--; b--;
		adj[a][b] = min(adj[a][b], c);
	}

	FloydWarshall();

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}