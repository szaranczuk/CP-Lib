#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int n;
int a[N];
int ans;
int min_pref;
int pref;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	ans = a[0];

	for(int i=0;i<n;i++){
		pref += a[i];
		min_pref = min(min_pref, pref);
		ans = max(ans, pref - min_pref);
	}

	cout << ans;

	return 0;
}