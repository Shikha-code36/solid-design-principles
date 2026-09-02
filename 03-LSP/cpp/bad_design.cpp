#include <iostream>

class Bird {
public:
    virtual void fly() {
        std::cout << "Flying\n";
    }

    virtual ~Bird() = default;
};

class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow flying\n";
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Penguins cannot fly");
    }
};

void makeBirdFly(Bird& bird) {
    bird.fly();
}

int main() {
    Sparrow sparrow;
    Penguin penguin;

    makeBirdFly(sparrow);
    makeBirdFly(penguin);

    return 0;
}