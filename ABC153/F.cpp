#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
  int n,d,a;
  cin >> n >> d >> a;

  vector<P> xh;
  REP(i,n){
    int x, h;
    cin >> x >> h;
    xh.emplace_back(x,h);
  }
  sort(ALL(xh));

  int r = 0;
  vector<ll> sum(n+1);
  ll ans = 0;
  REP(l,n){
    int x = xh[l].first;
    int h = xh[l].second;

    if(l>0)sum[l] += sum[l-1]; 
    if(h <= sum[l])continue;

    while(r < n && xh[r].first <= x + 2 * d)r++;

    ll cnt = (h - sum[l] + a - 1)/a;
    sum[l] += cnt * a;
    sum[r] -= cnt * a;

    ans += cnt;
//    cout << ans << endl;
  }

  cout << ans << endl;


}

