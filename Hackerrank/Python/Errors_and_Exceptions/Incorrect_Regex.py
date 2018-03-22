import re
for tc in range(int(input())):
    try:
        re.compile(input())
        print("True")
    except:
        print("False")
