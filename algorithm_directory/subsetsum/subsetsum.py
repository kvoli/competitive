def subsetsum(nums, n, total):

    # dp setup

    subset = ([False for _ in range(sum+1)] for _ in range(n+1))

    for i in range(n+1):
        subset[i][0] = True

    for i in range(1, sum+1):
        subset[0][i] = False
   
    for i in range(1,n+1):
        for j in range(1, sum+1):
            
            if j < nums[i-1]:
                subset[i][j] = subset[i-1][j]
            else:
                subset[i][j] = (subset[i-1][j] or subset[i-1][j-nums[i-1]])
    
    return subset


