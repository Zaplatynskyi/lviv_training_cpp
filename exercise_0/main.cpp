#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Result {
    int vowels;
    int consonant;
    int others;
};

Result countLetter(std::string firstLetter) {
    Result result;
    std::string vowels = "AEIOUYaeouy";
    int countVowels = 0;
    int countConsonant = 0;
    int countOther = 0;
    for (int i = 0; i < firstLetter.length(); i++) {
        if (isalpha(firstLetter[i]))
            if (vowels.find(firstLetter[i]) != std::string::npos)
                countVowels += 1;
            else
                countConsonant += 1;
        else
            countOther += 1;
    }
    result.vowels = countVowels;
    result.consonant = countConsonant;
    result.others = countOther;
    return result;
}

std::string firstLetterWord(std::string inputText) {
    std::string result = "";
    bool v = true;
    for (int i = 0; i < inputText.length(); i++) {
        if (inputText[i] == ' ')
            v = true;
        else if (inputText[i] != ' ' && v == true) {
            result.push_back(inputText[i]);
            v = false;
        }
    }
    return result;
}


int main() {
    std::string line;
    std::string firstLetters;
    int args;
    Result res;
    std::cout << "Enter 1 for read from file or 2  for read from console: " << std::endl;
    std::cin >> args;
    if (args == 1) {
        std::ifstream file("file.txt");
        if (file.is_open()) {
            while (getline(file, line)) {
                firstLetters.append(firstLetterWord(line));
            }
            res = countLetter(firstLetters);
            file.close();
        }
    }else if (args == 2) {
        std::cout << "Enter words (q to quit):" << std::endl;
        while (std::getline(std::cin, line)) {
            if (line.find(" q") != std::string::npos) {
                firstLetters.append(firstLetterWord(line.substr(0,line.find(" q"))));
                std::cout <<firstLetters<< std::endl;
                res = countLetter(firstLetters);
                break;
            } else
                firstLetters.append(firstLetterWord(line));
        }
    }
    std::cout <<res.vowels <<" words beginning with vowels" << std::endl;
    std::cout <<res.consonant <<" words beginning with consonants " << std::endl;
    std::cout <<res.others <<" others" << std::endl;
    return EXIT_FAILURE;
}