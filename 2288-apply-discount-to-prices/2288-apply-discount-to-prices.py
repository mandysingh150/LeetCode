class Solution:
    def discountPrices(self, s: str, discount: int) -> str:
        a = []
        for w in s.split():
            if w[0]=='$' and w[1:].isnumeric():
                price=int(w[1:])
                w=f'${(price*((100-discount)/100)):.2f}'
            a.append(w)
        return ' '.join(a)
                