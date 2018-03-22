from collections import namedtuple
N, Student = int(input()), namedtuple('Student',input())
print("%.2f" %(sum(float(Student(*input().split()).MARKS) for it in range(N))/N))
