template< typename T >
vector<T> get_divisor(T n){
  vector<T> ret;

  for(T i = 1; i*i <= n; i++){
    if(n%i==0){
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
