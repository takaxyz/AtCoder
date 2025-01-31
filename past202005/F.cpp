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
  vvi cnt(n,vi(26));
  REP(i,n)REP(j,n){
    char c;
    cin >> c;
    int x = c - 'a';
    cnt[i][x]++;
  }
  string s;
  REP(i,n/2){
    REP(j,26){
      if(cnt[i][j] > 0 && cnt[n-1-i][j] > 0){
        s += (char)('a' + j);
        break;
      }
    }
  }

  if(s.size() != n/2){
    cout << -1 << endl;
    return 0;
  }

  cout << s;
  if(n % 2 == 1){
    REP(i,26){
      if(cnt[n/2][i] > 0){
        cout << (char)('a'+i);
        break;
      }
    }
  }
  reverse(ALL(s));
  cout << s << endl;
}

