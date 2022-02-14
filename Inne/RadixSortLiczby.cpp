#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005

int n;
long long a[N];
vector<long long> b[2][256];
vector<long long> ans;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> a[i];
		b[0][0].push_back(a[i]);
	}

	/*
	for(int i=0;i<n;i++){
		b[0][a[i] & ((1LL << 8) - 1)].push_back(a[i]);
	}*/

	for(int i=0;i<8;i++){
		long long mask = ((1LL << (8 - (i == 7)))-1) << 8*i;
		for(int j=256;j>=0;j--){
			for(auto v : b[0][j]){
				b[1][(v & mask) >> 8*i].push_back(v);
			}

			b[0][j].clear();
		}

		swap(b[0], b[1]);
	}

	for(int i=0;i<256;i++){
		while(!b[0][i].empty()){
			ans.push_back(b[0][i].back()); b[0][i].pop_back();
		}
	}

	for(auto v : ans) cout << v << " ";

	return 0;
}