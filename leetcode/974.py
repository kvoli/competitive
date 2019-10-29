def subarraysDivByK(arr, k):
    mod =[0 for _ in range(k + 1)]
    cumSum, result = 0, 0

    for i in range(len(arr)): 
        cumSum = cumSum + arr[i] 
        mod[((cumSum % k)+k)% k]= mod[((cumSum % k)+k)% k] + 1 
    
    for i in range(k): 
        if (mod[i] > 1): 
            result = result + (mod[i]*(mod[i]-1))//2

    return result + mod[0]


print(subarraysDivByK([4,5,0,-2,-3,1], 5))
        