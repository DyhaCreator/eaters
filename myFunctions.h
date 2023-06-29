#include <iostream>
#include <fstream>
#include <vector>
#include <random>

int random(int min, int max)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);

    return dist6(rng);
}

void randFileBytes(std::string path, int size)
{
    std::vector<int>data = std::vector<int>();
    std::ofstream file;
    file.open(path);
    std::cout << "generating bytes to file" << std::endl;
    for(int i = 0; i < size; i++){
        int n = random(0, 255);
        data.push_back(n);
        std::cout << n << ' ';
        file << char(n);
    }
    file.close();
    std::cout << std::endl;
}