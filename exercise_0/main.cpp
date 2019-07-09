#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Result {
    int vowels = 0;
    int consonant = 0;
    int others = 0;
};

const std::string vowels = "AEIOUYaeouy";

Result countLetter(const std::string& firstLetter) {
    Result result{};
    for (const auto &letter: firstLetter){
        if (isalpha(letter))
            if (vowels.find(letter) != std::string::npos)
                ++result.vowels;
            else
                ++result.consonant;
        else
            ++result.others;
    }
    return result;
}


int main(int argc, char **argv) {
    std::string line;
    std::cout <<argv[0]<< std::endl;

    std::string firstLetters;
    Result res;
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            while (file>>line) {
                firstLetters+=line[0];
            }
            res = countLetter(firstLetters);
        }
        else
            perror("file not open");
    }else if (argc == 1) {
        std::cout << "Enter words (q to quit):" << std::endl;
        while ((std::cin >> line)&&(line != "q")) {
                firstLetters+=line[0];
        }
        res = countLetter(firstLetters);
    }
    std::cout <<res.vowels <<" words beginning with vowels" << std::endl;
    std::cout <<res.consonant <<" words beginning with consonants " << std::endl;
    std::cout <<res.others <<" others" << std::endl;
    return 0;
}