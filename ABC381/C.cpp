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
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<pair<char,int>> rle;

  int cnt=0;
  REP(i,n){
    if(i > 0 && s[i] != s[i-1]){
      rle.emplace_back(s[i-1], cnt);
      cnt=0;
    }
    cnt++;
    if(i==n-1)rle.emplace_back(s[i],cnt);
  }

  //for(auto [c, i]: rle)cout << c << " " << i << endl;

  int ans=1;
  FOR(i,1,rle.size()-1){
    if(rle[i-1].first == '1' && rle[i].first == '/' && rle[i].second == 1 && rle[i+1].first == '2'){
      chmax(ans,min(rle[i-1].second, rle[i+1].second) * 2 + 1);
    }
  }
  cout << ans << endl;

}

