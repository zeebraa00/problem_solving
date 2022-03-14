n = int(input())
digit = len(str(n)) # n자리 수의 경우, 자릿수의 합은 1 이상 9n 이하가 되어야 함

if digit == 1 : # 한자리 수의 경우, 짝수일 경우에만 생성자 존재
    if n % 2 == 0 :
        print(n//2)
    else :
        print("0")
    exit()

candidates = [i for i in range(9*digit, 0, -1)]

def get_digit_sum(n) :
    return sum(list(map(int,str(n))))

for i in candidates :
    remain = n - i
    if remain < 0 :
        continue
    if get_digit_sum(remain) == i :
        print(remain)
        exit()
print("0")