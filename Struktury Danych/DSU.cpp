#include <iostream>
#include <algorithm>

using namespace std;

#define N 1005

int par[N];
int siz[N];

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