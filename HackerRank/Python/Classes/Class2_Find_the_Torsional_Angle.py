import math
class Point():
    def __init__(self,_x,_y,_z):
        self.x, self.y, self.z = _x, _y, _z
    def __sub__(self,p):
        return Point(self.x-p.x,self.y-p.y,self.z-p.z)
    def __mul__(self,p):
        return Point(self.y*p.z-self.z*p.y,self.z*p.x-self.x*p.z,self.x*p.y-self.y*p.x)
    def dot(self,p):
        return self.x*p.x+self.y*p.y+self.z*p.z
    def mod(self):
        return math.sqrt(self.x*self.x+self.y*self.y+self.z*self.z)
A = Point(*map(float,input().split()))
B = Point(*map(float,input().split()))
C = Point(*map(float,input().split()))
D = Point(*map(float,input().split()))
AB, BC, CD = B-A, B-C, D-C
X, Y = AB*BC, BC*CD
print("%.2f" %math.degrees(math.acos(X.dot(Y)/(X.mod()*Y.mod()))))
