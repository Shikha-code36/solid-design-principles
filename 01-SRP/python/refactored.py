class OrderRules:
    def validate(self, order):
        print("Validating order")

    def calculate_price(self, order):
        print("Calculating price")
        return 1000


class OrderRepository:
    def save(self, order):
        print("Saving order to database")


class EmailService:
    def send_confirmation(self, order):
        print("Sending confirmation email")


class AuditLogger:
    def log_event(self, order):
        print("Logging order event")


class OrderService:
    def __init__(self, rules, repository, email_service, logger):
        self.rules = rules
        self.repository = repository
        self.email_service = email_service
        self.logger = logger

    def create_order(self, order):
        self.rules.validate(order)

        order["price"] = self.rules.calculate_price(order)

        self.repository.save(order)
        self.email_service.send_confirmation(order)
        self.logger.log_event(order)


if __name__ == "__main__":
    order = {
        "id": 101,
        "items": ["Laptop", "Mouse"]
    }

    rules = OrderRules()
    repository = OrderRepository()
    email_service = EmailService()
    logger = AuditLogger()

    service = OrderService(
        rules,
        repository,
        email_service,
        logger
    )

    service.create_order(order)