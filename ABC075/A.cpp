#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(a)     (a).begin(),(a).end()
#define MOD 1000000007

typedef long long int ll;

const ll INF=(ll)1e18;
//const int INF=(1<<30);


int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B)cout << C << endl;
  else if(B==C) cout << A << endl;
  else cout << B << endl;
}

