//******************************************************//
//  Created by DonaldTram on 12/7/19.                  //
//  Copyright © 2019 DonaldTr4n. All rights reserved. //
//***************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int pX,pY,kX,kY,eX,eY;
int check=0;
char map[4][4];
char step;

void p_move(char step) //di chuyển bằng các phím 'w a s d'
{
    if (step == 'w')
    {
        if(pY -1 <0) printf("Hay thu di huong khac!");
        else
        {
            map[pY][pX]='-';
            pY--;// w là hướng lên trên nên trục Y trong mảng sẽ giảm
            map[pY][pX]='P';
        }
    }
    
    if (step == 's')
    {
        if(pY +1 >3) printf("Hay thu di huong khac!");
        else
        {
            map[pY][pX]='-';
            pY++;// s hướng xuống dưới nên trục Y trong mảng sẽ tăng
            map[pY][pX]='P';
        }
    }
    
    if (step == 'a')
    {
        if(pX -1<0) printf("Hay thu di huong khac! ");
        else
        {
            map[pY][pX]='-';
            pX--;// a là hướng trái nên trục X trong mảng sẽ giảm
            map[pY][pX]='P';
        }
    }
    
    if (step == 'd')
    {
        if(pX +1 >3) printf("Hay thu di huong khac! ");
        else
        {
            map[pY][pX]='-';
            pX++;// d là hướng trái nên trục X trong mảng sẽ tăng
            map[pY][pX]='P';
        }
    }
    if (map[pY][pX] == map[kY][kX]) //kiểm tra đã lấy chìa khóa hay chưa
    {
        check=1;
        printf("Da tim thay chia khoa! ");
    }
    else check=0;
    
}

void p_return(char step) // CTCon lặp lại, CTC này ngược so với CTC @p_move
{
    if (step == 'w')
    {
        if(pY +1 >3) printf("error");
        else
        {
            map[pY][pX]='E';
            pY++;
            map[pY][pX]='P';
        }
    }
    
    if (step == 's')
    {
        if(pY -1 <0) printf("error");
        else
        {
            map[pY][pX]='E';
            pY--;
            map[pY][pX]='P';
        }
    }
    
    if (step == 'a')
    {
        
        if(pX +1 >3) printf("error");
        else
        {
            map[pY][pX]='E';
            pX++;
            map[pY][pX]='P';
        }
    }
    
    if (step == 'd')
    {
        if(pX -1<0) printf("error");
        else
        {
            map[pY][pX]='E';
            pX--;
            map[pY][pX]='P';
        }
    }
}

void map_move() // CTC in ra map sau khi @p_move
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

void vonglap() //lặp lại khi tìm được lối ra nhưng chưa có chìa khóa
{
    do{
        map_move();
        printf("\nNhap buoc di cua ban: \n");
        scanf("%c",&step);
        fflush(stdin);
        p_move(step);
        
    }while(map[pY][pX] != map[eY][eX]);
}



//******************************************************//
//  Created by DonaldTram on 12/7/19.                  //
//  Copyright © 2019 DonaldTr4n. All rights reserved. //
//***************************************************//
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
    
    //map_move();
    
    vonglap();
    if(check==1) printf("Da tim thay loi ra!\n");
    else if(check==0)
    {
        printf("Tim thay loi ra nhung chua co chia khoa\n");
        printf("\nNhap buoc di cua ban: \n");
        p_return(step);
        vonglap();
    }
    
}
