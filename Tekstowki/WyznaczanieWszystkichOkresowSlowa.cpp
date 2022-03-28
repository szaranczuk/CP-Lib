#include <iostream>
#include <vector>

using namespace std;

#define N 1005

string s;
int n;
int pi[N];
vector<int> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s;

	n = s.length();

	int t = 0;
	for(int i=1;i<n;i++){
		while(t>0 && s[i] != s[t]) t = pi[t-1];
		if(s[i] == s[t]) t++;
		pi[i] = t;
	}

	t = n-1;

	while(t > 0){
		ans.push_back(n-pi[t]);
		t = pi[t-1];
	}

	cout << ans.size() << "\n";
	for(int v : ans) cout << v << " ";

	return 0;
}