#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    bool iswinner(vector<string>&board , char player){
        for(int i = 0 ; i<3 ; i++){
            if(board[i][0]==player && board[i][1]==player && board[i][2]==player){   //winning condition for row
                return true;
            }
            if(board[0][i]==player && board[1][i]==player && board[2][i]==player){  //winning condition for column
                return true;
            }
        }
        if(board[0][0]==player && board[1][1]==player && board[2][2]==player){      //winning condition for diagonal
            return true;
        }
        if(board[0][2]==player && board[1][1]==player && board[2][0]==player){      //winning condition for anti-diagonal
            return true;
        }
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int count_X = 0 ; int count_O = 0; 
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                if(board[i][j]=='X'){
                    count_X ++;
                }
                else if(board[i][j]=='O'){
                    count_O ++;
                }
            }
        }
        //check for wrong turns
        if(count_X - count_O <0 || count_X - count_O >1){
            return false;
        }
        //check for multiple winners
        bool xwinner = iswinner(board , 'X');
        bool owinner = iswinner(board , 'O');
        if(xwinner && owinner){
            return false;
        }
        //check winner has correct counts
        if(xwinner && count_X != count_O +1 ){
            return false;
        }
        if(owinner && count_O != count_X){
            return false;
        }
        return true;
    }
};