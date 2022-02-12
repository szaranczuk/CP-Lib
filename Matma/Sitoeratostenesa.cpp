#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> primes;

vector<int> Sieve(int n){
	vector<bool> mark(n+1);
	vector<int> ret;

	for(int i=2;i<=n;i++){
		if(!mark[i]){
			ret.push_back(i);
			for(int j=i;j<=n;j+=i){
				mark[j] = true;
			}
		}
	}

	return ret;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;

	primes = Sieve(n);

	for(int v : primes) cout << v << " ";

	return 0;
}