print(*sorted(input(),key = lambda x: (x.isdigit() and int(x)&1==0, x.isdigit(), x.isupper(), x.islower(), x)),sep="")
