#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define COLOR_BOLD  "\e[1m"
#define COLOR_OFF   "\e[m"

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
int Check_Input( char Str[] )
{
    int i ;
    for( i = 0 ; Str[i] != 0 ; i++ )
    {
        if ( Str[i] < 48 || Str[i] > 57 )
        {
            return 1;
        }
    }
    return 0;
}


//TABE BARAYE TABDIL STRING BE ADAD
int StrToNum( char Str[] )
{
    int i , j ;
    int sum ;
    i = strlen(Str);
    for( j = 0 , sum = 0 ; Str[j] != 0 ; i-- , j++ )
    {
        sum = (Str[j] - 48) * pow(10 , i-1) + sum ;
    }
    return ( sum ) ;
}


// TABE TAGHIR RANG
void setTextColor(int textColor, int backColor)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
// 0=black,1=blue,2=green,3=cyan,4=red,14=yellow,15=white

int Print_Board(int board[][100],int Size)
{
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
                setTextColor(13, 0);
                printf("o  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("<  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf(">  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == 3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("^  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board[i][j] == -3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("V  ");
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
        printf("\n\n");
    }
}

int Print_TwoBoard(int board1[][100],int board2[][100],int Size)
{
    for (int i = 0; i < Size + 1; i++)
    {
        //PRINT BOARD AVAL
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
                setTextColor(13, 0);
                printf("o  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("<  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf(">  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == 3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("^  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board1[i][j] == -3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("V  ");
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

        printf("\t\t\t\t");

        //PRINT BOARD DOVOM
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
            else if (i >= 1 && j >= 1 && board2[i][j] == 1) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("o  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == 2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("<  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == -2) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf(">  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == 3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("^  ");
                setTextColor(15, 0);
            }
            else if (i >= 1 && j >= 1 && board2[i][j] == -3) // TARH KASHTI
            {
                setTextColor(13, 0);
                printf("V  ");
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
        printf("\n\n");
    }
}

int check_place(int board[][100], int x, int y, char position, int size)
{
    if (position == 'h' || position == 'H')
    {
        if (y < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x][y + i] == 1 || board[x][y + i] == 2 || board[x][y + i] == -2 || board[x][y + i] == 3 || board[x][y + i] == -3)
                {
                    return 1;
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
        if (x < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[x + i][y] == 1 || board[x + i][y] == 2 || board[x + i][y] == -2 || board[x + i][y] == 3 || board[x + i][y] == -3)
                {
                    return 1;
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

void place_boat(int board[][100], int x, int y, char position, int size)
{
    if (position == 'h' || position == 'H')
    {
        if (y < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if(i == 0)
                {
                    board[x][y + i] = 2; // 2 = ˂
                }
                else if(i == 2)
                {
                    board[x][y + i] = -2; // -2 = ˃
                }
                else
                {
                    board[x][y + i] = 1; // 1 = o
                }
            }
        }
        // else
        // {
        //     for (int i = 0; i < 3; i++)
        //     {
        //         if(i == 0)
        //         {
        //             board[x][y - i] = -2; // -2 = ˃
        //         }
        //         else if(i == 2)
        //         {
        //             board[x][y - i] = 2; // 2 = ˂
        //         }
        //         else 
        //         {
        //             board[x][y - i] = 1; // 1 = o
        //         }
        //     }
        // }
    }
    else if (position == 'v' || position == 'V')
    {
        if (x < size - 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if(i == 0)
                {
                    board[x + i][y] = 3; // 3 = ∧
                }
                else if(i == 2)
                {
                    board[x + i][y] = -3; // -3 = ∨
                }
                else
                {
                    board[x + i][y] = 1; // 1 = o
                }
            }
        }
        // else
        // {
        //     for (int i = 0; i < 3; i++)
        //     {
        //         if(i == 0)
        //         {
        //             board[x - i][y] = -3; // -3 = ∨
        //         }
        //         else if (i == 2)
        //         {
        //             board[x - i][y] = 3; // 3 = ∧
        //         }
        //         else
        //         {
        //             board[x - i][y] = 1; // 1 = o
        //         }
        //     }
        // }
    }
}



int main()
{
    int SIZE;
    char player1[20];
    char player2[20];
    char position;
    char temp1[20],temp2[20];
    printf("Please enter the length of board: ");
    for( ; ; )
    {
        scanf("%s", temp1);
        if( StrToNum(temp1) < 3 )
        {
            setTextColor(4,0);
            printf("ITS NOT ENOUGH FOR LENGTH!\n");
            setTextColor(15,0);
        }
        else if ( Check_Input(temp1) == 1 )
        {
            setTextColor(4,0);
            printf("ITS NOT A NUMBER!\n");
            setTextColor(15,0);
        }
        else
        {
            SIZE = StrToNum(temp1) ;
            break;
        }
    }
    int BOARD_P1[SIZE + 1][100];
    int BOARD_P2[SIZE + 1][100];
    int BOARD_OPP_P1[SIZE + 1][100];
    int BOARD_OPP_P2[SIZE + 1][100]; 
    int x = 0;
    int y = 0;

    // SEFR KARDANE KHANE HA
    for (int i = 0; i < SIZE + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            BOARD_P1[i][j] = 0;
            BOARD_P2[i][j] = 0;
            BOARD_OPP_P1[i][j] = 0;
            BOARD_OPP_P2[i][j] = 0;
        }
    }

    int Boat_Count;
    printf("Please enter the number of ships: ");
    for( ; ; )
    {
        for ( ; ; )
        {

            scanf("%s", temp1);
            if ( Check_Input(temp1) == 1 )
            {
                setTextColor(4,0);
                printf("ITS NOT A NUMBER!\n");
                setTextColor(15,0);
            }
            else if ( StrToNum(temp1) < 1 )
            {
                setTextColor(4,0);
                printf("INVALID NUMBER!\n");
                setTextColor(15,0);
            }
            else
            {
                Boat_Count = StrToNum(temp1) ;
                break;
            }        
        }
        getchar();
        if(Boat_Count>SIZE*SIZE/3)
        {
            setTextColor(4,0);
            printf("NO SPACE FOR ALL SHIPS!\n" );
            setTextColor(15,0);
        }
        else break;
    }
    printf("Please enter your name: ");
    gets(player1);

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of your ships and their positions %s(x y (h/v)): \n", player1);
    for (int i = 1; i <= Boat_Count; i++)
    {  
        for( ; ; )
        {
            scanf("%s %s %c", &temp1, &temp2, &position);
            if ( Check_Input(temp1) == 1 || Check_Input(temp2) == 1 )
            {
                setTextColor(4,0);
                printf("INVALID NUMBER!\n" );
                setTextColor(15,0);
            }
            else
            {
                x = StrToNum(temp1);
                y = StrToNum(temp2);
                break;
            }
        }
        getchar();
        if (position!='v' && position!='h' && position!='V' && position!='H')
        {
            setTextColor(4,0);
            printf("INVALID LETTER!\n" );
            setTextColor(15,0);
            i--;
            continue;
        }
        else if (check_place(BOARD_P1, x, y, position, SIZE + 1) == 1 || x>SIZE || y>SIZE || x<1 || y<1)
        {
            setTextColor(4,0);
            printf("YOU CANT PLACE HERE!\n" );
            setTextColor(15,0);
            i--;
            continue;
        }

        else
        {
            place_boat(BOARD_P1, x, y, position, SIZE + 1);
        }
    }

    Line(5);
    printf("\n");

    printf("Please enter your name: ");
    gets(player2);

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of your ships and their positions %s(x y (h/v)): \n", player2);
    for (int i = 1; i <= Boat_Count; i++)
    {
        for( ; ; )
        {
            scanf("%s %s %c", &temp1, &temp2, &position);
            if ( Check_Input(temp1) == 1 || Check_Input(temp2) == 1 )
            {
                setTextColor(4,0);
                printf("INVALID NUMBER!\n" );
                setTextColor(15,0);
            }
            else
            {
                x = StrToNum(temp1);
                y = StrToNum(temp2);
                break;
            }
        }
        if (position!='v' && position!='h' && position!='V' && position!='H')
        {
            setTextColor(4,0);
            printf("INVALID LETTER!\n" );
            setTextColor(15,0);
            i--;
            continue;
        }
        else if (check_place(BOARD_P2, x, y, position, SIZE + 1) == 1 || x>SIZE || y>SIZE || x<1 || y<1)
        {
            setTextColor(4,0);
            printf("YOU CANT PLACE HERE!\n");
            setTextColor(15,0);
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
        BOARD_OPP_P1[0][j] = j;
        BOARD_OPP_P2[0][j] = j;
    }
    // VARED KARDANE SHOMARE AMOODI
    for (int i = 1; i < SIZE + 1; i++)
    {
        BOARD_P1[i][0] = i;
        BOARD_P2[i][0] = i;
        BOARD_OPP_P1[i][0] = i;
        BOARD_OPP_P2[i][0] = i;
    }

    // printe board FOCP1
    printf("\n");
    printf(COLOR_BOLD"~ %s ~\n", player1);
    printf(COLOR_OFF"Number of ships: %d\n\n", Boat_Count);

    Print_TwoBoard(BOARD_P1,BOARD_OPP_P1,SIZE);

    Line(SIZE * 3 + 1);
    printf("\n\n");

    // printe board FOCP2
    printf(COLOR_BOLD"~ %s ~\n", player2);
    printf(COLOR_OFF"Number of ships: %d\n\n", Boat_Count);

    Print_TwoBoard(BOARD_P2,BOARD_OPP_P2,SIZE);

    return 0;
}