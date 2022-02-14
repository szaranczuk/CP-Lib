#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Bignum{
#define REDUCE() while(len>1&&c[len-1]==0) len--;

	vector<int> c;
	int len;

	int digits(int v){
		if(v == 0) return 1;
		int ret = 0;
		while(v){
			ret++;
			v/=10;
		}
		return ret;
	}

	Bignum(int v = 0, int l = 1){
		res(l);
		*this = v;
	}

	Bignum(const Bignum& a){
		res(a.len);
		for(int i=0;i<a.len;i++) c[i] = a.c[i];
		len = a.len;
	}

	void res(int k){
		//cout << k << " " << c.size() << "\n";
		if(k > (int)c.size()){
			c.resize(max(k, (int)c.size()*2));
		}
	}

	void carry(int n){
		int x = 0;
		for(; x < n || c[x] < 0 || c[x] >= 10; x++){
			//cout << x << " ";
			res(x+2);
			if(c[x] >= 10){
				long long d = c[x] / 10;
				c[x] -= d * 10;
				c[x+1] += d;
			}
			else if(c[x] < 0){
				long long d = (-c[x] - 1)/10 + 1;
				c[x] += d*10;
				c[x+1] -= d;
			}
		}
		len = max(len, x+1);
		REDUCE();
	}

	bool operator==(const Bignum& a) const{
		if(len != a.len) return false;
		for(int i=0;i<len;i++) if(c[i] != a.c[i]) return false;
		return true;
	}

	bool operator<(const Bignum& a) const{
		if(len != a.len) return len < a.len;
		for(int i=len-1;i>=0;i--){
			if(c[i] != a.c[i]) return c[i] < a.c[i];
		}
		return false;
	}

	bool operator>(const Bignum& a) const{
		return a < *this;
	}

	bool operator<=(const Bignum& a) const{
		return !(a < *this);
	}

	bool operator>=(const Bignum& a) const{
		return !(*this < a);
	}

	bool operator!=(const Bignum& a) const{
		return !(*this == a);
	}

	void operator+=(int a){
		c[0] += a;
		carry(1);
	}

	void operator-=(int a){
		c[0] -= a;
		carry(1);
	}

	void operator*=(int a){
		for(int i=0;i<len;i++) c[i] *= a;
		carry(len);
	}

	int operator/=(int a){
		long long w = 0;
		for(int i=len-1;i>=0;i--){
			w = w * 10 + c[i];
			c[i] = w / a;
			w = w % a;
		}
		REDUCE();
		return a;
	}

	int operator%(int a){
		long long w = 0;
		for(int i=len-1;i>=0;i--) w = (w*10 + c[i])%a;
		return w;
	}

	Bignum& operator+=(const Bignum& a){
		res(a.len);
		for(int i=0;i<a.len;i++) c[i] += a.c[i];
		carry(a.len);
		return *this;
	}

	Bignum& operator-=(const Bignum& a){
		for(int i=0;i<a.len;i++) c[i] -= a.c[i];
		carry(a.len);
		return *this;
	}

	Bignum& operator*=(const Bignum& a){
		Bignum b(0, len + a.len);

		//cout << b.len;

		for(int i=0;i<a.len;i++){
			for(int j=0;j<len;j++){
				b.c[i+j] += a.c[i] * c[j];
			}
			b.carry(i + len);
		}

		*this = b;
		return *this;
	}

	Bignum& operator/=(const Bignum& a){
		int n = max(len - a.len + 1, 1);
		Bignum ret(0, n), prod;
		for(int i=n-1;i>=0;i--){
			int k = 0;
			for(;k<10;k++){
				//cout << i << " " << k << " "; ((a*k) << i).write(); cout << "\n";
				if(*this < prod + (a * k << i)) break;
			}
			k--;
			prod += (a * k) << i;
			ret.c[i] = k;
			if(k)ret.len = max(ret.len, i+1);
		}
		*this = ret;
		//(*this).write(); cout << " ";
		//cout << (*this).len << " " << (*this).c.size() << "\n";
		return *this;
	}

	Bignum& operator%=(const Bignum& a){
		Bignum ret = *this;
		ret /= a;
		ret *= a;
		*this -= ret;
		return *this;
	}

	Bignum sqrt(){
		int n = (len + 1)/2;
		Bignum a(0, n), prod;
		a.len = n;
		for(int i=n-1;i>=0;i--){
			int k = 0;
			for(;k<10;k++){
				if(*this < prod + (a * 2 * k << i) + (Bignum(k) * k << 2 * i)) break;
			}
			k--;
			prod += (a * 2 * k << i) + (Bignum(k) * k << 2 * i);
			a.c[i] = k;
		}
		return a;
	}

	Bignum& operator>>=(int a){
		if(a > len) a = len;
		for(int i=0;i<len-a;i++) c[i] = c[i+a];
		for(int i=len-a;i<len;i++) c[i] = 0;
		len -= a;
		if(len == 0) len = 1;
		return *this;
	}

	Bignum& operator<<=(int a){
		if(c[0] == 0 && len == 1) return *this;
		res(len + a);
		for(int i=len-1;i>=0;i--) c[i+a] = c[i];
		for(int i=0;i<a;i++) c[i] = 0;
		len += a;
		return *this;
	}

	Bignum& operator=(int a){
		if(a == 0){
			res(1);
			c[0] = 0;
			len = 1;
		}
		else{
			len = 0;
			for(int i=0;a;i++){
				len++;
				res(i+1);
				c[i] = a%10;
				a /= 10;
			}
		}
		
		return *this;
	}

	Bignum& operator=(const Bignum& a){
		res(a.len);
		for(int i=0;i<a.len;i++) c[i] = a.c[i];
		for(int i=a.len;i<len;i++) c[i] = 0;
		len = a.len;
		REDUCE();
		return *this;
	}

	Bignum& operator=(string& s){
		int n = s.length();
		res(n);
		for(int i=0;i<n;i++) c[i] = s[n-i-1] - '0';
		for(int i=n;i<len;i++) c[i] = 0;
		len = n;
		REDUCE();
		return *this;
	}

	void write() const{
		for(int i=len-1;i>=0;i--) cout << c[i];
	}

	Bignum operator+(const Bignum& a) const{
		Bignum w = *this;
		w += a;
		return w;
	}
	Bignum operator-(const Bignum& a) const{
		Bignum w = *this;
		w -= a;
		return w;
	}
	Bignum operator*(const Bignum& a) const{
		Bignum w = *this;
		w *= a;
		return w;
	}
	Bignum operator/(const Bignum& a) const{
		Bignum w = *this;
		w /= a;
		return w;
	}
	Bignum operator%(const Bignum& a) const{
		Bignum w = *this;
		w %= a;
		return w;
	}
	Bignum operator>>(int a) const{
		Bignum w = *this;
		w >>= a;
		return w;
	}
	Bignum operator<<(int a) const{
		Bignum w = *this;
		w <<= a;
		return w;
	}
};

