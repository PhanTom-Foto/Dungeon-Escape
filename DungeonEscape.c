//******************************************************//
//  Created by DonaldTram on 12/7/19.                  //
//  Copyright © 2019 DonaldTr4n. All rights reserved. //
//***************************************************//

///đề bài: https://drive.google.com/file/d/0ByJaz8MlpRsDelplS0tzT1E3WTA/view?usp=sharing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

int pX,pY,kX,kY,eX,eY,check=0,error1=0;
char step,replay,map[4][4];

void baoloi()
{
    printf(" Hay thu di huong khac! \n");
}

void p_move(char step) //di chuyển bằng các phím 'w a s d'
{
    if (step == 'w')
    {
        if(pY -1 <0) error1=1;//dùng biến error1 =1 để kiểm tra lỗi ra ngoài map
        else
        {
            map[pY][pX]='-';
            pY--;// w là hướng lên trên nên trục Y trong mảng sẽ giảm
            map[pY][pX]='P';
        }
    }

    if (step == 's')
    {
        if(pY +1 >3) error1=1;//dùng biến error1 =1 để kiểm tra lỗi ra ngoài map
        else
        {
            map[pY][pX]='-';
            pY++;// s hướng xuống dưới nên trục Y trong mảng sẽ tăng
            map[pY][pX]='P';
        }
    }

    if (step == 'a')
    {
        if(pX -1<0) error1=1;//dùng biến error1 =1 để kiểm tra lỗi ra ngoài map
        else
        {
            map[pY][pX]='-';
            pX--;// a là hướng trái nên trục X trong mảng sẽ giảm
            map[pY][pX]='P';
        }
    }

    if (step == 'd')
    {
        if(pX +1 >3) error1=1;//dùng biến error1 =1 để kiểm tra lỗi ra ngoài map
        else
        {
            map[pY][pX]='-';
            pX++;// d là hướng trái nên trục X trong mảng sẽ tăng
            map[pY][pX]='P';
        }
    }
}

void check_k() //kiểm tra đã lấy chìa khóa hay chưa
{
    if (map[pY][pX] == map[kY][kX])
    {
        check=1;
        printf("\n Da tim thay chia khoa! \n");
        //loại bỏ hoàn toàn vị trí của "K" - chìa khóa
        kY=4;
        kX=4;

    }
}

void p_return(char step) // CTCon lặp lại, CTC này ngược so với CTC @p_move
{
    if (step == 'w')
    {
        if(pY +1 >3) printf("error");
        else {
            map[pY][pX]='E';
            pY++;
            map[pY][pX]='P';
        }
    }

    if (step == 's')
    {
        if(pY -1 <0) printf("error");
        else {
            map[pY][pX]='E';
            pY--;
            map[pY][pX]='P';
        }
    }

    if (step == 'a')
    {

        if(pX +1 >3) printf("error");
        else {
            map[pY][pX]='E';
            pX++;
            map[pY][pX]='P';
        }
    }

    if (step == 'd')
    {
        if(pX -1<0) printf("error");
        else{
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
        if(i==0)printf("\n\tDungeon Escape\n");
        if(i==0)printf("\t==============\n");
        printf("\t|  ");
        for(int j=0;j<4; j++) printf("%c ",map[i][j]);
        printf("  |");
        if(i==3)printf("\n\t==============");
        printf("\t\n");
    }
}

void vonglap() //lặp lại khi tìm được lối ra nhưng chưa có chìa khóa
{
    do{

        map_move();
        printf(" W(len) S(xuong) A(trai) D(phai)\n");
        if (error1 == 1) printf("\n Hay thu di huong khac! \n");
        if (error1 == 2) printf("\n Tim thay loi ra nhung chua co chia khoa\n");
        check_k();
        step = getch();
        printf("\n");
        fflush(stdin);
        error1=0;
        system("cls");
        p_move(step);
    }while(map[pY][pX] != map[eY][eX]);
}

void play()
{
    vonglap();
    if(check==1)
    {
        map_move();
        printf(" Da tim thay loi ra!\n");
        check = 0;
    } else {
        do{
        error1 = 2;//dùng biến error1 = 2 để kiểm tra lỗi tìm được lối ra nhưng không có chìa khóa
        p_return(step);
        vonglap();
        if (check==1) return map_move(),printf(" Da tim thay loi ra!\n"),check = 0,(void)0;
        }while(map[pY][pX] == map[eY][eX]);
    }
}

void ve_map(int m)
{
    //hỗ trợ random
    time_t t;
    srand((unsigned) time(&t));

    //khởi tạo @map
    for(int i=0;i<m;i++)
        for(int j=0;j<m; j++) map[i][j]='-';

    // random vị trí của P
    pX= rand()%(m);
    pY= rand()%(m);
    map[pY][pX]='P';
    // random vị trí K
    do {
        kX= rand()%(m);
        kY= rand()%(m);
    } while (map[kY][kX] != '-');
    map[kY][kX]='K';
    // random vị trí E
    do {
        eX= rand()%(m);
        eY= rand()%(m);
    } while (map[eY][eX] != '-');
    map[eY][eX]='E';
}

//******************************************************//
//  Created by DonaldTram on 12/7/19.                  //
//  Copyright © 2019 DonaldTr4n. All rights reserved. //
//***************************************************//
int main(void)
{
    do{
    system("cls");
    ve_map(4);
    // chạy trương trình
    play();
    printf("\n Ban co muon choi man moi? (y/n)\n");
    replay = getch();
    }while(replay == 'y');
}
