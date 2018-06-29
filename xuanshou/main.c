//
//  main.c
//  xuanshou
//
//  Created by 20161104568 on 2018/6/27.
//  Copyright © 2018年 20161104568. All rights reserved.
//

#define M 10
#define N 8
#include<stdio.h>
struct Xs
{
    int no;
    char name[20];
    int sc[N];
    float score;
};

void input(struct Xs* x, int m, int n); //输入数据，同时计算其相应的编号和平均分；
void sort(struct Xs* s, int m); //为选手进行排名
void output(struct Xs* x, int m);//输出排名及相关信息

int main()
{
    int m;//选手数目小于10
    int n;//评委； 小于8
    struct Xs s[M];
    printf("输入需要参加的选手数目和评委老师个数:\n");
    scanf("%d%d",&m,&n);
    printf("输入姓名和各评委的评分\n");
    input(s,m,n);
    sort(s,m);
    output(s,m);
    return 0;
}

float avg(int* sc, int n);

void input(struct Xs* x, int m, int n){
    int i,j;
    for(i=0; i<m; i++)
    {
        scanf("%s", x[i].name);    //地址符可有可无；对于数组a的首地址就是a=&a=&a[0]
        for(j=0; j<n ;j++)
        {
            scanf("%d",&x[i].sc[j]); //此处的地址符一定不能少；
        }
        //赋值；编号和求平均分；
        x[i].no=i+1;
        x[i].score=avg(x[i].sc,n);
    }
}

float avg(int* sc, int n){
    int i,j,t;
    float avg;
    int sum=0;
    int max = 0;
    int min = 100;
    for(i=0;i<n;i++)
    {
        sum += sc[i];
        max = max < sc[i] ? sc[i] : max;
        min = min > sc[i] ? sc[i] : min;
    }
    if(n>2)	{avg=1.0*(sum-max-min)/(n-2);}
    else 	{avg = 1.0*sum/n;}
    return avg;
}

void sort(struct Xs* s, int m)
{
    struct Xs t;
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<=m;j++)
        {
            if(s[i].score>s[j].score)
            {
                t=s[i];
                s[i]=s[j];
                s[j]=t;
            }
        }
    }
}

void output(struct Xs* x, int m){
    printf("名次\t编号\t姓名\t得分\n");
    for(int i=m; i>0; i--){
        printf("%d\t%d\t%s\t%.1f\n",m-i+1,x[i-1].no,x[i-1].name,x[i-1].score);
    }
}
