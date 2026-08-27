#include <iostream>
#include <string>

struct Order {
    int id;
    std::string item;
};

class OrderService {
public:
    void createOrder(const Order& order) {
        validateOrder(order);
        calculatePrice(order);
        saveToDatabase(order);
        sendConfirmationEmail(order);
        logEvent(order);
    }

private:
    void validateOrder(const Order& order) {
        std::cout << "Validating order\n";
    }

    void calculatePrice(const Order& order) {
        std::cout << "Calculating price\n";
    }

    void saveToDatabase(const Order& order) {
        std::cout << "Saving order to database\n";
    }

    void sendConfirmationEmail(const Order& order) {
        std::cout << "Sending confirmation email\n";
    }

    void logEvent(const Order& order) {
        std::cout << "Logging order event\n";
    }
};

int main() {
    Order order{101, "Laptop"};

    OrderService service;
    service.createOrder(order);

    return 0;
}