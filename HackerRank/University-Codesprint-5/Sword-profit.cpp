/**
 * > Author : TISparta
 * > Date : 09-09-18
 * > Tags : DP, Convex Hull Trick
 * > Difficulty : 6 / 10
 */

#include<bits/stdc++.h>
using namespace::std;

typedef long long ll;
typedef pair <ll, ll> Point;

const int MAX_N = 3e5;
const ll MOD = 1e9 + 7, INV = (MOD + 1) / 2;

int n, m, sz;
ll a[MAX_N + 10], b[MAX_N + 10], d[MAX_N + 10], q[MAX_N + 10], r[MAX_N + 10], dp[MAX_N + 10], ans;

vector <Point> hull;

inline ll norm (ll a) {
  return (a + MOD) % MOD;
}

inline ll add (ll a, ll b) {
  a = norm(a);
  b = norm(b);
  return (a + b) % MOD;
}

inline ll mul (ll a, ll b) {
  a = norm(a);
  b = norm(b);
  return (a * b) % MOD;
}

inline ll cross (Point c, Point x, Point y){
  return (x.first - c.first) * (y.second - c.second) - (y.first - c.first) * (x.second - c.second);
}

void insert (Point x){
  while (sz > 1) {
    Point p1 = hull[sz - 2];
    Point p2 = hull.back();
    if (cross(p1, p2, x) < 0) break;
    hull.pop_back();
    sz--;
	}
  hull.push_back(x);
  sz++;
}

ll get (ll x){
  int l = 0, r = sz - 1;
  while (l < r){
    int m = l + (r - l) / 2;
    (x * (hull[m].first - hull[m + 1].first) >= hull[m + 1].second - hull[m].second) ? r = m : l = m + 1;
  }
  return hull[l].second + x * hull[l].first;
}


ll solve (int id){
  ll cnt = dp[id] / b[id] + 1;
  ll ret = mul(dp[id], cnt);
  ll aux = mul(cnt - 1, INV);
  aux = mul(cnt, aux);
  aux = mul(b[id], aux);
  aux = mul(-1, aux);
  ret = add(ret, aux);
  return ret;
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld %lld %lld %lld %lld", q + i , a + i, b + i, r + i, d + i);
  for (int i = n; i >= 1; i--) {
    insert({-1LL * i, -r[i]});
    dp[i] = 1LL * i * d[i] - (a[i] + b[i]) + q[i] + get(d[i]);
  }
  for (int i = 1; i <= n; i++) if (dp[i] > 0) ans = add(ans, solve(i));
  printf("%lld\n", ans);
  return 0;
}
