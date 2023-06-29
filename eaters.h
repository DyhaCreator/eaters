#include <iostream>

int random(int min, int max)
{
  srand(time(NULL));
  int num = min + rand() % (max - min + 1);
  return num;
}

class Eaters{
    public:
        int x;
    Eaters(int SIZE_WORLD){
        this->x = random(0, SIZE_WORLD);
    }
};