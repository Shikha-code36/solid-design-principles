# Interface Segregation Principle (ISP)

## Definition

> Clients should not be forced to depend on interfaces they do not use.

In simple terms:

> Prefer small, focused interfaces over large interfaces that force classes to implement unnecessary methods.

---

## Why ISP?

ISP keeps abstractions focused and prevents classes from depending on capabilities they do not need.

Without ISP:

- classes are forced to implement irrelevant methods
- dummy implementations appear
- `NotImplementedError` or runtime errors become common
- abstractions become harder to understand
- changes to one capability can affect unrelated clients
- inheritance hierarchies become misleading

---

## The Problem

Consider a large `Machine` interface:

```text
Machine
├── print_document()
├── scan_document()
└── fax_document()
```

A `BasicPrinter` can only print.

But because it depends on `Machine`, it is forced to provide implementations for scanning and faxing too.

Example:

```python
class BasicPrinter(Machine):
    def print_document(self):
        print("Printing document")

    def scan_document(self):
        raise NotImplementedError

    def fax_document(self):
        raise NotImplementedError
```

The printer is being forced to depend on methods it does not need.

---

## Refactored Design

Split the large interface into smaller capability-based interfaces:

```text
Printable
└── print_document()

Scannable
└── scan_document()

Faxable
└── fax_document()
```

Now:

```text
BasicPrinter
└── Printable

MultiFunctionPrinter
├── Printable
├── Scannable
└── Faxable
```

Each class implements only the capabilities it supports.

---

## Core Mental Model

Ask:

> "Is this class being forced to implement or depend on methods it does not need?"

If yes, the interface may be too large.

---

## Common ISP Smells

Watch for:

- `NotImplementedError`
- empty method bodies
- dummy return values
- runtime errors for unsupported operations
- classes implementing many unused methods
- clients depending on a large interface but using only a small part of it

---

## Backend / Database Example

Instead of one large storage interface:

```text
Storage
├── read()
├── write()
├── begin()
├── commit()
└── rollback()
```

we can model capabilities separately:

```text
ReadableStorage
└── read()

WritableStorage
└── write()

TransactionalStorage
├── begin()
├── commit()
└── rollback()
```

A read-only component can depend only on `ReadableStorage`.

A normal key-value store can implement `ReadableStorage` and `WritableStorage`.

A transactional database can implement all three.

---

## ISP vs LSP

### LSP

> Can this subtype safely replace its parent without breaking the behavioral contract?

### ISP

> Should this class or client have been forced to depend on this entire interface in the first place?

A large interface can sometimes cause an LSP problem.

For example:

```text
Database
├── read()
└── write()
```

A `ReadOnlyDatabase` that throws from `write()` may violate LSP.

ISP may suggest separating:

```text
Readable
Writable
```

so the read-only implementation never promises write capability.

---

## ISP Does NOT Mean

ISP does **not** mean every interface should contain exactly one method.

The goal is to group methods into coherent capabilities.

For example:

```text
Transaction
├── begin()
├── commit()
└── rollback()
```

can be a perfectly reasonable interface because those operations belong together.

---

## Code Review Checklist

Ask:

- Does every client need all methods in this interface?
- Are implementations throwing errors for unsupported operations?
- Are there empty or dummy implementations?
- Can the interface be split by capability?
- Are unrelated operations grouped together?
- Is the client depending on much more behavior than it uses?

---

## SRP vs OCP vs LSP vs ISP

### SRP

> Does this class have multiple reasons to change?

### OCP

> Can expected variations be added without repeatedly modifying stable code?

### LSP

> Can a child safely replace its parent?

### ISP

> Is a client forced to depend on methods it does not need?

---

## Key Takeaway

> Interfaces should expose only the capabilities their clients actually need.

Good ISP design:

```text
Large interface
      ↓
Split by capability
      ↓
Clients depend only on what they use
```

---

## Code

### Python

- [Bad Design](./python/bad_design.py)
- [Refactored Design](./python/refactored.py)

### C++

- [Bad Design](./cpp/bad_design.cpp)
- [Refactored Design](./cpp/refactored.cpp)
