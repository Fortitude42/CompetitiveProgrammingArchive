//by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


class BigInt {
public:
    int sign;
    string s;

    BigInt()
        : s("")
    {
    }

    BigInt(string x)
    {
        *this = x;
    }

    BigInt(int x)
    {
        *this = to_string(x);
    }

    BigInt negative()
    {
        BigInt x = *this;

        x.sign *= -1;

        return x;
    }

    BigInt normalize(int newSign)
    {
        for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
            s.erase(s.begin() + a);

        sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);

        return *this;
    }

    void operator=(string x)
    {
        int newSign = (x[0] == '-' ? -1 : 1);

        s = (newSign == -1 ? x.substr(1) : x);

        reverse(s.begin(), s.end());

        this->normalize(newSign);
    }

    bool operator==(const BigInt& x) const
    {
        return (s == x.s && sign == x.sign);
    }

    bool operator<(const BigInt& x) const
    {
        if (sign != x.sign)
            return sign < x.sign;

        if (s.size() != x.s.size())
            return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());

        for (int a = s.size() - 1; a >= 0; a--)
            if (s[a] != x.s[a])
                return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);

        return false;
    }

    bool operator<=(const BigInt& x) const
    {
        return (*this < x || *this == x);
    }

    bool operator>(const BigInt& x) const
    {
        return (!(*this < x) && !(*this == x));
    }

    bool operator>=(const BigInt& x) const
    {
        return (*this > x || *this == x);
    }

    BigInt operator+(BigInt x)
    {
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr - x.negative();

        BigInt res;

        for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
            carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);

            res.s += (carry % 10 + '0');

            carry /= 10;
        }

        return res.normalize(sign);
    }

    BigInt operator-(BigInt x)
    {
        BigInt curr = *this;

        if (curr.sign != x.sign)
            return curr + x.negative();

        int realSign = curr.sign;

        curr.sign = x.sign = 1;

        if (curr < x)
            return ((x - curr).negative()).normalize(-realSign);

        BigInt res;

        for (int a = 0, borrow = 0; a < s.size(); a++) {
            borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));

            res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);

            borrow = (borrow >= 0 ? 0 : 1);
        }

        return res.normalize(realSign);
    }

    BigInt operator*(BigInt x)
    {
        BigInt res("0");

        for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
            while (b--)
                res = (res + x);

            x.s.insert(x.s.begin(), '0');
        }

        return res.normalize(sign * x.sign);
    }

    BigInt operator/(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');

        BigInt temp("0"), res;

        for (int a = 0; a < s.size(); a++)
            res.s += "0";

        int newSign = sign * x.sign;

        x.sign = 1;

        for (int a = s.size() - 1; a >= 0; a--) {
            temp.s.insert(temp.s.begin(), '0');
            temp = temp + s.substr(a, 1);

            while (!(temp < x)) {
                temp = temp - x;
                res.s[a]++;
            }
        }

        return res.normalize(newSign);
    }

    BigInt operator%(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');

        BigInt res("0");

        x.sign = 1;

        for (int a = s.size() - 1; a >= 0; a--) {
            res.s.insert(res.s.begin(), '0');

            res = res + s.substr(a, 1);

            while (!(res < x))
                res = res - x;
        }

        return res.normalize(sign);
    }

    // operator string(){
    // 	string ret = s;

    // 	reverse(ret.begin(), ret.end());

    // 	return (sign == -1 ? "-" : "") + s;
    // }

    string toString() const
    {
        string ret = s;

        reverse(ret.begin(), ret.end());

        return (sign == -1 ? "-" : "") + ret;
    }

    BigInt toBase10(int base)
    {
        BigInt exp(1), res("0"), BASE(base);

        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

            res = res + (exp * BigInt(curr));
            exp = exp * BASE;
        }

        return res.normalize(sign);
    }

    BigInt toBase10(int base, BigInt mod)
    {
        BigInt exp(1), res("0"), BASE(base);

        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));

            res = (res + ((exp * BigInt(curr) % mod)) % mod);
            exp = ((exp * BASE) % mod);
        }

        return res.normalize(sign);
    }

    string convertToBase(int base)
    {
        BigInt ZERO(0), BASE(base), x = *this;
        string modes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        if (x == ZERO)
            return "0";

        string res = "";

        while (x > ZERO) {
            BigInt mod = x % BASE;

            x = x - mod;

            if (x > ZERO)
                x = x / BASE;

            res = modes[stoi(mod.toString())] + res;
        }

        return res;
    }

    BigInt toBase(int base)
    {
        return BigInt(this->convertToBase(base));
    }

    friend ostream& operator<<(ostream& os, const BigInt& x)
    {
        os << x.toString();

        return os;
    }
};

vector < BigInt > a, b, c, d;
BigInt two = BigInt(2), ten = BigInt(10), five = BigInt(5);
int n;

int get(const BigInt &x) {
	if (!sz(x.s))
		return 0;

	return (x.s[0] - '0') % 2;
}


void solve() {
	int n;
	cin >> n;

	BigInt p10 = BigInt(10), p2 = BigInt(2), p5 = BigInt(5);
	int len = 0;
	a.pb(BigInt(0));
	b.pb(BigInt(1));
	c.pb(BigInt(0));
	d.pb(BigInt(1));

	while (sz(b) < n) {
		n -= sz(b);

		vector < BigInt > aa, bb, cc, dd;

		for (int i = 0; i < sz(a); ++i) {
		    BigInt cur = c[i] / two;
			if (!get(cur)) {
				aa.pb(a[i]); 
				cc.pb(cur);
				bb.pb(a[i] + p10);
				dd.pb(cur + p5);
			}		
		}

		for (int i = 0; i < sz(b); ++i) {
		    BigInt cur = d[i] / two;
			if (!get(cur)) {
				aa.pb(b[i]); 
				cc.pb(cur);
				bb.pb(b[i] + p10);
				dd.pb(cur + p5);
			}		
		}


		a = aa;
		b = bb;
		c = cc;
		d = dd;

		p10 = p10 * ten;
		p2 = p2 * two;
		p5 = p5 * five;
		len++;
	}

	cout << b[n - 1] << endl;
}

main () {
//	file("binary");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}
