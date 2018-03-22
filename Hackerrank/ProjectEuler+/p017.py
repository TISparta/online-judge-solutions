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

def main():
    for tc in range(int(input())):
        s = input()
        ans = list()
        for idx, it in list(enumerate(wrap(s[::-1],3)))[::-1]:
            if it!='000':
                ans.extend(convert(it[::-1]))
                if idx: ans.append(v[idx])
        print(' '.join(ans))

if __name__=="__main__":
    main()
