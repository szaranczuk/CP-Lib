#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N 1005

int n, max_length;
string s[N];
vector<string*> b[2][27];

inline char get_letter(string& s, int i){
	return i < (int)s.length() ? s[i] : 'a'-1;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	for(int i=0;i<n;i++){
		cin >> s[i];
		max_length = max(max_length, (int)s[i].length());
		b[0][0].push_back(&s[i]);
	}

	for(int i=max_length-1;i>=0;i--){
		for(int j=27;j>=0;j--){
			for(auto s : b[0][j]){
				b[1][get_letter(*s, i)-'a'+1].push_back(s);
			}
			b[0][j].clear();
		}
		swap(b[0], b[1]);
	}

	for(int i=0;i<27;i++){
		while(!b[0][i].empty()){
			cout << *(b[0][i].back()) << " ";
			b[0][i].pop_back();
		}
	}

	return 0;
}