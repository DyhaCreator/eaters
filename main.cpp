#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "eaters.h"

int main(){
    int SIZE_WORLD;
    std::vector<int> data = std::vector<int>();
    std::string path, dataStr;
    std::cin >> path;
    std::ifstream file;
    file.open(path);
    
    while(!file.eof()){
        char ch;
        file.get(ch);
        dataStr += ch;
    }

    SIZE_WORLD = dataStr.size();
    
    for(int i = 0; i < dataStr.size(); i++){
        int n = dataStr[i];
        data.push_back(n);
    }

    Eaters a = Eaters(SIZE_WORLD);
    std::cout << a.x << std::endl;

    /*for(int i = 0; i < data.size(); i++){
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;*/

    return 0;
}