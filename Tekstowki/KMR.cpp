#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005
#define K 25

string s;
int n;
int KMR[K][N];
int p[N];
int pn[N];
int logs[N];

int q;
int a, b, d;

void compute_KMR(string& s){
	s += '$';

	n = s.length();

	vector<int> cnt(max(n+1,256));

	for(int i=0;i<n;i++){
		cnt[s[i]]++;
	}
	for(int i=1;i<256;i++){
		cnt[i] = cnt[i-1];
	}
	for(int i=0;i<n;i++){
		p[--cnt[s[i]]] = i;
	}

	KMR[0][p[0]] = 0;
	int classes = 1;
	for(int i=1;i<n;i++){
		if(s[p[i-1]] != s[p[i]]) classes++;
		KMR[0][p[i]] = classes-1;
	}

	for(int k=0;(1<<(k+1))<n;k++){
		for(int i=0;i<n;i++){
			pn[i] = p[i] - (1<<k);
			if(pn[i] < 0) pn[i] += n;
		}

		fill(cnt.begin(), cnt.begin()+classes, 0);

		for(int i=0;i<n;i++){
			cnt[KMR[k][pn[i]]]++;
		}
		for(int i=1;i<classes;i++){
			cnt[i] += cnt[i-1];
		}
		for(int i=n-1;i>=0;i--){
			p[--cnt[KMR[k][pn[i]]]] = pn[i];
		}

		KMR[k+1][p[0]] = 0;
		classes = 1;

		for(int i=1;i<n;i++){
			pair<int, int> prev = {KMR[k][p[i-1]], KMR[k][(p[i-1] + (1<<k))%n]};
			pair<int, int> cur = {KMR[k][p[i]],    KMR[k][(p[i] + (1<<k))%n]};

			if(prev != cur) classes++;
			KMR[k+1][p[i]] = classes-1;
		}
	}

	s.pop_back();
}

bool compare(int a, int b, int d){
	int l = logs[d];

	pair<int, int> compare1 = {KMR[l][a], KMR[l][(a+d-(1<<l))%n]};
	pair<int, int> compare2 = {KMR[l][b], KMR[l][(b+d-(1<<l))%n]};

	return compare1 == compare2;
}

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);

	cin >> s;

	compute_KMR(s);

	n = s.length();

	for(int i=1;i<n/2+1;i++){
		logs[i*2] = logs[i*2+1] = logs[i]+1;
	}

	cin >> q;

	for(int i=0;i<q;i++){
		cin >> a >> b >> d;
		a--; b--;
		cout << compare(a, b, d) << "\n";
	}

	return 0;
}