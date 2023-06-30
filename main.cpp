#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "eaters.h"

std::vector<Eaters> del(std::vector<Eaters> unit1, int index){
    std::vector<Eaters> unit2 = std::vector<Eaters>();
    for(int i = 0; i < unit1.size(); i++){
        if(i != index){
            unit2.push_back(unit1[i]);
        }
    }
    return unit2;
}

void printArr(std::vector<int>data){
    for(int i = 0; i < data.size(); i++){
        if(data[i] >= 100){
            std::cout << data[i] << ' ';
        }
        else if(data[i] >= 10){
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
    int EAT_TO_MOVE;
    std::vector<int> data = std::vector<int>();
    std::string path, dataStr;
    std::cin >> path;

    randFileBytes(path, 4);

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
    EAT_TO_MOVE = 30;
    
    for(int i = 0; i < dataStr.size(); i++){
        int n = dataStr[i];
        data.push_back(n + 128);
    }

    printArr(data);

    Eaters unit = Eaters(SIZE_WORLD);

    std::vector<Eaters>units = std::vector<Eaters>();
    units.push_back(unit);
    while(units.size() > 0){
        std::vector<int>indexes = std::vector<int>();
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
            units[i].eat -= EAT_TO_MOVE;
            if(units[i].eat > EAT_TO_DIVISION){
                unit = Eaters(SIZE_WORLD);
                units.push_back(unit);
            }
            if(units[i].eat <= 0){
                indexes.push_back(i);
            }
        }
        for(int i = 0; i < indexes.size(); i ++){
            units = del(units, indexes[i] - i);
        }
        printArr(data);
        //std::cout << units.size() << ' ' << units[0].eat << std::endl;
    }

    return 0;
}