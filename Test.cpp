#include "Board.hpp"
#include "doctest.h"
#include <string>
using namespace std;
using namespace ariel;
Board board;
TEST_CASE("Empty Board")
{
    CHECK(board.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(board.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(2, 2, Direction::Horizontal, 0) == "");
    CHECK(board.read(2, 2, Direction::Vertical, 0) == string(""));
    CHECK(board.read(20,30, Direction::Vertical,1) == string("_"));
}

TEST_CASE("Horizontal case"){
    board.post(0, 0, Direction::Horizontal,"king moshe");
    CHECK(board.read(0, 0, Direction::Horizontal, 10) == string("king moshe"));
    CHECK(board.read(0, 1, Direction::Horizontal, 10) == string("ing moshe_"));
    CHECK(board.read(0, 2, Direction::Horizontal, 10) == string("ng moshe__"));
    CHECK(board.read(0, 3, Direction::Horizontal, 10) == string("g moshe___"));
    CHECK(board.read(0, 4, Direction::Horizontal, 10) == string(" moshe____"));
    CHECK(board.read(0, 5, Direction::Horizontal, 10) == string("moshe_____"));
    CHECK(board.read(0, 6, Direction::Horizontal, 10) == string("oshe______"));
    CHECK(board.read(0, 7, Direction::Horizontal, 10) == string("she_______"));
    CHECK(board.read(0, 8, Direction::Horizontal, 10) == string("he________"));
    CHECK(board.read(0, 9, Direction::Horizontal, 10) == string("e_________"));
    CHECK(board.read(0, 10, Direction::Horizontal, 10) == string("__________"));

}

    TEST_CASE("Vertically case") {
    board.post(0, 0, Direction::Vertical,"king moshe");
    CHECK(board.read(0, 0, Direction::Vertical, 10) == string("king moshe"));
    CHECK(board.read(1, 0, Direction::Vertical, 10) == string("ing moshe_"));
    CHECK(board.read(2, 0, Direction::Vertical, 10) == string("ng moshe__"));
    CHECK(board.read(3, 0, Direction::Vertical, 10) == string("g moshe___"));
    CHECK(board.read(4, 0, Direction::Vertical, 10) == string(" moshe____"));
    CHECK(board.read(5, 0, Direction::Vertical, 10) == string("moshe_____"));
    CHECK(board.read(6, 0, Direction::Vertical, 10) == string("oshe______"));
    CHECK(board.read(7, 0, Direction::Vertical, 10) == string("she_______"));
    CHECK(board.read(8, 0, Direction::Vertical, 10) == string("he________"));
    CHECK(board.read(9, 0, Direction::Vertical, 10) == string("e_________"));
    CHECK(board.read(10, 0,Direction::Vertical, 10) == string("__________"));
    }