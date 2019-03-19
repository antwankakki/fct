#define CATCH_CONFIG_MAIN
#include "third_party/catch2.h"

#include <fct/list.hpp>
#include <type_traits>

constexpr auto emptyList     = fct::List<int>{};
constexpr auto oneItemList   = fct::List<int, 1>{};
constexpr auto multiItemList = fct::List<int, 0, 1, 2, 3>{};

TEST_CASE( "empty list test", "[size]" ) {

    REQUIRE(0 == emptyList.size());
}

TEST_CASE( "one element list", "[size]" ) {

    REQUIRE(1 == oneItemList.size());
}

TEST_CASE( "multi element list", "[size]" ) {

    REQUIRE(4 == multiItemList.size());
}

TEST_CASE( "Simple Test", "[Append]" ) {

    constexpr auto result = fct::List<int, 1, 0, 1, 2, 3>{};

    constexpr auto totalList = fct::Append(oneItemList, multiItemList);
    REQUIRE( std::is_same<decltype(result), decltype(totalList)>::value);
}

TEST_CASE( "Append Two Empty Lists", "[Append]" ) {
    constexpr auto totalList = fct::Append(emptyList, emptyList);
    REQUIRE(totalList.size() == 0);
    REQUIRE( std::is_same<decltype(emptyList), decltype(totalList)>::value);
}

TEST_CASE( "Append Empty Test", "[Append]" ) {
    constexpr auto result = fct::List<int, 1>{};

    constexpr auto totalList  = fct::Append(emptyList, oneItemList);
    constexpr auto totalList2 = fct::Append(oneItemList, emptyList);

    REQUIRE( std::is_same<decltype(result), decltype(totalList)>::value);
    REQUIRE( std::is_same<decltype(result), decltype(totalList2)>::value);
}

TEST_CASE( "Head of a singe item list", "[Head]" ) {
    REQUIRE( Head(oneItemList) == 1);
}

TEST_CASE( "Head of a multi item list", "[Head]" ) {
    REQUIRE( Head(multiItemList) == 0);
}

TEST_CASE( "Use Head and Tail to get the third element", "[Head][Tail]" ) {
    REQUIRE( Head(Tail(Tail(multiItemList))) == 2);
}

TEST_CASE( "Tail of a single element list is the empty list", "[Tail]" ) {
    constexpr auto tailTillEmptyList = Tail(oneItemList);

    REQUIRE( std::is_same<decltype(tailTillEmptyList), decltype(emptyList)>::value);
    REQUIRE( Tail(oneItemList).size() == 0 );
}

TEST_CASE( "Multiple tail calls lead to empty list", "[Tail]" ) {
    REQUIRE( Tail(Tail(Tail(Tail(multiItemList)))).size() == 0 );

    constexpr auto tailTillEmptyList = Tail(Tail(Tail(Tail(multiItemList))));

    REQUIRE( std::is_same<decltype(tailTillEmptyList), decltype(emptyList)>::value);
}