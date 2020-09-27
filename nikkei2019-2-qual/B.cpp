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
const int MOD = 998244353;

int main(){
  int n;
  cin >> n;
  vi d(n,0);
  int mx=0;
  REP(i,n){
    int x;
    cin >> x;
    if(i==0 && x != 0){
      cout << 0 << endl;
      return 0;
    }
    d[x]++;
    chmax(mx,x);

  }
  ll ans=1;

  if(d[0] != 1){
    cout << 0 << endl;
    return 0;
  }
  REP(i,mx+1){
    ll tmp=1;
    REP(j,d[i+1]){
      tmp *= d[i];
      tmp %= MOD;
    }
    ans *= tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}

