#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int boardgen(char table[][3]);
int turn(bool bot);
int showtable(char table[][3]);
int check(char table [][3], char player);
int draw(char table[][3]);
int botgame(char table[][3], bool side); // true = x false = y


int main(int argc, char *argv[])
{   
    bool bot = false;
    int check;
    cout << "bot? ";
    cin >> check;
    if(check == 1)
    {
        bot = true;
    }
    turn(bot);
}


//generowanie gry w pliku svg
int boardgen(char table[][3])
{
    ofstream svgFile("board.svg");

    svgFile << "<svg width=\"600\" height=\"600\" xmlns=\"http://www.w3.org/2000/svg\">" << endl;

    svgFile << "  <line x1=\"200\" y1=\"0\" x2=\"200\" y2=\"600\" style=\"stroke:black;stroke-width:2\" /> " << endl;
    svgFile << "  <line x1=\"400\" y1=\"0\" x2=\"400\" y2=\"600\" style=\"stroke:black;stroke-width:2\" /> " << endl;
    svgFile << "  <line x1=\"000\" y1=\"200\" x2=\"600\" y2=\"200\" style=\"stroke:black;stroke-width:2\" /> " << endl;
    svgFile << "  <line x1=\"0\" y1=\"400\" x2=\"600\" y2=\"400\" style=\"stroke:black;stroke-width:2\" /> " << endl;

    for(int i=0; i < 4; i++)
    {
        for(int u = 0; u < 4; u++)
        {
            if(table[i - 1][u - 1] == 'o')
            {
                //svgFile << "  <circle r="100" cx="300" cy="300" fill="none" stroke="blue" stroke-width="3" />
                svgFile << "    <circle r=\"98\" cx=\"" << (u -1 ) * 200 + 100 << "\" cy=\"" << (i - 1) * 200 + 100 << "\" fill=\"none\" stroke=\"blue\" stroke-width=\"3\" />" << endl;
            }
            if(table[i - 1][u - 1] == 'x')
            {
                //  <line x1="0" y1=" 0" x2="200" y2="200" style="stroke:red;stroke-width:2" />
                //  <line x1="0" y1="200" x2="200" y2="0" style="stroke:red;stroke-width:2" />
                svgFile << "    <line x1=\"" << (u - 1) * 200 << "\" y1=\"" << (i-1) * 200 << "\" x2=\"" << (u-1) * 200 + 200 << "\" y2=\"" << (i - 1) * 200 + 200 << "\" style=\"stroke:red;stroke-width:2\" />" << endl;
                svgFile << "    <line x1=\"" << (u - 1) * 200 << "\" y1=\"" << (i-1) * 200 + 200 << "\" x2=\"" << (u-1) * 200 + 200 << "\" y2=\"" << (i - 1) * 200 << "\" style=\"stroke:red;stroke-width:2\" />" << endl;
            }
        }
    }

    svgFile << "</svg>" << endl;

    //svgFile.close();
    return 0;
}


//wyswietlanie gry w terminalu
int showtable(char table[][3])
{
    cout << table[0][0] << "|" << table[0][1] << "|" << table[0][2] << endl;
    cout << table[1][0] << "|" << table[1][1] << "|" << table[1][2] << endl;
    cout << table[2][0] << "|" << table[2][1] << "|" << table[2][2] << endl;
    return 0;
}


//sprawdzanie wygranej
int check(char table[][3], char player)
{
    int scam[3] = {4,2,0};
    int wygrana = 0; // 0 niema 1 wygrana
    for(int i = 0; i<4; i++)
    {
        if(table[i - 1][0] == player && table[i - 1][1] == player && table[i - 1][2] == player)
        {
            wygrana = 1;
        }
        if(table[0][i - 1] == player && table[1][i - 1] == player && table[2][i - 1] == player)
        {
            wygrana = 1;
        }
        if(table[0][0] == player && table[2][2] == player && table[3][3])
        {
            wygrana = 1;
        }
        if(table[3][1] == player && table[2][2] == player && table[1][3] == player)
        {
            wygrana = 1;
        }
    }
    return wygrana;
}


//sprawdzanie remisu
int draw(char table[][3])
{   
    int y = 0;
    y = 0;
    for(int i=0; i<4; i++)
    {
        for(int u=0; u<4; u++)
        {
            if(table[i - 1][u - 1] == 'x' || table[i - 1][u - 1] == 'o')
            {
                y++;
            }
        }
    }
    return y;
}


int botgame(char table[][3], bool side)
{
    int randomx, randomy;
    
    randomx = rand() %4;
    randomy = rand() %4;

    if(side == true)
    {
        return randomx;
    }
    else
    {
        return randomy;
    }
}


//gra
int turn(bool bot)
{
    int x, y;
    bool move = false, cord, side;
    char player = 'o';
    char boardstate[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    boardgen(boardstate);

    showtable(boardstate);
//ruch o
    for(int i=0; i<10; i++)
    {
    
        while (move == false)
        {
            player = 'o';
            cout << "podaj ruch (x,y)" << endl;
            while (cord == false)
            {
                cin >> x >> y;
                if (x > 3 || y > 3)
                {
                    cout << "zly ruch" << endl;
                }
                else
                {
                    cord = true;
                }
            }
            cord = false;
            if (boardstate[y-1][x-1] == 'x' || boardstate[y-1][x-1] == 'o') 
            {
                cout << "zly ruch" << endl;                
            }
            else
            {
                boardstate[y-1][x-1] = player;
                move = true;
            }
        }
        move = false;
        showtable(boardstate);
        boardgen(boardstate);
        
        //kontrola wygranej i remisu
        check(boardstate, player);
        if(check(boardstate, player) == 1)
        {
            cout << player << " wygrywa" << endl;
            move = true;
        }
        if(draw(boardstate) == 11 && move == false)
        {
            cout << "remis" << endl; 
            move = true;
        }

        //ruch x
        while (move == false)
        {
            player = 'x';
            if(bot == false)
            {
                cout << "podaj ruch (x,y)" << endl;
            }
                while (cord == false)
                {
                    if(bot == false)
                    {
                    cin >> x >> y;
                    }
                    else
                    {
                        side = true;
                        x = rand() %4; //botgame(boardstate, side);
                        side = false;
                        y = rand() %4; //botgame(boardstate, side);
                    }
                    if (x > 3 || y > 3)
                    {   
                        if(bot == false)
                        {
                        cout << "zly ruch" << endl;
                        }
                    }
                    else
                    {
                        cord = true;
                    }
                }
            
            cord = false;
            if (boardstate[y-1][x-1] == 'x' || boardstate[y-1][x-1] == 'o') 
            {
                cout << "zly ruch" << endl;                
            }
            else
            {
                boardstate[y-1][x-1] = player;
                move = true;
            }
        }
        move = false;
        showtable(boardstate);
        boardgen(boardstate);
        
        //kontrola wygranej i remisu
        check(boardstate, player);
        if(check(boardstate, player) == 1)
        {
            cout << player << " wygrywa" << endl;
            move = true;
        }
        if(draw(boardstate) == 11 && move == false)
        {
            cout << "remis" << endl; 
            move = true;
        }
    }
    
    return 0;
}