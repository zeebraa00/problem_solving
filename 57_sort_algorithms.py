def bubble_sort(arr) :
    iters = len(arr)
    for i in range(iters-1,0,-1) :
        for j in range(i) :
            if arr[j] > arr[j+1] :
                tmp = arr[j+1]
                arr[j+1] = arr[j]
                arr[j] = tmp
    print(arr)

def selection_sort(arr) :
    iters = len(arr)
    for i in range(iters-1) :
        min_idx = i
        for j in range(i+1,iters) :
            if arr[j] < arr[min_idx] :
                min_idx = j
        tmp = arr[i]
        arr[i] = arr[min_idx]
        arr[min_idx] = tmp
    print(arr)

def insertion_sort(arr) :
    iters = len(arr)
    for i in range(1,iters) :
        j = i-1
        tmp = arr[i]
        while j>=0 and arr[j] > tmp :
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = tmp
    print(arr)

def counting_sort(arr) :
    iters = len(arr)
    max_val = max(arr)
    cnt = [0]*(max_val+1)

    for i in range(iters) :
        cnt[arr[i]] += 1

    idx=0
    for i in range(max_val+1) :
        while cnt[i] > 0 :
            arr[idx] = i
            idx+=1
            cnt[i] -= 1
    print(arr)

bubble_sort([4,5,1,3,4,2,3,1,4,5,2,3])
selection_sort([4,5,1,3,4,2,3,1,4,5,2,3])
insertion_sort([4,5,1,3,4,2,3,1,4,5,2,3])
counting_sort([4,5,1,3,4,2,3,1,4,5,2,3])