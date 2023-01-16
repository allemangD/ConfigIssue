#include <iostream>
#include <string>
#include <stdlib.h>

std::string get_environ(std::string const &name) {
    char const *val = getenv(name.c_str());
    if (!val) return "";
    return val;
}

int main() {
    std::string sample = get_environ("SAMPLE");
    std::cout << "SAMPLE: '" << sample << "'" << std::endl;
    return 0;
}
