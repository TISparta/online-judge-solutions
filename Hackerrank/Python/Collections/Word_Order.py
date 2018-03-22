from collections import OrderedDict
d = OrderedDict()
for tc in range(int(input())):
    key = input()
    if d.__contains__(key): d[key] += 1
    else: d[key] = 1
print(len(d))
print(" ".join(map(lambda x: str(d[x]),d)))
