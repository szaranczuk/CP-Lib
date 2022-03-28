#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node{
	int next[26];

	Node() {
		fill(next, next+26, -1);
	}
};

int n;
string s;

vector<Node> tr(1);

void build(string& s){
	int v = 0;
	for(char ch : s){
		int c = ch - 'a';
		if(tr[v].next[c] == -1){
			tr[v].next[c] = tr.size();
			tr.emplace_back();
		}
		v = tr[v].next[c];
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> s;

		build(s);
	}

	return 0;
}