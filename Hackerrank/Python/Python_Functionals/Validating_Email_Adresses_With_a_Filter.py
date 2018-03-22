def check(s):
    idx1, idx2 = s.find("@"), s.find(".")
    ok = idx1>0 and all(it.isalnum() or it=="@" or it=="-" or it=="_" for it in s[:idx1])
    ok &= ~idx2 and idx2-idx1>1 and all(it.isalnum() for it in s[idx1+1:idx2])
    ok &= ~idx2 and 1<=len(s[idx2+1:])<=3 and s.count("@")==1 and s.count(".")==1
    return ok
print(sorted(filter(check,[input() for tc in range(int(input()))])))
