class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        lookup = {wrd[::-1]: idx for idx, wrd in enumerate(words)}
        res = []
        for idx, wrd in enumerate(words):
            for j in range(len(wrd)+1):
                pre, pos = wrd[:j], wrd[j:]
                if not len(pre) == 0 and pre == pre[::-1] and pos in lookup and lookup[pos] != idx:
                    res.append([lookup[pos], idx])
                if pos == pos[::-1] and pre in lookup and lookup[pre] != idx:
                    res.append([idx, lookup[pre]])
        return res