s = set(input().split())
print(all([s>set(input().split()) for it in range(int(input()))]))

