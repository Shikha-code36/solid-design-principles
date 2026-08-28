#include <iostream>
#include <string>

class Notification {
public:
    virtual void send(const std::string& message) = 0;

    virtual ~Notification() = default;
};


class EmailNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending Email: "
                  << message << "\n";
    }
};


class SMSNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending SMS: "
                  << message << "\n";
    }
};


class SlackNotification : public Notification {
public:
    void send(const std::string& message) override {
        std::cout << "Sending Slack message: "
                  << message << "\n";
    }
};


class NotificationService {
public:
    void send(
        Notification& notification,
        const std::string& message
    ) {
        notification.send(message);
    }
};


int main() {
    EmailNotification email;
    SMSNotification sms;
    SlackNotification slack;

    NotificationService service;

    service.send(email, "Order confirmed");
    service.send(sms, "Your OTP is 1234");
    service.send(slack, "Deployment completed");

    return 0;
}