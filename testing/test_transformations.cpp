#define CATCH_CONFIG_MAIN
#include "third_party/catch2.h"

#include  <fct/list.hpp>
#include <fct/transformations.hpp>

constexpr auto emptyList     = fct::List<int>{};
constexpr auto oneItemList   = fct::List<int, 1>{};
constexpr auto multiItemList = fct::List<int, 0, 1, 2, 3>{};


TEST_CASE( "Add one to each element in the list", "[Map]" ) {

    constexpr auto addOne      = [](int a) { return a + 1;};
    constexpr auto subtractOne = [](int a) { return a - 1;};

    constexpr auto listPlus1       = fct::transformation::Map(multiItemList, addOne);
    constexpr auto listPlus1Minus1 = fct::transformation::Map(listPlus1, subtractOne);
    constexpr auto resultPlus1     = fct::List<int, 1, 2, 3, 4>{};

    REQUIRE( std::is_same<decltype(listPlus1), decltype(resultPlus1)>::value);
    REQUIRE( std::is_same<decltype(listPlus1Minus1), decltype(multiItemList)>::value);
}

TEST_CASE( "Capitalize a sequence of characters", "[Map]" ) {

    constexpr auto capitalize = [](char c) {
        return ('a' <= c && c <= 'z')? (char) (c - 32) : c;
    };

    constexpr auto originalList    = fct::List<char, 's', 'F', 'i', 'n', 'A', 'e', '!'>{};
    constexpr auto resultList      = fct::List<char, 'S', 'F', 'I', 'N', 'A', 'E', '!'>{};
    constexpr auto capitalizedList = fct::transformation::Map(originalList, capitalize);

    REQUIRE( std::is_same<decltype(resultList), decltype(capitalizedList)>::value);
}


TEST_CASE( "Convert a list of integers to a list of characters", "[Map]" ) {

    constexpr auto intToChar = [](unsigned int i) {
        return (char) ((i % 26) + 'a');
    };

    constexpr auto intList         = fct::List<unsigned int, 0, 1, 2, 25>{};
    constexpr auto resultList      = fct::List<char, 'a', 'b', 'c', 'z'>{};
    constexpr auto mappedList      = fct::transformation::Map(intList, intToChar);

    REQUIRE( std::is_same<decltype(mappedList), decltype(resultList)>::value);
}


