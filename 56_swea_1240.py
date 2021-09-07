testcase = int(input())
num = ['0001101', '0011001', '0010011', '0111101', '0100011', '0110001', '0101111', '0111011', '0110111', '0001011']

for idx in range(0, testcase) :
    crypto_str = ''
    n, m = map(int, input().split())
    signal = []
    decimals = []

    for _ in range(n) :
        signal.append(list(input()))
    
    for i in range(n) :
        if '1' in signal[i] :
            for j in range(m) :
                crypto_str += signal[i][j]
            break

    crypto_str = crypto_str[::-1]
    for i in range(m) :
        if crypto_str[i] == '1' :
            crypto_str = crypto_str[i:i+56]
            break
    crypto_str = crypto_str[::-1]
    for i in range(8) :
        decimals.append(crypto_str[7*i:7*(i+1)])

    for i in range(8) :
        decimals[i] = num.index(decimals[i])

    output = ((decimals[0] + decimals[2] + decimals[4] + decimals[6]) * 3) + decimals[1] + decimals[3] + decimals[5] + decimals[7]

    if output % 10 == 0 :
        print("#"+str(idx+1)+str(" ")+str(sum(decimals)))
        continue
    print("#"+str(idx+1)+str(" 0"))