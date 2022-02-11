#include <iostream>
#include <algorithm>

using namespace std;

#define MOD 1000000007

long long a, b, k;

long long binpow(long long a, long long b){
	long long ret = 1;
	while(b){
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

long long fib(long long n){
	if(n == 0) return 0;

	long long mat[2][2] = {{0, 1}, {1, 1}};
	long long res[2][2] = {{0, 1}, {0, 0}};
	long long temp[2][2] = {{0, 0}, {0, 0}};
	n--;

	while(n){
		if(n & 1){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					temp[i][j] = (res[i][1]*mat[1][j]%MOD+res[i][0]*mat[0][j]%MOD)%MOD;
				}
			}

			swap(res, temp);
		}

		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				temp[i][j] = (mat[i][1]*mat[1][j]%MOD+mat[i][0]*mat[0][j]%MOD)%MOD;
			}
		}

		swap(mat, temp);

		n >>= 1;
	}

	return res[0][1];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> a >> b >> k;

	if(k == 0){
		cout << a;
	}
	else if(k == 1){
		cout << b;
	}
	else{
		cout << (binpow(a, fib(k-1))%MOD * binpow(b, fib(k))%MOD)%MOD;
	}

	return 0;
}
