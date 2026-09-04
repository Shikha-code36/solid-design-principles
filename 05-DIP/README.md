# Dependency Inversion Principle (DIP)

## Definition

> High-level modules should not depend on low-level modules. Both should depend on abstractions.

> Abstractions should not depend on details. Details should depend on abstractions.

In simple terms:

> High-level business logic should depend on an abstraction, not directly on a concrete implementation.

---

## Why DIP?

DIP reduces tight coupling between business logic and implementation details.

Without DIP:

- high-level code is tightly coupled to concrete classes
- replacing an implementation requires modifying business logic
- unit testing becomes harder
- infrastructure details leak into business logic
- adding alternative implementations becomes difficult

---

## The Problem

Consider a payment service:

```text
PaymentService
      ↓
RazorpayGateway
```

If `PaymentService` directly creates `RazorpayGateway`, it becomes coupled to Razorpay.

If we later want to support GPay or PayPal, the payment service needs to change.

---

## Bad Design

```python
class PaymentService:
    def __init__(self):
        self.gateway = RazorpayGateway()
```

The high-level module (`PaymentService`) directly depends on the low-level detail (`RazorpayGateway`).

---

## Refactored Design

Introduce an abstraction:

```text
             PaymentService
                    ↓
             PaymentGateway
              ↑      ↑      ↑
          Razorpay  GPay   PayPal
```

`PaymentService` only knows about `PaymentGateway`.

The concrete gateways implement that abstraction.

Now a new payment provider can be added without changing `PaymentService`.

---

## The Core Mental Model

Ask:

> "Does my high-level business logic directly depend on a concrete implementation detail?"

If yes, look for an opportunity to introduce an abstraction.

Another useful question:

> "Can I replace this implementation without modifying the high-level business logic?"

If yes, the design is likely better decoupled.

---

## Dependency Injection

Dependency Injection is a common technique for implementing DIP.

Instead of creating the dependency inside the class:

```python
class PaymentService:
    def __init__(self):
        self.gateway = RazorpayGateway()
```

inject it from outside:

```python
class PaymentService:
    def __init__(self, gateway):
        self.gateway = gateway
```

Then:

```python
service = PaymentService(RazorpayGateway())
```

The service does not need to know which concrete gateway was selected.

---

## DIP vs Dependency Injection

These terms are related but not identical.

### DIP

A **design principle**:

> High-level and low-level modules should depend on abstractions.

### Dependency Injection

A **technique**:

> Provide an object's dependencies from outside instead of creating them internally.

Dependency Injection is one way to achieve DIP.

---

## Testing Benefit

DIP makes unit testing easier.

Instead of:

```text
PaymentService
      ↓
Real Razorpay API
```

we can provide a fake implementation:

```text
PaymentService
      ↓
PaymentGateway
      ↑
FakePaymentGateway
```

The test does not need to call a real payment provider.

Example:

```python
class FakePaymentGateway:
    def charge(self, amount):
        print("Fake payment successful")
```

Then:

```python
service = PaymentService(FakePaymentGateway())
service.pay(1000)
```

---

## Backend / Database Example

The same idea applies to storage:

```text
OrderService
      ↓
OrderRepository
      ↑
 ┌────┴─────────┐
MySQLRepository
PostgresRepository
```

`OrderService` should focus on business logic.

It should not need to know whether orders are stored in MySQL, PostgreSQL, MongoDB, or another implementation.

---

## Backend / Cache Example

Similarly:

```text
ApplicationService
        ↓
    CacheInterface
       ↑      ↑
     Redis   InMemory
```

The application depends on the cache abstraction rather than directly constructing a Redis client.

---

## Dependency Direction

### Without DIP

```text
High-level module
        ↓
Low-level module
```

### With DIP

```text
        High-level module
                ↓
           Abstraction
                ↑
        Low-level module
```

The dependency direction is inverted.

That is where the name **Dependency Inversion** comes from.

---

## DIP vs OCP

### OCP

Asks:

> Can new implementations be added without repeatedly modifying stable code?

### DIP

Asks:

> Does the high-level code depend on abstractions instead of concrete implementation details?

DIP often helps us achieve OCP because new implementations can be introduced behind an abstraction.

---

## DIP vs ISP

### ISP

Asks:

> Is the client forced to depend on methods it does not need?

### DIP

Asks:

> Is the client depending directly on a concrete implementation instead of an abstraction?

A good design can use both:

```text
Small interface
      +
Dependency on abstraction
```

---

## Code Review Checklist

When reviewing code, ask:

- Does a high-level class directly instantiate infrastructure classes?
- Does business logic depend on a concrete database, cache, API client, or payment provider?
- Can the implementation be replaced without modifying business logic?
- Can a fake or mock implementation be injected for testing?
- Is an abstraction actually needed at this boundary?
- Are dependencies created internally when they could be supplied externally?

---

## Common Mistakes

### Creating interfaces everywhere

DIP does not mean every class needs an interface.

Introduce abstractions where they provide meaningful decoupling or allow expected variation.

### Confusing DIP with Dependency Injection

Dependency Injection is a technique, not the principle itself.

### Abstracting too early

If there is no meaningful variation or boundary, adding an interface may only add complexity.

---

## SOLID Summary

### SRP

> Does this class have multiple reasons to change?

### OCP

> Can expected variations be added without repeatedly modifying stable code?

### LSP

> Can a child safely replace its parent?

### ISP

> Is a client forced to depend on methods it does not need?

### DIP

> Does high-level code depend on abstractions rather than concrete details?

---

## Key Takeaway

> Depend on what the code needs, not on how that need is implemented.

Good DIP design:

```text
Business Logic
      ↓
   Abstraction
      ↑
Implementation
```

This reduces coupling, improves testability, and makes implementation changes easier.

---

## Code

### Python

- [Bad Design](./python/bad_design.py)
- [Refactored Design](./python/refactored.py)

### C++

- [Bad Design](./cpp/bad_design.cpp)
- [Refactored Design](./cpp/refactored.cpp)
