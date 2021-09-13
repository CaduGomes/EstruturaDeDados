#include <typeinfo>
#include <cmath>
#include <cstddef>
// std::size_t
#include <iterator>
// std::size
#include <string>
// std::string
#include <optional>
// std::nullopt
#include <map>
// std::map
#include <utility>
// std::pair
#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    std::size_t value = 0;
    std::string key = "UFSC";
    for (size_t i = 0; i < key.length(); i++)
    {
        size_t n = 31;
        size_t teste = key[i] * pow(n, key.length() - (i + 1));
        value += teste;
    }
    std::cout << value << std::endl;
}
