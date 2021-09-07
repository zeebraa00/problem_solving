nums = ["ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"]

iters = int(input())

for i in range(iters) :
    trans = []
    new = []
    case, length = map(str, input().split())
    length = int(length)
    numbers = list(input().split())

    for j in range(length) :
        trans.append(nums.index(numbers[j]))
    trans.sort()
    for j in range(length) :
        new.append(nums[trans[j]])
    printed = ""
    for j in range(length) :
        printed += new[j]+" "
    print("#"+str(i+1))
    print(printed)