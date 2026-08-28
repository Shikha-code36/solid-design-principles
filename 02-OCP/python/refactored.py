from abc import ABC, abstractmethod


class Notification(ABC):

    @abstractmethod
    def send(self, message):
        pass


class EmailNotification(Notification):

    def send(self, message):
        print(f"Sending Email: {message}")


class SMSNotification(Notification):

    def send(self, message):
        print(f"Sending SMS: {message}")


class SlackNotification(Notification):

    def send(self, message):
        print(f"Sending Slack message: {message}")


class NotificationService:

    def send(self, notification, message):
        notification.send(message)


if __name__ == "__main__":
    service = NotificationService()

    service.send(
        EmailNotification(),
        "Order confirmed"
    )

    service.send(
        SMSNotification(),
        "Your OTP is 1234"
    )

    service.send(
        SlackNotification(),
        "Deployment completed"
    )


# Now adding WhatsApp means adding:

# class WhatsAppNotification(Notification):

#     def send(self, message):
#         print(f"Sending WhatsApp: {message}")

# No change to NotificationService. 