struct Integer{
	Bignum c;
	int sgn;

	int sign(int a){
		return a > 0 ? 1 : a < 0 ? -1 : 0;
	}

	Integer(const Bignum& a, int s = 1){
		c = a;
		sgn = (a == Bignum(0)) ? 0 : !s ? 1 : s;
	}

	Integer(int a = 0){
		c = Bignum(abs(a));
		sgn = sign(a);
	}

	Integer(string& s){
		if(s.length() == 1 && s[0] == 0){
			c = Bignum(0);
			sgn = 0;
		}
		else if(s[0] == '-'){
			s[0] = '0';
			c = s;
			sgn = -1;
		}
		else{
			c = s;
			sgn = 1;
		}
	}

	Integer operator-() const{
		return Integer(c, -sgn);
	}

	bool operator<(const Integer& a) const{
		if(sgn != a.sgn) return sgn < a.sgn;
		return (sgn == 1) ? c < a.c : c > a.c;
	}
	bool operator==(const Integer& a) const{
		return c == a.c && sgn == a.sgn;
	}

	Integer operator+(const Integer& a) const{
		if(sgn == -1) return -(-(*this) + -a);
		if(a.sgn >= 0) return Integer(c + a.c, min(1, sgn + a.sgn));
		if(c < a.c) return Integer(a.c - c, -1);
		return Integer(c - a.c, c > a.c);	
	}
	Integer operator-(const Integer& a) const{
		return *this + (-a);
	}
	Integer operator*(const Integer& a) const{
		return Integer(c * a.c, sgn * a.sgn);
	}
	Integer operator/(const Integer& a) const{
		return Integer(c / a.c, sgn * a.sgn);
	}
	Integer operator%(const Integer& a) const{
		return sgn == 1 ? c % a.c : Integer((a.c - (c % a.c)) % a.c); 
	}

	Integer operator+=(const Integer& a){
		return *this = *this + a;
	}
	Integer operator-=(const Integer& a){
		return *this = *this - a;
	}
	Integer operator*=(const Integer& a){
		return *this = *this * a;
	}
	Integer operator/=(const Integer& a){
		return *this = *this / a;
	}
	Integer operator%=(const Integer& a){
		return *this = *this % a;
	}

	void write() const{
		if(sgn == -1) cout << "-";
		c.write();
	}
};

Integer a, b;
Bignum c;
string s1, s2;

int main(){
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);

	c = 1;

	cout << c.c[0];

	/*
	cin >> s1 >> s2;

	a = s1;
	b = s2;

	(a+b).write(); cout << "\n";
	(a*b).write();*/

	return 0;
}

/*
348732498327423984324198321740932174
7653728101928872838232879143214
*/