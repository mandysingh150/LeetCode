class Cashier:
    
    def __init__(self, n: int, discount: int, products: List[int], prices: List[int]):
        self.cnt = 0
        self.total = n
        self.discount = discount
        self.dict={}
        for prod, price in zip(products, prices):
            self.dict[prod] = price

    def getBill(self, product: List[int], amount: List[int]) -> float:
        self.cnt += 1
        total=0.0
        for prod, amt in zip(product, amount):
            total += self.dict[prod]*amt
        return ((100-self.discount)/100.0)*total if self.cnt%self.total==0 else total
            


# Your Cashier object will be instantiated and called as such:
# obj = Cashier(n, discount, products, prices)
# param_1 = obj.getBill(product,amount)