import VectorsLib as vec
import random

class Creatures:
    def __init__(self,SIZE_WORLD):
        self.x = random.randint(0,SIZE_WORLD)
        self.eat = 100
        self.speed = 0