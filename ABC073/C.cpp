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
  int N;
  cin >> N;
  set<int> st;
  REP(i,N){
    int a;
    cin >> a;
    if(st.find(a) == st.end()){
      st.insert(a);
    }else{
      st.erase(a);
    }
  }
  cout << st.size() << endl;
}

