#include <iostream>
#include <algorithm>

using namespace std;

#define N 105

string s;
string s1;
int n, m;

int dp[2][N];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s >> s1;

	n = s.length();
	m = s1.length();

	for(int i=0;i<n;i++){
		if(s1[0] == s[i]) dp[0][i] = 1;
	}

	for(int j=1;j<m;j++){
		for(int i=0;i<n;i++){
			if(s1[j] == s[i]){
				if(i == 0) dp[1][i] = 1;
				else dp[1][i] = dp[0][i-1] + 1;
			}
			else{
				dp[1][i] = (i == 0 ? dp[0][i] : max(dp[0][i], dp[1][i-1]));
			}
		}
		swap(dp[0], dp[1]);
	}

	cout << dp[0][n-1];

	return 0;
}