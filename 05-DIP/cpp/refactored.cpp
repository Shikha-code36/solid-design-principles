#include <iostream>

class PaymentGateway {
public:
    virtual void charge(double amount) = 0;
    virtual ~PaymentGateway() = default;
};

class RazorpayGateway : public PaymentGateway {
public:
    void charge(double amount) override {
        std::cout << "Charging " << amount
                  << " using Razorpay\n";
    }
};

class GPayGateway : public PaymentGateway {
public:
    void charge(double amount) override {
        std::cout << "Charging " << amount
                  << " using GPay\n";
    }
};

class PayPalGateway : public PaymentGateway {
public:
    void charge(double amount) override {
        std::cout << "Charging " << amount
                  << " using PayPal\n";
    }
};

class PaymentService {
private:
    PaymentGateway& gateway;

public:
    PaymentService(PaymentGateway& gateway)
        : gateway(gateway) {}

    void pay(double amount) {
        gateway.charge(amount);
    }
};

int main() {
    RazorpayGateway razorpay;
    PaymentService service(razorpay);
    service.pay(1000);

    GPayGateway gpay;
    PaymentService gpayService(gpay);
    gpayService.pay(2000);

    return 0;
}