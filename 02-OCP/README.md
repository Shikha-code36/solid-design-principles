# Open/Closed Principle (OCP)

## Definition

> Software entities should be open for extension but closed for modification.

In simple terms:

> We should be able to add new behavior without repeatedly modifying stable existing code.

---

## Why OCP?

As a system grows, new variants of existing behavior are often added.

For example:

- New notification types
- New payment methods
- New storage implementations
- New cache eviction policies
- New output formats

If every new variant requires modifying the same existing class, that class becomes harder to maintain and more likely to introduce regressions.

OCP encourages us to design an extension point for behavior that is expected to vary.

---

## The Problem

Consider a notification service that supports:

- Email
- SMS
- Slack

A straightforward implementation might use conditional logic:

```text
if notification_type == "email":
    ...

elif notification_type == "sms":
    ...

elif notification_type == "slack":
    ...
```

When a new notification type such as WhatsApp is introduced, the existing `NotificationService` must be modified.

This means new functionality requires changes to existing code.

---

## Bad Design

See:

- `python/bad_design.py`
- `cpp/bad_design.cpp`

The `NotificationService` contains the implementation logic for every notification type.

Adding a new notification requires modifying this class.

### Problem

```text
New notification type
        ↓
Modify NotificationService
        ↓
Add another if/elif
        ↓
Existing code changes
```

As the number of notification types grows, the class becomes increasingly difficult to maintain.

---

## Refactored Design

We introduce an abstraction representing the notification behavior.

```text
                  Notification
                   abstraction
                       │
          ┌────────────┼────────────┐
          ↓            ↓            ↓
        Email          SMS         Slack
```

Each notification type implements the common `Notification` interface.

`NotificationService` works with the abstraction rather than knowing the details of each notification type.

See:

- `python/refactored.py`
- `cpp/refactored.cpp`

---

## Adding a New Notification

Suppose we need to add WhatsApp.

Instead of modifying `NotificationService`, we add:

```text
WhatsAppNotification
        ↓
implements Notification
```

The existing code remains unchanged:

```text
NotificationService      → unchanged
EmailNotification        → unchanged
SMSNotification          → unchanged
SlackNotification        → unchanged

WhatsAppNotification     → new code
```

This demonstrates:

> **Open for extension, closed for modification.**

---

## Important Mental Model

When a new variation is introduced, ask:

> Can I add the new behavior by extending the system instead of modifying stable existing code?

If the same class repeatedly needs new `if/elif` or `switch` branches whenever a new variant is introduced, it may be an OCP violation.

---

## OCP Does NOT Mean

OCP does not mean:

- Existing code can never be modified.
- Every `if/else` is an OCP violation.
- Every class needs an interface.
- Everything must use inheritance.
- We should create abstractions for every possible future requirement.

The goal is to identify behavior that genuinely varies and provide an appropriate extension point.

---

## When OCP Is Useful

OCP is particularly useful when:

- New variants are expected regularly.
- Existing behavior is stable and well-tested.
- Changes frequently affect the same conditional logic.
- Adding a new feature should not risk breaking existing implementations.

Examples:

- Payment methods
- Notification channels
- Cache eviction policies
- Storage backends
- Serialization formats
- Authentication providers

---

## DB / Cache Example

Consider a cache supporting different eviction policies:

```text
                 EvictionPolicy
                       │
          ┌────────────┼────────────┐
          ↓            ↓            ↓
         LRU          LFU         Random
```

A bad design might contain:

```python
if policy == "LRU":
    ...

elif policy == "LFU":
    ...

elif policy == "Random":
    ...
```

Adding a new policy requires modifying the cache implementation.

With an `EvictionPolicy` abstraction, a new policy can be added as a new implementation without modifying the stable cache logic.

This is a practical application of OCP in database/cache systems.

---

## SRP vs OCP

### SRP asks:

> What responsibilities should be separated?

SRP helps organize responsibilities around their reasons for change.

### OCP asks:

> What behavior is likely to vary, and how can it be extended safely?

OCP helps design extension points for changing behavior.

```text
SRP
 ↓
Separate independent responsibilities

OCP
 ↓
Make expected variations extensible
```

---

## Code Review Checklist

When reviewing code, ask:

- Does adding a new variant require modifying this class?
- Is there a growing `if/elif` or `switch` based on type?
- Is the varying behavior isolated?
- Could an abstraction or strategy represent the variation?
- Is the abstraction justified by actual or expected variation?
- Would introducing the abstraction make the design more complex than necessary?

---

## Common Mistakes

### 1. Treating every conditional as an OCP violation

Not every `if/else` needs an abstraction.

### 2. Creating abstractions too early

If there is no meaningful variation, introducing interfaces and multiple classes can be unnecessary complexity.

### 3. Overengineering

The goal is not to maximize the number of classes.

The goal is to make meaningful variation easier to extend.

---

## Key Takeaway

> Identify behavior that changes independently or varies by type, isolate that behavior behind an appropriate extension point, and allow new variants to be added without repeatedly modifying stable core logic.

---

## Code

### Python

- [Bad Design](./python/bad_design.py)
- [Refactored Design](./python/refactored.py)

### C++

- [Bad Design](./cpp/bad_design.cpp)
- [Refactored Design](./cpp/refactored.cpp)
