#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll INF=(ll)1e19;
//const int INF=(1<<30);

int main(){
  int r,c;
  cin >> r >> c;

  vector<vector<int>> a(r, vector<int>(c));
  
  REP(i,r)REP(j,c)cin >> a[i][j];

  int ans=0;
  REP(i,(1<<r)){
    int cnt=0;
    REP(j,c){
      int t=0;
      REP(k,r){
        t += (a[k][j] ^ ((i>>k) & 1));
      }
      cnt += max(r-t, t);
    }
    chmax(ans,cnt);
  }

  cout << ans << endl;

}

