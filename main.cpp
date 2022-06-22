#include <iostream>
#include <string>

class LengthException : std::exception {
    void what() {
        std::cout << "bad_length";
    }
};

int function(std::string str, int forbidden_length) {
    int length = str.length();
    if (length != forbidden_length) {
        return length;
    }
    else {
        throw LengthException();
    }
}

int main() {
    std::string str = "";
    int fl = 0;

    std::cout << "Введите запретную длину: ";
    std::cin >> fl;
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> str;

        try {
            int l = function(str, fl);
            std::cout << "Длина слова " << str << " равна " << l << "\n";
        }
        catch(LengthException) {
            std::cout << "Вы ввели слово запретной длины! До свидания" << "\n";
            break;
        }
    }
    return 0;
}