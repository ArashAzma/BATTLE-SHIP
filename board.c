#include <stdio.h>

int main()
{
    const int SIZE;
    printf("Please enter the lenght: ");
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
    printf("Please enter the number of boats: ");
    scanf("%d", &Boat_Count);

    // gereftan mokhtasat kashtiha va alamat gozari (bedoone zakhire sazi)
    printf("Please enter the coordinates of 3 boats for FOCP1 (x y): \n");
    for(int i=1; i<=3; i++)
    {
        scanf("%d %d", &x, &y);
        if(x<=SIZE && y<=SIZE)
        {
        BOARD_P1[x][y] = 1;
        }
        else
        {
            i--;
            printf("ERROR\n");
            continue;
        }
    }

    printf("Please enter the coordinates of 3 boats for FOCP2 (x y): \n");
    for(int i=1; i<=3; i++)
    {
        scanf("%d %d", &x, &y);
        if(x<=SIZE && y<=SIZE)
        {
            BOARD_P2[x][y] = 1;
        }
        else
        {
            i--;
            printf("ERROR\n");
            continue;
        }
    }



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
    for(int i=0; i<SIZE+1; i++)
    {
        for(int j=0; j<SIZE+1; j++)
        {
            if(i>=1 && j>=1 && BOARD_P1[i][j]==0) //TARH UB DADAN
            {
                printf("~ ");
            }
            else if(i>=1 && j>=1 && BOARD_P1[i][j]==1) //TARH UB DADAN
            {
                printf("* ");
            }
            else
            {
            printf("%d ", BOARD_P1[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("\n");

    // printe board FOCP2
    for(int i=0; i<SIZE+1; i++)
    {
        for(int j=0; j<SIZE+1; j++)
        {
            if(i>=1 && j>=1 && BOARD_P2[i][j]==0) //TARH UB DADAN
            {
                printf("~ ");
            }
            else if(i>=1 && j>=1 && BOARD_P2[i][j]==1) //TARH UB DADAN
            {
                printf("* ");
            }
            else
            {
            printf("%d ", BOARD_P2[i][j]);
            }
        }
        printf("\n");
    }



    return 0;
}