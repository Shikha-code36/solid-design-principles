from abc import ABC, abstractmethod

class Machine(ABC):

    @abstractmethod
    def print_document(self):
        pass

    @abstractmethod
    def scan_document(self):
        pass

    @abstractmethod
    def fax_document(self):
        pass


class BasicPrinter(Machine):

    def print_document(self):
        print("Printing document")

    def scan_document(self):
        raise NotImplementedError("BasicPrinter cannot scan")

    def fax_document(self):
        raise NotImplementedError("BasicPrinter cannot fax")

if __name__ == "__main__":
    printer = BasicPrinter()

    printer.print_document()

'''
PS C:\Users\Shikha Pandey\Documents\github\solid-design-principles>python 04-ISP/python/bad_design.py"
Printing document
'''