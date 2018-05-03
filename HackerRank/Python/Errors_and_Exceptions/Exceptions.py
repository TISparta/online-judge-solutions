for tc in range(int(input())):
    try:
        a, b = map(int,input().split())
        print(a//b)
    except ZeroDivisionError as ex:
        print("Error Code:",ex)
    except ValueError as ex:
        print("Error Code:",ex)
