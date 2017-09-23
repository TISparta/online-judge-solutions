first = True
for tc in range( int( input() ) ):
    if first: input()
    else: print('')
    in_tab, out_tab = input(), input()
    print(out_tab)
    print(in_tab)
    while True:
        try:
            line = input()
            if len(line) == 0: break
            print(line.translate( str.maketrans(in_tab, out_tab) ))
        except EOFError:
            break
    first = False