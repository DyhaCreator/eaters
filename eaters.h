#include <iostream>
#include "myFunctions.h"

class Eaters{
    public:
        int x;
        int speed = 0;
        int eat = 100;
    Eaters(int SIZE_WORLD){
        this->x = random(0, SIZE_WORLD);
    }
};