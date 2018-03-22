from math import degrees
from cmath import phase
AB = int(input())
BC = int(input())
print(str(int(round(degrees(phase(complex(BC,AB))))))+"°")
