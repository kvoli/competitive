def largestP(A):
    A.sort(reverse=True)
    def validTriangle(a, b, c):
        return a + b > c and a + c > b and b + c > a
    for i in range(2, len(A)):
        if validTriangle(A[i-2], A[i-1], A[i]):
            print(A[i-2], A[i-1], A[i])
            return A[i-2] + A[i-1] + A[i]
    return 0

print(largestP([3,2,3,4]))