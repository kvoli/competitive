class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        def selfdividing(n):
            k = str(n)
            for val in k:
                if n % int(val) != 0 or int(val) == 0:
                    return False
            return True
        
        
        res = []
        for i in range(left, right+1):
            if selfdividing(i):
                res.append(i)
        return res