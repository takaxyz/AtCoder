#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define VI         vector<int>
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e19;
//const int INF=(1<<30);


int main(){
  int r;
  cin >> r;
  string ans;
  if(r<1200)ans="ABC";
  else if(r<2800)ans="ARC";
  else ans="AGC";
  cout << ans << endl;
}

