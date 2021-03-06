#include <stdio.h>

#define SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=1, OUT=2} Piece;

void cell_output(void);                                 //コマの出力
void init(void);                                        //初期盤面
void input(Piece trn);                                  //入力判定
int end(void);                                          //終了判定
int judge(void);                                        //勝者判定
void Umetarou(int player);                              //全自動埋め機

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

                                                               //コマの出力
void cell_output(void) {
    
    int i, p;
    
    printf("　X1X2X3X4X5X6X7X8\n");
    
    
    for(i = 0; i < SIZE; i++){
        printf("Y%d", i + 1);
        for(p = 0; p < SIZE; p++){
            switch(cell[i][p]){
                case EMP : printf("・"); break;
                case BLK : printf("〇"); break;
                case WHT : printf("●"); break;
            }
        }
        printf("\n");
    }
}

                                                                //初期盤面
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

                                                               //入力判定
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
        printf("そこには置けません(ΦωΦ)\n");
    }
    
}

                                                               //終了判定
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

                                                     //勝者判定
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
    printf("黒:%d　白:%d\n", B, W);
    if(B > W){
        printf("黒の勝ちです");
    } else if(B < W){
        printf("白の勝ちです");
    } else{
        printf("引き分け");
    }
}

//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
//盤面埋め太郎
//−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
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
