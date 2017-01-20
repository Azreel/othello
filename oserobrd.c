#include <stdio.h>

void brd_output(int brd[8][8]) {
    
    int i, j;
    
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            switch(brd[i][j]){
                case 0 : printf("E"); break;
                case 1 : printf("Z"); break;
                case -1 : printf("œ"); break;
            }
        }
        printf("\n");
    }
}

int main(void) {
    int arr[8][8] = { {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,-1,1,0,0,0},
                      {0,0,0,1,-1,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,0,0,0}};
    
    brd_output(arr);
    
    return 0;

}