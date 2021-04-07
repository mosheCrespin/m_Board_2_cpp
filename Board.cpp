#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
using ariel::Direction;
using namespace ariel;
using namespace std;
Board::Board(){
      this->min_col=0;
      this->min_row=0;
      this->max_col=0;
      this->max_row=0;
}

    void Board::post(u_int row, u_int col, Direction direction, const string &msg)
    {
      //if its the first post 
      if((this->max_row==this->min_row)&&(this->max_col==this->min_col)){
         this->min_col=col;
         this->min_row=row;
      }
      //set min bounds
      if(row < this->min_row )
      {
         min_row=row;
      }
      if(col < this->min_col )
      {
         min_col=col;
      }
      u_int j=0;
      u_int msg_len=msg.length();
      if(direction==Direction::Horizontal){
         for(size_t i=col; i<col + msg_len;i++)
         {
            this->my_board[row][i]=msg[j];            
            j++;
         }
  
         }else {
            for(size_t i=row; i<row + msg_len;i++)
            {
               this->my_board[i][col]=msg[j];
               j++;
               
            }

         }
         
         //set max bounds
         if(max_col<col+msg_len)
         {
         	max_col=col+msg_len;
         }
         if(max_row<row+msg_len)
         {
         	max_row=row+msg_len;
         }
         
         
         
    }

   
    string Board::read(u_int row, u_int col, Direction direction, u_int length){
         string ans;
         if(direction==Direction::Horizontal){
            for(size_t i=col;i<col+length;i++)
            {
            if((this->my_board.count(row)>0)&&(my_board.at(row).count(i)>0)){
            		ans += this->my_board.at(row).at(i);
            		}else
            		{
            		    ans+='_';		
            		} 		

            }
         }else {
            for(size_t i=row;i<row+length;i++)
            {
               if((this->my_board.count(i)>0)&&(my_board.at(i).count(col)>0)){
                  ans += this->my_board.at(i).at(col);
               }else
               {
                   ans+='_';
         }
            }
          

         }
       return ans;
    }
    
      void Board::show(){
         for (size_t i = this -> min_row; i < this-> max_row +1 ; i++) {
            for (size_t j = this -> min_col; j < this-> max_col+1; j++) {
               if((this->my_board.count(i)>0)&&(my_board.at(i).count(j)>0)){
                    cout << this->my_board.at(i).at(j);
                  }else{cout << '_';} 
                }
            cout << endl;
            }
            
        } 
    

