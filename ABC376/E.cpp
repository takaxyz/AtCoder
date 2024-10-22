#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);++i)
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

using mint = modint1000000007;
// using mint = modint998244353;

int main(){
  int t;
  cin >> t;
  REP(_,t){
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab(n);
    REP(i,n)cin >> ab[i].first;
    REP(i,n)cin >> ab[i].second;

    sort(ALL(ab));
    multiset<ll> st;
    ll sum = 0;
    REP(i,k){
      st.insert(ab[i].second);
      sum += ab[i].second;
    }

    ll ans = ab[k-1].first * sum;
    FOR(i,k,n){
      auto it = st.rbegin();
      if(*it > ab[i].second){
        sum -= *it;       
        sum += ab[i].second;
        st.erase(st.find(*it));
        st.insert(ab[i].second);
      }
      chmin(ans, ab[i].first * sum);
    }
    cout << ans << endl;

  }
}

