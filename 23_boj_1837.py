MAX_INT = 1000000

prime = [0 for i in range(MAX_INT+1)] # 0=>prime / 1=>composite

def eratosthenes() :
    for i in range(2,1000) :
        if prime[i]==0 :
            j=i*i
            while (True) :
                if j>MAX_INT :
                    break
                prime[j]=1
                j+=i

eratosthenes()

p,k=map(int,input().split())

for i in range(2,MAX_INT+1) :
    if (i >= k) :
        print("GOOD")
        exit()
    if prime[i] == 0 :
        if p % i == 0 :
            print("BAD "+str(i))
            exit()