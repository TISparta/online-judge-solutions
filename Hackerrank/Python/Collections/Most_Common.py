from collections import Counter
print("\n".join(" ".join(str(n) for n in it) for it in sorted(Counter(input()).most_common(),key = lambda n: (-n[1],n[0]))[0:3]))
