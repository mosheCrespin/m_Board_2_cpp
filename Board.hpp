#include <iostream>
#include "Direction.hpp"
#include <map>
#include <string>
using namespace std;
namespace ariel {
        class Board{
            std::map<u_int, std::map<u_int, char>> my_board;
            u_int min_col;
            u_int min_row;
            u_int max_col;
            u_int max_row;
           
            public : 
                Board();
                ~Board(){};
                string read(u_int row, u_int col, Direction direction, u_int length);
                void post(u_int row, u_int col, Direction direction, const string &msg);
                void show();
        };
 }