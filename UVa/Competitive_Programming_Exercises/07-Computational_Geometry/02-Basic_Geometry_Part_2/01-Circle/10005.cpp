#include <bits/stdc++.h>

typedef double ptype;

using namespace std;

struct Point {
    ptype x, y;
    Point() {}
    Point(ptype x_, ptype y_): x(x_), y(y_) {}
};

int N;
double R;
vector <Point> vert;
Point center;

bool getCenter(Point p1, Point p2) {
    double d2 = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
    double det = R * R / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    center.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    center.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

bool packed () {
    for (Point p_i: vert) {
        double dis = pow(p_i.x - center.x, 2) + pow(p_i.y - center.y, 2);
        if (dis > R * R) return false;
    }
    return true;
}

bool possible () {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (getCenter(vert[i], vert[j]) and packed()) return true;
            if (getCenter(vert[j], vert[i]) and packed()) return true;
        }
    }
    return false;
}

bool readCase () {
    scanf("%d", &N);
    if (N == 0) return false;
    vert.resize(N);
    for (int i = 0; i < N; i++) scanf("%lf %lf", &vert[i].x, &vert[i].y);
    scanf("%lf", &R);
    return true;
}

inline void clear () {
    vert.clear();
}

int main () {
    while (readCase()) {
        puts(possible()
            ? "The polygon can be packed in the circle."
            : "There is no way of packing that polygon.");
        clear();
    }
    return (0);
}
