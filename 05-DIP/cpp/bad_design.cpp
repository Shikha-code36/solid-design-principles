#include <iostream>

class RazorpayGateway {
public:
    void charge(double amount) {
        std::cout << "Charging " << amount
                  << " using Razorpay\n";
    }
};

class PaymentService {
private:
    RazorpayGateway gateway;

public:
    void pay(double amount) {
        gateway.charge(amount);
    }
};

int main() {
    PaymentService service;
    service.pay(1000);

    return 0;
}