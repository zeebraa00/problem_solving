def magnetic(arr,num,index) :
    cnt = 0
    for i in range(num) :
        flag = 0
        for j in range(num) :
            if flag==0 and arr[j][i]==1 :
                flag = 1
            elif flag==1 and arr[j][i]==2 :
                cnt +=1
                flag = 0
    print("#"+str(index+1)+str(" ")+str(cnt))

for index in range(10) :
    num = int(input())
    arr = []
    for _ in range(num) :
        arr.append(list(map(int,input().split())))
    magnetic(arr,num,index)