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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){
  int h,w,k;
  cin >> h >> w >> k;
  vector<string> s(h);
  REP(i,h)cin >> s[i];

  vvi dist(h,vi(w,-1));
  int ans = 0;
  auto dfs = [&](int x, int y, int d, auto dfs) -> void {
    //fprintf(stderr, "%d %d %d\n",x,y,d);
    if(d == k){
      ans++;
      return;
    }
    dist[x][y]=d;
    REP(i,4){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;
      if(s[nx][ny]=='#')continue;
      if(dist[nx][ny]!=-1)continue;
      dfs(nx,ny,d+1,dfs);
    }
    dist[x][y]=-1;
  };

  REP(i,h)REP(j,w){
    if(s[i][j]=='.'){
//      REP(i,h)REP(j,w)dist[i][j]=-1;
      dfs(i,j,0,dfs);
    }
  }
  cout << ans << endl;

}

