#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int pX,pY,kX,kY,eX,eY;
char map[4][4];

void p_move()
{
    char step;
    printf("Nhap buoc di cua ban: ");
    scanf("%c",&step);
    if (step == 'w')
    {
        if(pY -1 <0) printf("Hay thu di huong khac!\n");
        else
        {
            map[pY][pX]='-';
            pY--;
            map[pY][pX]='P';
            
        }
    }
    
    if (step == 's')
    {
        if(pY +1 >4) printf("Hay thu di huong khac!\n");
        else
        {
            map[pY][pX]='-';
            pY++;
            map[pY][pX]='P';
            
        }
    }
    
    if (step == 'a')
    {
        if(pX -1<0) printf("Hay thu di huong khac!\n");
        else
        {
            map[pY][pX]='-';
            pX--;
            map[pY][pX]='P';
            
        }
    }
    
    if (step == 'd')
    {
        if(pX +1 >4) printf("Hay thu di huong khac!\n");
        else
        {
            map[pY][pX]='-';
            pX++;
            map[pY][pX]='P';
            
        }
    }
}

void map_move()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4; j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int m=4;
    
    time_t t;
    srand((unsigned) time(&t));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m; j++)
        {
            map[i][j]='-';
        }
    }
    
    pX= rand()%(m);
    pY= rand()%(m);
    map[pY][pX]='P';
    do{
        kX= rand()%(m);
        kY= rand()%(m);
    } while (map[kY][kX] != '-');
    map[kX][kY]='K';
    do{
        eX= rand()%(m);
        eY= rand()%(m);
    } while (map[eY][eX] != '-');
    map[eY][eX]='E';
    
    map_move();
    
    do{
        p_move();
        printf("\n");
        map_move();
        if(map[pY][pX] == map[eY][eX])
        {
            printf("Da tim loi ra");
            continue;
        }
    } while(map[pY][pX] != map[kY][kX]);
    printf("Tim thay lopi ra nhung chua co chia khoa");
    
}
