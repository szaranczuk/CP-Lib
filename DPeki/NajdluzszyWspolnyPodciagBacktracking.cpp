#include <iostream>
#include <algorithm>

using namespace std;

#define N 105

string s;
string s1;
int n, m;
int dp[N][N];
string ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s >> s1;

	n = s.length();
	m = s1.length();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i] == s1[j]){
				if(i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max((i > 0 ? dp[i-1][j] : 0), (j > 0 ? dp[i][j-1] : 0));
			}
		}
	}

	cout << dp[n-1][m-1] << "\n";

	int i = n-1;
	int j = m-1;

	while(i > 0 && j > 0){
		if(dp[i][j] == dp[i-1][j-1] + 1){
			ans += s[i];
			j--;
		}
		i--;
	}

	if(dp[i][j] == 1) ans += s[i];

	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}