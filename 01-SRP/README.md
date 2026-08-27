# Single Responsibility Principle (SRP)

## Definition

> A class should have one reason to change.

SRP does not mean that a class should have only one method or perform only one operation.

The goal is to keep responsibilities that change for different reasons separate.

---

## Problem

Consider an `OrderService` that handles:

- Order validation
- Price calculation
- Database persistence
- Email notification
- Audit logging

These responsibilities can change independently.

For example:

- Business rules may change.
- Database implementation may change.
- Email provider may change.
- Logging requirements may change.

This makes the class harder to maintain and test.

---

## Bad Design

See:

- `python/bad_design.py`
- `cpp/bad_design.cpp`

`OrderService` contains multiple independent responsibilities.

---

## Refactored Design

Responsibilities are separated into:

- `OrderRules` → validation and price calculation
- `OrderRepository` → persistence
- `EmailService` → notification
- `AuditLogger` → logging
- `OrderService` → coordinates the order creation workflow

See:

- `python/refactored.py`
- `cpp/refactored.cpp`

---

## Important Mental Model

When reviewing a class, ask:

> What are the independent reasons this class could change?

If multiple unrelated reasons exist, the class may be violating SRP.

---

## SRP Does NOT Mean

- One method per class
- Very small classes everywhere
- Splitting every operation into a separate class
- Avoiding classes with multiple methods

Related responsibilities can stay together when they have the same reason to change.

---

## Code Review Questions

- Are unrelated responsibilities mixed together?
- Do these responsibilities change independently?
- Is business logic mixed with infrastructure concerns?
- Can each responsibility be tested independently?
- Would changing one concern require modifying unrelated code?

---

## Key Takeaway

Keep things together when they change together.

Separate things when they change independently.