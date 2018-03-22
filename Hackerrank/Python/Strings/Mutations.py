string = input()
idx,ch = input().split()
print(string[:int(idx)]+ch+string[int(idx)+1:])
