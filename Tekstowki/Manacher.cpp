#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

string s;
int d[2*N];
int d1[N];
int d2[N];

void manacher_odd(string& s){
	int l = 0, r = -1;
	for(int i=1;i<(int)s.length()-1;i++){
		d[i] = max(0, min(r-i, d[l+(r-i)]));
		while(s[i-d[i]] == s[i+d[i]]) d[i]++;
		if(r < i+d[i]) l = i-d[i], r = i+d[i];
	}
}

void manacher(string& s){
	string s1 = "$#";

	for(auto c : s){
		s1 += c;
		s1 += '#';
	}

	s1 += '^';

	manacher_odd(s1);

	for(int i=2;i<(int)s1.length()-2;i++){
		if(i%2 == 0) d1[i/2-1] = d[i]/2;
		else d2[i/2-1] = d[i]/2;
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> s;

	manacher(s);

	for(int i=0;i<s.length();i++){
		cout << d1[i] << " ";
	}

	cout << "\n";\

	for(int i=0;i<s.length()-1;i++){
		cout << d2[i] << " ";
	}

	return 0;
}