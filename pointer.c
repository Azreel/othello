#include <stdio.h>

int main(void)
{
    int n = 3;
    int *p = &n;        // ポインタ変数 p
    int *m = p;
    
    printf("変数nの値   = %d\n", n);
    
    printf("変数nの番地 = %p\n", &n);
    printf("変数pの値   = %p\n", p);
    
    printf("変数pの番地 = %p\n", &p);
    
    printf("変数pの中身 = %d\n", *p);
    
    printf("変数mの番地 = %p\n", &m);
    printf("変数mの値   = %p\n", m);
    printf("変数mの中身 = %d\n", *m);
}