#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005
#define M 1005

int n;
int a[N];
int b[N];
int cnt[M];
int maxi;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
		cnt[a[i]]++;
		maxi = max(maxi, a[i]);
	}

	for(int i=1;i<=maxi;i++){
		cnt[i] += cnt[i-1];
	}

	for(int i=0;i<n;i++){
		b[--cnt[a[i]]] = a[i];
	}

	for(int i=0;i<n;i++){
		cout << b[i] << " ";
	}

	return 0;
}