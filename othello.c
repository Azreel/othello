#include <stdio.h>

#define SIZE 8

typedef enum {WHT=-1, EMP=0, BLK=1, OUT=2} Piece;

void cell_output(void);                                 //コマの出力//
void init(void);                                        //初期盤面//
void input(Piece trn);                                  //入力判定//


Piece cell[SIZE][SIZE];

int main(void) {
    int i, j;
    Piece trn = BLK;
    
    init();
    
    cell_output();
    
    while(1){
        input(trn);
        trn *= -1;
        
        cell_output();
    }
    
    return 0;

}

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


