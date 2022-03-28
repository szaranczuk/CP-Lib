#include <iostream>

using namespace std;

#define N 1005
#define K 25

int n, q;
int a, b;
int w[N];
int sp[N][K];
int logs[N];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> w[i];
	}

	for(int i=1;i<=n/2+1;i++){
		logs[i*2] = logs[i*2+1] = logs[i]+1;
	}

	for(int i=0;i<n;i++){
		sp[i][0] = w[i];
	}

	for(int k=1;k<K;k++){
		for(int i=0;i+(1<<k)-1<n;i++){
			sp[i][k] = min(sp[i][k-1], sp[i+(1<<(k-1))][k-1]);
		}
	}

	cin >> q;

	for(int i=0;i<q;i++){
		cin >> a >> b;
		a--; b--;
		int d = b - a + 1;
		int l = logs[d];

		cout << min(sp[a][l], sp[b-(1<<l)+1][l]) << "\n";
	}

	return 0;
}