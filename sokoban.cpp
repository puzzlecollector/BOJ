// solution is wrong for some reason 
// prints correctly for sample test cases 
// should be correc in terms of implementation 
// the code may be wrong because of some printing errors (perhaps printing format is wrong??) 
// needs further investigation. 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
char grid[20][20]; 
char cpy[20][20];  
int R,C,cnt; // initialised to zero
string command;  
bool inRange(int x,int y){
        return (x >= 0 && x < R && y >= 0 && y < C); 
}
void update_vertical(int &sx,int &sy,int dir){
        int nx = sx+dir, ny = sy; 
        bool wasplus = false; 
        if (inRange(nx,ny)){
                if (grid[nx][ny] == '#'){
                        return;  
                }else if (grid[nx][ny] == '.'){
                        grid[nx][ny] = 'w'; // move player
                        if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                        else grid[sx][sy] = '.';  
                        sx = nx; 
                        sy = ny;  
                }else if (grid[nx][ny] == '+'){
                        grid[nx][ny] = 'W'; // because it's on top of the plus   
                        if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                        else grid[sx][sy] = '.';  
                        sx = nx; 
                        sy = ny; 
                }else if (grid[nx][ny] == 'b' || grid[nx][ny] == 'B'){
                        if (inRange(nx+dir,ny) && (grid[nx+dir][ny] == 'b' || grid[nx+dir][ny] == 'B' || grid[nx+dir][ny] == '#')){
                                return; // no movements whatsoever  
                        }else if (inRange(nx+dir,ny) && grid[nx+dir][ny] == '.'){
                                grid[nx+dir][ny]  = 'b';  
                                if (cpy[nx][ny] == '+') grid[nx][ny] = 'W';  
                                else grid[nx][ny] = 'w';  
                                if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                                else grid[sx][sy] = '.';   
                                sx = nx; 
                                sy = ny;  
                        }else if (inRange(nx+dir,ny) && grid[nx+dir][ny] == '+'){
                                grid[nx+dir][ny] = 'B'; 
                                if (cpy[nx][ny] == '+') grid[nx][ny] = 'W';  
                                else grid[nx][ny] = 'w';   
                                if (cpy[sx][sy] == '+') grid[sx][sy] = '+';  
                                else grid[sx][sy] = '.'; 
                                sx = nx; 
                                sy = ny; 
                        }
                }
        }
}
void update_horizontal(int &sx,int &sy,int dir){
        int nx = sx, ny = sy+dir; 
        bool wasplus = false; 
        if (inRange(nx,ny)){
                if (grid[nx][ny] == '#'){
                        return;  
                }else if (grid[nx][ny] == '.'){
                        grid[nx][ny] = 'w'; // move player
                        if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                        else grid[sx][sy] = '.';  
                        sx = nx; 
                        sy = ny;  
                }else if (grid[nx][ny] == '+'){
                        grid[nx][ny] = 'W'; // because it's on top of the plus   
                        if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                        else grid[sx][sy] = '.';  
                        sx = nx; 
                        sy = ny; 
                }else if (grid[nx][ny] == 'b' || grid[nx][ny] == 'B'){
                        if (inRange(nx,ny+dir) && (grid[nx][ny+dir] == 'b' || grid[nx][ny+dir] == 'B' || grid[nx][ny+dir] == '#')){
                                return; // no movements whatsoever  
                        }else if (inRange(nx,ny+dir) && grid[nx][ny+dir] == '.'){
                                grid[nx][ny+dir]  = 'b';  
                                if (cpy[nx][ny] == '+') grid[nx][ny] = 'W';  
                                else grid[nx][ny] = 'w';  
                                if (cpy[sx][sy] == '+') grid[sx][sy] = '+'; 
                                else grid[sx][sy] = '.';   
                                sx = nx; 
                                sy = ny;  
                        }else if (inRange(nx,ny+dir) && grid[nx][ny+dir] == '+'){
                                grid[nx][ny+dir] = 'B'; 
                                if (cpy[nx][ny] == '+') grid[nx][ny] = 'W';  
                                else grid[nx][ny] = 'w';   
                                if (cpy[sx][sy] == '+') grid[sx][sy] = '+';  
                                else grid[sx][sy] = '.'; 
                                sx = nx; 
                                sy = ny; 
                        }
                }
        }
}
int main(){
        while (++cnt){
                cin >> R >> C;
                int sx,sy;  
                if (R == 0 && C == 0) break;  
                for (int i = 0; i < R; i++){
                        for (int j = 0; j < C; j++){
                                cin >> grid[i][j]; 
                                cpy[i][j] = grid[i][j]; 
                                if (grid[i][j] == 'w'){
                                        sx = i; 
                                        sy = j;  
                                } 
                        }
                }
                cin >> command; 
                bool complete = true; 
                for (int i = 0; i < command.size(); i++){
                        complete = true; // initialise complete at every step 
                        for (int j = 0; j < R; j++){
                                for (int k = 0; k < C; k++){
                                        if (grid[j][k] == '+'){
                                                complete = false; 
                                        }
                                }
                        }
                        if (complete) break; // no need to look at commands anymore 
                        if (command[i] == 'U'){
                                update_vertical(sx,sy,-1);  
                        }else if (command[i] == 'D'){
                                update_vertical(sx,sy,1); 
                        }else if (command[i] == 'L'){
                                update_horizontal(sx,sy,-1);  
                        }else if (command[i] == 'R'){
                                update_horizontal(sx,sy,1); 
                        }
                }
                // print out result 
                cout << "Game " << cnt << ": "; 
                complete = true; 
                for (int i = 0; i < R; i++){
                        for (int j = 0; j < C; j++){
                                if (grid[i][j] == '+'){
                                        complete = false;  
                                }
                        }
                }
                if (complete) cout << "complete" << endl; 
                else cout << "incomplete" << endl; 
                for (int i = 0; i < R; i++){
                        for (int j = 0; j < C; j++){
                                cout << grid[i][j]; 
                        }
                        cout << endl; 
                }
        }
        return 0; 
}
