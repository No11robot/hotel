#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void chaRoom();
void showMe();
int visitor()
{//游客函数
    system("cls");
    int c,loop=1;
    while(loop==1)
    {
        printf("\n尊敬的旅客：");
        showTime(1);
        printf("\t\t\t  旅馆管理系统---旅客模块\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  查询房间\n");
        printf("\t\t\t  * 2  查看自己信息\n");
        printf("\t\t\t  * 0  注销\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&c);
        while(c<0||c>2)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t#查询房间#\n");
                chaRoom();
                break;
            case 2:
                printf("\t\t\t#查看自己信息#\n");
                showMe();
                break;
            default:
                loop=0;
                break;

        }
    }
}
void showMe()
{//查看自己信息
    customer *head,*p;
    int n=0;
    char name[9];                      //姓名
    head=readCustomer();
    p=head->next->next;
    printf("请输入姓名：");
    scanf("%s",name);
    printf("********************************************************************************************************************** \n");
    while(p)
    {
        if(index(p->m_name,name)!=-1)
        {
            n++;
            printf("NO%d:\n",n);
            printf("房号: %d\t",p->roomId);
            printf("身份证号: %s\t",p->m_ID);
            printf("姓名: %s\t",p->m_name);
            printf("性别: %s\t",p->m_sex);
            printf("年龄: %d\t",p->m_age);
            printf("电话号码: %s\n",p->phone);
            printf("入住时间: %s\t",p->inDay);
            printf("退房时间: %s\t",p->outDay);
            if(p->status==0)
                printf("状态: 已退房\n");
            else if(p->status==1)
                printf("状态: 入住\n");
            else
                printf("状态: 预约\n");
            p=p->next;
        }
        else p=p->next;
    }
    printf("********************************************************************************************************************** \n");
    p=head->next->next;
    clearCustomer(head);
}
void chaRoom()
{
    room *head,*p;
    int id,n=0,c=1,select;
    char name[15];
    head=readRoom();
    p=head->next;
    while(c)
    {
        n=0;
        printf("请输入要查询的房间类型关键字（输入all显示所有客房）：");
        scanf("%s",name);
        if(strcmp(name,"all")==0)
            display_room(head);
        else
        {
            printf("********************************************************************************************************* \n");
            while(p)
            {
                if(index(p->name,name)!=-1)
                {
                    printf("NO%d:\n",n);
                    printf("房号: %d\t",p->roomId);
                    printf("房间类型: %s\t",p->name);
                    printf("房价(元): %d\t",p->price);
                    printf("押金(元): %d\t",p->cashPledge);
                    if(p->discount==0)
                        printf("优惠: 否\t");
                    else
                        printf("优惠: 是\t");
                    if(p->status==0)
                        printf("状态: 空\n");
                    else if(p->status==1)
                        printf("状态: 非空\n");
                    else if(p->status==2)
                        printf("状态: 未打扫\n");
                    else
                        printf("状态: 打扫中\n");
                    n++;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("********************************************************************************************************* \n");
            printf("查询到%d间符合条件的房间\n",n);
            getch();
        }

        c=0;
    }
    clearRoom(head);
}
