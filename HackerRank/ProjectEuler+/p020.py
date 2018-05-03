from math import factorial as f

def main():
    for tc in range(int(input())):
        print(sum((int(it) for it in str(f(int(input()))))))

if __name__=="__main__":
    main()
