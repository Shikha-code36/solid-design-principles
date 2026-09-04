#include <iostream>

class Printable {
public:
    virtual void printDocument() = 0;
    virtual ~Printable() = default;
};

class Scannable {
public:
    virtual void scanDocument() = 0;
    virtual ~Scannable() = default;
};

class Faxable {
public:
    virtual void faxDocument() = 0;
    virtual ~Faxable() = default;
};

class BasicPrinter : public Printable {
public:
    void printDocument() override {
        std::cout << "Printing document\n";
    }
};

class MultiFunctionPrinter :
    public Printable,
    public Scannable,
    public Faxable {

public:
    void printDocument() override {
        std::cout << "Printing document\n";
    }

    void scanDocument() override {
        std::cout << "Scanning document\n";
    }

    void faxDocument() override {
        std::cout << "Faxing document\n";
    }
};

int main() {
    BasicPrinter basicPrinter;
    basicPrinter.printDocument();

    MultiFunctionPrinter multiFunctionPrinter;
    multiFunctionPrinter.printDocument();
    multiFunctionPrinter.scanDocument();
    multiFunctionPrinter.faxDocument();

    return 0;
}