class myclass():
    def __init__(self,_x,_y):
        self.x, self.y = _x, _y
    def __str__(self):
        return "%.2f%+.2fi" %(self.x,self.y)
    def __add__(self,z):
        return myclass(self.x+z.x,self.y+z.y)
    def __sub__(self,z):
        return myclass(self.x-z.x,self.y-z.y)
    def __mul__(self,z):
        return myclass(self.x*z.x-self.y*z.y,self.x*z.y+self.y*z.x)
    def __truediv__(self,z):
        return myclass((self.x*z.x+self.y*z.y)/(z.x*z.x+z.y*z.y),(self.y*z.x-self.x*z.y)/(z.x*z.x+z.y*z.y))
    def __abs__(self):
        return myclass((self.x*self.x+self.y*self.y)**0.5,0)

z1 = myclass(*map(float,input().split()))
z2 = myclass(*map(float,input().split()))
print("\n".join(map(str,[z1+z2, z1-z2, z1*z2, z1/z2, abs(z1), abs(z2)])))
