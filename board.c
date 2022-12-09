#include <stdio.h>

int main()
{
    int n;
    printf("please enter the lenght: ");
    scanf("%d", &n);    
    int BOARD_P1[n+1][n+1];
    int BOARD_P2[n+1][n+1];
    //SEFR KARDANE KHANE HA
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            BOARD_P1[i][j] = 0;
            BOARD_P2[i][j] = 0;
        }
    }

    //VARED KARDANE SHOMARE OFOGHI
    for(int j=1; j<n+1; j++)
    {
        BOARD_P1[0][j] = j;
        BOARD_P2[0][j] = j;
    } 
    //VARED KARDANE SHOMARE AMOODI  
    for(int i=1; i<n+1; i++)
    {
        BOARD_P1[i][0] = i;
        BOARD_P2[i][0] = i;
    }

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(i>=1 && j>=1)
            {
                printf("~ ");
            }
            else
            {
            printf("%d ", BOARD_P1[i][j]);
            }
        }
        printf("\n");
    }


    return 0;
}