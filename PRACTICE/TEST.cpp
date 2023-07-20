#include <iostream>

void function(std::string S1, std::string S2) {
    std::cout << "Length(function()) : " << S1.length() << " : " << S2.length() << std::endl;
}

int main() {
    std::string S1;
    std::string S2;
    std::cin >> S1 >> S2;
    std::cout << "Length(main()) : " << S1.length() << " : " << S2.length() << std::endl;
    function(S1, S2);
    return 0;
}