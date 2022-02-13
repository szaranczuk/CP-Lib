#include <iostream>
#include <algorithm>

using namespace std;

#define N 55

int n, m, k;
int a, b;
int adj[N][N];
int dp[N][N];
int temp[N][N];

void clear(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp[i][j] = 0;
		}
	}
}

long long CountPaths(int b){
	bool assigned = false;

	while(b){
		if(b & 1){
			if(assigned){
				clear();

				for(int k=0;k<n;k++){
					for(int v=0;v<n;v++){
						for(int u=0;u<n;u++){
							temp[v][u] += dp[v][k] * adj[k][u];
						}
					}
				}
				swap(dp, temp);
			}

			else{
				assigned = true;
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						dp[i][j] = adj[i][j];
					}
				}
			}
		}

		clear();

		for(int k=0;k<n;k++){
			for(int v=0;v<n;v++){
				for(int u=0;u<n;u++){
					temp[v][u] += adj[v][k] * adj[k][u];
				}
			}
		}
		swap(adj, temp);

		b >>= 1;
	}

	long long sum = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			sum += dp[i][j];
		}
	}

	return sum;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> k;

	for(int i=0;i<m;i++){
		cin >> a >> b;
		a--; b--;
		adj[a][b]++;
	}

	cout << CountPaths(k);

	return 0;
}
