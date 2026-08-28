class NotificationService:
    def send(self, notification_type, message):
        if notification_type == "email":
            print(f"Sending Email: {message}")

        elif notification_type == "sms":
            print(f"Sending SMS: {message}")

        elif notification_type == "slack":
            print(f"Sending Slack message: {message}")


if __name__ == "__main__":
    service = NotificationService()

    service.send("email", "Order confirmed")
    service.send("sms", "Your OTP is 1234")
    service.send("slack", "Deployment completed")


# What's wrong?

# When WhatsApp arrives:

# elif notification_type == "whatsapp":
#     ...

# we have to modify NotificationService.

# That's our OCP problem.