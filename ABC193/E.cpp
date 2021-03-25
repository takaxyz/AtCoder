#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define RALL(a)     (a).rbegin(),(a).rend()
#define PRINT(a)   cout << (a) << endl

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second

#define debug(x) cerr << x << " " << "(L:" << __LINE__ << ")" << '\n';

using ll = long long int;
using P = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using pii = pair<int, int>;

template <typename T> using PQ = priority_queue<T>;
template <typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

int main(){
  int t;
  cin >> t;
  REP(i,t){
    ll x,y,p,q;
    cin >> x >> y >> p >> q;
    REP(j,10){
      ll tl = (2*x+2*y)*j+x;
      ll tr = tl+y;
      cout << tl << " " << tr << endl;

      ll l1 = (tl-p)/(p+q)*(p+q) + p;
      ll r1 = l1 + q;
      ll l2 = ((tl-p)/(p+q)+1)*(p+q) + p;
      ll r2 = l2 + q;
      cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
    }
  }
}

