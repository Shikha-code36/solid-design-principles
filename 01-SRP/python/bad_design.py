class OrderService:
    def create_order(self, order):
        self.validate_order(order)
        self.calculate_price(order)
        self.save_to_database(order)
        self.send_confirmation_email(order)
        self.log_event(order)

    def validate_order(self, order):
        print("Validating order")

    def calculate_price(self, order):
        print("Calculating price")

    def save_to_database(self, order):
        print("Saving order to database")

    def send_confirmation_email(self, order):
        print("Sending confirmation email")

    def log_event(self, order):
        print("Logging order event")


if __name__ == "__main__":
    order = {
        "id": 101,
        "items": ["Laptop", "Mouse"]
    }

    service = OrderService()
    service.create_order(order)