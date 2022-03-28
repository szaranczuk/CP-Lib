#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define N 1005

int n;
int a[N];
set<int> pref;
int sum;
int ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	ans = a[0];
	pref.insert(0);

	for(int i=0;i<n;i++){
		sum += a[i];
		pref.insert(sum);
		ans = max(ans, sum - *(pref.begin()));
	}

	cout << ans;

	return 0;
}