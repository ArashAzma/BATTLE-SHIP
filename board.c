#include <stdio.h>
#include <windows.h>
#include <conio.h>

// TABE BARAYE KHAT KESHI BE TOOLE VOOROODIE (length)
int Line(int length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        printf("=");
    }
}

int check_place(int board[][100], int x, int y, char position, int size)
{
    if (position == 'h')
    {
        if (y < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x][y + i] == 1)
                {
                    return 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x][y - i] == 1)
                {
                    return 1;
                }
            }
        }
    }
    else if (position == 'v')
    {
        if (x < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x + i][y] == 1)
                {
                    return 1;
                }
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x - i][y] == 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void place_boat(int board[][100], int x, int y, char position, int size)
{
    if (position == 'h')
    {
        if (y < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                board[x][y + i] = 1;
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                board[x][y - i] = 1;
            }
        }
    }
    else if (position == 'v')
    {
        if (x < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                board[x + i][y] = 1;
            }
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                board[x - i][y] = 1;
            }
        }
    }
}

// TABE TAGHIR RANG
void setTextColor(int textColor, int backColor)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
// 0=black,1=blue,2=green,3=cyan,4=red,14=yellow,15=white

int main()
{
    const int SIZE;
    char player1[10];
    char player2[10];
    char position;
    printf("Please enter the length of board: ");
    scanf("%d", &SIZE);
    int BOARD_P1[SIZE + 1][100];
    int BOARD_P2[SIZE + 1][100];
    int x = 0;
    int y = 0;

    // SEFR KARDANE KHANE HA
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            BOARD_P1[i][j] = 0;
            BOARD_P2[i][j] = 0;
        }
    }

    const int Boat_Count;
    printf("Please enter the number of ships: ");
    scanf("%d", &Boat_Count);
    printf("Please enter your name: ");
    scanf("%s", player1);

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of your ships and their position %s(x y (h/v)): \n", player1);
    for (int i = 1; i <= Boat_Count; i++)
    {
        scanf("%d %d %c", &x, &y, &position);
        if (check_place(BOARD_P1, x, y, position, SIZE + 1) == 1 || x>SIZE || y>SIZE)
        {
            printf("YOU CANT PLACE THERE!\n" );
            i--;
            continue;
        }

        else
        {
            place_boat(BOARD_P1, x, y, position, SIZE + 1);
        }
    }
    printf("---\n");
    printf("Please enter your name: ");
    scanf("%s", player2);
    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of your ships and their position %s(x y (h/v)): \n", player2);
    for (int i = 1; i <= Boat_Count; i++)
    {
        scanf("%d %d %c", &x, &y, &position);
        if (check_place(BOARD_P2, x, y, position, SIZE + 1) == 1 || x>SIZE || y>SIZE)
        {
            printf("YOU CANT PLACE THERE!\n");
            i--;
            continue;
        }

        else
        {
            place_boat(BOARD_P2, x, y, position, SIZE + 1);
        }
    }

    //  VARED KARDANE SHOMARE OFOGHI
    for (int j = 1; j < SIZE + 1; j++)
    {
        BOARD_P1[0][j] = j;
        BOARD_P2[0][j] = j;
    }
    // VARED KARDANE SHOMARE AMOODI
    for (int i = 1; i < SIZE + 1; i++)
    {
        BOARD_P1[i][0] = i;
        BOARD_P2[i][0] = i;
    }

    // printe board FOCP1
    printf("\n");
    printf("~%s~\n", player1);
    printf("Number of ships: %d\n\n", Boat_Count);

    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("   ");
                continue;
            }
            else if (i >= 1 && j >= 1 && BOARD_P1[i][j] == 0) // TARH UB DADAN
            {
                setTextColor(3, 0);
                printf("~  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && BOARD_P1[i][j] == 1) // TARH UB DADAN
            {
                setTextColor(2, 0);
                printf("O  ");
                setTextColor(15, 0);
            }
            else
            {
                if (i == 0 && j > 9)
                {
                    printf("%d ", BOARD_P1[i][j]);
                }
                else if (i > 9 && j == 0)
                {
                    printf("%d ", BOARD_P1[i][j]);
                }
                else
                {
                    printf("%d  ", BOARD_P1[i][j]);
                }
            }
        }
        printf("\n\n");
    }
    Line(SIZE * 3 + 1);
    printf("\n\n");

    // printe board FOCP2
    printf("\n");
    printf("~%s~\n", player2);
    printf("Number of ships: %d\n\n", Boat_Count);
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("   ");
                continue;
            }
            else if (i >= 1 && j >= 1 && BOARD_P2[i][j] == 0) // TARH UB DADAN
            {
                setTextColor(3, 0);
                printf("~  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && BOARD_P2[i][j] == 1) // TARH UB DADAN
            {
                setTextColor(2, 0);
                printf("O  ");
                setTextColor(15, 0);
            }
            else
            {
                if (i == 0 && j > 9)
                {
                    printf("%d ", BOARD_P2[i][j]);
                }
                else if (i > 9 && j == 0)
                {
                    printf("%d ", BOARD_P2[i][j]);
                }
                else
                {
                    printf("%d  ", BOARD_P2[i][j]);
                }
            }
        }
        printf("\n\n");
    }

    return 0;
}