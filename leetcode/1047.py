class Solution:
    def removeDuplicates(self, S: str) -> str:
        for i in range(1, len(s)):
            if s[i] == s[i-1]:
                return removeDuplicates(s[:i-1] + s[i+1:])
        return s
