#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void keepRoom();
void changeRoom();
int index(char t[],char s[]);
void showRoom();
void outRoom();
void clearCustomer(customer *head);
void clearBill(bill *head);
void inRoom(int id);
void payment(int id,char inDay[],char outDay[]);
void checkCustomer();
void receptionist(user *r)
{//前台接待模块
    int c,loop=1;
    while(loop==1)
    {
        //system("cls");
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  旅馆管理系统---前台模块\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  查询房间\n");
        printf("\t\t\t  * 2  退房\n");
        printf("\t\t\t  * 3  换房\n");
        printf("\t\t\t  * 4  续住\n");
        printf("\t\t\t  * 5  查看客人信息\n");
        printf("\t\t\t  * 6  修改个人信息\n");
        printf("\t\t\t  * 0  注销\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&c);
        while(c<0||c>8)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
             case 1:
                printf("\t\t\t#查询房间#\n");
                showRoom();
                break;
            case 2:
                printf("\t\t\t#退房#\n");
                outRoom();
                break;
            case 3:
                printf("\t\t\t#换房#\n");
                changeRoom();
                break;
            case 4:
                printf("\t\t\t#续住#\n");
                keepRoom();
                break;
            case 5:
                printf("\t\t\t#查看客人信息#\n");
                checkCustomer();
                break;
            case 6:
                printf("\t\t\t#修改个人信息#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void checkCustomer()
{//查看旅客信息
    customer *head,*p;
    int id,n=0,c=1,s,num=0;
    char day[12];                     //开房时间
    char name[9];                      //姓名
    head=readCustomer();
    p=head->next->next;
    while(c)
    {
        printf("\t\t\t      #旅客信息#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  按月份查询\n");
        printf("\t\t\t      2： 按房间号查询\n");
        printf("\t\t\t      3： 按姓名查询\n");
        printf("\t\t\t      4： 查看全部\n");
        printf("\t\t\t      0： 退出\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&s);
        while(s<0||s>4)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&s);
        }
        if(s==1)
        {
            n=0;
            printf("请输入年份月份（如：2017.05）：");
            scanf("%s",day);
            printf("********************************************************************************************************************** \n");
            while(p)
            {
                if(index(p->inDay,day)!=-1)
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
            printf("查询到%d条记录\n",n);
            p=head->next->next;
        }
        else if(s==2)
        {
            n=0;
            num=0;
            printf("请输入房间号）：");
            scanf("%d",&id);
            printf("********************************************************************************************************************** \n");
            while(p)
            {
                if(p->roomId==id)
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
            printf("查询到%d条记录\n",n);
            p=head->next->next;
        }
        else if(s==3)
        {
            n=0;
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
            printf("查询到%d条记录\n",n);
            p=head->next->next;
        }
        else if(s==4)
            display_customer(head);
        else c=0;
    }
    clearCustomer(head);
}
void keepRoom()
{//续住函数
    customer *head,*p,*pa;
    bill *head1,*q;
    int id,m,rm,c;
    char m_name[9];     //顾客姓名
    char outDay[12];
    char ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    printf("请输入续住房间的房号：\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            if(p->status==1)
            {
                printf("\n房号: %d\t",p->roomId);
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
                pa=p;
            }
            else if(p->status==3)
            {
                printf("当前房间有人预约\n");
                printf("预约时间%s到%s\n",p->inDay,p->outDay);
            }
            p=p->next;
        }
        else p=p->next;
    }
    printf("确定续住？(y/n):");
    scanf(" %c",&ans);
    if(ans=='y'||ans=='Y')
    {
        printf("输入续住退房时间：");
        scanf("%s",outDay);
        strcpy(pa->outDay,outDay);
        while(q)
        {
            if(q->roomId==pa->roomId&&q->status==1)
            {
                printf("房号=%d\n",q->roomId);
                printf("房价=%d\n",q->price);
                strcpy(q->outDay,outDay);
                printf("应补交费用=");
                scanf("%d",&m);
                q->yingPrice=q->yingPrice+m;
                printf("\n实交费用=");
                scanf("%d",&rm);
                q->realPrice=q->realPrice+rm;
                c=rm-m;
                printf("\n找零=%d",c);
                q->change=q->change+c;
                q=head1->next->next;
                break;
            }
            else q=q->next;
        }
        p=head->next->next;
        FILE *f = fopen("customer.txt","w");//以“w”（写）方式打开
        while(p)
        {
            fprintf(f,"%-5d",p->roomId);
            fprintf(f,"%-20s",p->m_ID);
            fprintf(f,"%-9s",p->m_name);
            fprintf(f,"%-4s",p->m_sex);
            fprintf(f,"%-4d",p->m_age);
            fprintf(f,"%-12s",p->phone);
            fprintf(f,"%-12s",p->inDay);
            fprintf(f,"%-12s",p->outDay);
            fprintf(f,"%d\n",p->status);
            p=p->next;
        }
        fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
        FILE *f1 = fopen("bill.txt","w");//以“w”（写）方式打开
        while(q)
        {
            fprintf(f1,"%-5d",q->roomId);
            fprintf(f1,"%-5d",q->price);
            fprintf(f1,"%-5d",q->cashPledge);
            fprintf(f1,"%-5d",q->yingPrice);
            fprintf(f1,"%-5d",q->realPrice);
            fprintf(f1,"%-5d",q->change);
            fprintf(f1,"%-3d",q->status);
            fprintf(f1,"%-12s",q->inDay);
            fprintf(f1,"%-12s\n",q->outDay);
            q=q->next;
        }
        fclose(f1);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
        printf("\n续住完成！\n");
        getch();
        clearCustomer(head);
        clearBill(head1);
    }
}

void changeRoom()
{//换房
    customer *head,*p;
    bill *head1,*q;
    room *head2,*s,*sa;
    int id,n=0;
    char name[15],ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    head2=readRoom();
    s=head2->next;
    printf("请输入原房间的房号：\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id&&p->status==1)
        {
            printf("\n房号: %d\t",p->roomId);
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
            while(s)
            {
                if(s->roomId==id)
                {
                    printf("该房间类型=%s\n",s->name);
                    strcpy(name,s->name);
                    sa=s;
                    s=head2->next;
                    break;
                }
                else s=s->next;
            }
            printf("********************************************************************************************************* \n");
            while(s)
            {
                if(index(s->name,name)!=-1&&s->status!=1)
                {
                    printf("NO%d:\n",n);
                    printf("房号: %d\t",s->roomId);
                    printf("房间类型: %s\t",s->name);
                    printf("房价(元): %d\t",s->price);
                    printf("押金(元): %d\t",s->cashPledge);
                    if(s->discount==0)
                        printf("优惠: 否\t");
                    else
                        printf("优惠: 是\t");
                    if(s->status==0)
                        printf("状态: 空\n");
                    else if(s->status==1)
                        printf("状态: 非空\n");
                    else if(s->status==2)
                        printf("状态: 未打扫\n");
                    else
                        printf("状态: 打扫中\n");
                    n++;
                    s=s->next;
                }
                else s=s->next;
            }
            s=head2->next;
            printf("********************************************************************************************************* \n");
            printf("查询到%d间符合换房条件的房间\n",n);
            printf("确定换房？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                while(q)
                {
                    if(q->roomId==id) break;
                    else q=q->next;
                }
                printf("请输入要换到那个房间：\n");
                scanf("%d",&id);
                p->roomId=id;      //更改旅客房间号
                while(s)
                {
                    if(s->roomId==id) break;
                    else s=s->next;
                }
                sa->status=2;       //原房间置为未打扫
                q->roomId=id;      //账单更改房间号
                q=head1->next->next;
                p=head->next->next;
                s=head2->next->next;
                FILE *f = fopen("customer.txt","w");//以“w”（写）方式打开
                while(p)
                {
                    fprintf(f,"%-5d",p->roomId);
                    fprintf(f,"%-20s",p->m_ID);
                    fprintf(f,"%-9s",p->m_name);
                    fprintf(f,"%-4s",p->m_sex);
                    fprintf(f,"%-4d",p->m_age);
                    fprintf(f,"%-12s",p->phone);
                    fprintf(f,"%-12s",p->inDay);
                    fprintf(f,"%-12s",p->outDay);
                    fprintf(f,"%d\n",p->status);
                    p=p->next;
                }
                fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                while(s)
                {
                    if(s->roomId==id)
                    {
                        s->status=1;   //换后房间置为非空
                        s=head2->next->next;
                        break;
                    }
                    else s=s->next;
                }
                FILE *f2 = fopen("room.txt","w");//以“w”（写）方式打开
                while(s)
                {
                    fprintf(f2,"%-5d",s->roomId);
                    fprintf(f2,"%-15s",s->name);
                    fprintf(f2,"%-6d",s->price);
                    fprintf(f2,"%-6d",s->cashPledge);
                    fprintf(f2,"%-3d",s->discount);
                    fprintf(f2,"%-d\n",s->status);
                    s=s->next;
                }
                fclose(f2);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                FILE *f1 = fopen("bill.txt","w");//以“w”（写）方式打开
                while(q)
                {

                    fprintf(f1,"%-5d",q->roomId);
                    fprintf(f1,"%-5d",q->price);
                    fprintf(f1,"%-5d",q->cashPledge);
                    fprintf(f1,"%-5d",q->yingPrice);
                    fprintf(f1,"%-5d",q->realPrice);
                    fprintf(f1,"%-5d",q->change);
                    fprintf(f1,"%-3d",q->status);
                    fprintf(f1,"%-12s",q->inDay);
                    fprintf(f1,"%-12s\n",q->outDay);
                    q=q->next;
                }
                fclose(f1);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                printf("换房完成！\n");
                getch();
                clearCustomer(head);
                clearBill(head1);
                clearRoom(head2);
                break;
            }
            else break;
        }
        else p=p->next;
    }
    //printf("未查到该记录，请确认房间号！");
    getch();

}
void outRoom()
{//退房函数
    customer *head,*p;
    bill *head1,*q;
    room *head2,*s;
    int id;
    char ans;
    head=readCustomer();
    p=head->next;
    head1=readBill();
    q=head1->next;
    head2=readRoom();
    s=head2->next;
    printf("请输入将退房的房号：\n");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
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
            printf("确定退房？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                p->status=0;      //状态置为已退房
                p=head->next->next;
                FILE *f = fopen("customer.txt","w");//以“w”（写）方式打开
                while(p)
                {
                    fprintf(f,"%-5d",p->roomId);
                    fprintf(f,"%-20s",p->m_ID);
                    fprintf(f,"%-9s",p->m_name);
                    fprintf(f,"%-4s",p->m_sex);
                    fprintf(f,"%-4d",p->m_age);
                    fprintf(f,"%-12s",p->phone);
                    fprintf(f,"%-12s",p->inDay);
                    fprintf(f,"%-12s",p->outDay);
                    fprintf(f,"%d\n",p->status);
                    p=p->next;
                }
                fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                while(q)
                {
                    if(q->roomId==id)
                    {
                        printf("应退还押金=%d\n",q->cashPledge);
                        getch();
                        q->status=0;           //更改状态已退还押金
                        q=head1->next->next;
                        break;
                    }
                    else q=q->next;
                }
                FILE *f1 = fopen("bill.txt","w");//以“w”（写）方式打开
                while(q)
                {

                    fprintf(f1,"%-5d",q->roomId);
                    fprintf(f1,"%-5d",q->price);
                    fprintf(f1,"%-5d",q->cashPledge);
                    fprintf(f1,"%-5d",q->yingPrice);
                    fprintf(f1,"%-5d",q->realPrice);
                    fprintf(f1,"%-5d",q->change);
                    fprintf(f1,"%-3d",q->status);
                    fprintf(f1,"%-12s",q->inDay);
                    fprintf(f1,"%-12s\n",q->outDay);
                    q=q->next;
                }
                fclose(f1);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                while(s)
                {
                    if(s->roomId==id)
                    {
                        s->status=2;           //更改状态为未打扫
                        s=head2->next->next;
                        break;
                    }
                    else s=s->next;
                }
                FILE *f2 = fopen("room.txt","w");//以“w”（写）方式打开
                while(s)
                {
                    fprintf(f2,"%-5d",s->roomId);
                    fprintf(f2,"%-15s",s->name);
                    fprintf(f2,"%-6d",s->price);
                    fprintf(f2,"%-6d",s->cashPledge);
                    fprintf(f2,"%-3d",s->discount);
                    fprintf(f2,"%-d\n",s->status);
                    s=s->next;
                }
                fclose(f2);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                printf("退房完成！\n");
                getch();
                clearCustomer(head);
                clearBill(head1);
                clearRoom(head2);
                break;
            }
            else break;
        }
        else p=p->next;
    }
}
void showRoom()
{
    room *head,*p;
    int id,n=0,c=1,select;
    char name[15];
    head=readRoom();
    p=head->next;
    while(c)
    {
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
                    n++;
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

                    p=p->next;
                }
                else p=p->next;
            }
            printf("********************************************************************************************************* \n");
            printf("查询到%d间符合条件的房间\n",n);
        }
        printf("\t\t\t      #办理#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  办理入住\n");
        printf("\t\t\t      2： 办理预约\n");
        printf("\t\t\t      0： 退出\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&select);
        while(select<0||select>2)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&select);
        }
        if(select==1) c=stayRoom();
        else if(select==2) c=reserveRoom();
        else c=0;
    }
    clearRoom(head);
}
int reserveRoom()
{//预约函数
    room *head,*p;
    customer *head2,*s,*t;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    head2=readCustomer();
    p=head->next->next;
    s=head2->next->next;
    printf("\n\t\t\t#预约#\n");
    while(c)
    {
        printf("请输入要预约的房间号(输入0重新查询)：");
        scanf("%d",&id);
        if(id==0)
        {
            clearRoom(head);
            return 1;
        }
        else
        {
            while(s)
            {
                if(s->roomId==id&&s->status==2)
                {
                    printf("房间已有人预约！\n");
                    t=s;
                    s=head2->next->next;
                    break;
                }
                else s=s->next;
            }
            while(p)
            {
                if(p->roomId==id&t->status!=2)
                {
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
                    if(p->status==1)
                    {
                        while(s)
                        {
                            if(s->roomId==id)
                            {
                                printf("该房间退房时间为：%s\n",s->outDay);
                                break;
                            }
                            else s=s->next;
                        }
                        s=head2->next->next;
                    }
                    printf("确定预约？(y/n):");
                    scanf(" %c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        inRoom(id);     //登记客人信息
                        clearRoom(head);
                        return 0;
                    }
                }
                else p=p->next;
            }
        }
    }
    clearCustomer(head2);
}
int stayRoom()
{//入住函数
    room *head,*p;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    p=head->next;
    printf("\n\t\t\t#入住#\n");
    while(c)
    {
        printf("请输入要入住房间号(输入0重新查询)：");
        scanf("%d",&id);
        if(id==0)
        {
            clearRoom(head);
            return 1;
        }
        else
        {
            while(p)
            {
                if(p->roomId==id)
                {
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
                    printf("确定入住？(y/n):");
                    scanf(" %c",&ans);
                    if(ans=='y'||ans=='Y')
                    {
                        inRoom(id);     //登记客人信息
                        p->status=1;      //房间置为非空
                        p=head->next->next;
                        FILE *f = fopen("room.txt","w");//以“w”（写）方式打开
                        while(p)
                        {
                            fprintf(f,"%-5d",p->roomId);
                            fprintf(f,"%-15s",p->name);
                            fprintf(f,"%-6d",p->price);
                            fprintf(f,"%-6d",p->cashPledge);
                            fprintf(f,"%-3d",p->discount);
                            fprintf(f,"%-d\n",p->status);
                            p=p->next;
                        }
                        fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                        clearRoom(head);
                        return 0;
                    }
                }
                else p=p->next;
            }
            if(!p)
            {
                printf("无此客房！请重新输入！");
                clearRoom(head);
                return 1;

            }
        }
    }
}
void inRoom(int id)
{//客人信息
    char m_ID[19];     /*身份证号码*/
    char m_name[9];   /*顾客姓名*/
    int  m_age;        /*顾客年龄*/
    char  m_sex[6];    /*顾客性别*/
    char phone[12];     //电话号码
    char inDay[12];     //开房时间
    char outDay[12];    //退房时间
    int status;         //旅客状态：1表示入住；2表示预约；0表示已退房；
    FILE *f = fopen("customer.txt","a");//以“a”（写）方式打开user.txt
    printf("房间号是：%d\n",id);
    fprintf(f,"%-5d",id);
    printf("输入身份证号：\n");
    scanf("%s",&m_ID);
    fprintf(f,"%-20s",m_ID);
    printf("输入姓名：\n");
    scanf("%s",&m_name);
    fprintf(f,"%-9s",m_name);
    printf("输入性别：\n");
    scanf("%s",&m_sex);
    fprintf(f,"%-4s",m_sex);
    printf("输入年龄：\n");
    scanf("%d",&m_age);
    fprintf(f,"%-4d",m_age);
    printf ("输入电话号码：");
    scanf ("%s",&phone);
    fprintf(f,"%-12s",phone);
    printf ("输入入住时间（年月日用.隔开）：");
    scanf ("%s",&inDay);
    fprintf(f,"%-12s",inDay);
    printf ("输入应退房时间（年月日用.隔开）：");
    scanf ("%s",&outDay);
    fprintf(f,"%-12s",outDay);
    printf("输入旅客状态(1表示入住；2表示预约)：\n");
    scanf("%d",&status);
    fprintf(f,"%d\n",status);
    fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
    printf("登记完成！\n");
    payment(id,inDay,outDay);      //付款
}
void payment(int id,char inDay[],char outDay[])
{//账单函数
    int roomId;                         //房号
    int price;                          //房价
    int yingPrice;                      //应收费用
    int realPrice;                      //实收费用
    int cashPledge;                     //押金
    int change;                         //找零
    int status;                         //状态
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    while(p)
    {
        if(p->roomId==id)
        {
            printf("房价=%d\n",p->price);
            price=p->price;
            printf("押金=%d\n",p->cashPledge);
            cashPledge=p->cashPledge;           //押金
            printf("应收金额：");
            scanf("%d",&yingPrice);
            printf("实收金额：");
            scanf("%d",&realPrice);             //实收费用
            change=realPrice-yingPrice;             //找零
            printf("找零：%d\n",change);
            break;
        }
        else p=p->next;
    }
    FILE *f = fopen("bill.txt","a");//以“a”（写）方式打开
    printf("房间号：%d\n",id);
    fprintf(f,"%-5d",id);
    printf("房价：%d\n",price);
    fprintf(f,"%-5d",price);
    printf("押金：%d\n",cashPledge);
    fprintf(f,"%-5d",cashPledge);
    printf("应收金额：%d\n",yingPrice);
    fprintf(f,"%-5d",yingPrice);
    printf("实收金额：%d\n",realPrice);
    fprintf(f,"%-5d",realPrice);
    printf("找零：%d\n",change);
    fprintf(f,"%-5d",change);
    printf ("输入状态（1表示入住押金；2表示预约押金；0表示已还押金）：");
    scanf ("%d",&status);
    fprintf(f,"%-3d",status);
    printf("入住时间=%s\n",inDay);
    fprintf(f,"%-12s",inDay);
    printf("退房时间=%s\n",outDay);
    fprintf(f,"%-12s\n",outDay);
    fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
    printf("登记完成！\n");
    clearRoom(head);
}
