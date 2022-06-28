class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        l = -(-len(b) // len(a))
        return l if (b in a*l) else (l+1) if (b in a*(l+1)) else -1