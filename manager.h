#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
bill *readBill();
customer *readCustomer();
void display_room(room *head);
void display_customer(customer *head);
void display_bill(bill *head);
customer *readCustomer();
void writeRoom();
void deleteRoom();
void amendRoom();
void checkBill();
int index(char t[],char s[]);
void manager(user *r)
{//经理函数
    int c,loop=1;
    while(loop==1)
    {
        //system("cls");
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  旅馆管理系统---经理模块\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  浏览用户\n");
        printf("\t\t\t  * 2  增加用户\n");
        printf("\t\t\t  * 3  删除用户\n");
        printf("\t\t\t  * 4  浏览客房\n");
        printf("\t\t\t  * 5  修改客房\n");
        printf("\t\t\t  * 6  增加客房\n");
        printf("\t\t\t  * 7  删除客房\n");
        printf("\t\t\t  * 8  查看收支\n");
        printf("\t\t\t  * 9  修改个人信息\n");
        printf("\t\t\t  * 0  注销\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&c);
        while(c<0||c>9)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t\t\t#浏览用户#\n");
                display_user(read());
                break;
            case 2:
                printf("\t\t\t\t\t#增加用户#\n");
                write();
                break;
            case 3:
                printf("\t\t\t\t\t#删除用户#\n");
                deleteUser();
                break;
            case 4:
                printf("\t\t\t\t\t#浏览客房#\n");
                display_room(readRoom());
                break;
            case 5:
                printf("\t\t\t\t\t#修改客房#\n");
                amendRoom();
                break;
            case 6:
                printf("\t\t\t\t\t#增加客间#\n");
                writeRoom();
                break;
            case 7:
                printf("\t\t\t\t\t#删除客间#\n");
                deleteRoom();
                break;
            case 8:
                printf("\t\t\t\t\t#查看收支#\n");
                checkBill();
                break;
            case 9:
                printf("\t\t\t\t\t#修改个人信息#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void checkBill()
{//查看账单
    bill *head,*p;
    int id,n=0,c=1,s,num=0;
    char day[12];                     //开房时间
    head=readBill();
    p=head->next->next;
    while(c)
    {
        printf("\t\t\t      #查看账单#\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t      1:  按月份查询\n");
        printf("\t\t\t      2： 按房间查询\n");
        printf("\t\t\t      3： 查看全部\n");
        printf("\t\t\t      0： 退出\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&s);
        while(s<0||s>3)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&s);
        }
        if(s==1)
        {
            n=0;
            num=0;
            printf("请输入年份月份（如：2017.05）：");
            scanf("%s",day);
            printf("*************************************************************************************************************** \n");
            while(p)
            {
                if(index(p->inDay,day)!=-1)
                {
                    n++;
                    printf("NO%d:\n",n);
                    printf("房号: %d\t",p->roomId);
                    printf("房价(元): %d\t",p->price);
                    printf("押金(元): %d\t",p->cashPledge);
                    printf("应收费用(元): %d\t",p->yingPrice);
                    printf("实收费用(元): %d\t",p->realPrice);
                    printf("找零(元): %d\n",p->change);
                    if(p->status==0)
                        printf("状态: 已退房\t");
                    else if(p->status==1)
                        printf("状态: 入住\t");
                    else
                        printf("状态: 预约\t");
                    printf("\n入住时间: %s\t",p->inDay);
                    printf("退房时间: %s\n",p->outDay);
                    num=num+p->yingPrice-p->cashPledge;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("*************************************************************************************************************** \n");
            printf("查询到%d条记录\n",n);
            printf("%s月总收入=%d\n",day,num);
            p=head->next->next;
            getch();
        }
        else if(s==2)
        {
            n=0;
            num=0;
            printf("请输入房间号）：");
            scanf("%d",&id);
            printf("*************************************************************************************************************** \n");
            while(p)
            {
                if(p->roomId==id)
                {
                    n++;
                    printf("NO%d:\n",n);
                    printf("房号: %d\t",p->roomId);
                    printf("房价(元): %d\t",p->price);
                    printf("押金(元): %d\t",p->cashPledge);
                    printf("应收费用(元): %d\t",p->yingPrice);
                    printf("实收费用(元): %d\t",p->realPrice);
                    printf("找零(元): %d\n",p->change);
                    if(p->status==0)
                        printf("状态: 已退房\t");
                    else if(p->status==1)
                        printf("状态: 入住\t");
                    else
                        printf("状态: 预约\t");
                    printf("入住时间: %s\t",p->inDay);
                    printf("退房时间: %s\n",p->outDay);
                    num=num+p->yingPrice-p->cashPledge;
                    p=p->next;
                }
                else p=p->next;
            }
            printf("*************************************************************************************************************** \n");
            printf("查询到%d条记录\n",n);
            printf("%d号房总收入=%d\n",id,num);
            p=head->next->next;
            getch();
        }
        else if(s==3)
            display_bill(head);
        else
            c=0;
    }
}
void deleteRoom()
{//删除房间
    int pos,id;
    char ans;
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    pa=head;
    display_room(readRoom());
    printf("请输入要删除的房间号（若账号不存在返回）：");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            printf("狠心删除？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                pa->next=p->next;
                free(p);
                p=head->next;
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
                printf("删除成功！\n");
                display_room(readRoom());
                clearRoom(head);
                return;
            }
            else clearRoom(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("无此房间！\n");
        clearRoom(head);
        return;
    }
}
void amendRoom()
{//修改房间
    int pos,id;
    char ans,name[15];
    room *head,*p,*pa;
    head=readRoom();
    p=head->next;
    pa=head;
    display_room(readRoom());
    printf("请输入要修改信息的房间号（若房间号不存在返回）：");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id)
        {
            printf("房子当前信息如下：\n");
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
            printf("确定修改？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("输入房号：\n");
                scanf("%d",&p->roomId);
                printf("输入房间类型：\n");
                scanf("%s",&name);
                strcpy(p->name,name);
                printf("输入房价：\n");
                scanf("%d",&p->price);
                printf("输入押金：\n");
                scanf("%d",&p->cashPledge);
                printf("输入房价类型(0表示正常价；1表示优惠价)：\n");
                scanf("%d",&p->discount);
                printf("输入房间状态（0表示空；1表示非空；2表示待打扫）：\n");
                scanf("%d",&p->status);
                pa=p;
                p=head->next->next;
                FILE *f = fopen("room.txt","w");//以“r”（写）方式打开
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
                printf("修改成功！\n");
                printf("房子当前信息如下：\n");
                printf("房号: %d\t",pa->roomId);
                printf("房间类型: %s\t",pa->name);
                printf("房价(元): %d\t",pa->price);
                printf("押金(元): %d\t",pa->cashPledge);
                if(pa->discount==0)
                    printf("优惠: 否\t");
                else
                    printf("优惠: 是\t");
                if(pa->status==0)
                    printf("状态: 空\n");
                else if(pa->status==1)
                    printf("状态: 非空\n");
                else if(pa->status==2)
                    printf("状态: 未打扫\n");
                else
                    printf("状态: 打扫中\n");
                clearRoom(head);
                return;
            }
            else clearRoom(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("无此房间！\n");
        clearRoom(head);
        return;
    }
}
void writeRoom()
{//增加房间
    int roomId;         //房号
    char name[15];      //房间类型
    int price;          //房价
    int cashPledge;     //押金
    int discount;       //0表示正常价；1表示优惠价。
    int status;         //房间状态：0表示空；1表示非空；2表示待打扫
    int select;         //写数据控制器
    printf("按\"1\"继续，\"0\"退出:\n");
    scanf("%d",&select);
    while(1==select)
    {
        FILE *f = fopen("room.txt","a");//以“a”（写）方式打开user.txt
        printf("输入房号：\n");
        scanf("%d",&roomId);
        fprintf(f,"%-5d",roomId);
        printf("输入房间类型：\n");
        scanf("%s",&name);
        fprintf(f,"%-15s",name);
        printf("输入房价：\n");
        scanf("%d",&price);
        fprintf(f,"%-6d",price);
        printf("输入押金：\n");
        scanf("%d",&cashPledge);
        fprintf(f,"%-6d",cashPledge);
        printf("输入房价类型(0表示正常价；1表示优惠价)：\n");
        scanf("%d",&discount);
        fprintf(f,"%-3d",discount);
        printf("输入房间状态（0表示空；1表示非空；2表示待打扫）：\n");
        scanf("%d",&status);
        fprintf(f,"%d\n",status);
        fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
        printf("按\"1\"继续，\"0\"退出:\n");
        scanf("%d",&select);
    }
}
