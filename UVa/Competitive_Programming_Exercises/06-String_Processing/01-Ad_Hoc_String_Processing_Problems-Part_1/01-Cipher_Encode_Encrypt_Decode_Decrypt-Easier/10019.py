for N in range( int( input() ) ):
    M = int( input() )
    print("%d %d" %(bin(M).count('1'), bin(sum(16 ** pos * int(digit) for pos, digit in enumerate(reversed(str(M))))).count('1')))