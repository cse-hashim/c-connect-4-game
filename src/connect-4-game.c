/****************************************************
 * connect_4_game.c									*
 *		connect 4 simple game multi-players only	*
 *      Author: HASHIM								*
 *      Email : cse.hashim.hossam@gmail.com			*
 ****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
char a_sym=(char)2;
char b_sym=(char)6;
char up_sym=(char)281;
char empty_sym=(char)178;
int isA = 1;
int  firstRun = 1;
char panel[4][4];
int game_status(char** p){
    if(p[0][0]==p[1][1]==p[2][2]==p[3][3]){
        if(p[0][0]==a_sym){return 1;}
        if(p[0][0]==b_sym){return 2;}
    }
    if(p[3][0]==p[2][1]==p[1][2]==p[0][3]){
        if(p[3][0]==a_sym){return 1;}
        if(p[3][0]==b_sym){return 2;}
    }
    for(int i = 0;i<4;i++){
        if(p[i][0]==p[i][1]==p[i][2]==p[i][3]){
            if(p[i][0]==a_sym){return 1;}
            if(p[i][0]==b_sym){return 2;}
        }
        if(p[0][i]==p[1][i]==p[2][i]==p[3][i]){
            if(p[0][i]==a_sym){return 1;}
            if(p[0][i]==b_sym){return 2;}
        }
        //for(int j = 0;j<4;j++){//droau case
          //  //return 0;
        //}
    }
    return -1;
}
/**
    //p[i][j]
    i is row #
    j is col #
**/
void play(char** pan,int c){
    if(pan[3][c]!=empty_sym){
        printf("** Error Full column ");
        if(isA){
            isA=0;
            printf("please player B try again\n");
        }else{
            isA=1;
            printf("please player A try again\n");
        }
    }else{
        for(int i=0;i<4;i++){//row counter
            //for(int j=0;j<4;j++){//col counter
            //
            //}

            if(pan[i][c]==empty_sym){//must add winning condition if some one won or drue it must not play that turn
                if(isA){
                    pan[i][c] = b_sym;
                    return;
                }else{
                    pan[i][c] = a_sym;
                    return;
                }
            }
        }
    }
}
int main(void)
{
    system("cls");
    //char panel[4][4];//={{empty_sym,empty_sym,empty_sym,empty_sym},{empty_sym,empty_sym,empty_sym,empty_sym},{empty_sym,empty_sym,empty_sym,empty_sym},{empty_sym,empty_sym,empty_sym,empty_sym}};
    if(firstRun){
        for (int j1 = 0; j1 < 4; j1++) {
            for (int j2 = 0; j2 < 4; j2++) {
                panel[j1][j2]=empty_sym;
            }
        }
        firstRun = 0;
    }
     if(isA){
        printf("player A (%c) turn\n\n",a_sym);
        isA=0;
    }else{
        printf("player B (%c) turn\n\n",b_sym);
        isA=1;
    }
    int i=0;
//display
    for(int k = 3;k>=0;k--){
            printf("\t\t");
        for(int k1 = 0;k1<4;k1++){
            printf("%c  ",panel[k][k1]);
        }
        printf("\n\n");
    }
    printf("\n\t\t%c  %c  %c  %c\n",up_sym,up_sym,up_sym,up_sym);
    printf("\t\t1  2  3  4\n");
    puts("please enter your column number:");
    int col;
    scanf("%d",&col);
    col--;
    //play(panel,col-1);
    if(panel[3][col]!=empty_sym){
        printf("** Error Full column ");
        if(isA){
            isA=0;
            printf("please player B try again\n");
            system("pause()");
        }else{
            isA=1;
            printf("please player A try again\n");
            system("pause()");
        }
    }else{
        for(int i=0;i<4;i++){//row counter
            //for(int j=0;j<4;j++){//col counter
            //
            //}

            if(panel[i][col]==empty_sym){//must add winning condition if some one won or drue it must not play that turn
                if(isA){
                    panel[i][col] = b_sym;
                    break;
                }else{
                    panel[i][col] = a_sym;
                    break;
                }
            }
        }
    }
    int stts = -1;//=game_status(panel);
    if(panel[0][0]==panel[1][1]&&panel[1][1]==panel[2][2]&&panel[2][2]==panel[3][3]){
        if(panel[0][0]==a_sym){stts = 1;}
        else if(panel[0][0]==b_sym){stts = 2;}
    }
    else if(panel[3][0]==panel[2][1]&&panel[2][1]==panel[1][2]&&panel[1][2]==panel[0][3]){
        if(panel[3][0]==a_sym){stts = 1;}
        else if(panel[3][0]==b_sym){stts = 2;}
    }
    for(int i = 0;i<4;i++){
        if(panel[i][0]==panel[i][1]&&panel[i][1]==panel[i][2]&&panel[i][2]==panel[i][3]){
            if(panel[i][0]==a_sym){stts = 1;}
            else if(panel[i][0]==b_sym){stts = 2;}
        }
        else if(panel[0][i]==panel[1][i]&&panel[1][i]==panel[2][i]&&panel[2][i]==panel[3][i]){
            if(panel[0][i]==a_sym){stts = 1;}
            else if(panel[0][i]==b_sym){stts = 2;}
        }
        int dro = 1;
        for(int j = 0;j<4;j++){//droau case
            if(panel[3][j]==empty_sym){
                dro = 0;
            }
        }
        if(dro){
            stts = 0;
        }
    }

    //stts = -1;
    if(stts==-1){//holding
        //puts("______________________________________");
        main();
    }else if(stts==1){//finished
        system("cls");
        puts("player A wins. congrats!");
        //display
    for(int k = 3;k>=0;k--){
            printf("\t\t");
        for(int k1 = 0;k1<4;k1++){
            printf("%c  ",panel[k][k1]);
        }
        printf("\n\n");
    }
    system("pause()");
    }else if(stts==2){
        system("cls");
        puts("player B wins. congrats!");
        //display
        for(int k = 3;k>=0;k--){
            printf("\t\t");
            for(int k1 = 0;k1<4;k1++){
                printf("%c  ",panel[k][k1]);
            }
            printf("\n\n");
        }
        system("pause()");
    }else if(stts==0){
        system("cls");
        puts("ops! no player wins!");
        //display
        for(int k = 3;k>=0;k--){//
            printf("\t\t");
            for(int k1 = 0;k1<4;k1++){
                printf("%c  ",panel[k][k1]);
            }
            printf("\n\n");
        }
        system("pause()");
    }
    return 0;
}
