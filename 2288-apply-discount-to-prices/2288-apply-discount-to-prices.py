class Solution:
    def discountPrices(self, s: str, discount: int) -> str:
        a = []
        for w in s.split():
            if w[0]=='$' and w[1:].isnumeric():
                price=int(w[1:])
                rem=(100-discount)/100
                w=f'${(price*rem):.2f}'
            a.append(w)
        return ' '.join(a)
                