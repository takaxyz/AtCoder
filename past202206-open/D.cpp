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

class UnionFindTree{
  public:
    vector<int> rank,p,count;

    UnionFindTree() {}

    UnionFindTree(int size){
      rank.assign(size, 0);
      p.assign(size, 0);
      count.assign(size,1);
      REP(i,size)makeSet(i);
    }

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y){
      if(findSet(x) == findSet(y))return;

      x = findSet(x);
      y = findSet(y);
      
      if(rank[x] > rank[y]){
        p[y] = x;
      }else{
        p[x] = y;
        if(rank[x] == rank[y]){
          rank[y]++;
        }
      }

      int tmp = count[x] + count[y];
      count[x] = tmp;
      count[y] = tmp;
    }

    int findSet(int x){
      if(x != p[x]){
        p[x] = findSet(p[x]);
      }
      return p[x];
    }

    int getCount(int x){
      return count[findSet(x)];
    }

    void print(){
      REP(i,p.size()){
        cout << p[i] << " ";
      }
      cout << endl;
      REP(i,p.size()){
        cout << rank[i] << " ";
      }
      cout << endl;
    }

};


int main(){
  int n;
  cin >> n;
  UnionFindTree uft(26);

  REP(i,n){
    char a,b;
    cin >> a >> b;
    uft.unite(a-'a',b-'a');
  }
  string s,t;
  cin >> s >> t;

  REP(i,s.size()){
    if(s[i]!=t[i]){
      if(!uft.same(s[i]-'a',t[i]-'a')){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}

