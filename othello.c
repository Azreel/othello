#include <stdio.h>

#define SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=1, OUT=2} Piece;

void cell_output(void);                                 //ƒRƒ}‚Ìo—Í
void init(void);                                        //‰Šú”Õ–Ê
void input(Piece trn);                                  //“ü—Í”»’è
int end(void);                                          //I—¹”»’è
int judge(void);                                        //ŸÒ”»’è
void Umetarou(int player);                              //‘S©“®–„‚ß‹@

Piece cell[SIZE][SIZE];

int main(void) {
    int i, j;
    Piece trn = BLK;
    
    init();
    
    cell_output();
    
    while(!end()){
        input(trn);
        //Umetarou(trn);
        trn *= -1;
        
        cell_output();
    }
    judge();
    
    return 0;

}

                                                               //ƒRƒ}‚Ìo—Í
void cell_output(void) {
    
    int i, p;
    
    printf("@X1X2X3X4X5X6X7X8\n");
    
    
    for(i = 0; i < SIZE; i++){
        printf("Y%d", i + 1);
        for(p = 0; p < SIZE; p++){
            switch(cell[i][p]){
                case EMP : printf("E"); break;
                case BLK : printf("Z"); break;
                case WHT : printf("œ"); break;
            }
        }
        printf("\n");
    }
}

                                                                //‰Šú”Õ–Ê
void init(void)
{
    int i, j;
    
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            cell[i][j] = EMP;
        }
    }
    
    cell[3][3] = cell[4][4] = WHT;
    cell[3][4] = cell[4][3] = BLK;
}

                                                               //“ü—Í”»’è
void input(Piece trn)
{
    int x, y;
    
    while(1)
    {
        printf("X > "); scanf("%d", &x); x--;
        printf("Y > "); scanf("%d", &y); y--;
        
        if (x >= 0 && x < 8 && y >= 0 && y < 8)
        {
            cell[y][x] = trn; break;
        }
        printf("‚»‚±‚É‚Í’u‚¯‚Ü‚¹‚ñ(ƒ³ƒÖƒ³)\n");
    }
    
}

                                                               //I—¹”»’è
int end(void)
{
    int i, j;
    
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(cell[i][j] == EMP){
                return 0;
            }
        }
    }
    return 1;
}

                                                     //ŸÒ”»’è
int judge(void)
{
    int i, j;
    int B, W;
    
    B = 0;
    W = 0;
    
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(cell[i][j] == BLK){
                B++;
            }
            else if(cell[i][j] == WHT){
                W++;
            }
        }
    }
    printf("•:%d@”’:%d\n", B, W);
    if(B > W){
        printf("•‚ÌŸ‚¿‚Å‚·");
    } else if(B < W){
        printf("”’‚ÌŸ‚¿‚Å‚·");
    } else{
        printf("ˆø‚«•ª‚¯");
    }
}

//|||||||||||||||||||||||||||||||||||||||
//”Õ–Ê–„‚ß‘¾˜Y
//|||||||||||||||||||||||||||||||||||||||
void Umetarou(int player){
    int i, j;
    
    for( i = 0; i < SIZE; i++ ){
        for( j = 0; j < SIZE; j++ ){
            if( cell[i][j] == EMP ){
                cell[i][j] = player;
                return;
            }
        }
    }
}
