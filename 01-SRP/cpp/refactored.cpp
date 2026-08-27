#include <iostream>
#include <string>

struct Order {
    int id;
    std::string item;
    double price;
};


class OrderRules {
public:
    void validate(const Order& order) {
        std::cout << "Validating order\n";
    }

    double calculatePrice(const Order& order) {
        std::cout << "Calculating price\n";
        return 1000.0;
    }
};


class OrderRepository {
public:
    void save(const Order& order) {
        std::cout << "Saving order to database\n";
    }
};


class EmailService {
public:
    void sendConfirmation(const Order& order) {
        std::cout << "Sending confirmation email\n";
    }
};


class AuditLogger {
public:
    void logEvent(const Order& order) {
        std::cout << "Logging order event\n";
    }
};


class OrderService {
private:
    OrderRules& rules;
    OrderRepository& repository;
    EmailService& emailService;
    AuditLogger& logger;

public:
    OrderService(
        OrderRules& rules,
        OrderRepository& repository,
        EmailService& emailService,
        AuditLogger& logger
    )
        : rules(rules),
          repository(repository),
          emailService(emailService),
          logger(logger) {}

    void createOrder(Order& order) {
        rules.validate(order);

        order.price = rules.calculatePrice(order);

        repository.save(order);
        emailService.sendConfirmation(order);
        logger.logEvent(order);
    }
};


int main() {
    Order order{101, "Laptop", 0.0};

    OrderRules rules;
    OrderRepository repository;
    EmailService emailService;
    AuditLogger logger;

    OrderService service(
        rules,
        repository,
        emailService,
        logger
    );

    service.createOrder(order);

    return 0;
}