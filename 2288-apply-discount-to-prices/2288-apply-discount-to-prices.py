class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ans = []
        for word in sentence.split():
            if word[0]=='$' and word[1:].isnumeric():
                price = int(word[1:])
                ans.append('${:.2f}'.format(price-(price*discount/100.0)))
            else:
                ans.append(word)
        return ' '.join(ans)