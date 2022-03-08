/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Sabrina Khazanov
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good"){
    CHECK(nospaces(ariel::mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@\n"));
    CHECK(nospaces(ariel::mat(13,5,'@','-')) == nospaces("@@@@@@@@@@@@@\n"
                                                        "@-----------@\n"
                                                        "@-@@@@@@@@@-@\n"
                                                        "@-----------@\n"
                                                        "@@@@@@@@@@@@@"));
    CHECK(nospaces(ariel::mat(13,5,'@','-')) == nospaces("@@@@@@@@@@@@@\n"
                                                        "@-----------@\n"
                                                        "@-@@@@@@@@@-@\n"
                                                        "@-----------@\n"
                                                        "@@@@@@@@@@@@@\n"));
    CHECK(nospaces(ariel::mat(21,15,'#','-')) == nospaces("#####################\n"
                                                    "#-------------------#\n"
                                                    "#-#################-#\n"
                                                    "#-#---------------#-#\n"
                                                    "#-#-#############-#-#\n"
                                                    "#-#-#-----------#-#-#\n"
                                                    "#-#-#-#########-#-#-#\n"
                                                    "#-#-#-#-------#-#-#-#\n"
                                                    "#-#-#-#########-#-#-#\n"
                                                    "#-#-#-----------#-#-#\n"
                                                    "#-#-#############-#-#\n"
                                                    "#-#---------------#-#\n"
                                                    "#-#################-#\n"
                                                    "#-------------------#\n"
                                                    "#####################\n"));
}
TEST_CASE("One Row"){
    CHECK(nospaces(ariel::mat(5,1,'#','-')) == nospaces("#####"));
    CHECK(nospaces(ariel::mat(11,1,'#','-')) == nospaces("###########"));
    CHECK(nospaces(ariel::mat(7,1,'#','-')) == nospaces("#######"));
    CHECK(nospaces(ariel::mat(1,1,'$','-')) == nospaces("$"));
}
TEST_CASE("One Col"){
    CHECK(nospaces(ariel::mat(1,5,'#','-')) == nospaces("#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"));
    CHECK(nospaces(ariel::mat(11,1,'#','-')) == nospaces("#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"));
    CHECK(nospaces(ariel::mat(7,1,'#','-')) == nospaces("#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"
                                                        "#\n"));
}
TEST_CASE("Bad input") {
    CHECK_THROWS(ariel::mat(10, 5, '$', '%'));
    CHECK_THROWS(ariel::mat(9, 4, '$', '%'));
    CHECK_THROWS(ariel::mat(15, 20, '$', '%'));
    CHECK_THROWS(ariel::mat(22, 2, '$', '%'));
    CHECK_THROWS(ariel::mat(10, 13, '$', '%'));
    CHECK_THROWS(ariel::mat(8, 5, '$', '%'));
    CHECK_THROWS(ariel::mat(-1, 5, '$', '%'));
    CHECK_THROWS(ariel::mat(8, -9, '$', '%'));
    CHECK_THROWS(ariel::mat(-4,-3, '$', '%'));
    CHECK_THROWS(ariel::mat(-4,-3, '\n', '%'));
    CHECK_THROWS(ariel::mat(-4,-3, '\r', '%'));
    CHECK_THROWS(ariel::mat(-4,-3, '\t', '%'));
    CHECK_THROWS(ariel::mat(-4,-3, ' ', '%'));


}
TEST_CASE("Not Thorwing"){
    CHECK_NOTHROW(ariel::mat(7, 5, '$', '%'));
    CHECK_NOTHROW(ariel::mat(3, 5, '$', '%'));
    CHECK_NOTHROW(ariel::mat(9, 13, '$', '%'));
    CHECK_NOTHROW(ariel::mat(19, 21, '$', '%'));
    CHECK_NOTHROW(ariel::mat(1, 1, '$', '%'));
    CHECK_NOTHROW(ariel::mat(7, 15, '$', '%'));
    CHECK_NOTHROW(ariel::mat(1, 3, '$', '%'));
    CHECK_NOTHROW(ariel::mat(31, 15, '$', '%'));
    CHECK_NOTHROW(ariel::mat(71, 15, '$', '%'));
}