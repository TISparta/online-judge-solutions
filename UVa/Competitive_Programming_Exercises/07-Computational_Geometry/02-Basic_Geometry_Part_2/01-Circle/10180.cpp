#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;
const double PI = acos(-1.0);

struct Vector{
   double x, y;
   Vector(): x(0), y(0) {};
   Vector(double x_, double y_): x(x_), y(y_) {};
   Vector(Vector &A, Vector &B): x(B.x - A.x), y(B.y - A.y) {};

   Vector operator + (const Vector& other) const{
      return Vector(x + other.x, y + other.y);
   }

   Vector operator - (const Vector& other) const{
      return Vector(x - other.x, y - other.y);
   }

   Vector operator * (const double& K) const{
      return Vector(x * K, y * K);
   }

   Vector operator / (const double& K) const{
      return Vector(x / K, y / K);
   }

   Vector Ortogonal() const{
      return Vector(-y, x);
   }

   Vector Normalize() const{
      double K = ( *this ).Norm();
      return Vector(x / K, y / K);
   }

   Vector Rotate(double theta){
      return Vector(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta) );
   }

   Vector Reflect(Vector& other){
      return (*this) - Vector( (*this), other);
   }

   bool operator == (const Vector& other) const{
      return ( fabs(x - other.x) < EPS and fabs(y - other.y) < EPS );
   }

   bool operator < (const Vector& other) const{
      if( not fabs(x - other.x) < EPS ) return x < other.x;
      return y < other.y;
   }

   bool isCollinear(const Vector& other) const{
      return fabs( ( *this ).CrossProduct(other) ) < EPS;
   }

   bool ccw(const Vector other) const{
      return ( ( *this ).CrossProduct(other) > 0.0 );
   }

   bool isInsideCircle(const Vector& other, const double& r) const{
      double dx = x - other.x, dy = y - other.y, R = r * r;
      dx *= dx, dy *= dy;
      if( dx + dy < R ) return true;
      return false;
   }

   double DotProduct(const Vector& other) const{
      return x * other.x + y * other.y;
   }

   double CrossProduct(const Vector& other) const{
      return x * other.y - y * other.x;
   }

   double Norm() const{
      return hypot(x, y);
   }

   double Norm2() const{
      return x * x + y * y;
   }

   double Distance(const Vector& other) const{
      return hypot(x - other.x, y - other.y);
   }

   double Angle(const Vector& other) const{
      return acos( ( *this ).DotProduct(other) / sqrt( ( *this ).Norm2() * other.Norm2() ) );
   }

   double ScalarProyection(const Vector& other) const{
      return ( *this ).DotProduct(other) / other.Norm2();
   }

   void print() const{
      printf("(%.2lf, %.2lf)\n", x, y);
   }

};

struct Line{
   double a, b, c;
   Vector A, B;
   Line(): a(0), b(0), c(0) {};
   Line(double a_, double b_, double c_): a(a_), b(b_), c(c_) {};
   Line(Vector& P1, Vector& P2): A(P1), B(P2){
      if( fabs(P1.x - P2.x) < EPS )
         a = 1.0, b = 0.0, c = -P1.x;
      else
         a = ( P1.y - P2.y ) / ( P2.x - P1.x ), b = 1.0, c = -a * P1.x - P1.y;
   }
   
   inline bool isParallel(const Line& other) const{
      return ( fabs(a - other.a) < EPS and fabs(b - other.b) < EPS );
   }

   inline bool isEqual(const Line& other) const{
      return ( ( *this ).isParallel(other) and fabs(c - other.c) < EPS );
   }

   int Intersection(Line& other, Vector& P) const{
      if( ( *this ).isEqual(other) ) return 0;
      if( ( *this ).isParallel(other) ) return -1;
      P.x = (b * other.c - other.b * c ) / (a * other.b - b * other.a);
      if( fabs(other.b) < EPS )
         P.y = -c - a * P.x;
      else
         P.y = -other.c - other.a * P.x;
      return 1;
   }

   double Distance(Vector& P, Vector& C){
      C = A + Vector(A, B) * Vector(A, P).ScalarProyection( Vector(A, B) );
      return P.Distance(C);
   }

   double DistanceLineSegment(Vector& P, Vector& C){
      double u = Vector(A, P).ScalarProyection( Vector(A, B) );
      if( u < 0.0 ){
         C = A;
         return A.Distance(P);
      }
      if( u > 1.0 ){
         C = B;
         return B.Distance(P);
      }
      return ( *this ).Distance(P, C);
   }

   bool isOnSegment(const Vector& other) const{
      return ( min(A.x, B.x) <= other.x + EPS and other.x - EPS <= max(A.x, B.x) and 
            min(A.y, B.y) <= other.y + EPS and other.y - EPS <= max(A.y, B.y) );
   }

   bool LineSegmentIntersection(Line& other, Vector& P){
      int k = ( *this ).Intersection(other, P);
      if( k == -1 ) return false;
      if( k == 0 ){
         if( ( *this ).isOnSegment(other.A) or ( *this ).isOnSegment(other.B) or
               other.isOnSegment(A) or other.isOnSegment(B) ) return true;
         return false;
      }
      if( k == 1 ){
         if( ( *this ).isOnSegment(P) and other.isOnSegment(P) ) return true;
         return false;
      }
   }

};

int tc;
double R, d, alfa, beta, theta1, theta2, theta, ans;
Vector P1, P2, A, B, C, Zero(0.0, 0.0);

int main(){
   scanf("%d", &tc);
   while(tc--){
      scanf("%lf %lf %lf %lf %lf", &P1.x, &P1.y, &P2.x, &P2.y, &R);
      Line(P1, P2).DistanceLineSegment( Zero, C );
      if( C.isInsideCircle( Zero, R) ){
         alfa = acos( R / P1.Norm() );
         beta = acos( R / P2.Norm() );
         P1 = P1.Normalize() * R;
         P2 = P2.Normalize() * R;
         A = P1.Rotate(-alfa);
         B = P2.Rotate(beta);
         d = A.Distance(B);
         theta1 = 2.0 * asin( d / ( 2.0 * R ) );
         A = P1.Rotate(alfa);
         B = P2.Rotate(-beta);
         d = A.Distance(B);
         theta2 = 2.0 * asin( d / ( 2.0 * R ) );
         theta = min(theta1, theta2);
         ans = R * ( tan(alfa) + tan(beta) + theta );
      }
      else
         ans = P1.Distance(P2);
      printf("%.3lf\n", ans);
   }
   return(0);
}
