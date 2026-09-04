from abc import ABC, abstractmethod

class PaymentGateway(ABC):
    @abstractmethod
    def charge(self, amount):
        pass

class RazorpayGateway(PaymentGateway):
    def charge(self, amount):
        print(f"Charging ₹{amount} using Razorpay")

class GooglepayGateway(PaymentGateway):
    def charge(self, amount):
        print(f"Charging ₹{amount} using Googlepay")

class PaypalGateway(PaymentGateway):
    def charge(self, amount):
        print(f"Charging ₹{amount} using Paypal")

class PaymentService:
    def __init__(self, gateway):
        self.gateway = gateway

    def pay(self, amount):
        self.gateway.charge(amount)

if __name__ == "__main__":
    razorpay = RazorpayGateway()
    service = PaymentService(razorpay)
    service.pay(1000)

    gpay = GooglepayGateway()
    service = PaymentService(gpay)
    service.pay(2000)

'''
PS C:\Users\Shikha Pandey\Documents\github\solid-design-principles>python 05-DIP/python/refactored.py"
Charging ₹1000 using Razorpay
Charging ₹2000 using Googlepay
'''

'''
Notice the important change:

# Before
self.gateway = RazorpayGateway()

# After
self.gateway = gateway

PaymentService no longer creates or knows about the concrete gateway.
'''