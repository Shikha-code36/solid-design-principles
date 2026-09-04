#include <iostream>
#include <stdexcept>

class Machine {
public:
    virtual void printDocument() = 0;
    virtual void scanDocument() = 0;
    virtual void faxDocument() = 0;

    virtual ~Machine() = default;
};

class BasicPrinter : public Machine {
public:
    void printDocument() override {
        std::cout << "Printing document\n";
    }

    void scanDocument() override {
        throw std::runtime_error("BasicPrinter cannot scan");
    }

    void faxDocument() override {
        throw std::runtime_error("BasicPrinter cannot fax");
    }
};

int main() {
    BasicPrinter printer;

    printer.printDocument();

    return 0;
}