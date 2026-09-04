from abc import ABC, abstractmethod


class Printable(ABC):
    @abstractmethod
    def print_document(self):
        pass


class Scannable(ABC):
    @abstractmethod
    def scan_document(self):
        pass


class Faxable(ABC):
    @abstractmethod
    def fax_document(self):
        pass


class BasicPrinter(Printable):
    def print_document(self):
        print("Printing document")


class MultiFunctionPrinter(Printable, Scannable, Faxable):
    def print_document(self):
        print("Printing document")

    def scan_document(self):
        print("Scanning document")

    def fax_document(self):
        print("Faxing document")


if __name__ == "__main__":
    basic_printer = BasicPrinter()
    basic_printer.print_document()

    multifunction_printer = MultiFunctionPrinter()
    multifunction_printer.print_document()
    multifunction_printer.scan_document()
    multifunction_printer.fax_document()

'''
PS C:\Users\Shikha Pandey\Documents\github\solid-design-principles> python 04-ISP/python/refactored.py"
Printing document
Printing document
Scanning document
Faxing document
'''