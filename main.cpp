#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string path, data;
    std::cin >> path;
    std::ifstream file;
    file.open(path);
    getline(file, data);
    std::cout << data << std::endl;
    return 0;
}