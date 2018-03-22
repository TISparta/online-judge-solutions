
# Execution time : 0.016337 seconds

# Solution Explanation
# We can solve first a bigger problem
# https://www.hackerrank.com/contests/projecteuler/challenges/euler017
# Then we just need to iterate in [1,1000] and add the length of
# the representation of the iterared number
# Finally, we add len('and') * N
# where N is the number of numbers which representations requires the word 'and'
# But, is easy to note that between the numbers than are less or equal than 1000
# only the three-digits numbers have the word 'and' except the ones that are divisible by 100
# So N = 1000-100-9

import time
width = 40
from textwrap import wrap

v = ['','Thousand','Million','Billion','Trillion']

def check1(n):
    if n=='1': return 'One'
    if n=='2': return 'Two'
    if n=='3': return 'Three'
    if n=='4': return 'Four'
    if n=='5': return 'Five'
    if n=='6': return 'Six'
    if n=='7': return 'Seven'
    if n=='8': return 'Eight'
    if n=='9': return 'Nine'

def check2(n):
    if n=='10': return 'Ten'
    if n=='11': return 'Eleven'
    if n=='12': return 'Twelve'
    if n=='13': return 'Thirteen'
    if n=='14': return 'Fourteen'
    if n=='15': return 'Fifteen'
    if n=='16': return 'Sixteen'
    if n=='17': return 'Seventeen'
    if n=='18': return 'Eighteen'
    if n=='19': return 'Nineteen'

def check3(n):
    if n=='2': return 'Twenty'
    if n=='3': return 'Thirty'
    if n=='4': return 'Forty'
    if n=='5': return 'Fifty'
    if n=='6': return 'Sixty'
    if n=='7': return 'Seventy'
    if n=='8': return 'Eighty'
    if n=='9': return 'Ninety'

def convert(s):
    aux = list()
    if len(s)==3:
        if s[0]!='0':
            aux.append(check1(s[0]))
            aux.append('Hundred')
        s = s[1:]
    if len(s)==2:
        if s[0]=='1':
            aux.append(check2(s))
            s = '000'
        if s[0]!='0':
            aux.append(check3(s[0]))
        s = s[-1]
    if len(s)==1 and s[-1]!='0':
        aux.append(check1(s))
    return aux

def solution():
    ans = 0
    for num in range(1,1001):
        s = str(num)
        u = list()
        for idx, it in list(enumerate(wrap(s[::-1],3)))[::-1]:
            if it!='000':
                u.extend(convert(it[::-1]))
                if idx: u.append(v[idx])
        ans += sum(len(it) for it in u)
    return ans+len('and')*(1000-100-9)

if __name__=="__main__":
    start_ = time.time()
    print(' Answer -> %s '.center(width,'-') % ( solution() ))
    print(' %f seconds '.center(width,'-') % ( time.time() - start_))
