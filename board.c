#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"
#define Missed -10
#define Clashed 10
#define MAXIMUM_PLAYER_COUNT 20
struct Boats_Cords
{
    int x;
    int y;
    int length;
    int width;
    char position;
    int situ;
};
struct Boats_Cords P1_boats[100];
struct Boats_Cords P2_boats[100];

struct attacked_coard
{
    int x;
    int y;
};
struct attacked_coard attacked_places[100];

void clrscr()
{
    system("@cls||clear");
}
int Space(int Count)
{
    int i;
    for (i = 0; i < Count; i++)
    {
        printf(" ");
    }
}
// TABE BARAYE KHAT KESHI BE TOOLE VOOROODIE (length)
int Line(int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("=");
    }
}
// TABE BARAYE CHECK KARDANE VOOROODI KE FAGHAT ADAD BASHE
int Check_Input(char Str[])
{
    int i;
    for (i = 0; Str[i] != 0; i++)
    {
        if (Str[i] < 48 || Str[i] > 57)
        {
            return 1;
        }
    }
    return 0;
}
// TABE BARAYE TABDIL STRING BE ADAD
int StrToNum(char Str[])
{
    int i, j;
    int sum;
    i = strlen(Str);
    for (j = 0, sum = 0; Str[j] != 0; i--, j++)
    {
        sum = (Str[j] - 48) * pow(10, i - 1) + sum;
    }
    return (sum);
}
int Error(int Err_Num)
{
    // Error 1 : ITS NOT ENOUGH FOR LENGTH!
    // Error 2 : ITS NOT A NUMBER!
    // Error 3 : INVALID NUMBER!
    // Error 4 : INVALID LETTER!
    // Error 5 : NO SPACE FOR ALL SHIPS!
    // Error 6 : YOU CANT PLACE HERE!
    // Error 7 : YOU CANT ATTACK HERE!
    // Error 8 : YOU HAVE ALREADY ATTACKED HERE!
    // Error 9 : YOU CAN'T REPAIR HERE!
    // Error 10 : THE BOAT HAS SUNKEN COMPLETLY!
    // Error 11 : NO GAME HAVE BEEN SAVED IN THE PAST!

    if (Err_Num == 1)
    {
        setTextColor(4, 0);
        printf("ITS NOT ENOUGH FOR LENGTH!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 2)
    {
        setTextColor(4, 0);
        printf("ITS NOT A NUMBER!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 3)
    {
        setTextColor(4, 0);
        printf("INVALID NUMBER!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 4)
    {
        setTextColor(4, 0);
        printf("INVALID LETTER!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 5)
    {
        setTextColor(4, 0);
        printf("NO SPACE FOR ALL SHIPS!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 6)
    {
        setTextColor(4, 0);
        printf("YOU CANT PLACE HERE!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 7)
    {
        setTextColor(4, 0);
        printf("YOU CANT ATTACK HERE!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 8)
    {
        setTextColor(4, 0);
        printf("YOU HAVE ALREADY ATTACKED HERE!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 9)
    {
        setTextColor(4, 0);
        printf("YOU CAN'T REPAIR HERE!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 10)
    {
        setTextColor(4, 0);
        printf("THE BOAT HAS SUNKEN COMPLETLY!\n");
        setTextColor(15, 0);
    }
    else if (Err_Num == 11)
    {
        setTextColor(4, 0);
        printf("NO GAME HAVE BEEN SAVED IN THE PAST!\n");
        setTextColor(15, 0);
    }
}
// TABE TAGHIR RANG
void setTextColor(int textColor, int backColor)
{
    // 0=black,1=blue,2=green,3=cyan,4=red,14=yellow,15=white
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

void Delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}

void PreBoard(int Size, int BOARD_P1[][100], int BOARD_P2[][100], int BOARD_OPP_P1[][100], int BOARD_OPP_P2[][100], int BOARD_CONST_P1[][100], int BOARD_CONST_P2[][100])
{
    int i, j;
    for (i = 0; i < Size + 1; i++)
    {
        for (j = 0; j < Size + 1; j++)
        {
            BOARD_P1[i][j] = 0;
            BOARD_P2[i][j] = 0;
            BOARD_OPP_P1[i][j] = 0;
            BOARD_OPP_P2[i][j] = 0;
            BOARD_CONST_P1[i][j] = 0;
            BOARD_CONST_P2[i][j] = 0;
        }
    }
    for (int j = 1; j < Size + 1; j++)
    {
        BOARD_P1[0][j] = j;
        BOARD_P2[0][j] = j;
        BOARD_OPP_P1[0][j] = j;
        BOARD_OPP_P2[0][j] = j;
        BOARD_CONST_P1[0][j] = j;
        BOARD_CONST_P2[0][j] = j;
    }
    for (int i = 1; i < Size + 1; i++)
    {
        BOARD_P1[i][0] = i;
        BOARD_P2[i][0] = i;
        BOARD_OPP_P1[i][0] = i;
        BOARD_OPP_P2[i][0] = i;
        BOARD_CONST_P1[i][0] = i;
        BOARD_CONST_P2[i][0] = i;
    }
}

int Print_Board(int board[][100], int Size, char name[], int NumOfShips, int Col)
{
    setTextColor(Col, 0);
    printf(COLOR_BOLD "~ %s ~\n", name);
    setTextColor(15, 0);
    printf(COLOR_OFF "Number Of Ships: %d\n\n\n", NumOfShips);
    Space(5 * Size / 4 - 2);
    // Delay(1000);
    printf("Your Board :\n\n");
    // Delay(1000);
    for (int i = 0; i < Size + 1; i++)
    {
        for (int j = 0; j < Size + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("   ");
                continue;
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 0) // TARH UB DADAN
            {
                setTextColor(9, 0);
                printf("~  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 1) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("o  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -1) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("+  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 2) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("<  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -2) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf(">  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 3) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("^  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -3) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("V  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 4) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("/  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -4) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("\\  ");
                setTextColor(15, 0);
            }
            else
            {
                if (i == 0 && j > 9)
                {
                    printf("%d ", board[i][j]);
                }
                else if (i > 9 && j == 0)
                {
                    printf("%d ", board[i][j]);
                }
                else
                {
                    printf("%d  ", board[i][j]);
                }
            }
        }
        if (i != Size)
        {
            printf("\n\n");
        }
    }
}

int Print_TwoBoard(int board1[][100], int board2[][100], int Size, char name[], int NumOfShips, int Col)
{
    Space((3 * Size + 1) + 4);
    setTextColor(Col, 0);
    printf(COLOR_BOLD "~ %s ~\n", name);
    setTextColor(15, 0);
    Space((3 * Size + 1) + 4);
    printf(COLOR_OFF "Number Of Ships: %d\n\n\n", NumOfShips);
    Space(5 * Size / 4 - 2);
    // Delay(1000);
    printf("Your Board :");
    Space(3 * Size + 8);
    printf("Your OPP's Board :\n\n");
    // Delay(1000);
    for (int i = 0; i < Size + 1; i++)
    {
        // PRINT BOARD AVAL
        for (int j = 0; j < Size + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("   ");
                continue;
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 0) // TARH UB DADAN
            {
                setTextColor(9, 0);
                printf("~  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 1) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("o  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -1) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("+  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 2) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("<  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -2) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf(">  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 3) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("^  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -3) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("V  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 4) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("/  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -4) // TARH KASHTI
            {
                setTextColor(Col, 0);
                printf("\\  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 10) // TARH KASHTI
            {
                setTextColor(4, 0);
                printf("X  ");
                setTextColor(15, 0);
            }
            else
            {
                if (i == 0 && j > 9)
                {
                    printf("%d ", board1[i][j]);
                }
                else if (i > 9 && j == 0)
                {
                    printf("%d ", board1[i][j]);
                }
                else
                {
                    printf("%d  ", board1[i][j]);
                }
            }
        }

        printf("\t\t\t");

        // PRINT BOARD DOVOM
        for (int j = 0; j < Size + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("   ");
                continue;
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == 0) // TARH UB DADAN
            {
                setTextColor(9, 0);
                printf("~  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == 10) // TARH KASHTI
            {
                setTextColor(4, 0);
                printf("X  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == -10) // TARH KASHTI
            {
                setTextColor(4, 0);
                printf("?  ");
                setTextColor(15, 0);
            }
            else
            {
                if (i == 0 && j > 9)
                {
                    printf("%d ", board2[i][j]);
                }
                else if (i > 9 && j == 0)
                {
                    printf("%d ", board2[i][j]);
                }
                else
                {
                    printf("%d  ", board2[i][j]);
                }
            }
        }
        if (i != Size)
        {
            printf("\n\n");
        }
    }
}

int check_place(int board[][100], int x, int y, char position, int size, int length, int width)
{
    if (position == 'h' || position == 'H')
    {
        if (y < size - width + 1 && x < size - length + 1)
        {
            for (int i = 0; i < length; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    if (board[x + i][y + j] == 1 || board[x + i][y + j] == -1 || board[x + i][y + j] == 2 || board[x + i][y + j] == -2 || board[x + i][y + j] == 3 || board[x + i][y + j] == -3 || board[x + i][y + j] == 4 || board[x + i][y + j] == -4)
                    {
                        return 1;
                    }
                }
            }
        }
        else
        {
            return 1;
        }
    }
    else if (position == 'v' || position == 'V')
    {
        if (y < size - length + 1 && x < size - width + 1)
        {
            for (int i = 0; i < width; i++)
            {
                for (int j = 0; j < length; j++)
                {
                    if (board[x + i][y + j] == 1 || board[x + i][y + j] == -1 || board[x + i][y + j] == 2 || board[x + i][y + j] == -2 || board[x + i][y + j] == 3 || board[x + i][y + j] == -3 || board[x + i][y + j] == 4 || board[x + i][y + j] == -4)
                    {
                        return 1;
                    }
                }
            }
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

void PrePlaceShip(int SIZE, int Boat_Count, int Board1[][100], int ConstBoard1[][100], int Board2[][100], int ConstBoard2[][100], int length, int width, int player, int *player_cur_boat_count, int bot, FILE *LOAD, int *Load_Situ)
{
    char position;
    char temp1[10];
    char temp2[10];
    int x, y;
    for (int i = 1; i <= Boat_Count; i++)
    {
        for (;;)
        {
            if (*(Load_Situ) == 1 && feof(LOAD) == 0)
            {
                fscanf(LOAD, "%d %d %c", &x, &y, &position);
                if (feof(LOAD) != 0)
                {
                    *(Load_Situ) = 0;
                }
                else
                {
                    break;
                }
            }
            if (*(Load_Situ) == 0)
            {
                scanf("%s %s %c", &temp1, &temp2, &position);
                if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
                {
                    Error(3);
                }
                else
                {
                    x = StrToNum(temp1);
                    y = StrToNum(temp2);
                    break;
                }
            }
        }
        if (position != 'v' && position != 'h' && position != 'V' && position != 'H')
        {
            Error(4);
            i--;
            continue;
        }
        else if (check_place(Board1, x, y, position, SIZE + 1, length, width) == 1 || x > SIZE || y > SIZE || x < 1 || y < 1)
        {
            Error(6);
            i--;
            continue;
        }
        else
        {
            if (*(Load_Situ) == 0)
            {
                fprintf(LOAD, "%d %d %c\n", x, y, position);
                fflush(LOAD);
            }
            place_boat(Board1, ConstBoard1, x, y, position, SIZE + 1, length, width);
            if (player == 1)
            {
                P1_boats[*player_cur_boat_count].x = x;
                P1_boats[*player_cur_boat_count].y = y;
                P1_boats[*player_cur_boat_count].length = length;
                P1_boats[*player_cur_boat_count].width = width;
                P1_boats[*player_cur_boat_count].position = position;
                if (bot)
                {
                    int i, j, p;
                    P2_boats[*player_cur_boat_count].length = length;
                    P2_boats[*player_cur_boat_count].width = width;
                    P2_boats[*player_cur_boat_count].position = position;
                    i = rand() % (SIZE - 1 + 1) + 1;
                    j = rand() % (SIZE - 1 + 1) + 1;
                    p = rand() % 2;
                    // if (p==0)
                    // {
                    //     P2_boats[*player_cur_boat_count].position = 'h';
                    // }
                    // else P2_boats[*player_cur_boat_count].position = 'v';
                    while (check_place(Board2, i, j, position, SIZE + 1, length, width) == 1)
                    {
                        i = rand() % (SIZE - 1 + 1) + 1;
                        j = rand() % (SIZE - 1 + 1) + 1;
                    }
                    P2_boats[*player_cur_boat_count].x = i;
                    P2_boats[*player_cur_boat_count].y = j;
                    place_boat(Board2, ConstBoard2, i, j, position, SIZE + 1, length, width);
                }

                (*player_cur_boat_count)++;
            }
            else if (player == 2)
            {
                P2_boats[*player_cur_boat_count].x = x;
                P2_boats[*player_cur_boat_count].y = y;
                P2_boats[*player_cur_boat_count].length = length;
                P2_boats[*player_cur_boat_count].width = width;
                P2_boats[*player_cur_boat_count].position = position;
                (*player_cur_boat_count)++;
            }
        }
    }
}

void place_boat(int board[][100], int const_board[][100], int x, int y, char position, int size, int length, int width)
{
    if (position == 'h' || position == 'H')
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (length == 1 && width == 1)
                {
                    board[x + i][y + j] = -1; // -1 = +
                    const_board[x + i][y + j] = -1;
                }
                else if (length == 1)
                {
                    if (j == 0)
                    {
                        board[x + i][y + j] = 2; // 2 = <
                        const_board[x + i][y + j] = 2;
                    }
                    else if (j == width - 1)
                    {
                        board[x + i][y + j] = -2; // -2 = >
                        const_board[x + i][y + j] = -2;
                    }
                    else
                    {
                        board[x + i][y + j] = 1; // 1 = o
                        const_board[x + i][y + j] = 1;
                    }
                }
                else if (width == 1)
                {
                    if (i == 0)
                    {
                        board[x + i][y + j] = 3; // 3 = ∧
                        const_board[x + i][y + j] = 3;
                    }
                    else if (i == length - 1)
                    {
                        board[x + i][y + j] = -3; // -3 = ∨
                        const_board[x + i][y + j] = -3;
                    }
                    else
                    {
                        board[x + i][y + j] = 1; // 1 = o
                        const_board[x + i][y + j] = 1;
                    }
                }
                else if ((i == 0 && j == 0) || (i == length - 1 && j == width - 1))
                {
                    board[x + i][y + j] = 4; // 4 = /
                    const_board[x + i][y + j] = 4;
                }
                else if ((i == 0 && j == width - 1) || (i == length - 1 && j == 0))
                {
                    board[x + i][y + j] = -4; // -4 = back slash
                    const_board[x + i][y + j] = -4;
                }
                else if (j == 0)
                {
                    board[x + i][y + j] = 2; // 2 = <
                    const_board[x + i][y + j] = 2;
                }
                else if (j == width - 1)
                {
                    board[x + i][y + j] = -2; // -2 = >
                    const_board[x + i][y + j] = -2;
                }
                else if (i == 0)
                {
                    board[x + i][y + j] = 3; // 3 = ∧
                    const_board[x + i][y + j] = 3;
                }
                else if (i == length - 1)
                {
                    board[x + i][y + j] = -3; // -3 = ∨
                    const_board[x + i][y + j] = -3;
                }
                else
                {
                    board[x + i][y + j] = 1; // 1 = o
                    const_board[x + i][y + j] = 1;
                }
            }
        }
    }
    else if (position == 'v' || position == 'V')
    {
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < length; j++)
            {
                if (length == 1 && width == 1)
                {
                    board[x + i][y + j] = -1; // -1 = +
                    const_board[x + i][y + j] = -1;
                }
                else if (width == 1)
                {
                    if (j == 0)
                    {
                        board[x + i][y + j] = 2; // 2 = <
                        const_board[x + i][y + j] = 2;
                    }
                    else if (j == length - 1)
                    {
                        board[x + i][y + j] = -2; // -2 = >
                        const_board[x + i][y + j] = -2;
                    }
                    else
                    {
                        board[x + i][y + j] = 1; // 1 = o
                        const_board[x + i][y + j] = 1;
                    }
                }
                else if (length == 1)
                {
                    if (i == 0)
                    {
                        board[x + i][y + j] = 3; // 3 = ∧
                        const_board[x + i][y + j] = 3;
                    }
                    else if (i == width - 1)
                    {
                        board[x + i][y + j] = -3; // -3 = ∨
                        const_board[x + i][y + j] = -3;
                    }
                    else
                    {
                        board[x + i][y + j] = 1; // 1 = o
                        const_board[x + i][y + j] = 1;
                    }
                }
                else if ((i == 0 && j == 0) || (i == width - 1 && j == length - 1))
                {
                    board[x + i][y + j] = 4; // 4 = /
                    const_board[x + i][y + j] = 4;
                }
                else if ((i == 0 && j == length - 1) || (i == width - 1 && j == 0))
                {
                    board[x + i][y + j] = -4; // -4 = back slash
                    const_board[x + i][y + j] = -4;
                }
                else if (j == 0)
                {
                    board[x + i][y + j] = 2; // 2 = <
                    const_board[x + i][y + j] = 2;
                }
                else if (j == length - 1)
                {
                    board[x + i][y + j] = -2; // -2 = >
                    const_board[x + i][y + j] = -2;
                }
                else if (i == 0)
                {
                    board[x + i][y + j] = 3; // 3 = ∧
                    const_board[x + i][y + j] = 3;
                }
                else if (i == width - 1)
                {
                    board[x + i][y + j] = -3; // -3 = ∨
                    const_board[x + i][y + j] = -3;
                }
                else
                {
                    board[x + i][y + j] = 1; // 1 = o
                    const_board[x + i][y + j] = 1;
                }
            }
        }
    }
}

int check_remaining_boats(int board[][100], int player_cur_boat_count, int *remaining_boat, int player)
{
    for (int i = 0; i < player_cur_boat_count; i++)
    {
        int sw = 0;
        int x;
        int y;
        int length;
        int width;
        char type;
        if (player == 1)
        {
            int situation = P1_boats[i].situ;
            if (situation == 1)
            {
                continue;
            }
            x = P1_boats[i].x;
            y = P1_boats[i].y;
            length = P1_boats[i].length;
            width = P1_boats[i].width;
            type = P1_boats[i].position;
            if (type == 'h' || type == 'H')
            {
                for (int k = x; k < length + x; k++)
                {
                    for (int j = y; j < width + y; j++)
                    {
                        if (board[k][j] != 10)
                        {
                            sw = 1;
                            break;
                        }
                    }
                    if (sw == 1)
                        break;
                }
                if (sw == 0 && P1_boats[i].situ == 0)
                {
                    (*remaining_boat)--;
                    P1_boats[i].situ = 1;
                    return 1;
                }
            }
            else if (type == 'v' || type == 'V')
            {
                for (int k = x; k < width + x && P1_boats[i].situ == 0; k++)
                {
                    for (int j = y; j < length + y; j++)
                    {
                        if (board[k][j] != 10)
                        {
                            sw = 1;
                            break;
                        }
                    }
                    if (sw == 1)
                        break;
                }
                if (sw == 0 && P1_boats[i].situ == 0)
                {
                    (*remaining_boat)--;
                    P1_boats[i].situ = 1;
                    return 1;
                }
            }
        }
        else if (player == 2)
        {
            x = P2_boats[i].x;
            y = P2_boats[i].y;
            length = P2_boats[i].length;
            width = P2_boats[i].width;
            type = P2_boats[i].position;
            int situation = P2_boats[i].situ;
            if (situation == 1)
            {
                continue;
            }
            if (type == 'h' || type == 'H')
            {
                for (int k = x; k < length + x; k++)
                {
                    for (int j = y; j < width + y; j++)
                    {
                        if (board[k][j] != 10)
                        {
                            sw = 1;
                            break;
                        }
                    }
                    if (sw == 1)
                        break;
                }
                if (sw == 0 && P2_boats[i].situ == 0)
                {
                    (*remaining_boat)--;
                    P2_boats[i].situ = 1;
                    return 2;
                }
            }
            else if (type == 'v' || type == 'V')
            {
                for (int k = x; k < width + x && P2_boats[i].situ == 0; k++)
                {
                    for (int j = y; j < length + y; j++)
                    {
                        if (board[k][j] != 10)
                        {
                            sw = 1;
                            break;
                        }
                    }
                    if (sw == 1)
                        break;
                }
                if (sw == 0 && P2_boats[i].situ == 0)
                {
                    (*remaining_boat)--;
                    P2_boats[i].situ = 1;
                    return 2;
                }
            }
        }
    }
    return 0;
}

int repair(int board[][100], int const_board[][100], int BOARD_OPP[][100], int Total_boats, int X, int Y, int player)
{
    for (int i = 0; i < Total_boats; i++)
    {
        int x;
        int y;
        int length;
        int width;
        char type;
        if (player == 1)
        {
            int situation = P1_boats[i].situ;
            x = P1_boats[i].x;
            y = P1_boats[i].y;
            length = P1_boats[i].length;
            width = P1_boats[i].width;
            type = P1_boats[i].position;
            if (type == 'h' || type == 'H')
            {
                for (int k = x; k < length + x; k++)
                {
                    for (int j = y; j < width + y; j++)
                    {
                        if (k == X && j == Y)
                        {
                            if (situation == 1)
                            {
                                return 0;
                            }
                            else
                            {
                                int temp = const_board[X][Y];
                                board[X][Y] = temp;
                                BOARD_OPP[X][Y] = 0;
                                return 1;
                            }
                        }
                    }
                }
            }
            else if (type == 'v' || type == 'V')
            {
                for (int k = x; k < width + x && P1_boats[i].situ == 0; k++)
                {
                    for (int j = y; j < length + y; j++)
                    {
                        if (k == X && j == Y)
                        {
                            if (situation == 1)
                            {
                                return 0;
                            }
                            else
                            {
                                int temp = const_board[X][Y];
                                board[X][Y] = temp;
                                BOARD_OPP[X][Y] = 0;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        else if (player == 2)
        {
            x = P2_boats[i].x;
            y = P2_boats[i].y;
            length = P2_boats[i].length;
            width = P2_boats[i].width;
            type = P2_boats[i].position;
            int situation = P2_boats[i].situ;
            if (type == 'h' || type == 'H')
            {
                for (int k = x; k < length + x; k++)
                {
                    for (int j = y; j < width + y; j++)
                    {
                        if (k == X && j == Y)
                        {
                            if (situation == 1)
                            {
                                return 0;
                            }
                            else
                            {
                                int temp = const_board[X][Y];
                                board[X][Y] = temp;
                                BOARD_OPP[X][Y] = 0;
                                return 1;
                            }
                        }
                    }
                }
            }
            else if (type == 'v' || type == 'V')
            {
                for (int k = x; k < width + x && P2_boats[i].situ == 0; k++)
                {
                    for (int j = y; j < length + y; j++)
                    {
                        if (k == X && j == Y)
                        {
                            if (situation == 1)
                            {
                                return 0;
                            }
                            else
                            {
                                int temp = const_board[X][Y];
                                board[X][Y] = temp;
                                BOARD_OPP[X][Y] = 0;
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

int random_place_x_aft(int i, int size)
{
    int x[3] = {0};
    if (i - 1 >= 1)
        x[0] = i - 1;
    x[1] = i;
    if (i + 1 <= size)
        x[2] = i + 1;
    int answ = x[rand() % (3)];
    while (answ == 0)
    {
        answ = x[rand() % (3)];
    }
    return answ;
}

int random_place_y_aft(int j, int size)
{
    int y[3] = {0};
    if (j - 1 >= 1)
        y[0] = j - 1;
    y[1] = j;
    if (j + 1 <= size)
        y[2] = j + 1;
    int answ = y[rand() % (3)];
    while (answ == 0)
    {
        answ = y[rand() % (3)];
    }
    return answ;
}

int random_place(int size, int board[][100])
{
    int x, y;
    x = rand() % (size - 1 + 1) + 1;
    y = rand() % (size - 1 + 1) + 1;
    while (board[x][y] == 10)
    {
        x = rand() % (size - 1 + 1) + 1;
        y = rand() % (size - 1 + 1) + 1;
    }
    int answ = (x * 10) + y;
    return answ;
}

void print_image(FILE *fptr)
{
    char read_string[128];

    while (fgets(read_string, sizeof(read_string), fptr) != NULL)
        printf("%s", read_string);
}

int MainMenu()
{
    char temp[5];
    int number;
    printf("\n\n");
    Space(85);
    printf("MAIN MENU\n\n");
    Space(80);
    printf("1. Play Multiplayer\n\n");
    Space(80);
    printf("2. Play With AI\n\n");
    Space(80);
    printf("3. Load Last Game\n\n");
    for (;;)
    {
        Space(80);
        scanf("%s", temp);
        if (Check_Input(temp) == 1)
        {
            Space(80);
            Error(2);
            continue;
        }
        else
        {
            number = StrToNum(temp);
        }
        if (number != 1 && number != 2 && number != 3)
        {
            Space(80);
            Error(3);
            continue;
        }
        else
        {
            return (number);
        }
    }
}

int main()
{
    clrscr();
    char *startup = "startup.txt";
    FILE *fptr = NULL;
    if ((fptr = fopen(startup, "r")) == NULL)
    {
        fprintf(stderr, "error opening %s\n", startup);
        return 1;
    }
    print_image(fptr);
    fclose(fptr);
    int Command = MainMenu();
    int play_robot;
    int attack_bot_count = -1;
    int P1_col;
    int P2_col;
    int SIZE;
    char player1[MAXIMUM_PLAYER_COUNT];
    char player2[MAXIMUM_PLAYER_COUNT];
    char position;
    char temp1[MAXIMUM_PLAYER_COUNT], temp2[MAXIMUM_PLAYER_COUNT], temp3[MAXIMUM_PLAYER_COUNT];
    int Load_Situ;
    FILE *LOAD;
    for (int i = 0; i < 100; i++)
    {
        P1_boats[i].situ = 0;
        P2_boats[i].situ = 0;
    }
    // clrscr();
    if (Command == 1)
    {
        play_robot = 0;
        Load_Situ = 0;
        LOAD = fopen("Load.txt", "wt");
        if (!LOAD)
        {
            printf("CANT OPEN FILE");
            return 0;
        }
        fprintf(LOAD, "%d\n", Command);
    }
    else if (Command == 2)
    {
        play_robot = 1;
        Load_Situ = 0;
        LOAD = fopen("Load.txt", "wt");
        if (!LOAD)
        {
            printf("CANT OPEN FILE");
            return 0;
        }
        fprintf(LOAD, "%d\n", Command);
    }
    else if (Command == 3)
    {
        Load_Situ = 1;
        LOAD = fopen("Load.txt", "r+t");
        if (!LOAD)
        {
            printf("CANT OPEN FILE");
            return 0;
        }
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%d", &Command);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
                Error(11);
                return 0;
            }
            else
            {
                if (Command == 1)
                {
                    play_robot = 0;
                }
                else if (Command == 2)
                {
                    play_robot = 1;
                }
            }
        }
    }
    printf("Please enter the length of board: ");
    for (;;)
    {
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%d", &SIZE);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
            }
            else
            {
                break;
            }
        }
        if (Load_Situ == 0)
        {
            scanf("%s", temp1);
            if (StrToNum(temp1) < 3)
            {
                Error(1);
            }
            else if (Check_Input(temp1) == 1)
            {
                Error(2);
            }
            else
            {
                SIZE = StrToNum(temp1);
                fprintf(LOAD, "%d\n", SIZE);
                fflush(LOAD);
                break;
            }
        }
    }
    int BOARD_P1[SIZE + 1][100];
    int BOARD_P2[SIZE + 1][100];
    int BOARD_OPP_P1[SIZE + 1][100];
    int BOARD_OPP_P2[SIZE + 1][100];
    int BOARD_CONST_P1[SIZE + 1][100];
    int BOARD_CONST_P2[SIZE + 1][100];
    int x = 0;
    int y = 0;
    int length;
    int width;
    int repair_p1;
    int repair_p2;

    PreBoard(SIZE, BOARD_P1, BOARD_P2, BOARD_OPP_P1, BOARD_OPP_P2, BOARD_CONST_P1, BOARD_CONST_P2);

    int Boat_Count;
    int All_Ships;
    int Temp_All_Ships;
    int Total_Boats_P1 = 0;
    int Total_Boats_P2 = 0;

    printf("Please enter the number of total space for all ships: ");
    for (;;)
    {
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%d", &All_Ships);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
            }
            else
            {
                break;
            }
        }
        if (Load_Situ == 0)
        {
            for (;;)
            {
                scanf("%s", temp1);
                if (Check_Input(temp1) == 1)
                {
                    Error(2);
                }
                else if (StrToNum(temp1) < 1)
                {
                    Error(3);
                }
                else
                {
                    All_Ships = StrToNum(temp1);
                    break;
                }
            }
            getchar();
            if (All_Ships > SIZE * SIZE)
            {
                Error(5);
            }
            else
            {
                fprintf(LOAD, "%d\n", All_Ships);
                fflush(LOAD);
                break;
            }
        }
    }
    printf("Please enter the amount of alowed repairs: ");
    for (;;)
    {
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%d", &repair_p1);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
            }
            else
            {
                break;
            }
        }
        if (Load_Situ == 0)
        {
            scanf("%s", &temp1);
            if (Check_Input(temp1) == 1)
            {
                Error(3);
                continue;
            }
            else
            {
                repair_p1 = StrToNum(temp1);
            }
            if (repair_p1 < 0)
            {
                Error(3);
                continue;
            }
            else
            {
                fprintf(LOAD, "%d\n", repair_p1);
                fflush(LOAD);
                break;
            }
        }
    }
    repair_p2 = repair_p1;
    getchar();
    printf("Please enter your name : ");
    if (Load_Situ == 1 && feof(LOAD) == 0)
    {
        fscanf(LOAD, "%s", player1);
        if (feof(LOAD) != 0)
        {
            Load_Situ = 0;
        }
    }
    if (Load_Situ == 0)
    {
        gets(player1);
        fprintf(LOAD, "%s\n", player1);
        fflush(LOAD);
    }

    printf("Choose your color : ");

    setTextColor(4, 0);
    printf("\nRed = 4");
    setTextColor(2, 0);
    printf("\nGreen = 2");
    setTextColor(6, 0);
    printf("\nYellow = 6");
    setTextColor(5, 0);
    printf("\nPurple = 5\n");
    setTextColor(15, 0);

    for (;;) // check kardan voroodi dorost baraye rang
    {
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%d", &P1_col);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
            }
            else
            {
                break;
            }
        }
        if (Load_Situ == 0)
        {
            scanf("%s", temp1);
            if (Check_Input(temp1) == 1)
            {
                Error(3);
                continue;
            }
            else
            {
                P1_col = StrToNum(temp1);
            }
            if (P1_col != 2 && P1_col != 4 && P1_col != 5 && P1_col != 6)
            {
                Error(3);
            }
            else
            {
                fprintf(LOAD, "%d\n", P1_col);
                fflush(LOAD);
                break;
            }
        }
    }

    // gereftan mokhtasat kashtiha va alamat gozari
    Temp_All_Ships = All_Ships;
    do
    {
        setTextColor(P1_col, 0);
        printf("%s", player1);
        setTextColor(15, 0);
        printf("! Please enter length and width of your ship and the number of it: \n");

        for (;;)
        {
            if (Load_Situ == 1 && feof(LOAD) == 0)
            {
                fscanf(LOAD, "%d %d %d", &length, &width, &Boat_Count);
                if (feof(LOAD) != 0)
                {
                    Load_Situ = 0;
                }
                else
                {
                    break;
                }
            }
            if (Load_Situ == 0)
            {
                scanf("%s %s %s", temp1, temp2, temp3);
                if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1 || Check_Input(temp3) == 1)
                {
                    Error(3);
                    continue;
                }
                else
                {
                    length = StrToNum(temp1);
                    width = StrToNum(temp2);
                    Boat_Count = StrToNum(temp3);
                }
                if (length * width * Boat_Count > Temp_All_Ships || length < 1 || width < 1 || Boat_Count < 1 || length > SIZE || width > SIZE)
                {
                    Error(3);
                    continue;
                }
                else
                {
                    fprintf(LOAD, "%d %d %d\n", length, width, Boat_Count);
                    fflush(LOAD);
                    break;
                }
            }
        }

        setTextColor(P1_col, 0);
        printf("%s", player1);
        setTextColor(15, 0);
        printf("! Please enter the coordinates of your ships and their positions (x y (h/v)): \n");

        PrePlaceShip(SIZE, Boat_Count, BOARD_P1, BOARD_CONST_P1, BOARD_P2, BOARD_CONST_P2, length, width, 1, &Total_Boats_P1, play_robot, LOAD, &Load_Situ);

        Temp_All_Ships -= length * width * Boat_Count;
        if (Temp_All_Ships != 0)
        {
            printf("Do you want to put another ship ? (y/n): ");
            for (;;)
            {
                if (Load_Situ == 1 && feof(LOAD) == 0)
                {
                    fscanf(LOAD, "%s", &temp1);
                    if (feof(LOAD) != 0)
                    {
                        Load_Situ = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                if (Load_Situ == 0)
                {
                    scanf("%s", temp1);
                    if (temp1[0] == 'y')
                    {
                        fprintf(LOAD, "%c\n", temp1[0]);
                        fflush(LOAD);
                        break;
                    }
                    else if (temp1[0] == 'n')
                    {
                        fprintf(LOAD, "%c\n", temp1[0]);
                        fflush(LOAD);
                        break;
                    }
                    else
                        Error(4);
                }
            }
        }
    } while (temp1[0] == 'y' && Temp_All_Ships != 0);

    Line(5);
    printf("\n");
    if (Load_Situ == 0)
    {
        getchar();
    }
    Delay(1000);
    clrscr();
    if (play_robot == 1)
    {
        strcpy(player2, "Jamshid");
        P2_col = 4;
        Total_Boats_P2 = Total_Boats_P1;
    }
    else
    {
        printf("Please enter your name: ");
        if (Load_Situ == 1 && feof(LOAD) == 0)
        {
            fscanf(LOAD, "%s", &player2);
            if (feof(LOAD) != 0)
            {
                Load_Situ = 0;
            }
        }
        if (Load_Situ == 0)
        {
            gets(player2);
            fprintf(LOAD, "%s\n", player2);
            fflush(LOAD);
        }

        printf("Choose your color : ");

        setTextColor(4, 0);
        printf("\nRed = 4");
        setTextColor(2, 0);
        printf("\nGreen = 2");
        setTextColor(6, 0);
        printf("\nYellow = 6");
        setTextColor(5, 0);
        printf("\nPurple = 5\n");
        setTextColor(15, 0);

        for (;;) // check kardan voroodi dorost baraye rang
        {
            if (Load_Situ == 1 && feof(LOAD) == 0)
            {
                fscanf(LOAD, "%d", &P2_col);
                if (feof(LOAD) != 0)
                {
                    Load_Situ = 0;
                }
                else
                {
                    break;
                }
            }
            if (Load_Situ == 0)
            {
                scanf("%s", temp1);
                if (Check_Input(temp1) == 1)
                {
                    Error(3);
                    continue;
                }
                else
                    P2_col = StrToNum(temp1);
                if (P2_col != 2 && P2_col != 4 && P2_col != 5 && P2_col != 6)
                    Error(3);
                else
                {
                    fprintf(LOAD, "%d\n", P2_col);
                    fflush(LOAD);
                    break;
                }
            }
        }
        // gereftan mokhtasat kashtiha va alamat gozari
        Temp_All_Ships = All_Ships;
        do
        {
            setTextColor(P2_col, 0);
            printf("%s", player2);
            setTextColor(15, 0);
            printf("! Please enter length and width of your ship and the number of it: \n");

            for (;;)
            {
                if (Load_Situ == 1 && feof(LOAD) == 0)
                {
                    fscanf(LOAD, "%d %d %d", &length, &width, &Boat_Count);
                    if (feof(LOAD) != 0)
                    {
                        Load_Situ = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                if (Load_Situ == 0)
                {
                    scanf("%s %s %s", temp1, temp2, temp3);
                    if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1 || Check_Input(temp3) == 1)
                    {
                        Error(3);
                        continue;
                    }
                    else
                    {
                        length = StrToNum(temp1);
                        width = StrToNum(temp2);
                        Boat_Count = StrToNum(temp3);
                    }
                    if (length * width * Boat_Count > Temp_All_Ships || length < 1 || width < 1 || Boat_Count < 1 || length > SIZE || width > SIZE)
                    {
                        Error(3);
                        continue;
                    }
                    else
                    {
                        fprintf(LOAD, "%d %d %d\n", length, width, Boat_Count);
                        fflush(LOAD);
                        break;
                    }
                }
            }

            setTextColor(P2_col, 0);
            printf("%s", player2);
            setTextColor(15, 0);
            printf("! Please enter the coordinates of your ships and their positions (x y (h/v)): \n");

            PrePlaceShip(SIZE, Boat_Count, BOARD_P2, BOARD_CONST_P2, BOARD_P1, BOARD_CONST_P1, length, width, 2, &Total_Boats_P2, play_robot, LOAD, &Load_Situ);

            Temp_All_Ships -= length * width * Boat_Count;

            if (Temp_All_Ships != 0)
            {
                printf("Do you want to put another ship ? (y/n): ");
                for (;;)
                {
                    if (Load_Situ == 1 && feof(LOAD) == 0)
                    {
                        fscanf(LOAD, "%s", &temp1);
                        if (feof(LOAD) != 0)
                        {
                            Load_Situ = 0;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (Load_Situ == 0)
                    {
                        scanf("%s", temp1);
                        if (temp1[0] == 'y')
                        {
                            fprintf(LOAD, "%c\n", temp1[0]);
                            fflush(LOAD);
                            break;
                        }
                        else if (temp1[0] == 'n')
                        {
                            fprintf(LOAD, "%c\n", temp1[0]);
                            fflush(LOAD);
                            break;
                        }
                        else
                            Error(4);
                    }
                }
            }
        } while (temp1[0] == 'y' && Temp_All_Ships != 0);
        if (Load_Situ == 0)
        {
            getchar();
        }
    }

    Line(5);
    printf("\n");

    // Delay(1000);
    clrscr();
    if (Load_Situ == 0)
    {
        setTextColor(P1_col, 0);
        printf("\n%s", player1);
        setTextColor(15, 0);
        printf("! If you ready to see your final board , press ENTER : ");

        for (;;)
        {
            gets(temp1);
            if (temp1[0] == 0)
                break;
            else
                Error(4);
        }

        printf("\n");
        Line(SIZE * 3 + 1);
        printf("\n");

        // Delay(1000);

        // printe board FOCP1
        Print_Board(BOARD_P1, SIZE, player1, Total_Boats_P1, P1_col);

        Delay(3000);

        printf("\n");
        Line(SIZE * 3 + 1);
        printf("\n");

        Delay(3000);
        clrscr();

        if (play_robot != 1)
        {
            setTextColor(P2_col, 0);
            printf("\n%s", player2);
            setTextColor(15, 0);
            printf("! If you ready to see your final board , press ENTER : ");
            for (;;)
            {
                gets(temp1);
                if (temp1[0] == 0)
                    break;
                else
                    Error(4);
            }
            printf("\n");
            Line(SIZE * 3 + 1);
            printf("\n");

            // Delay(1000);

            // printe board FOCP2
            Print_Board(BOARD_P2, SIZE, player2, Total_Boats_P2, P2_col);

            Delay(3000);

            printf("\n");
            Line(SIZE * 3 + 1);
            printf("\n");
            Delay(3000);
            clrscr();
        }

    }

    int RMN_Ships1 = Total_Boats_P1; // remaining ships for player 1
    int RMN_Ships2 = Total_Boats_P2; // remaining ships for player 2
    int Round;
    int P1_SW = 0;
    int P2_SW = 0;

    int sink_p1_boat;
    int sink_p2_boat;
    // ghesmate entehayi bazi (hamle kardan be mape hamdige)
    int bot_hit = 0;
    int x_hit, y_hit;
    for (Round = 1; RMN_Ships1 != 0 && RMN_Ships2 != 0;)
    {
        int att_or_rep;
        // Delay(1500);
        Space((3 * SIZE + 1) + 4);

        setTextColor(4, 0);
        printf("ROUND%d\n\n", Round);
        setTextColor(15, 0);

        // Delay(1500);

        if (repair_p1 != 0)
        {
            setTextColor(P1_col, 0);
            printf("%s ", player1);
            setTextColor(15, 0);
            printf("! Do you want to attack(1) or repair(2)?  (1/2)\n");
            for (;;)
            {
                if (Load_Situ == 1 && feof(LOAD) == 0)
                {
                    fscanf(LOAD, "%d", &att_or_rep);
                    if (feof(LOAD) != 0)
                    {
                        Load_Situ = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                if (Load_Situ == 0)
                {
                    scanf("%s", &temp1);
                    if (Check_Input(temp1) == 1)
                    {
                        Error(2);
                        continue;
                    }
                    else
                        att_or_rep = StrToNum(temp1);
                    if (att_or_rep != 1 && att_or_rep != 2)
                    {
                        Error(3);
                        continue;
                    }
                    else
                    {
                        fprintf(LOAD, "%d\n", att_or_rep);
                        fflush(LOAD);
                        break;
                    }
                }
            }
        }
        if (att_or_rep == 1 || repair_p1 == 0)
        {
            setTextColor(P1_col, 0);
            printf("%s ", player1);
            setTextColor(15, 0);
            printf("! Enter a coordinate to attack : ");

            for (;;)
            {
                if (Load_Situ == 1 && feof(LOAD) == 0)
                {
                    fscanf(LOAD, "%d %d", &x, &y);
                    if (feof(LOAD) != 0)
                    {
                        Load_Situ = 0;
                    }
                    else
                    {
                        break;
                    }
                }
                if (Load_Situ == 0)
                {
                    scanf("%s %s", &temp1, &temp2);
                    if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
                        Error(3);
                    else
                    {
                        x = StrToNum(temp1);
                        y = StrToNum(temp2);
                        if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                            Error(7);
                        else if (BOARD_P2[x][y] == Clashed)
                            Error(8);
                        else
                        {
                            fprintf(LOAD, "%d %d\n", x, y);
                            fflush(LOAD);
                            break;
                        }
                    }
                }
            }

            if (BOARD_P2[x][y] == 1 || BOARD_P2[x][y] == -1 || BOARD_P2[x][y] == 2 || BOARD_P2[x][y] == -2 || BOARD_P2[x][y] == 3 || BOARD_P2[x][y] == -3 || BOARD_P2[x][y] == 4 || BOARD_P2[x][y] == -4)
            {
                BOARD_OPP_P1[x][y] = Clashed;
                BOARD_P2[x][y] = Clashed;
            }
            else
            {
                BOARD_OPP_P1[x][y] = Missed;
            }
        }
        else if (att_or_rep == 2)
        {
            setTextColor(P1_col, 0);
            printf("%s ", player1);
            setTextColor(15, 0);
            printf("! Enter a coordinate to repair : ");

            for (;;)
            {
                if (Load_Situ == 1 && feof(LOAD) == 0)
                {
                    fscanf(LOAD, "%d %d", &x, &y);
                    if (feof(LOAD) != 0)
                    {
                        Load_Situ = 0;
                    }
                    else
                    {
                        int rep = repair(BOARD_P1, BOARD_CONST_P1, BOARD_OPP_P2, Total_Boats_P1, x, y, 1);
                        if (rep == 1)
                        {
                            repair_p1--;
                            break;
                        }
                    }
                }
                if (Load_Situ == 0)
                {
                    scanf("%s %s", &temp1, &temp2);
                    if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
                    {
                        Error(3);
                        continue;
                    }
                    else
                    {
                        x = StrToNum(temp1);
                        y = StrToNum(temp2);
                        if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                        {
                            Error(9);
                            continue;
                        }
                        else if (BOARD_P1[x][y] != 10)
                        {
                            Error(9);
                            continue;
                        }
                    }
                    int rep = repair(BOARD_P1, BOARD_CONST_P1, BOARD_OPP_P2, Total_Boats_P1, x, y, 1);
                    if (rep == 0) // kashti ghargh shode ast
                    {
                        Error(10);
                        continue;
                    }
                    else if (rep == 1)
                    {
                        fprintf(LOAD, "%d %d\n", x, y);
                        fflush(LOAD);
                        repair_p1--;
                        break;
                    }
                }
            }
        }
        sink_p2_boat = check_remaining_boats(BOARD_P2, Total_Boats_P2, &RMN_Ships2, 2);
        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        Print_TwoBoard(BOARD_P1, BOARD_OPP_P1, SIZE, player1, RMN_Ships1, P1_col);

        if (sink_p1_boat == 1)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(4, 0);
            printf("You lost a ship");
            setTextColor(15, 0);
            sink_p1_boat = 0;
        }
        if (sink_p2_boat == 2)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(2, 0);
            printf("You sinked a ship");
            setTextColor(15, 0);
        }

        if (BOARD_OPP_P1[x][y] == -10) BOARD_OPP_P1[x][y] = 0; // hazf khune hamle shode be dalil nabood keshti dar mokhtasate morede nazar
        // Delay(4500);

        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        if (RMN_Ships2 == 0)
        {
            // Delay(1500);
            setTextColor(P1_col, 0);
            printf("%s", player1);
            setTextColor(15, 0);
            printf(" WINS!");
            // Delay(2500);
            break;
        }

        Delay(4000);
        printf("\n");
        // clrscr();
        if (play_robot)
        {
            if (bot_hit == 0)
            {
                int sw = 0;
                attack_bot_count++;
                while (sw == 0)
                {
                    int xy = random_place(SIZE, BOARD_OPP_P2);
                    x = xy / 10;
                    y = xy % 10;
                    if (attack_bot_count == 0)
                    {
                        attacked_places[attack_bot_count].x = x;
                        attacked_places[attack_bot_count].y = y;
                        break;
                    }
                    for (int i = 0; i < attack_bot_count; i++)
                    {
                        if (x != attacked_places[i].x || y != attacked_places[i].y)
                            sw = 1;
                        else if (x == attacked_places[i].x && y == attacked_places[i].y)
                        {
                            sw = 0;
                            break;
                        }
                    }
                }
                if (attack_bot_count != 0)
                {
                    attacked_places[attack_bot_count].x = x;
                    attacked_places[attack_bot_count].y = y;
                }
            }
            else
            {
                int sw = 0;
                attack_bot_count++;
                while (sw == 0)
                {
                    x = random_place_x_aft(x_hit, SIZE);
                    y = random_place_y_aft(y_hit, SIZE);
                    while (BOARD_OPP_P2[x][y] == 10)
                    {
                        x = random_place_x_aft(x_hit, SIZE);
                        y = random_place_y_aft(y_hit, SIZE);
                    }
                    for (int i = 0; i < attack_bot_count; i++)
                    {
                        if (x != attacked_places[i].x || y != attacked_places[i].y)
                            sw = 1;
                        else if (x == attacked_places[i].x && y == attacked_places[i].y)
                        {
                            sw = 0;
                            break;
                        }
                    }
                }
                attacked_places[attack_bot_count].x = x;
                attacked_places[attack_bot_count].y = y;
            }

            if (BOARD_P1[x][y] == 1 || BOARD_P1[x][y] == -1 || BOARD_P1[x][y] == 2 || BOARD_P1[x][y] == -2 || BOARD_P1[x][y] == 3 || BOARD_P1[x][y] == -3 || BOARD_P1[x][y] == 4 || BOARD_P1[x][y] == -4)
            {
                BOARD_OPP_P2[x][y] = Clashed;
                BOARD_P1[x][y] = Clashed;
                x_hit = x;
                y_hit = y;
                bot_hit = 1;
            }
            else
            {
                BOARD_OPP_P2[x][y] = Missed;
                bot_hit = 0;
            }
        }
        else
        {
            if (repair_p2 != 0)
            {
                setTextColor(P2_col, 0);
                printf("%s ", player2);
                setTextColor(15, 0);
                printf("! Do you want to attack(1) or repair(2)?  (1/2)\n");
                for (;;)
                {
                    if (Load_Situ == 1 && feof(LOAD) == 0)
                    {
                        fscanf(LOAD, "%d", &att_or_rep);
                        if (feof(LOAD) != 0)
                        {
                            Load_Situ = 0;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (Load_Situ == 0)
                    {
                        scanf("%s", &temp1);
                        if (Check_Input(temp1) == 1)
                        {
                            Error(2);
                            continue;
                        }
                        else
                        {
                            att_or_rep = StrToNum(temp1);
                        }
                        if (att_or_rep != 1 && att_or_rep != 2)
                        {
                            Error(3);
                            continue;
                        }
                        else
                        {
                            fprintf(LOAD, "%d\n", att_or_rep);
                            fflush(LOAD);
                            break;
                        }
                    }
                }
            }

            if (att_or_rep == 1 || repair_p2 == 0)
            {
                setTextColor(P2_col, 0);
                printf("%s ", player2);
                setTextColor(15, 0);
                printf("! Enter a coordinate to attack : ");

                for (;;)
                {
                    if (Load_Situ == 1 && feof(LOAD) == 0)
                    {
                        fscanf(LOAD, "%d %d", &x, &y);
                        if (feof(LOAD) != 0)
                        {
                            Load_Situ = 0;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if (Load_Situ == 0)
                    {
                        scanf("%s %s", &temp1, &temp2);
                        if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
                            Error(3);
                        else
                        {
                            x = StrToNum(temp1);
                            y = StrToNum(temp2);
                            if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                                Error(7);
                            else if (BOARD_P1[x][y] == 10)
                                Error(8);
                            else
                            {
                                fprintf(LOAD, "%d %d\n", x, y);
                                fflush(LOAD);
                                break;
                            }
                        }
                    }
                }
                if (BOARD_P1[x][y] == 1 || BOARD_P1[x][y] == -1 || BOARD_P1[x][y] == 2 || BOARD_P1[x][y] == -2 || BOARD_P1[x][y] == 3 || BOARD_P1[x][y] == -3 || BOARD_P1[x][y] == 4 || BOARD_P1[x][y] == -4)
                {
                    BOARD_OPP_P2[x][y] = Clashed;
                    BOARD_P1[x][y] = Clashed;
                }
                else
                    BOARD_OPP_P2[x][y] = Missed;
            }
            else if (att_or_rep == 2)
            {
                setTextColor(P2_col, 0);
                printf("%s ", player2);
                setTextColor(15, 0);
                printf("! Enter a coordinate to repair : ");

                for (;;)
                {
                    if (Load_Situ == 1 && feof(LOAD) == 0)
                    {
                        fscanf(LOAD, "%d %d", &x, &y);
                        if (feof(LOAD) != 0)
                        {
                            Load_Situ = 0;
                        }
                        else
                        {
                            int rep = repair(BOARD_P2, BOARD_CONST_P2, BOARD_OPP_P1, Total_Boats_P2, x, y, 2);
                            if (rep == 1)
                            {
                                repair_p2--;
                                break;
                            }
                        }
                    }
                    if (Load_Situ == 0)
                    {
                        scanf("%s %s", &temp1, &temp2);
                        if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
                        {
                            Error(3);
                            continue;
                        }
                        else
                        {
                            x = StrToNum(temp1);
                            y = StrToNum(temp2);
                            if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                            {
                                Error(9);
                                continue;
                            }
                            else if (BOARD_P2[x][y] != 10)
                            {
                                Error(9);
                                continue;
                            }
                        }
                        int rep = repair(BOARD_P2, BOARD_CONST_P2, BOARD_OPP_P1, Total_Boats_P2, x, y, 2);
                        if (rep == 0) // kashti ghargh shode ast
                        {
                            Error(10);
                            continue;
                        }
                        else if (rep == 1)
                        {
                            repair_p2--;
                            break;
                        }
                    }
                }
            }
            printf("\n");
            Line(7 * SIZE + 2 + 21);
            printf("\n");

            Print_TwoBoard(BOARD_P2, BOARD_OPP_P2, SIZE, player2, RMN_Ships2, P2_col);
        }
        sink_p1_boat = check_remaining_boats(BOARD_P1, Total_Boats_P1, &RMN_Ships1, 1);

        if (sink_p2_boat == 2)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(4, 0);
            printf("You lost a ship");
            setTextColor(15, 0);
            sink_p2_boat = 0;
        }
        if (sink_p1_boat == 1)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(2, 0);
            printf("You sinked a ship");
            setTextColor(15, 0);
        }

        if (BOARD_OPP_P2[x][y] == Missed)  BOARD_OPP_P2[x][y] = 0; // hazf khune hamle shode be dalil nabood keshti dar mokhtasate morede nazar
        // Delay(4500);
        if (!play_robot)
        {
            printf("\n");
            Line(7 * SIZE + 2 + 21);
            printf("\n");
        }

        if (RMN_Ships1 == 0)
        {
            // Delay(1500);
            setTextColor(P2_col, 0);
            printf("\n%s", player2);
            setTextColor(15, 0);
            printf(" WINS!");
            // Delay(2500);
            break;
        }
        // Delay(4000);
        clrscr();
        Round++;
    }
    fclose(LOAD);
    return 0;
}