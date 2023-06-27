import VectorsLib as vec
import random

class Creatures:
    def __init__(self,SIZE_WORLD):
        self.vector = vec.Vector(random.randint(0,16),random.randint(0,SIZE_WORLD))