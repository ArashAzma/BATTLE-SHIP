#include <stdio.h>

int main()
{
    int n;
    printf("please enter the lenght: ");
    scanf("%d", &n);    
    int BOARD[n+1][n+1];
    //SEFR KARDANE KHANE HA
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            BOARD[i][j] = 0;
        }
    }
    //VARED KARDANE SHOMARE OFOGHI
    for(int j=1; j<n+1; j++)
    {
        BOARD[0][j] = j;
    } 
    //VARED KARDANE SHOMARE AMOODI  
    for(int i=1; i<n+1; i++)
    {
        BOARD[i][0] = i;
    }

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            printf("%d ", BOARD[i][j]);
        }
        printf("\n");
    }


    return 0;
}