class Codec:

    alphabet = string.ascii_letters + '0123456789'
    
    def __init__(self):
        self.url_to_code = {}
        self.code_to_url = {}
    
    
    def encode(self, longUrl: str) -> str:
        while longUrl not in self.url_to_code:
            code = ''.join(random.choice(Codec.alphabet) for _ in range(6))
            if code not in self.code_to_url:
                self.code_to_url[code] = longUrl
                self.url_to_code[longUrl] = code
        return self.url_to_code[longUrl]
        

    def decode(self, shortUrl: str) -> str:
        return self.code_to_url[shortUrl[-6:]]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))