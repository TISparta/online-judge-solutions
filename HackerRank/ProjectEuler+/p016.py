def main():
    for tc in range(int(input())):
        print(sum([int(it) for it in str(1<<int(input()))]))

if __name__=="__main__":
    main()
