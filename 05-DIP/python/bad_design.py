class RazorpayGateway:
    def charge(self, amount):
        print(f"Charging ₹{amount} using Razorpay")


class PaymentService:
    def __init__(self):
        self.gateway = RazorpayGateway()

    def pay(self, amount):
        self.gateway.charge(amount)


if __name__ == "__main__":
    service = PaymentService()
    service.pay(1000)

'''
PS C:\Users\Shikha Pandey\Documents\github\solid-design-principles> python 05-DIP/python/bad_design.py"
Charging ₹1000 using Razorpay
'''