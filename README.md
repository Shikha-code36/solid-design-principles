# SOLID Design Principles — Python & C++

SOLID is a set of five object-oriented design principles that help us write software that is easier to **maintain, extend, test, and modify**.

This repository teaches SOLID through **practical examples in both Python and C++**, focusing on the design problem behind each principle rather than just memorizing definitions.

## Why SOLID?

As software grows, poor design can lead to:

- Tightly coupled components
- Difficult-to-test code
- Large classes with multiple responsibilities
- Changes in one part of the system breaking another
- Difficult feature additions
- High maintenance cost

SOLID provides guidelines for designing components so that they are more **cohesive, loosely coupled, and easier to evolve**.

> SOLID is not a strict set of rules. It is a set of design principles that help us reason about software structure and change.

## The Five Principles

### S — Single Responsibility Principle

A class should have **one reason to change**.

[Study SRP →](./01-SRP/README.md)

### O — Open/Closed Principle

Software entities should be **open for extension but closed for modification**.

[Study OCP →](./02-OCP/README.md)

### L — Liskov Substitution Principle

Subtypes should be **substitutable for their base types** without breaking the correctness of the program.

[Study LSP →](./03-LSP/README.md)

### I — Interface Segregation Principle

Clients should not be forced to depend on interfaces they **do not use**.

[Study ISP →](./04-ISP/README.md)

### D — Dependency Inversion Principle

High-level modules should not depend directly on low-level modules. Both should depend on **abstractions**.

[Study DIP →](./05-DIP/README.md)

## Repository Structure

```text
solid-design-principles/
├── 01-SRP/
├── 02-OCP/
├── 03-LSP/
├── 04-ISP/
└── 05-DIP/
```

Each principle follows the same structure:

```text
01-SRP/
├── README.md
├── python/
│   ├── bad_design.py
│   └── refactored.py
└── cpp/
    ├── bad_design.cpp
    └── refactored.cpp
```

The same structure is used for each SOLID principle.

## How This Repository Is Organized

Each principle is studied using the same approach:

1. Understand the problem
2. Understand the principle
3. Identify the violation
4. Refactor the design
5. Implement it in Python
6. Implement the same design problem in C++
7. Apply it in code-review scenarios
8. Look at realistic backend / database / systems examples
9. Practice

Python is used as the primary language, with C++ implementations of the **same examples and design problems** to understand the principles independently of language syntax.

## Who Is This For?

This repository is useful for:

- Developers learning object-oriented design
- Python developers learning C++ design concepts
- C++ developers looking for practical SOLID examples
- Backend engineers preparing for code reviews and design interviews
- Developers who want to understand **when** to apply SOLID rather than just memorize definitions

## Goal

The goal is not to memorize the five definitions.

The goal is to be able to look at unfamiliar code and reason about:

- Where the design is becoming difficult to change
- Where responsibilities are mixed
- Where components are tightly coupled
- Where abstractions would help
- How to refactor the design
- Whether a SOLID principle actually applies

The ultimate goal is to apply SOLID principles during **code reviews, system design discussions, and real-world software development**.
