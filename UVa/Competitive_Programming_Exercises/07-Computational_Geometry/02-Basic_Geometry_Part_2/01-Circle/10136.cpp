#include <bits/stdc++.h>

typedef double ptype;

using namespace std;

const int LEN = 30;
const long double R = 2.5L, EPS = 1e-9;

struct Point {
    ptype x, y;
    Point() {}
    Point(ptype x_, ptype y_): x(x_), y(y_) {}
};

int T;
char line[LEN];
vector <Point> points;
Point center;

bool getCenter(Point p1, Point p2) {
    ptype d2 = powl(p1.x - p2.x, 2) + powl(p1.y - p2.y, 2);
    ptype det = R * R / d2 - 0.25;
    if (det < 0.0) return false;
    ptype h = sqrt(det);
    center.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    center.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}


int getAnswer() {
    int ret = 0;
    for (Point p_i: points) {
        ptype d = sqrtl(powl(p_i.x - center.x, 2) + powl(p_i.y - center.y, 2));
        if (d <= R + EPS or fabs(d - R) < EPS) ret++;
    }
    return ret;
}

int solve() {
    int ret = 1;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            if (getCenter(points[i], points[j])) {
                ret = max(ret, getAnswer());
            }
            if (getCenter(points[j], points[i])) {
                ret = max(ret, getAnswer());
            }
        }
    }
    return ret;
}

bool readCase () {
    while (cin.getline(line, LEN), strlen(line)) {
        ptype x, y;
        sscanf(line, "%lf %lf", &x, &y);
        points.push_back(Point(x, y));
    }
    return true;
}

inline void clear () {
    points.clear();
}

int main () {
    cin.getline(line, LEN);
    sscanf(line, "%d", &T);
    cin.getline(line, LEN);
    while (T--) {
        readCase();
        printf("%d\n", solve());
        if (T) putchar('\n');
        clear();
    }
    return (0);
}
