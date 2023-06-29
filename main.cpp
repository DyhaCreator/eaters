#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "eaters.h"

void printArr(std::vector<int>data){
    for(int i = 0; i < data.size(); i++){
        if(data[i] > 100){
            std::cout << data[i] << ' ';
        }
        else if(data[i] > 10){
            std::cout << " " << data[i] << ' ';
        }
        else{
            std::cout << "  " << data[i] << ' ';
        }
    }
    std::cout << std::endl;
}

int main(){
    int SIZE_WORLD;
    int EAT_TO_DIVISION;
    std::vector<int> data = std::vector<int>();
    std::string path, dataStr;
    std::cin >> path;

    randFileBytes(path, 16);

    std::ifstream file;
    file.open(path);
    
    while(!file.eof()){
        char ch;
        file.get(ch);
        dataStr += ch;
    }

    file.close();

    SIZE_WORLD = dataStr.size();
    EAT_TO_DIVISION = 512;
    
    for(int i = 0; i < dataStr.size(); i++){
        int n = dataStr[i];
        data.push_back(n + 127);
    }

    printArr(data);

    Eaters unit = Eaters(SIZE_WORLD);

    std::vector<Eaters>units = std::vector<Eaters>();
    units.push_back(unit);
    for(int j = 0; j < 15; j++){
        for(int i = 0; i < units.size(); i ++){
            units[i].eat += data[units[i].x];
            data[units[i].x] = 0;
            if(units[i].x == 0){
                units[i].speed = 1;
            }
            else if(units[i].x == SIZE_WORLD - 1){
                units[i].speed = -1;
            }
            else{
                if(data[units[i].x + 1] > data[units[i].x - 1]){
                    units[i].speed = 1;
                }
                else if(data[units[i].x + 1] < data[units[i].x - 1]){
                    units[i].speed = -1;
                }
            }
            units[i].x += units[i].speed;
            if(units[i].eat > EAT_TO_DIVISION){
                unit = Eaters(SIZE_WORLD);
                units.push_back(unit);
            }
        }
        printArr(data);
        //std::cout << units.size() << ' ' << units[0].eat << std::endl;
    }

    return 0;
}