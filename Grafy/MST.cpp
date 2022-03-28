#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second
#define N 1005
#define M 10005

int n, m;
int a, b, c;
vector<pair<int, pair<int, int>>> edges;
int par[N];
int siz[N];
int ans;

int find(int a){
	if(a == par[a]) return a;
	return par[a] = find(par[a]);
}

void join(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b) return;

	if(siz[a] > siz[b]) swap(a, b);

	siz[b] += siz[a];
	par[a] = b;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for(int i=0;i<n;i++){
		par[i] = i;
		siz[i] = 1;
	}

	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		a--; b--;
		edges.push_back({c, {a, b}});
	}

	sort(edges.begin(), edges.end());

	for(auto e : edges){
		int c = e.f;
		int a = e.s.f;
		int b = e.s.s;

		if(find(a) != find(b)){
			ans += c;
			join(a, b);
		}
	}

	cout << ans;

	return 0;
}