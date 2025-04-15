#include <iostream>
#include <fstream>
#include <string>

int main() {

    if (std::ifstream fin("14.04(test).txt"); fin) {
        std::ofstream fout("14.04(result).txt");

        std::string line;
        while (std::getline(fin, line)) {
            if (line.length() > 0 &&
                line.find_first_not_of(' ') != line.npos) { 
                fout << line << '\n';
            }
        }
    }

    else {
        std::cerr << "invalid file stream\n";
    }
    
    return 0;
}
