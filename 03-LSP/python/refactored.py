class Bird:
    def eat(self):
        print("Eating")


class FlyingBird(Bird):
    def fly(self):
        print("Flying")


class Sparrow(FlyingBird):
    def fly(self):
        print("Sparrow flying")


class Penguin(Bird):
    def eat(self):
        print("Penguin eating")


def make_bird_eat(bird):
    bird.eat()


def make_bird_fly(bird):
    bird.fly()


if __name__ == "__main__":
    sparrow = Sparrow()
    penguin = Penguin()

    make_bird_eat(sparrow)
    make_bird_eat(penguin)

    make_bird_fly(sparrow)

'''
Output:
Eating
Penguin eating
Sparrow flying
'''