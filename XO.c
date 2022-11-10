#include <stdio.h>

char t[3][5];
int cnt=1;

int finish(){
    if(((t[0][0]==t[0][2])&&(t[0][2]==t[0][4])&&(t[0][4]!=' '))||((t[1][0]==t[1][2])&&(t[1][2]==t[1][4])&&(t[1][4]!=' '))||((t[2][0]==t[2][2])&&(t[2][2]==t[2][4])&&(t[2][4]!=' '))||((t[0][0]==t[1][0])&&(t[1][0]==t[2][0])&&(t[2][0]!=' '))||((t[0][2]==t[1][2])&&(t[1][2]==t[2][2])&&(t[2][2]!=' '))||((t[0][4]==t[1][4])&&(t[1][4]==t[2][4])&&(t[2][4]!=' '))||((t[0][0]==t[1][2])&&(t[1][2]==t[2][4])&&(t[2][4]!=' '))||((t[2][0]==t[1][2])&&(t[1][2]==t[0][4])&&(t[0][4]!=' '))){
        return 0;
    }else{
        if(cnt<9){
            return 1;
        }else{
            return 2;
        }
    }
}
int main(){
    char first_player,second_player,p;
    int n;
    t[0][1]=t[0][3]=t[1][1]=t[1][3]=t[2][1]=t[2][3]='|';
    t[0][0]=t[0][2]=t[0][4]=t[1][0]=t[1][2]=t[1][4]=t[2][0]=t[2][2]=t[2][4]=' ';
    printf("please enter first player(X or O):\n");
    scanf("%c",&first_player);
    if((first_player!='X')&&(first_player!='O')){
        printf("your input is invalid\n");
        return 0;
    }
    if(first_player=='X'){
        second_player='O';
    }else{
        second_player='X';
    }

    while(1){
        if(cnt%2!=0){
            p=first_player;
        }else{
            p=second_player;
        }
        printf("Player %c:\n",p);
        printf("please enter a location number:\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                t[0][0]=p;
                break;
            case 2:
                t[0][2]=p;
                break;
            case 3:
                t[0][4]=p;
                break;
            case 4:
                t[1][0]=p;
                break;
            case 5:
                t[1][2]=p;
                break;
            case 6:
                t[1][4]=p;
                break;
            case 7:
                t[2][0]=p;
                break;
            case 8:
                t[2][2]=p;
                break;
            case 9:
                t[2][4]=p;
                break;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<5;j++){
                printf("%c ",t[i][j]);
            }
            printf("\n");
            printf("\n");
        }
        if(finish()==0) {
            if (cnt% 2 == 0) {
                printf("Player %c is winner :) ", second_player);
                return 0;
            } else {
                printf("Player %c is winner :) ", first_player);
                return 0;
            }
        }
        if(finish()==2){
            printf("No winner!");
            return 0;
        }
        cnt++;
    }
}
