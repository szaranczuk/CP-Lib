#include <iostream>
#include <vector>

using namespace std;

#define N 1005

int n;
string s;
string s1;
int pi[N];
vector<int> ans;

void KMP(string s, string& s1){
	int t = 0;

	for(int i=0;i<s1.length();i++){
		while(t>0 && s1[i] != s[t]) t = pi[t-1];
		if(s1[i] == s[t]) t++;
		if(t == n){
			ans.push_back(i+1-n);
			t = pi[t-1];
		}
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s >> s1;

	n = s.length();

	int t = 0;
	for(int i=1;i<n;i++){
		while(t>0 && s[i] != s[t]) t = pi[t-1];
		if(s[i] == s[t]) t++;
		pi[i] = t;
	}

	KMP(s, s1);

	cout << ans.size() << "\n";

	for(int v : ans) cout << v << " ";

	return 0;
}