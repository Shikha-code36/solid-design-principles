#include <iostream>
#include <string>

class NotificationService {
public:
    void send(
        const std::string& notificationType,
        const std::string& message
    ) {
        if (notificationType == "email") {
            std::cout << "Sending Email: "
                      << message << "\n";
        }
        else if (notificationType == "sms") {
            std::cout << "Sending SMS: "
                      << message << "\n";
        }
        else if (notificationType == "slack") {
            std::cout << "Sending Slack message: "
                      << message << "\n";
        }
    }
};


int main() {
    NotificationService service;

    service.send("email", "Order confirmed");
    service.send("sms", "Your OTP is 1234");
    service.send("slack", "Deployment completed");

    return 0;
}