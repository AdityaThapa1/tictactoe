/*
This code has been compiled in DEV C++ IDE on Windows 11
Author:- Aditya Thapa, Bibek Belbase and Koshish K.C.
*/
#include<stdio.h>
#include<string.h>
char x,o;
char a[9]={'1','2','3','4','5','6','7','8','9'};
char u1[50],u2[50];
void board();
void rules();
int checkforwin();
int main()
{
    FILE *p;
    p=fopen("score.txt","a+"); //opening a file with mode a+ i.e both reading and writing 
    fclose(p);
    system("color 75");//changing the color of system (both background and foreground)
    int player=1;
    int choice,score=-1;
    char symbol,re;
    char start,dec;
    int s;
  rules();
  restart:
    printf("\n\nType 1 to start the game:-\nType 2 to view leaderboard:-\n");
    scanf("%d",&s);
    if(s==1)
    {
    read:
    p=fopen("score.txt","a+");
    printf("\n\tEnter name of player1: ");
    scanf("%s",u1);
    fprintf(p,"\n\t%s",u1);
    printf("\tEnter name of player2: ");
    scanf("%s",u2);
    fprintf(p,"\t%s",u2);
    fclose(p);
    if(!strcmp(u1,u2))
    {
        printf("Enter names of different players!\n\n");
        goto read;
    }
    else
        decision();
    system("color fc");
    board();
    do
    {
        player=((player%2)?1:2);
        if(player==1)
        printf("\t%s Type any digit from 1-9 to fill your response:- ",u1);
  else
            printf("\t%s Type any digit from 1-9 to fill your response:- ",u2);
        scanf("%d",&choice);
        symbol=((player==1)?x:o);
        if(choice==1 && a[0]=='1')
            a[0]=symbol;
        else if(choice==2 && a[1]=='2')
            a[1]=symbol;
        else if(choice==3 && a[2]=='3')
            a[2]=symbol;
        else if(choice==4 && a[3]=='4')
            a[3]=symbol;
        else if(choice==5 && a[4]=='5')
            a[4]=symbol;
        else if(choice==6 && a[5]=='6')
            a[5]=symbol;
        else if(choice==7 && a[6]=='7')
            a[6]=symbol;
        else if(choice==8 && a[7]=='8')
            a[7]=symbol;
        else if(choice==9 && a[8]=='9')
            a[8]=symbol;
        else{
            printf("\tWrong Selection\n");player--;
}
        score=checkforwin();
        player++;
        board();
}while(score == -1);
    p=fopen("score.txt","a+");
    if(score==1)
    {
        if(player==2)
        {printf("\n\n\t\tPlayer1 %s Wins!\n\n",u1);fprintf(p,"\t%s %s",u1,"(Wins)");
        fclose(p);
        goto restart;
        getch();}
        else
            {printf("\n\n\t\tPlayer2 %s Wins!\n\n",u2);fprintf(p,"\t%s %s",u2,"(Wins)");
             fclose(p);
        goto restart;
            }
    }
    else
        printf("\n\n\t\tGame Draws!\n\n");fprintf(p,"\t%s","DRAW");
         fclose(p);
        goto restart;
    
    }
    if(s==2)
    {
        int cho;
        system("cls");
        printf("\n\n");
        printf("\tLEADERBOARD\n\n");
        char c;
        p=fopen("score.txt","r");
        while((c=getc(p))!=EOF)
        {
            printf("%c",c);
  }
        fclose(p);
        printf("\n\n\tPress 1 to start the game:- ");
        scanf("%d",&cho);
        if(cho==1)
            goto read;
        else
            getch();
    }
    else
    {
        printf("\n\n\tShould have typed 1 to play the game!\n\tHope to see you back soon!\n\n");
        getch();
    }
}
void rules()
{
    char link;
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c",&link);
    if(link=='y' || link=='Y')
 {
        system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}
void board()
{
    int i;
    system("cls");
    printf("\tTic-Tac-Toe\n\n");
        printf("\n\n");
        printf("\t%s:- (%c)\n\t%s:-  (%c)\n\n\n",u1,x,u2,o);
        printf("\t  %c |  %c | %c\n",a[0],a[1],a[2]);
        printf("\t    |    |    \n");
        printf("\t----|----|----\n");
        printf("\t    |    |    \n");
        printf("\t  %c |  %c | %c\n",a[3],a[4],a[5]);
        printf("\t    |    |    \n");
        printf("\t----|----|----\n");
        printf("\t  %c |  %c | %c\n",a[6],a[7],a[8]);
        printf("\t    |    |    \n");
    }
int decision()
{
    char dec;
        deci:
        printf("\n\n\tPlayer1 %s choose the X or 0:",u1);
        dec=getchar();
        scanf("%c",&dec);
 {
            if(dec=='X' || dec=='x')
            {
                x='X';
                o='0';
            }
            else if(dec=='0')
            {
                x='0';
                o='X';
            }
            else
            {
                printf("\tPlease enter either X or 0 only \n\n");
                goto deci;
            }
        }
}
 
int checkforwin()
{
    if(a[0]==a[1] && a[1]==a[2])
        return 1;
    else if(a[3]==a[4] && a[4]==a[5])
        return 1;
    else if(a[6]==a[7] && a[7]==a[8])
        return 1;
    else if(a[0]==a[3] && a[3]==a[6])
  return 1;
    else if(a[1]==a[4] && a[4]==a[7])
        return 1;
    else if(a[2]==a[5] && a[5]==a[8])
        return 1;
    else if(a[0]==a[4] && a[4]==a[8])
        return 1;
    else if(a[2]==a[4] && a[4]==a[6])
        return 1;
    else if(a[0]!='1' && a[1]!='2' && a[2]!='3' && a[3]!='4' && a[4]!='5' && a[5]!='6' && a[6]!='7' && a[7]!='8' && a[8]!='9')
        return 0;
    else
        return -1;

}
