#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(){
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
    
    for(int i = 0; i < dataStr.size(); i++){
        int n = dataStr[i];
        std::cout << n << std::endl;
    }

    return 0;
}