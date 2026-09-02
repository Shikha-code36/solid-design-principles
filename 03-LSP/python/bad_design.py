class Bird:
    def fly(self):
        print("Flying")

class Sparrow(Bird):
    def fly(self):
        print("Sparrow flying")

class Penguin(Bird):
    def fly(self):
        raise Exception("Penguin can't fly")

def make_bird_fly(bird):
    bird.fly()

if __name__ == "__main__":
    sparrow = Sparrow()
    penguin = Penguin()

    make_bird_fly(sparrow)
    make_bird_fly(penguin)

'''
Output:
Sparrow flying
Traceback (most recent call last):
  File "c:\Users\Shikha Pandey\Documents\github\solid-design-principles\03-LSP\python\bad_design.py", line 21, in <module>
    make_bird_fly(penguin)
  File "c:\Users\Shikha Pandey\Documents\github\solid-design-principles\03-LSP\python\bad_design.py", line 14, in make_bird_fly
    bird.fly()
  File "c:\Users\Shikha Pandey\Documents\github\solid-design-principles\03-LSP\python\bad_design.py", line 11, in fly
    raise Exception("Penguin can't fly")
Exception: Penguin can't fly
'''

# The problem: make_bird_fly() expects any Bird to work, but Penguin breaks that expectation.