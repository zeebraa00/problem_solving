memo = [0 for i in range(10000)]

while True :
    try :
        n=int(input())
        one=1
        length=1
        if memo[n]!=0 :
            print(memo[n])
            continue
        while True :
            if one % n == 0 :
                memo[n]=len( str(one) )
                print(length)
                break
            else :
                one = 10*one + 1
                length+=1

    except EOFError :
        break