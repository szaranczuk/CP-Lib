#include <iostream>

using namespace std;

typedef __int128_t lll;

long long n;

long long binpow(long long a, long long b, long long m){
	long long ret = 1;
	while(b){
		if(b&1) ret = (lll) ret * a % m;
		a = (lll) a * a % m;
		b >>= 1;
	}
	return ret;
}

bool check(long long n, int a, long long d, int s){
	long long k = binpow(a, d, n);

	if(k == 1 || k == n-1) return true;

	for(int i=1;i<s;i++){
		k = (lll) k * k % n;
		if(k == n-1) return true;
	}

	return false;
}

bool miller_rabin(long long n){
	if(n < 2) return false;

	long long d = n-1;
	int s = 0;
	while(!(d&1)){
		d >>= 1;
		s++;
	}
	s--;

	for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
		if(a == n) return true;
		if(!check(n, a, d, s)) return false;
	}

	return true;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	cout << (miller_rabin(n) ? "prime\n" : "not prime\n");

	return 0;
}
