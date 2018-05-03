def main():
    palindrome = [it1*it2 for it1 in range(100,1000) for it2 in range(it1,1000) if str(it1*it2)==str(it1*it2)[::-1]]
    for tc in range(int(input())):
        N = int(input())
        print(max(filter(lambda x: x<N,palindrome)))

if __name__=="__main__":
    main()
