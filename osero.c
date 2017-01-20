#include <stdio.h>

int main(void)
{
    int i, p, arr[8][8] = { {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,-1,1,0,0,0},
                            {0,0,0,1,-1,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0},
                            {0,0,0,0,0,0,0,0}};
    
    for(i = 0; i < 8; i++){
        for(p = 0; p < 8; p++){
            switch(arr[i][p]){
                case 0 : printf(" "); break;
                case 1 : printf("Z"); break;
                case -1 : printf("œ"); break;
            }
        }
        printf("\n");
    }
    return 0;
}