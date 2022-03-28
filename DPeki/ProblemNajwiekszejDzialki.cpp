#include <iostream>
#include <algorithm>

using namespace std;

#define N 105

int n, m;
bool a[N][N];
int p[N][N];
int s[N][N];
int ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}

	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n;j++){
			if(a[i][j]){
				if(i == n-1) p[i][j] = 1;
				else{
					p[i][j] = p[i+1][j] + 1;
				}
			}
			else{
				p[i][j] = 0;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=n-1;j>=0;j--){
			if(j == n-1) s[i][j] = n;
			else{
				int k = j+1;
				while(k != n && p[i][k] >= p[i][j]) k = s[i][k];
				s[i][j] = k;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int l = s[i][j];
			if(j == 0) s[i][j] = -1;
			else{
				int k = j-1;
				while(k != -1 && p[i][k] >= p[i][j]) k = s[i][k];
				s[i][j] = k;
			}

			ans = max(ans, p[i][j]*(l-s[i][j]-1));
		}
	}

	cout << ans;

	return 0;
}