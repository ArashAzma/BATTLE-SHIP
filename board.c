#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define COLOR_BOLD "\e[1m"
#define COLOR_OFF "\e[m"

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
    Delay(1000);
    printf("Your Board :\n\n");
    Delay(1000);
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
    Delay(1000);
    printf("Your Board :");
    Space(3 * Size + 8);
    printf("Your OPP's Board :\n\n");
    Delay(1000);
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

void PrePlaceShip(int SIZE, int Boat_Count, int Board[][100], int ConstBoard[][100], int length, int width)
{
    char position;
    char temp1[10];
    char temp2[10];
    int x, y;
    for (int i = 1; i <= Boat_Count; i++)
    {
        for (;;)
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
        if (position != 'v' && position != 'h' && position != 'V' && position != 'H')
        {
            Error(4);
            i--;
            continue;
        }
        else if (check_place(Board, x, y, position, SIZE + 1, length, width) == 1 || x > SIZE || y > SIZE || x < 1 || y < 1)
        {
            Error(6);
            i--;
            continue;
        }
        else
        {
            place_boat(Board, ConstBoard, x, y, position, SIZE + 1, length, width);
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

int main()
{
    int P1_col;
    int P2_col;
    int SIZE;
    char player1[20];
    char player2[20];
    char position;
    char temp1[20], temp2[20], temp3[20];
    clrscr();
    printf("Please enter the length of board: ");
    for (;;)
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
            break;
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

    PreBoard(SIZE, BOARD_P1, BOARD_P2, BOARD_OPP_P1, BOARD_OPP_P2, BOARD_CONST_P1, BOARD_CONST_P2);

    int Boat_Count;
    int All_Ships;
    int Temp_All_Ships;

    printf("Please enter the number of total space for all ships: ");
    for (;;)
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
            break;
        }
    }

    printf("Please enter your name : ");
    gets(player1);

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
            break;
        }
    }

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    Temp_All_Ships = All_Ships;
    do
    {
        setTextColor(P1_col, 0);
        printf("%s", player1);
        setTextColor(15, 0);
        printf("! Please enter length and width of your ship and the number of it: \n");

        for (;;)
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
                break;
            }
        }

        setTextColor(P1_col, 0);
        printf("%s", player1);
        setTextColor(15, 0);
        printf("! Please enter the coordinates of your ships and their positions (x y (h/v)): \n");

        PrePlaceShip(SIZE, Boat_Count, BOARD_P1, BOARD_CONST_P1, length, width);

        Temp_All_Ships -= length * width * Boat_Count;

        printf("Do you want to put another ship ? (y/n): ");
        for (;;)
        {
            scanf("%s", temp1);
            if (temp1[0] == 'y')
            {
                break;
            }
            else if (temp1[0] == 'n')
            {
                break;
            }
            else
            {
                Error(4);
            }
        }
    } while (temp1[0] == 'y' && Temp_All_Ships != 0);

    Line(5);
    printf("\n");
    getchar();
    Delay(2000);
    clrscr();
    printf("Please enter your name: ");
    gets(player2);

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
        scanf("%s", temp1);
        if (Check_Input(temp1) == 1)
        {
            Error(3);
            continue;
        }
        else
        {
            P2_col = StrToNum(temp1);
        }
        if (P2_col != 2 && P2_col != 4 && P2_col != 5 && P2_col != 6)
        {
            Error(3);
        }
        else
        {
            break;
        }
    }

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)

    Temp_All_Ships = All_Ships;

    do
    {
        setTextColor(P2_col, 0);
        printf("%s", player2);
        setTextColor(15, 0);
        printf("! Please enter length and width of your ship and the number of it: \n");

        for (;;)
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
                break;
            }
        }

        setTextColor(P2_col, 0);
        printf("%s", player2);
        setTextColor(15, 0);
        printf("! Please enter the coordinates of your ships and their positions (x y (h/v)): \n");

        PrePlaceShip(SIZE, Boat_Count, BOARD_P2, BOARD_CONST_P2, length, width);

        Temp_All_Ships -= length * width * Boat_Count;

        printf("Do you want to put another ship ? (y/n): ");
        for (;;)
        {
            scanf("%s", temp1);
            if (temp1[0] == 'y')
            {
                break;
            }
            else if (temp1[0] == 'n')
            {
                break;
            }
            else
            {
                Error(4);
            }
        }
    } while (temp1[0] == 'y' && Temp_All_Ships != 0);

    Line(5);
    printf("\n");

    Delay(1000);

    getchar();
    clrscr();
    setTextColor(P1_col, 0);
    printf("\n%s", player1);
    setTextColor(15, 0);
    printf("! If you ready to see your final board , press ENTER : ");

    for (;;)
    {
        gets(temp1);
        if (temp1[0] == 0)
        {
            break;
        }
        else
        {
            Error(4);
        }
    }

    printf("\n");
    Line(SIZE * 3 + 1);
    printf("\n");

    Delay(1000);

    // printe board FOCP1
    Print_Board(BOARD_P1, SIZE, player1, Boat_Count, P1_col);

    Delay(3000);

    printf("\n");
    Line(SIZE * 3 + 1);
    printf("\n");

    Delay(3000);
    clrscr();
    setTextColor(P2_col, 0);
    printf("\n%s", player2);
    setTextColor(15, 0);
    printf("! If you ready to see your final board , press ENTER : ");

    for (;;)
    {
        gets(temp1);
        if (temp1[0] == 0)
        {
            break;
        }
        else
        {
            Error(4);
        }
    }

    printf("\n");
    Line(SIZE * 3 + 1);
    printf("\n");

    Delay(1000);

    // printe board FOCP2
    Print_Board(BOARD_P2, SIZE, player2, Boat_Count, P2_col);

    Delay(3000);

    Delay(2000);
    printf("\n");
    Line(SIZE * 3 + 1);
    printf("\n");
    Delay(3000);
    clrscr();

    int RMN_Ships1 = Boat_Count; // remaining ships for player 1
    int RMN_Ships2 = Boat_Count; // remaining ships for player 2
    int Round;
    int P1_SW = 0;
    int P2_SW = 0;

    // ghesmate entehayi bazi (hamle kardan be mape hamdige)
    for (Round = 1; RMN_Ships1 != 0 && RMN_Ships2 != 0;)
    {
        Delay(1500);
        Space((3 * SIZE + 1) + 4);

        setTextColor(4, 0);
        printf("ROUND%d\n\n", Round);
        setTextColor(15, 0);

        Delay(1500);

        setTextColor(P1_col, 0);
        printf("%s", player1);
        setTextColor(15, 0);
        printf("! Enter a coordinate to attack : ");

        for (;;)
        {
            scanf("%s %s", &temp1, &temp2);
            if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
            {
                Error(3);
            }
            else
            {
                x = StrToNum(temp1);
                y = StrToNum(temp2);
                if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                {
                    Error(7);
                }
                else if (BOARD_P2[x][y] == 10)
                {
                    Error(8);
                }
                else
                {
                    break;
                }
            }
        }

        if (BOARD_P2[x][y] == 1 || BOARD_P2[x][y] == 2 || BOARD_P2[x][y] == -2 || BOARD_P2[x][y] == 3 || BOARD_P2[x][y] == -3)
        {
            if (BOARD_P2[x][y] == 1)
            {
                if (BOARD_P2[x - 1][y] == 10 && BOARD_P2[x + 1][y] == 10 && BOARD_CONST_P2[x - 1][y] == 3 && BOARD_CONST_P2[x + 1][y] == -3)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
                else if (BOARD_P2[x][y - 1] == 10 && BOARD_P2[x][y + 1] == 10 && BOARD_CONST_P2[x][y - 1] == 2 && BOARD_CONST_P2[x][y + 1] == -2)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
            }
            else if (BOARD_P2[x][y] == 2)
            {
                if (BOARD_P2[x][y + 1] == 10 && BOARD_P2[x][y + 2] == 10 && BOARD_CONST_P2[x][y + 1] == 1 && BOARD_CONST_P2[x][y + 2] == -2)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
            }
            else if (BOARD_P2[x][y] == -2)
            {
                if (BOARD_P2[x][y - 1] == 10 && BOARD_P2[x][y - 2] == 10 && BOARD_CONST_P2[x][y - 1] == 1 && BOARD_CONST_P2[x][y - 2] == 2)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
            }
            else if (BOARD_P2[x][y] == 3)
            {
                if (BOARD_P2[x + 1][y] == 10 && BOARD_P2[x + 2][y] == 10 && BOARD_CONST_P2[x + 1][y] == 1 && BOARD_CONST_P2[x + 2][y] == -3)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
            }
            else if (BOARD_P2[x][y] == -3)
            {
                if (BOARD_P2[x - 1][y] == 10 && BOARD_P2[x - 2][y] == 10 && BOARD_CONST_P2[x - 1][y] == 1 && BOARD_CONST_P2[x - 2][y] == 3)
                {
                    RMN_Ships2--;
                    P2_SW = 1;
                }
            }
            BOARD_OPP_P1[x][y] = 10;
            BOARD_P2[x][y] = 10;
        }
        else
        {
            BOARD_OPP_P1[x][y] = -10;
        }

        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        Print_TwoBoard(BOARD_P1, BOARD_OPP_P1, SIZE, player1, RMN_Ships1, P1_col);

        if (P1_SW == 1)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(4, 0);
            printf("You lose a ship");
            setTextColor(15, 0);
            P1_SW = 0;
        }

        if (BOARD_OPP_P1[x][y] == -10)
        {
            BOARD_OPP_P1[x][y] = 0; // hazf khune hamle shode be dalil nabood keshti dar mokhtasate morede nazar
        }

        Delay(4500);

        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        if (RMN_Ships2 == 0)
        {
            Delay(1500);
            setTextColor(P1_col, 0);
            printf("%s", player1);
            setTextColor(15, 0);
            printf(" WINS!");
            Delay(2500);
            break;
        }

        Delay(4000);
        printf("\n");
        clrscr();
        setTextColor(P2_col, 0);
        printf("%s", player2);
        setTextColor(15, 0);
        printf("! Enter a coordinate to attack : ");

        for (;;)
        {
            scanf("%s %s", &temp1, &temp2);
            if (Check_Input(temp1) == 1 || Check_Input(temp2) == 1)
            {
                Error(3);
            }
            else
            {
                x = StrToNum(temp1);
                y = StrToNum(temp2);
                if (x < 1 || y < 1 || x > SIZE || y > SIZE)
                {
                    Error(7);
                }
                else if (BOARD_P1[x][y] == 10)
                {
                    Error(8);
                }
                else
                {
                    break;
                }
            }
        }
        if (BOARD_P1[x][y] == 1 || BOARD_P1[x][y] == 2 || BOARD_P1[x][y] == -2 || BOARD_P1[x][y] == 3 || BOARD_P1[x][y] == -3)
        {
            if (BOARD_P1[x][y] == 1)
            {
                if (BOARD_P1[x - 1][y] == 10 && BOARD_P1[x + 1][y] == 10 && BOARD_CONST_P1[x - 1][y] == 3 && BOARD_CONST_P1[x + 1][y] == -3)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
                else if (BOARD_P1[x][y - 1] == 10 && BOARD_P1[x][y + 1] == 10 && BOARD_CONST_P1[x][y - 1] == 2 && BOARD_CONST_P1[x][y + 1] == -2)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
            }
            else if (BOARD_P1[x][y] == 2)
            {
                if (BOARD_P1[x][y + 1] == 10 && BOARD_P1[x][y + 2] == 10 && BOARD_CONST_P1[x][y + 1] == 1 && BOARD_CONST_P1[x][y + 2] == -2)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
            }
            else if (BOARD_P1[x][y] == -2)
            {
                if (BOARD_P1[x][y - 1] == 10 && BOARD_P1[x][y - 2] == 10 && BOARD_CONST_P1[x][y - 1] == 1 && BOARD_CONST_P1[x][y - 2] == 2)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
            }
            else if (BOARD_P1[x][y] == 3)
            {
                if (BOARD_P1[x + 1][y] == 10 && BOARD_P1[x + 2][y] == 10 && BOARD_CONST_P1[x + 1][y] == 1 && BOARD_CONST_P1[x + 2][y] == -3)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
            }
            else if (BOARD_P1[x][y] == -3)
            {
                if (BOARD_P1[x - 1][y] == 10 && BOARD_P1[x - 2][y] == 10 && BOARD_CONST_P1[x - 1][y] == 1 && BOARD_CONST_P1[x - 2][y] == 3)
                {
                    RMN_Ships1--;
                    P1_SW = 1;
                }
            }
            BOARD_OPP_P2[x][y] = 10;
            BOARD_P1[x][y] = 10;
        }
        else
        {
            BOARD_OPP_P2[x][y] = -10;
        }

        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        Print_TwoBoard(BOARD_P2, BOARD_OPP_P2, SIZE, player2, RMN_Ships2, P2_col);

        if (P2_SW == 1)
        {
            printf("\n\n");
            Space((3 * SIZE + 1) + 4);
            setTextColor(4, 0);
            printf("You lose a ship");
            setTextColor(15, 0);
            P2_SW = 0;
        }

        if (BOARD_OPP_P2[x][y] == -10)
        {
            BOARD_OPP_P2[x][y] = 0; // hazf khune hamle shode be dalil nabood keshti dar mokhtasate morede nazar
        }

        Delay(4500);

        printf("\n");
        Line(7 * SIZE + 2 + 21);
        printf("\n");

        if (RMN_Ships1 == 0)
        {
            Delay(1500);
            setTextColor(P2_col, 0);
            printf("%s", player2);
            setTextColor(15, 0);
            printf(" WINS!");
            Delay(2500);
            break;
        }
        Delay(4000);
        clrscr();
        Round++;
    }

    return 0;
}