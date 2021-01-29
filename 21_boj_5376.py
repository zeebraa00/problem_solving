import re

detect = re.compile('[(].+[)]')
n = int(input())

def GCD(x,y) :
    if y !=0 :
        return GCD(y, x%y)
    else :
        return x

for i in range(n) :
    num = input()[2:]

    iter = detect.findall(num)

    if ( len(iter)!=0 ) :
        iter = iter[0][1:len(iter[0])-1]
        iter_len = len(iter)

        idx1 = num.index('(')
        idx2 = num.index(')')

        if idx1==0 :
            denominator = int('9'*iter_len)
            numerator = int(iter)   
        else :
            not_iter = num[:idx1]
            not_iter_len = len(not_iter)

            denominator = int('9'*iter_len + '0'*not_iter_len)
            numerator = int(not_iter+iter) - int(not_iter)
    else :
        denominator = int('1'+'0'*len(num))
        numerator = int(num)
    
    gcd = GCD(numerator, denominator)
    denominator /= gcd
    numerator /= gcd
    print(str(int(numerator))+'/'+str(int(denominator)))