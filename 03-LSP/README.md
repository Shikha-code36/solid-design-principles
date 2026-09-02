# Liskov Substitution Principle (LSP)

## Definition

> Objects of a superclass should be replaceable with objects of its subclasses without breaking the correctness of the program.

In simple terms:

> If code expects a parent type, replacing it with a child type should not break the expected behavior.

---

## Why LSP?

LSP helps us design abstractions whose subclasses actually honor the behavior promised by the parent.

Without LSP:

- subclasses may throw unexpected exceptions
- subclasses may reject valid operations
- callers need special-case checks
- inheritance becomes misleading
- abstractions become difficult to use correctly

---

## The Problem

Consider a `Bird` abstraction with a `fly()` method.

```text
Bird
├── Sparrow
└── Penguin
```

A Sparrow can fly, but a Penguin cannot.

If `Bird` promises that every Bird can fly, then Penguin cannot correctly substitute for Bird.

---

## Bad Design

The parent class requires:

```python
class Bird:
    def fly(self):
        pass
```

But:

```python
class Penguin(Bird):
    def fly(self):
        raise NotImplementedError
```

Now code expecting a `Bird` may break when given a Penguin.

---

## Refactored Design

Separate the capabilities:

```text
Bird
├── FlyingBird
│   └── Sparrow
└── Penguin
```

`Bird` represents behavior common to all birds.

`FlyingBird` represents the additional ability to fly.

Now:

- Every Bird can eat.
- Every FlyingBird can fly.
- Penguin does not need to pretend that it can fly.

---

## The Core Mental Model

Ask:

> "If I replace the parent object with this child object, will existing code still work correctly?"

If the answer is no, investigate an LSP violation.

---

## LSP Is About Contracts

LSP is not simply about inheritance.

The important question is:

> What behavior does the parent abstraction promise to its callers?

For example, if:

```text
Database.write()
```

promises that data can be written successfully, then a `ReadOnlyDatabase` that throws an exception when `write()` is called may violate LSP.

The problem may indicate that the abstraction itself is wrong.

---

## LSP vs SRP vs OCP

### SRP

Asks:

> Does this class have multiple reasons to change?

### OCP

Asks:

> Can expected new variations be added without repeatedly modifying stable code?

### LSP

Asks:

> Can this subtype safely replace its parent?

---

## Code Review Checklist

When reviewing inheritance, ask:

- Does the child honor the parent's behavioral contract?
- Can the child be substituted wherever the parent is expected?
- Does the child unexpectedly throw exceptions?
- Does the child weaken or change expected behavior?
- Does the caller need special checks for specific subclasses?
- Is inheritance actually representing a valid "is-a" relationship?

---

## Common Mistake

LSP does **not** mean:

> "Every child must implement every parent method in exactly the same way."

Different implementations are completely fine.

The important thing is that the child's behavior remains compatible with the expectations established by the parent abstraction.

---

## Key Takeaway

> LSP is about behavioral substitutability.

Good inheritance means:

```text
Parent contract
      ↓
    Child
      ↓
Still honors the contract
```

If the child cannot honor the parent's contract, the abstraction or inheritance relationship probably needs to be redesigned.

---

## Code

### Python

- [Bad Design](./python/bad_design.py)
- [Refactored Design](./python/refactored.py)

### C++

- [Bad Design](./cpp/bad_design.cpp)
- [Refactored Design](./cpp/refactored.cpp)
