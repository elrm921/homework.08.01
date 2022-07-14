#include <iostream>
#include <string>
#include <stdexcept>

class bad_length : public std::domain_error {
    public:
        bad_length(std::string s) : std::domain_error(s) {} 
};

int function(std::string str, int forbidden_length) {
    int length = str.length();
    if (length != forbidden_length) {
        return length;
    }
    else {
        throw bad_length("Вы ввели слово запретной длины! До свидания. " + str + " длинна " + std::to_string(length));
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
        catch(bad_length e) {
            std::cout << e.what() << "\n";
            break;
        }
    }
    return 0;
}