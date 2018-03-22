fib = lambda x: x if x<2 else fib(x-1)+fib(x-2)
print(list(map(lambda x: x**3,map(fib,range(int(input()))))))
