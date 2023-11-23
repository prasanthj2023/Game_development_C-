#include <iostream>
#include <string>
#include <algorithm>

// Function to remove common characters from two strings
void removeCommonCharacters(std::string& str1, std::string& str2) {
    for (int i = 0; i < str1.length(); ++i) {
        for (int j = 0; j < str2.length(); ++j) {
            if (str1[i] == str2[j]) {
                str1.erase(i, 1);
                str2.erase(j, 1);
                --i;
                break;
            }
        }
    }
}

// Function to calculate Flames result
char calculateFlamesResult(std::string& str1, std::string& str2) {
    removeCommonCharacters(str1, str2);

    int totalLength = str1.length() + str2.length();
    std::string flames = "FLAMES";

    while (flames.length() > 1) {
        int index = (totalLength % flames.length() - 1 + flames.length()) % flames.length();
        flames.erase(index, 1);
    }

    return flames[0];
}

int main() {
    std::string name1, name2;

    std::cout << "Enter the first name: ";
    std::cin >> name1;

    std::cout << "Enter the second name: ";
    std::cin >> name2;

    std::transform(name1.begin(), name1.end(), name1.begin(), ::toupper);
    std::transform(name2.begin(), name2.end(), name2.begin(), ::toupper);

    char result = calculateFlamesResult(name1, name2);

    std::cout << "\nFLAMES Result: ";

    switch (result) {
        case 'F':
            std::cout << "Friends" << std::endl;
            break;
        case 'L':
            std::cout << "Love" << std::endl;
            break;
        case 'A':
            std::cout << "Affection" << std::endl;
            break;
        case 'M':
            std::cout << "Marriage" << std::endl;
            break;
        case 'E':
            std::cout << "Enemy" << std::endl;
            break;
        case 'S':
            std::cout << "Sibling" << std::endl;
            break;
        default:
            std::cout << "Invalid input" << std::endl;
            break;
    }

    return 0;
}
