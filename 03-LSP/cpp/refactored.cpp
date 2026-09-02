#include <iostream>

class Bird {
public:
    virtual void eat() = 0;
    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    void eat() override {
        std::cout << "Eating\n";
    }

    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        std::cout << "Sparrow flying\n";
    }
};

class Penguin : public Bird {
public:
    void eat() override {
        std::cout << "Penguin eating\n";
    }
};

void makeBirdEat(Bird& bird) {
    bird.eat();
}

void makeBirdFly(FlyingBird& bird) {
    bird.fly();
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    makeBirdEat(sparrow);
    makeBirdEat(penguin);

    makeBirdFly(sparrow);

    return 0;
}