#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define N 3005
#define K 26

struct Node{
	int next[K];
	int leaf = -1;
	int p = -1;
	char pch;
	int link = -1;
	int go[K];
	int exit_link = -1;
	int con = 0;

	Node(int p=-1, char c='$') : p(p), pch(c) {
		fill(begin(next), end(next), -1);
		fill(begin(go), end(go), -1);
	}
};

vector<int> roots;

int n;
int leafs;
string s[N];
int which_leaf[N];
int cont[N];
vector<Node> t(1);

string s1;
vector<int> adj[N];

void build(string &s){
	int v = 0;
	for(char ch : s){
		int c = ch - 'a';
		if(t[v].next[c] == -1){
			t[v].next[c] = t.size();
			t.emplace_back(v, ch);
		}
		v = t[v].next[c];
	}
	t[v].leaf = leafs++;
}

int go(int v, char ch);

int get_link(int v){
	if(t[v].link == -1){
		if(v == 0 || t[v].p == 0){
			t[v].link = 0;
		}
		else {
			t[v].link = go(get_link(t[v].p), t[v].pch);
		}

		get_link(t[v].link);

		int link_v = t[v].link;

		if(t[link_v].leaf == -1){
			t[v].exit_link = t[link_v].exit_link;
		}
		else{
			//cout << v;
			t[v].exit_link = link_v;
			if(t[v].leaf == -1) t[v].leaf = leafs++;
		}

		if(t[v].leaf != -1){
			//cout << v;
			if(t[v].exit_link == -1) { roots.push_back(v); }
			else{
				adj[t[v].exit_link].push_back(v);
			}
		}
	}
	return t[v].link;
}

int go(int v, char ch){
	int c = ch - 'a';
	if(t[v].go[c] == -1){
		if(t[v].next[c] != -1){
			t[v].go[c] = t[v].next[c];
		}
		else{
			t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
		}
	}
	return t[v].go[c];
}

void dfs(int v, int p){
	for(int u : adj[v]){
		if(u != p) dfs(u, v);
		t[v].con += t[u].con;
	}
}

void walk(string &s){
	int v = 0;
	for(char c : s){
		v = go(v, c);
		get_link(v);

		if(t[v].leaf != -1){
			t[v].con++;
		}
	}
}

int main(){
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> s[i];

		build(s[i]);

		which_leaf[i] = t.size()-1;
	}

	cin >> s1;

	walk(s1);

	for(auto root : roots){
		dfs(root, root);
	}
	cout << "\n";

	for(int i=0;i<n;i++){
		cout << s[i] << " " << t[which_leaf[i]].con << "\n";
	}
}

/*
5
a
b
ab
ba
aba
ababa
*/