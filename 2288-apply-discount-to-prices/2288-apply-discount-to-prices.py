class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        ans = []
        words = sentence.split()
        for i, word in enumerate(words):
            if word[0]=='$' and word[1:].isnumeric():
                words[i] = f'${(((100-discount)/100.0)*int(word[1:])):.2f}'
        return ' '.join(words)
    
    