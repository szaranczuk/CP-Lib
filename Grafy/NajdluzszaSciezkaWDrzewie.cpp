#include <iostream>
#include <vector>

using namespace std;

#define N 1005

int n;
int a, b;
vector<int> adj[N];
pair<int, int> maxi;
int par[N];
int beg;
vector<int> ans;

void dfs1(int v, int p, int d){
	if(d > maxi.first) maxi = {d, v};
	for(int u : adj[v]){
		if(u == p) continue;
		dfs1(u, v, d+1);
	}
}

bool dfs2(int v, int p){
	if(v == maxi.second){
		ans.push_back(v);
		return true;
	}

	for(int u : adj[v]){
		if(u == p) continue;
		if(dfs2(u, v)){
			ans.push_back(v);
			return true;
		}	
	}

	return false;
} 

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n-1;i++){
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	dfs1(0, -1, 0);

	beg = maxi.second;
	maxi = {0, 0};

	dfs1(beg, -1, 0);
	dfs2(beg, -1);

	cout << ans.size() << "\n";

	for(int v : ans) cout << v << " ";

	return 0;
}