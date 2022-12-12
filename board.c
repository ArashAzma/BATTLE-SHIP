#include <stdio.h>
#include <windows.h>
#include <conio.h>


//TABE BARAYE KHAT KESHI BE TOOLE VOOROODIE (length)
int Line(int length)
{
    int i;
    for( i=0 ; i<length ; i++ )
    {
        printf("=");
    }
}


//TABE BARAYE PAK KARDANE SAFE
// void ClearScreen()
// {
//     system("cls");
// }


//TABE TAGHIR RANG
void setTextColor(int textColor , int backColor)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorAttribute = backColor << 4 | textColor;
    SetConsoleTextAttribute(consoleHandle , colorAttribute);
}
// 0=black,1=blue,2=green,3=cyan,4=red,14=yellow,15=white


int main()
{
    const int SIZE;
    printf("Please enter the length of board: ");
    scanf("%d", &SIZE);    
    int BOARD_P1[SIZE+1][SIZE+1];
    int BOARD_P2[SIZE+1][SIZE+1];
    int x=0; int y=0;

    //SEFR KARDANE KHANE HA
    for(int i=0; i<SIZE+1; i++)
    {
        for(int j=0; j<SIZE+1; j++)
        {
            BOARD_P1[i][j] = 0;
            BOARD_P2[i][j] = 0;
        }
    }

    const int Boat_Count;
    printf("Please enter the number of ships: ");
    scanf("%d", &Boat_Count);

    //gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of 3 ships for FOCP1 (x y): \n");
    for(int i=1; i<=3; i++)
    {
        scanf("%d %d", &x, &y);
        if(BOARD_P1[x][y] == 1)
        {
            i--;
            printf("YOU ALREADY PUT A SHIP HERE!\n");
            continue;
        }
        else if(x<=SIZE && y<=SIZE && x>=1 && y>=1)
        {
            BOARD_P1[x][y] = 1;
        }
        else
        {
            i--;
            printf("YOUR COORDINATE IS OUT OF THE BOARD!\n");
            continue;
        }
    }

    printf("Please enter the coordinates of 3 ships for FOCP2 (x y): \n");
    for(int i=1; i<=3; i++)
    {
        scanf("%d %d", &x, &y);
        if(BOARD_P2[x][y] == 1)
        {
            i--;
            printf("YOU ALREADY PUT A SHIP HERE!\n");
            continue;
        }
        else if(x<=SIZE && y<=SIZE && x>=1 && y>=1)
        {
            BOARD_P2[x][y] = 1;
        }
        else
        {
            i--;
            printf("YOUR COORDINATE IS OUT OF THE BOARD!\n");
            continue;
        }
    }
    
    printf("\n\n");

    //VARED KARDANE SHOMARE OFOGHI
    for(int j=1; j<SIZE+1; j++)
    {
        BOARD_P1[0][j] = j;
        BOARD_P2[0][j] = j;
    } 
    //VARED KARDANE SHOMARE AMOODI  
    for(int i=1; i<SIZE+1; i++)
    {
        BOARD_P1[i][0] = i;
        BOARD_P2[i][0] = i;
    }


    // printe board FOCP1
    printf("\n");
    printf("~FOCP1~\n"); 
    printf("remaining ship: %d\n\n", Boat_Count);

    for(int i=0; i<SIZE+1; i++)
    {
        for(int j=0; j<SIZE+1; j++)
        {
            if(i==0 && j==0)
            {
                printf("   ");
                continue;
            }     
            else if(i>=1 && j>=1 && BOARD_P1[i][j]==0) //TARH UB DADAN
            {
                setTextColor(3,0);
                printf("~  ");
                setTextColor(15,0);
            }
            else if(i>=1 && j>=1 && BOARD_P1[i][j]==1) //TARH UB DADAN
            {
                setTextColor(4,0);
                printf("X  ");
                setTextColor(15,0);
            }
            else
            {
                if(i==0 && j>9)
                {
                    printf("%d ", BOARD_P1[i][j]);
                }
                else if(i>9 && j==0)
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

    Line(SIZE*3+1);
    printf("\n\n");
    
    //printe board FOCP2
    printf("\n");
    printf("~FOCP2~\n"); 
    printf("remaining ship: %d\n\n", Boat_Count);
   for(int i=0; i<SIZE+1; i++)
    {
        for(int j=0; j<SIZE+1; j++)
        {
            if(i==0 && j==0)
            {
                printf("   ");
                continue;
            }     
            else if(i>=1 && j>=1 && BOARD_P2[i][j]==0) //TARH UB DADAN
            {
                setTextColor(3,0);
                printf("~  ");
                setTextColor(15,0);
            }
            else if(i>=1 && j>=1 && BOARD_P2[i][j]==1) //TARH UB DADAN
            {
                setTextColor(4,0);
                printf("X  ");
                setTextColor(15,0);
            }
            else
            {
                if(i==0 && j>9)
                {
                    printf("%d ", BOARD_P2[i][j]);
                }
                else if(i>9 && j==0)
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