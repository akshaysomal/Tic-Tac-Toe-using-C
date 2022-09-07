#include<stdio.h>
#include<stdlib.h>

char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int choice , player ;

void drawBoard();
int checkForWin();
void markBoard(char mark);

int main(){

    int gameStatus;

    char mark='X';
    player = 1;
    char play='y';

        do{
            drawBoard();
            player=(player % 2) ? 1:2 ;

            mark = (player==1)? 'X' :'O';

            printf("\n\nPlayer %d (%c), Enter a number: ",player,mark);
            scanf("%d",&choice);

            drawBoard();

            markBoard(mark);

            gameStatus = checkForWin();

            player++;

        }while(gameStatus==-1);

        if(gameStatus == 1){
            printf("  \n\nPlayer %d (%c) win \n\n",--player,mark);
        }
        else{
            printf("\n\nGame Draw \n\n");
        }


    

    return 0;
}

int checkForWin(){
    // this function is used to check the game status--> 
    // 1:game is over with result., -1:for game is in progress , 0:game is over for no result

    int returnValue=0;
    if(square[1]==square[2] && square[2]==square[3]){
        returnValue=1;
    }
    else if(square[1]==square[4] && square[4]==square[7]){
        returnValue=1;
    }
    else if(square[1]==square[5] && square[5]==square[9]){
        returnValue=1;
    }
    else if(square[2]==square[5] && square[5]==square[8]){
        returnValue=1;
    }
    else if(square[3]==square[6] && square[6]==square[9]){
        returnValue=1;
    }
    else if(square[3]==square[5] && square[5]==square[7]){
        returnValue=1;
    }
    else if(square[4]==square[5] && square[5]==square[6]){
        returnValue=1;
    }
    else if(square[7]==square[8] && square[8]==square[9]){
        returnValue=1;
    }
    else if(square[1]!='1' && square[2]!='2' && square[3]!='3' && square[4]!='4' && square[5]!='5' && square[6]!='6' && square[7]!='7' && square[8]!='8' && square[9]!='9' ){
        returnValue=0;
    }
    else{
        returnValue=-1;
    }

    return returnValue;

}

void drawBoard(){

    system("clear");

    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X) - Player 2 (O)\n\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
    printf("\t     |     |     \n");
    printf("\t-----------------\n");


    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
    printf("\t     |     |     \n");
    printf("\t-----------------\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
    printf("\t     |     |     \n");

}

void markBoard(char mark){
    if(choice == 1 && square[1]=='1')
        square[1]=mark;
    else if(choice == 2 && square[2]=='2')
        square[2]=mark;
    else if(choice == 3 && square[3]=='3')
        square[3]=mark;
    else if(choice == 4 && square[4]=='4')
        square[4]=mark;
    else if(choice == 5 && square[5]=='5')
        square[5]=mark;
    else if(choice == 6 && square[6]=='6')
        square[6]=mark;
    else if(choice == 7 && square[7]=='7')
        square[7]=mark;
    else if(choice == 8 && square[8]=='8')
        square[8]=mark;
    else if(choice == 9 && square[9]=='9')
        square[9]=mark;
    else{
        printf("\n\nInvalid Move ");
        player--;
        int input;
        scanf("%d",&input);
    }

}