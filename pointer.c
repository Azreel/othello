#include <stdio.h>

int main(void)
{
    int n = 3;
    int *p = &n;        // �|�C���^�ϐ� p
    int *m = p;
    
    printf("�ϐ�n�̒l   = %d\n", n);
    
    printf("�ϐ�n�̔Ԓn = %p\n", &n);
    printf("�ϐ�p�̒l   = %p\n", p);
    
    printf("�ϐ�p�̔Ԓn = %p\n", &p);
    
    printf("�ϐ�p�̒��g = %d\n", *p);
    
    printf("�ϐ�m�̔Ԓn = %p\n", &m);
    printf("�ϐ�m�̒l   = %p\n", m);
    printf("�ϐ�m�̒��g = %d\n", *m);
}