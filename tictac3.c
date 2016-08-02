#include <stdio.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"



void printBoard();
void play();
int check(char sym);

//for storing the values
char val[3][3];
char symbol='X';
char symbol2='O';

int main()
{
    int i=0,j=0;

    char tryagain='y';
    while(tryagain=='y' || tryagain=='Y')
    {
        //initilize array to blanks
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                val[i][j]=' ';

        printBoard(val);
        play();
        printf("\nWanna try again (y/n) : ");
        scanf(" %c",&tryagain);
        
    }
}

//prints the board with line and value
void printBoard()
{   
    printf("%s",MAG"\n        TICTAC TOE\n"RESET);
    printf("\n");
    int i,j;
        //for the first line
        printf("      1     2     3   \n");
        printf(CYN"   ___________________\n");
    for(int i=0;i<3;i++)
    {
        printf(CYN"   |     |     |     |\n"RESET);
        printf("%d  \x1B[36m|\x1B[0m  %c  \x1B[36m|\x1B[0m  %c  \x1B[36m|\x1B[0m  %c  \x1B[36m|\x1B[0m\n",i+1,val[i][0],val[i][1],val[i][2]);
        printf(CYN"   |_____|_____|_____|\n"RESET);
    }
    printf("\n");
}

//start asking the quest, call print and check
void play()
{
    int row=0;
    int col=0;
    int status=1;
    int numofplayer=1;
    //for storing winners
    int win1,win2;
    while(status)
    {
        int i;
        //this loop is for change the player number;
        for(i=0;i<2;i++)
        {
            printf("\nTurn : Player%d\n",i+1);
            printf("%s","Enter row: ");
            scanf("%d",&row);
            printf("%s","Enter col: ");
            scanf("%d",&col);


            //whether enter rows and cols in range or not, and repetitive or not
            if(row > 0 && row < 4 && col > 0 && col < 4 && val[row-1][col-1]!='X' && val[row-1][col-1]!='O')
            {
                if(i==0)
                    val[row-1][col-1]=symbol;
                else if(i==1)
                    val[row-1][col-1]=symbol2;

                printBoard(val);
                status=(win1=check(symbol)) && (win2=check(symbol2)) ;
            }
            else
            {
                //error, so the player no/count dont increase
                i=i-1;
                printf(RED"\n!! Invalid entry! Enter correctly !! \n"RESET);
            }
           
            //break the loop after the status is false
            if(!status)
                break;
        }
    }
    //prints out the winner and losers
    if(win1==0)
        printf(GRN "!!! Player 1 is winner !!!\n" RESET);
    else if(win2==0)
        printf(GRN "!!! Player 2 is winner !!!\n" RESET);
    else
        printf(RED "!!! No one is winner !!!\n" RESET);
}
//return 0 if player wins means all X in row, cols or diagnoal
int check(char sym)
{
    int i;
    //check all rows and cols ie 0,1,2
    for(i=0;i<3;i++)
    {
        if((val[0][i]==sym && val[1][i]==sym && val[2][i]==sym) || (val[i][0]==sym && val[i][1]==sym && val[i][2]==sym) || (val[0][0]==sym && val[1][1]==sym && val[2][2]==sym) || (val[2][0]==sym && val[1][1]==sym && val[0][2]==sym))
        {
            printf(RED"\n\n!!!! Game over !!!!\n\n"RESET);
            return 0;
        }
        //if all the rows and column filled, then break
        int l,m;
        int sum=0;
        for(l=0;l<3;l++)
            for(m=0;m<3;m++)
                if(val[l][m]=='X' || val[l][m]=='O')
                    sum++;
        if(sum==9)
            break;
    }
}
