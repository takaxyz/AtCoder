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
const int MOD = 1e9 + 7;

vector<string> s;
vi ans;

void dfs(int d, vi& g){
  //cout << d << endl;
  //REP(i,g.size())cout << g[i] << (i==g.size()-1 ? "\n" : " ");
  vvi nxg(26, vi());
  REP(i,g.size()){
    int id = g[i];
    if(s[id].size()==d){
      ans[id]=d;
      continue;
    }
    int t = s[id][d] - 'a';
    nxg[t].pb(id);
  }

  REP(i,26){
    if(nxg[i].size()==1){
      ans[nxg[i][0]]=d;
    }else if(nxg[i].size()>1){
      dfs(d+1, nxg[i]);
    }
  }

}


int main(){
  int n;
  cin >> n;
  s.resize(n);
  REP(i,n)cin >> s[i];
  ans.resize(n);

  vi g;
  REP(i,n)g.pb(i);

  dfs(0, g);

  REP(i,n)cout << ans[i] << endl;
}

