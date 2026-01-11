//tutaj wpisz numer albumu i wgl

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct vec2{
    int x,y;
};
struct rgbcolour{
    int red;
    int green;
    int blue;
};
struct rectangle{
    vec2 pos;
    vec2 size;
    rgbcolour colour;
};

struct circle{
    int radius;
    vec2 pos;
    rgbcolour colour;
};

struct line{
    vec2 pos1;
    vec2 pos2;
    rgbcolour colour;
};

int emptySvgGen();
int menu();
int ticTacToe();
int boardGen(char table[][3]);
int turn(bool bot);
int showTable(char table[][3]);
int check(char table [][3], char player);
int draw(char table[][3]);
int botGame(char table[][3], bool side); // true = x false = y
int checkers();
int printCheckersBoard(char board[8][8]);
int drawCheckersBoardSVG(char board[8][8]);


int main()
{
    menu();
    return 0;
}

// funkcja generująca pusty plik svg
int emptySvgGen(){
    //nazwa nowego pliku
    string nazwa;
    //otwarcie tagu, zdefiniowanie wymiarów oraz przestrzeni nazw pliku svg
    string svgBodyStart = "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">";
    //zamknięcie tagu
    string svgBodyEnd = "\n</svg>";

    //pobranie nazwy pliku od użytkownika
    cout << "Nazwa pliku SVG do wygenerowania: ";
    cin >> nazwa;
    
    //wygenerowanie pliku svg na podstawie zebranych danych
    fstream svgFile;
    string FileName = nazwa + ".svg";

    svgFile.open(FileName, ios::out);
    svgFile << svgBodyStart;
    svgFile << svgBodyEnd;
    svgFile.close();

    cout << "Plik " + FileName + " został wygenerowany pomyślnie.\n";
    return 0;
}
//funkcja generująca plik svg zawierający trzy figury
int customSvgGen(){

    rectangle rec1;
    circle circ1;
    line line1;

     //nazwa nowego pliku
    string nazwa;
    //otwarcie tagu, zdefiniowanie wymiarów oraz przestrzeni nazw pliku svg
    string svgBodyStart = "<svg width=\"200\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">";
    //zamknięcie tagu
    string svgBodyEnd = "\n</svg>";

    //pobranie nazwy pliku od użytkownika
    cout << "Nazwa pliku SVG do wygenerowania: ";
    cin >> nazwa;

    //pobranie danych prostokąta
    cout << "Wprowadź pozycję horyznontalną prostokąta(liczba od 0 do 200):";
    while (!(cin >> rec1.pos.x) || rec1.pos.x < 0 || rec1.pos.x > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź pozycję wertykalną prostokąta(liczba od 0 do 200):";
    while (!(cin >> rec1.pos.y) || rec1.pos.y < 0 || rec1.pos.y > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź szerokość prostokąta:";
    while (!(cin >> rec1.size.x)) {
        cout << "Błąd! Wprowadź liczbę.";
    }
    cout << "Wprowadź wysokość prostokąta:";
    while (!(cin >> rec1.size.y)) {
        cout << "Błąd! Wprowadź liczbę.";
    }
    cout << "Wprowadź wartość kanału czerwieni prostokąta(liczba od 0 do 255):";
    while (!(cin >> rec1.colour.red)|| rec1.colour.red < 0 || rec1.colour.red > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału zieleni prostokąta(liczba od 0 do 255):";
    while (!(cin >> rec1.colour.green)|| rec1.colour.green < 0 || rec1.colour.green > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału błękitu prostokąta(liczba od 0 do 255):";
    while (!(cin >> rec1.colour.blue)|| rec1.colour.blue < 0 || rec1.colour.blue > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }

    //pobranie danycch okręgu
    cout << "Wprowadź pozycję horyznontalną okręgu(liczba od 0 do 200):";
    while (!(cin >> circ1.pos.x) || circ1.pos.x < 0 || circ1.pos.x > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź pozycję wertykalną okręgu(liczba od 0 do 200):";
    while (!(cin >> circ1.pos.y) || circ1.pos.y < 0 || circ1.pos.y > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź promień okręgu:";
    while (!(cin >> circ1.radius)) {
        cout << "Błąd! Wprowadź liczbę.";
    }
    cout << "Wprowadź wartość kanału czerwieni okręgu(liczba od 0 do 255):";
    while (!(cin >> circ1.colour.red)|| circ1.colour.red < 0 || circ1.colour.red > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału zieleni okręgu(liczba od 0 do 255):";
    while (!(cin >> circ1.colour.green)|| circ1.colour.green < 0 || circ1.colour.green > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału błękitu okręgu(liczba od 0 do 255):";
    while (!(cin >> circ1.colour.blue)|| circ1.colour.blue < 0 || circ1.colour.blue > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    
    //pobranie danych lini
    cout << "Wprowadź początkową pozycję horyznontalną lini(liczba od 0 do 200):";
    while (!(cin >> line1.pos1.x) || line1.pos1.x < 0 || line1.pos1.x > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź początkową pozycję wertykalną lini(liczba od 0 do 200):";
    while (!(cin >> line1.pos1.y) || line1.pos1.y < 0 || line1.pos1.y > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }

    cout << "Wprowadź końcową pozycję horyznontalną lini(liczba od 0 do 200):";
    while (!(cin >> line1.pos2.x) || line1.pos2.x < 0 || line1.pos2.x > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }
    cout << "Wprowadź końcową pozycję wertykalną lini(liczba od 0 do 200):";
    while (!(cin >> line1.pos2.y) || line1.pos2.y < 0 || line1.pos2.y > 200) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 200";
    }

     cout << "Wprowadź wartość kanału czerwieni lini(liczba od 0 do 255):";
    while (!(cin >> line1.colour.red)|| line1.colour.red < 0 || line1.colour.red > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału zieleni lini(liczba od 0 do 255):";
    while (!(cin >> line1.colour.green)|| line1.colour.green < 0 || line1.colour.green > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }
    cout << "Wprowadź wartość kanału błękitu lini(liczba od 0 do 255):";
    while (!(cin >> line1.colour.blue)|| line1.colour.blue < 0 || line1.colour.blue > 255) {
        cout << "Błąd! Wprowadź liczbę w zakresie od 0 do 255.";
    }

    //wygenerowanie pliku svg na podstawie zebranych danych
    fstream svgFile;
    string FileName = nazwa + ".svg";

    svgFile.open(FileName, ios::out);
    svgFile << svgBodyStart;
    svgFile << "\n<rect x=\"" << rec1.pos.x << "\" y=\"" << rec1.pos.y << "\" width=\"" << rec1.size.x << "\" height=\"" << rec1.size.y << "\" fill=\"rgb(" << rec1.colour.red << "," << rec1.colour.green << "," << rec1.colour.blue << ")\"/>";
    svgFile << "\n<circle cx=\"" << circ1.pos.x << "\" cy=\"" << circ1.pos.y << "\" r=\"" << circ1.radius << "\" fill=\"rgb(" << circ1.colour.red << "," << circ1.colour.green << "," << circ1.colour.blue << ")\"/>";
    svgFile << "\n<line x1=\"" << line1.pos1.x << "\" x2=\"" << line1.pos1.y << "\" y1=\"" << line1.pos2.x << "\" y2=\"" << line1.pos2.y << "\" stroke=\"rgb(" << line1.colour.red << "," << line1.colour.green << "," << line1.colour.blue << ")\" stroke-width=\"5\"/>";
    svgFile << svgBodyEnd;
    svgFile.close();

    cout << "Plik " + FileName + " został wygenerowany pomyślnie.\n";
    return 0;
}
//główna funkcja gry w kółko i krzyżyk
int ticTacToe(){
        bool bot = false;
    int check;
    cout << "bot? ";
    cin >> check;
    if(check == 1)
    {
        bot = true;
    }
    turn(bot);
    return 0;
}

//generowanie gry kk w pliku svg
int boardGen(char table[][3])
{
    ofstream svgFile("board.svg");

    svgFile << "<svg width=\"600\" height=\"600\" xmlns=\"http://www.w3.org/2000/svg\">";

    svgFile << "\n<line x1=\"200\" y1=\"0\" x2=\"200\" y2=\"600\" style=\"stroke:black;stroke-width:2\" />";
    svgFile << "\n<line x1=\"400\" y1=\"0\" x2=\"400\" y2=\"600\" style=\"stroke:black;stroke-width:2\" />";
    svgFile << "\n<line x1=\"000\" y1=\"200\" x2=\"600\" y2=\"200\" style=\"stroke:black;stroke-width:2\" />";
    svgFile << "\n<line x1=\"0\" y1=\"400\" x2=\"600\" y2=\"400\" style=\"stroke:black;stroke-width:2\" />";

    for(int i=0; i < 4; i++)
    {
        for(int u = 0; u < 4; u++)
        {
            if(table[i - 1][u - 1] == 'o')
            {
                //svgFile << "  <circle r="100" cx="300" cy="300" fill="none" stroke="blue" stroke-width="3" />
                svgFile << "\n<circle r=\"98\" cx=\"" << (u -1 ) * 200 + 100 << "\" cy=\"" << (i - 1) * 200 + 100 << "\" fill=\"none\" stroke=\"blue\" stroke-width=\"3\" />";
            }
            if(table[i - 1][u - 1] == 'x')
            {
                //  <line x1="0" y1=" 0" x2="200" y2="200" style="stroke:red;stroke-width:2" />
                //  <line x1="0" y1="200" x2="200" y2="0" style="stroke:red;stroke-width:2" />
                svgFile << "\n<line x1=\"" << (u - 1) * 200 << "\" y1=\"" << (i-1) * 200 << "\" x2=\"" << (u-1) * 200 + 200 << "\" y2=\"" << (i - 1) * 200 + 200 << "\" style=\"stroke:red;stroke-width:2\" />";
                svgFile << "\n<line x1=\"" << (u - 1) * 200 << "\" y1=\"" << (i-1) * 200 + 200 << "\" x2=\"" << (u-1) * 200 + 200 << "\" y2=\"" << (i - 1) * 200 << "\" style=\"stroke:red;stroke-width:2\" />";
            }
        }
    }

    svgFile << "\n</svg>\n";

    //svgFile.close();
    return 0;
}


//wyswietlanie gry w terminalu
int showTable(char table[][3])
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

//logika bota kk
int botGame(char table[][3], bool side)
{
    vec2 randv;
    
    randv.x = rand() %4;
    randv.y = rand() %4;

    if(side == true)
    {
        return randv.x;
    }
    else
    {
        return randv.y;
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

    boardGen(boardstate);

    showTable(boardstate);
//ruch o
    for(int i=0; i<10; i++)
    {
    
        while (move == false)
        {
            player = 'o';
            cout << "Podaj ruch (x,y):";
            while (cord == false)
            {
                cin >> x >> y;
                if (x > 3 || y > 3)
                {
                    cout << "Zły ruch!";
                }
                else
                {
                    cord = true;
                }
            }
            cord = false;
            if (boardstate[y-1][x-1] == 'x' || boardstate[y-1][x-1] == 'o') 
            {
                cout << "Zły ruch!";                
            }
            else
            {
                boardstate[y-1][x-1] = player;
                move = true;
            }
        }
        move = false;
        showTable(boardstate);
        boardGen(boardstate);
        
        //kontrola wygranej i remisu
        check(boardstate, player);
        if(check(boardstate, player) == 1)
        {
            cout << player << " wygrywa!\n";
            move = true;
        }
        if(draw(boardstate) == 11 && move == false)
        {
            cout << "Remis!\n"; 
            move = true;
        }

        //ruch x
        while (move == false)
        {
            player = 'x';
            if(bot == false)
            {
                cout << "Podaj ruch (x,y):";
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
                        x = rand() %4;
                        side = false;
                        y = rand() %4;
                    }
                    if (x > 3 || y > 3)
                    {   
                        if(bot == false)
                        {
                        cout << "Zły ruch!\n";
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
                cout << "Zły ruch!\n";                
            }
            else
            {
                boardstate[y-1][x-1] = player;
                move = true;
            }
        }

        move = false;
        showTable(boardstate);
        boardGen(boardstate);
        
        //kontrola wygranej i remisu
        check(boardstate, player);
        if(check(boardstate, player) == 1)
        {
            cout << player << " wygrywa!\n";
            move = true;
        }
        if(draw(boardstate) == 11 && move == false)
        {
            cout << "Remis!\n"; 
            move = true;
        }
    }
    
    return 0;
}


//warcaby
bool isRed(char c) {
    return c == 'r' || c == 'R';
}

bool isBlack(char c) {
    return c == 'b' || c == 'B';
}

bool isKing(char c) {
    return c == 'R' || c == 'B';
}

bool hasOpponent(char c, char player) {
    return (player == 'r') ? isBlack(c) : isRed(c);
}

bool hasAnyPieces(char board[8][8], char player) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((player == 'r' && isRed(board[i][j])) || (player == 'b' && isBlack(board[i][j])))
                return true;
    return false;
}

int printCheckersBoard(char board[8][8]) {
    cout << "  0 1 2 3 4 5 6 7\n";
    for (int i = 0; i < 8; i++) {
        cout << i << " ";
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

int checkers() {
    char board[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '.';

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 8; j++)
            if ((i + j) % 2 == 1)
                board[i][j] = 'b';

    for (int i = 5; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if ((i + j) % 2 == 1)
                board[i][j] = 'r';

    char player = 'r';

    while (true) {
        printCheckersBoard(board);

        if (!hasAnyPieces(board, player)) {
            cout << "Gracz " << ((player == 'r') ? "b" : "r") << " wygrywa!\n";
            break;
        }

        cout << "Gracz " << player << " wykonuje ruch\n";
        cout << "Podaj: y1 x1 y2 x2: ";

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        char piece = board[x1][y1];

        if (piece == '.' ||
            (player == 'r' && !isRed(piece)) || (player == 'b' && !isBlack(piece)) || board[x2][y2] != '.') {
            cout << "Nieprawidłowy wybór pionka!\n";
            continue;
        }

        int dx = x2 - x1;
        int dy = y2 - y1;
        bool capture = abs(dx) == 2 && abs(dy) == 2;
        bool normal = abs(dx) == 1 && abs(dy) == 1;

        if (!isKing(piece)) {
            if ((player == 'r' && dx >= 0) || (player == 'b' && dx <= 0)) {
                cout << "Zły kierunek ruchu!\n";
                continue;
            }
        }

        if (normal) {
            board[x2][y2] = piece;
            board[x1][y1] = '.';
        }
        else if (capture) {
            int mx = (x1 + x2) / 2;
            int my = (y1 + y2) / 2;

            if (!hasOpponent(board[mx][my], player)) {
                cout << "Brak pionka przeciwnika do zbicia!\n";
                continue;
            }

        board[x2][y2] = piece;
        board[x1][y1] = '.';
        board[mx][my] = '.';
        }
        else {
            cout << "Nielegalny ruch!\n";
            continue;
        }

        //promocja z piona na damke
        if (player == 'r' && x2 == 0 && piece == 'r')
            board[x2][y2] = 'R';
        if (player == 'b' && x2 == 7 && piece == 'b')
            board[x2][y2] = 'B';

        drawCheckersBoardSVG(board);
        player = (player == 'r') ? 'b' : 'r';
    }

    return 0;
}

int drawCheckersBoardSVG(char board[8][8]) {
    int tileSize = 60;
    int boardSize = 8 * tileSize;
    string filename = "boardstate.svg";
    ofstream svg(filename);

    svg << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
        << "width=\"" << boardSize << "\" height=\"" << boardSize << "\">\n";

    // wyświetlanie planszy
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            string color = ((i + j) % 2 == 0) ? "#ece0ccff" : "#161515ff";
            svg << "<rect x=\"" << j * tileSize << "\" y=\"" << i * tileSize << "\" width=\"" << tileSize << "\" height=\"" << tileSize << "\" fill=\"" << color << "\" />\n";
        }
    }

    // wyświetlanie pionów
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char p = board[i][j];
            if (p == '.') continue;

            int cx = j * tileSize + tileSize / 2;
            int cy = i * tileSize + tileSize / 2;
            int r  = tileSize / 2 - 6;

            // pion
            string fill =
                (p == 'r' || p == 'R') ? "lime" : "black";

            svg << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r << "\" fill=\"" << fill << "\" stroke=\"white\" stroke-width=\"2\" />\n";

            // pion damka
            if (p == 'R' || p == 'B') {
                svg << "<text x=\"" << cx << "\" y=\"" << cy + 6 << "\" font-size=\"24\" text-anchor=\"middle\" "<< "fill=\"magenta\" font-weight=\"bold\">D</text>\n";
            }
        }
    }

    svg << "</svg>\n";
    svg.close();

    cout << "Zapisano plansze do pliku: " << filename << "\n";
    return 0;
}


int menu(){
    char choice;
    string entries[6] = {"1 - Wygeneruj podstawowy plik SVG", "2 - Wygeneruj zaawansowany plik SVG", "3 - Kółko i krzyrzyk", "4 - Warcaby", "H - Pomoc", "X - Wyjście"};

    cout << "\n";
    for (int i=0; i<int(size(entries)); i++) {
        cout << entries[i] << "\n";
    }
    cout << ">>";
    cin >> choice;

    switch (choice) {
        case '1':
            emptySvgGen();
            menu();
            break;
        case '2':
            customSvgGen();
            menu();
            break;
        case '3':
            ticTacToe();
            break;
        case '4':
            checkers();
            break;
        case 'H':
            cout << "Podstawowy plik svg generuje pusty plik svg\n";
            cout << "zaawansowany plik svg generuje plik svg z kolem prostokatem i linia\n";
            cout << "kolko i krzyzyk wpisujac jeden gra sie z komputerem wpisujac 0 gra sie z graczem\n";
            cout << "warcaby gra sie wpisujac kordynaty y x pionka a nastepnie mijsca docelowego\n";
            menu();
            break;
        case 'X':
            break;
        default:
            cout << "Nieznana opcja!\n";
            menu();
            break;
    }
    return 0;
}