// Tags: Geometry, Graphs
// Difficulty: 6.5
// Priority: 1
// Date: 05-05-2021

#include <bits/stdc++.h>
     
#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair
     
using namespace std;
     
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

const double EPS = 1e-6;

template <typename T>
struct Point {
  T x;
  T y;

  constexpr Point (): x(0), y(0) {}
  Point (T x, T y): x(x), y(y) {}

  Point& operator += (const Point& other) { x += other.x, y += other.y; return *this; }
  Point& operator -= (const Point& other) { x -= other.x, y -= other.y; return *this; }
  T operator *= (const Point& other) { return x * other.x + y * other.y; }
  
  bool operator == (const Point& other) { return abs(x - other.x) < EPS and abs(y - other.y) < EPS; }
  bool operator != (const Point& other) { return not (*this == other); }
  bool operator < (const Point& other) { return abs(x - other.x) < EPS ? y < other.y : x < other.x; }
  
  Point& operator += (const T& fact) { x += fact, y += fact; return *this; }
  Point& operator -= (const T& fact) { x -= fact, y -= fact; return *this; }
  Point& operator *= (const T& fact) { x *= fact, y *= fact; return *this; }
  Point& operator /= (const T& fact) { assert(abs(fact) > EPS); x /= fact, y /= fact; return *this; }

  friend Point operator + (const Point& lhs, const Point& rhs) { Point r = lhs; r += rhs; return r; }
  friend Point operator + (const Point& lhs, const T& rhs) { Point r = lhs; r += rhs; return r; }
  friend Point operator + (const T& lhs, const Point& rhs) { Point r = rhs; r += lhs; return r; }

  friend Point operator - (const Point& lhs, const Point& rhs) { Point r = lhs; r -= rhs; return r; }
  friend Point operator - (const Point& lhs, const T& rhs) { Point r = lhs; r -= rhs; return r; }
  friend Point operator - (const T& lhs, const Point& rhs) { Point r = rhs; r -= lhs; return r; }

  friend Point operator * (const Point& lhs, const Point& rhs) { Point r = lhs; r *= rhs; return r; }
  friend Point operator * (const Point& lhs, const T& rhs) { Point r = lhs; r *= rhs; return r; }
  friend Point operator * (const T& lhs, const Point& rhs) { Point r = rhs; r *= lhs; return r; }

  friend Point operator / (const Point& lhs, const T& rhs) { Point r = lhs; r /= rhs; return r; }
  friend Point operator / (const T& lhs, const Point& rhs) { Point r = rhs; r /= lhs; return r; }

  friend std::ostream& operator << (std::ostream& stream, const Point& pt) { return stream << '(' << pt.x << ", " << pt.y << ')'; }

  friend std::istream& operator >> (std::istream& stream, Point& pt) {
    T x, y;
    stream >> x >> y;
    pt.x = x;
    pt.y = y;
    return stream;
  }

  double norm () const { return sqrt(1.0 * x * x + 1.0 * y * y); }
  T norm2 () const { return x * x + y * y; }
  Point rotate (double beta) const { return Point(cos(beta) * x - sin(beta) * y, sin(beta) * x + cos(beta) * y); }
  Point rotate90 () const { return Point(-y, x); }

};

template <typename T>
struct Circle {
  Point <T> c;
  T r;

  constexpr Circle (): c(0, 0), r(0) {}
  Circle (Point <T> c, T r): c(c), r(r) {}
  Circle (T x, T y, T r): c(x, y), r(r) {}

  tuple <Point <T>, Point <T>, bool> intersect (Circle other) const {
    if ((r + other.r) * (r + other.r) < (other.c - c).norm2()) return {Point <T>(), Point <T>(), false};
    if ((r - other.r) * (r - other.r) > (other.c - c).norm2()) return {Point <T>(), Point <T>(), false};
    double d = (other.c - c).norm();
    double b = 0.5 * (d + (r * r - other.r * other.r) / d);
    Point p = c + ((other.c - c) / d) * b;
    double h = sqrt(r * r - b * b);
    Point dir = (((other.c - c) / d) * h).rotate90();
    return {p + dir, p - dir, true};
  }

};

struct DSU {
  vi root;
  vi ss;
  int n_sets;

  DSU (int n): n_sets(n) {
    root.resize(n);
    iota(all(root), 0);
    ss = vi(n, 1);
  }

  int get (int u) {
    return root[u] = (u == root[u]) ? u : get(root[u]);
  }

  int join (int u, int v) {
    u = get(u);
    v = get(v);
    if (u == v) return 0;
    if (ss[u] < ss[v]) swap(u, v);
    root[v] = u;
    ss[u] += ss[v];
    n_sets -= 1;
    return 1;
  }
};

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  using MCircle = Circle <double>;
  using MPoint = Point <double>;
  vector <MCircle> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].c >> a[i].r;
  }
  DSU dsu(n);
  vector <MPoint> vert;
  int e = 0;
  for (int i = 0; i < n; i++) {
    vector <MPoint> z;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      auto [pt1, pt2, intersect] = a[i].intersect(a[j]);
      if (not intersect) continue;
      z.pb(pt1);
      z.pb(pt2);
      dsu.join(i, j);
    }
    sort(all(z));
    z.erase(unique(all(z)), end(z));
    e += sz(z);
    vert.insert(end(vert), all(z));
  }
  sort(all(vert));
  vert.erase(unique(all(vert)), end(vert));
  cout << e - sz(vert) + dsu.n_sets + 1 << '\n';
  return (0);
}
