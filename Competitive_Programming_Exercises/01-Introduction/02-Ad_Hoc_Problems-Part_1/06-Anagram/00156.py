import sys
import collections

def solution():
    d = collections.defaultdict(int)
    v = list()
    while True:
        line = sys.stdin.readline().strip().split()
        if line[0] == '#':
            break
        for s in line:
            d[str(sorted(s.lower()))] += 1
        v.extend(line)
    for s in sorted(v):
        if d[str(sorted(s.lower()))] == 1:
            sys.stdout.write(s + '\n')

if __name__=="__main__":
    solution()
