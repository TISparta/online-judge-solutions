from collections import OrderedDict
d = OrderedDict()
for tc in range(int(input())):
    key, space, value = input().rpartition(' ')
    if key in d:
        d[key] += int(value)
    else:
        d[key] = int(value)
print("\n".join(key+' '+str(d[key]) for key in d))
