#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005
#define W 1005

int n, w;
pair<int, int> items[N];
int dp[N][W];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> w;

	for(int i=0;i<n;i++){
		cin >> items[i].first >> items[i].second;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			dp[i][j] = max(i > 0 ? dp[i-1][j] : 0, j > 0 ? dp[i][j-1] : 0);
			if(items[i].second <= j){
				dp[i][j] = max(dp[i][j], i > 0 ? dp[i-1][j-items[i].second] + items[i].first : items[i].first);
			}
		}
	}

	cout << dp[n-1][w];

	return 0;
}