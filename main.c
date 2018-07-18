#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lg.h"                 //结构体
#include "adminSystem.h"        //系统管理员
#include "manager.h"            //经理
#include "receptionist.h"       //前台接待
#include "visitor.h"            //保洁
#include "cleaner.h"            //旅客
void inputPassWord(char password[],int n);
void display_user(user *head);
void display_room(room *head);
void display_customer(customer *head);
void display_bill(bill *head);
user *read();
room *readRoom();
bill *readBill();
customer *readCustomer();
void write();
void writeRoom();
void adminSystem(user *r);
void manager(user *r);
void receptionist(user *r);
void deleteUser();
void deleteRoom();
void initPassWord();
void amendPassWord(user *r);
void amendRoom();
void clear(user *head);
void clearRoom(room *head);
void clearCustomer(customer *head);
void clearBill(bill *head);
void backupUser();
void backupRoom();
void showRoom();
int reserveRoom();
int index(char t[],char s[]);
void inRoom(int id);
void payment(int id,char inDay[],char outDay[]);
void outRoom();
void changeRoom();
void keepRoom();
void showTime(int k)
{//显示当前时间
    //system("cls");
    struct tm *ptr;
    time_t it;
    it=time(NULL);
    ptr=localtime(&it);
    if(ptr->tm_hour>=5&&ptr->tm_hour<9)
        printf("早上好！\n");
    else if(ptr->tm_hour>=9&&ptr->tm_hour<12)
        printf("上午好！\n");
    else if(ptr->tm_hour>=12&&ptr->tm_hour<14)
        printf("中午好！\n");
    else if(ptr->tm_hour>=14&&ptr->tm_hour<18)
        printf("下午好！\n");
    else
        printf("晚上好！\n");
    printf("现在是%4d年%02d月%02d日 %d:%d:%d\n",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
    switch(k)
    {
        case 1:
            printf("欢迎使用旅馆管理系统！\n");
            break;
        case 0:
            printf("谢谢使用旅馆管理系统！\n");
            break;
    }
}
int mainMenu()
{//主菜单函数
    int c;
    printf("\t\t\t      旅馆管理系统\n");
    printf("\t\t\t==========================\n");
    printf("\t\t\t      1:  用户登录\n");
    printf("\t\t\t      2： 旅客\n");
    printf("\t\t\t      0： 退出系统\n");
    printf("\t\t\t==========================\n");
    printf("\t\t\t请输入选项:");
    scanf("%d",&c);
    while(c<0||c>2)
    {
        printf("输入选项错误！请重新输入：");
        scanf("%d",&c);
    }
    return c;
}

user* login()
{//统一登陆函数
    int i,counter=3;      //验证次数
    int pos=-1;
    char userId[12];    //编号
    char password[7];   //密码
    user *head,*s;
    head=read();                        //文件读取链表
    while(counter>0)
    {
        s=head->next;
        system("cls");
        counter--;
        printf("\t\t\t旅馆管理系统---用户登录\n");
        printf("\t\t\t==========================\n");
        printf("\t\t\t用户账号：");
        scanf("%s",userId);
        printf("\t\t\t密码：");
        for(i=0;i<6;i++)
        {
            password[i]=getch();
            printf("*");
        }
        password[i]='\0';
        getch();
        while(s)
        {
            if(strcmp(userId, s->userId)==0)
            {//匹配账号成功
                pos=0;
                break;
            }
            else
                s=s->next;
        }
        if(pos==-1)
        {
            printf("用户不存在！还有%d次登录机会。\n",counter);
            getch();
            continue;
        }
        else
        {
            if(strcmp(password, s->password)!=0)  //比较密码
            {//密码匹配错误
                printf("输入密码错误！还有%d次登录机会。\n",counter);
                getch();
                continue;
            }
            else
            {//密码匹配正确
                return s;               // 返回用户节点
            }
        }
    }
    return NULL;   //登录失败
}
void enterSystem(user *r)
{//角色调用函数
    system("cls");
    if(strcmp(r->role,"管理员")==0)
    {
        adminSystem(r);
    }
    else if(strcmp(r->role,"经理")==0)
    {
        manager(r);
    }
    else if(strcmp(r->role,"前台")==0)
    {
        receptionist(r);
    }
    else if(strcmp(r->role,"保洁")==0)
    {
        cleaner(r);
    }
    else
        printf("\n角色错误！！\n");
}
int index(char t[],char s[])
{
    int i,j,k;
    int tLength=strlen(t),sLength=strlen(s);
    i=0;
    while(i<=tLength-sLength)
    {
        k=i;
        j=0;
        while(s[j]&&t[i]==s[j])
        {
            i++;
            j++;
        }
        if(j==sLength) return k;
        i++;
    }
    return -1;
}
void amendPassWord(user *r)
{//修改个人信息
    int pos;
    char ans;
    char userId[12];                    //编号
    char name[9];                       //姓名
    char email[20];                     //email
    char password[7];                   //密码
    user *head,*p,*pa;
    head=read();
    p=head->next;
    while(p)
    {
        if(strcmp(r->userId,p->userId)==0)
        {
            printf("%s\n",p->name);
            printf("确定修改个人信息？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                printf("请输入原密码：");
                scanf("%s",&password);
                if(strcmp(password,p->password)==0)
                {
                    printf("输入新账号：\n");
                    scanf("%s",&userId);
                    strcpy(p->userId,userId);
                    printf("输入新密码：\n");
                    scanf("%s",&password);
                    strcpy(p->password,password);
                    printf("输入新用户名：\n");
                    scanf("%s",&name);
                    strcpy(p->name,name);
                    printf("输入新邮箱：\n");
                    scanf("%s",&email);
                    strcpy(p->email,email);
                    printf("修改信息成功！\n");
                    printf("ID: %s\t",p->userId);
                    printf("密码: %s\t",p->password);
                    printf("用户名: %s\t",p->name);
                    printf("性别: %s\t",p->sex);
                    printf("职位: %s\t",p->role);
                    printf("邮箱: %s\n",p->email);
                }
                else
                {
                    printf("密码错误！禁止修改个人信息！\n");
                }
                p=head->next->next;
                FILE *f = fopen("user.txt","w");//以“r”（写）方式打开user.txt
                while(p)
                {
                    fprintf(f,"%-12s",p->userId);
                    fprintf(f,"%-7s",p->password);
                    fprintf(f,"%-9s",p->name);
                    fprintf(f,"%-4s",p->sex);
                    fprintf(f,"%-8s",p->role);
                    fprintf(f,"%-8s\n",p->email);
                    p=p->next;
                }
                fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                clear(head);
                return;
            }
            else clear(head);return;
        }
        else p=p->next;
    }
}
void deleteUser()
{//删除用户
    int pos;
    char id[12],ans;
    user *head,*p,*pa;
    head=read();
    p=head->next;
    pa=head;
    display_user(read());
    printf("请输入要删除的用户账号（若账号不存在返回）：");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(id,p->userId)==0)
        {
            printf("狠心删除？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                pa->next=p->next;
                free(p);
                p=head->next;
                FILE *f = fopen("user.txt","w");//以“w”（写）方式打开user.txt
                while(p)
                {
                    fprintf(f,"%-12s",p->userId);
                    fprintf(f,"%-7s",p->password);
                    fprintf(f,"%-9s",p->name);
                    fprintf(f,"%-4s",p->sex);
                    fprintf(f,"%-8s",p->role);
                    fprintf(f,"%-8s\n",p->email);
                    p=p->next;
                }
                fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
                printf("删除成功！\n");
                display_user(read());
                clear(head);
                return;
            }
            else clear(head);return;
        }
        else p=p->next;
    }
    if(!p)
    {
        printf("无此用户！\n");
        clear(head);
        return;
    }
}
void write()
{//增加用户
    char userId[12];                    //编号
    char name[9];                       //姓名
    char sex[4];                        //性别
    char role[8];                       //角色
    char email[20];                     //email
    char password[7];                   //密码
    int select;//写数据控制器
    printf("按\"1\"继续，\"0\"退出:\n");
    scanf("%d",&select);
    while(1==select)
    {
        FILE *f = fopen("user.txt","a");//以“a”（写）方式打开user.txt
        printf("输入账号：\n");
        scanf("%s",&userId);
        fprintf(f,"%-12s",userId);
        printf("输入密码：\n");
        scanf("%s",&password);
        fprintf(f,"%-7s",password);
        printf("输入用户名：\n");
        scanf("%s",&name);
        fprintf(f,"%-9s",name);
        printf("输入性别：\n");
        scanf("%s",&sex);
        fprintf(f,"%-4s",sex);
        printf("输入角色：\n");
        scanf("%s",&role);
        fprintf(f,"%-8s",role);
        printf("输入邮箱：\n");
        scanf("%s",&email);
        fprintf(f,"%-8s\n",email);
        fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
        printf("按\"1\"继续，\"0\"退出:\n");
        scanf("%d",&select);
    }
}
/*
 *从文件中读取节点，并由此建立链表
 */
user *read()
{//用户文件读入链表
    FILE *f = fopen("user.txt","r");//以"r"（读）的形式读取文件，!*文件必须存在
    user *head = (user *)malloc(sizeof(user));//链表头节点
    head->next=NULL;//工作指针，建立链表
    while(!feof(f))
    {
        user *newNode = (user *)malloc(sizeof(user));//临时节点,从文件中读取节点
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%s",newNode->userId);
        fscanf(f,"%s",newNode->password);
        fscanf(f,"%s",newNode->name);
        fscanf(f,"%s",newNode->sex);
        fscanf(f,"%s",newNode->role);
        fscanf(f,"%s",newNode->email);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
room *readRoom()
{//房间文件读入链表
    FILE *f = fopen("room.txt","r");//以"r"（读）的形式读取文件，!*文件必须存在
    room *head = (room *)malloc(sizeof(room));//链表头节点
    head->next=NULL;//工作指针，建立链表
    while(!feof(f))
    {
        room *newNode = (room *)malloc(sizeof(room));//临时节点,从文件中读取节点
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%s",newNode->name);
        fscanf(f,"%d",&newNode->price);
        fscanf(f,"%d",&newNode->cashPledge);
        fscanf(f,"%d",&newNode->discount);
        fscanf(f,"%d",&newNode->status);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
bill *readBill()
{//账单文件读入链表
    FILE *f = fopen("bill.txt","r");//以"r"（读）的形式读取文件，!*文件必须存在
    bill *head = (bill *)malloc(sizeof(bill));//链表头节点
    head->next=NULL;//工作指针，建立链表
    while(!feof(f))
    {
        bill *newNode = (bill *)malloc(sizeof(bill));//临时节点,从文件中读取节点
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%d",&newNode->price);
        fscanf(f,"%d",&newNode->cashPledge);
        fscanf(f,"%d",&newNode->yingPrice);
        fscanf(f,"%d",&newNode->realPrice);
        fscanf(f,"%d",&newNode->change);
        fscanf(f,"%d",&newNode->status);
        fscanf(f,"%s",newNode->inDay);
        fscanf(f,"%s",&newNode->outDay);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
customer *readCustomer()
{//账单文件读入链表
    FILE *f = fopen("customer.txt","r");//以"r"（读）的形式读取文件，!*文件必须存在
    customer *head = (customer *)malloc(sizeof(customer));//链表头节点
    head->next=NULL;//工作指针，建立链表
    while(!feof(f))
    {
        customer *newNode = (customer *)malloc(sizeof(customer));//临时节点,从文件中读取节点
        memset(newNode,0,sizeof(newNode));
        fscanf(f,"%d",&newNode->roomId);
        fscanf(f,"%s",newNode->m_ID);
        fscanf(f,"%s",&newNode->m_name);
        fscanf(f,"%s",&newNode->m_sex);
        fscanf(f,"%d",&newNode->m_age);
        fscanf(f,"%s",&newNode->phone);
        fscanf(f,"%s",&newNode->inDay);
        fscanf(f,"%s",&newNode->outDay);
        fscanf(f,"%d",&newNode->status);
        newNode->next=head->next;
        head->next=newNode;
    }
    fclose(f);
    return head;
}
/*
 *输出链表
 */
void display_user(user *head)
{//输出用户链表
    int num=0;
    user *p = head->next;//工作指针
    printf("********************************************************************************************************* \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
        printf("ID: %s\t",p->userId);
        printf("密码: %s\t",p->password);
        printf("用户名: %s\t",p->name);
        printf("性别: %s\t",p->sex);
        printf("职位: %s\t",p->role);
        printf("邮箱: %s\n",p->email);

    }
    printf("********************************************************************************************************* \n");
    getch();
}
void display_room(room *head)
{//输出客房链表
    int num=0;
    room *p = head->next;//工作指针
    printf("********************************************************************************************************* \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
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

    }
    printf("********************************************************************************************************* \n");
    printf("查询到%d条记录\n",num);
    getch();
}
void display_bill(bill *head)
{//输出账单链表
    int num=0,zong=0;
    bill *p = head->next->next;//工作指针
    printf("************************************************************************************************************ \n");
    while(p)
    {
        num++;
        printf("NO%d:\n",num);
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

        zong=zong+p->yingPrice-p->cashPledge;
        p=p->next;
    }
    printf("************************************************************************************************************ \n");
    printf("查询到%d条记录\n",num);
    printf("总收入=%d\n",zong);
    getch();
}
void display_customer(customer *head)
{//输出旅客信息链表
    int num=0;
    customer *p = head->next;//工作指针
    printf("********************************************************************************************************************** \n");
    while(p->next)
    {
        num++;
        p=p->next;
        printf("NO%d:\n",num);
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

    }
    printf("********************************************************************************************************************** \n");
    printf("查询到%d条记录\n",num);
    getch();
}
void clear(user *head)
{//清除用户链表
    user *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearRoom(room *head)
{//清除房间链表
    room *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearCustomer(customer *head)
{//清除旅客链表
    customer *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
void clearBill(bill *head)
{//清除账单链表
    bill *q,*s;
    q=s=head;
    while(q)
    {
        q=q->next;
        free(s);
        s=q;
    }
}
int main()
{
    user *r;
    int c,loop=1;
    while(loop==1)
    {
        system("cls");
        c=mainMenu();
        switch(c)
        {
            case 1:
                r=login();
                if(r==NULL)
                    loop=0;
                else
                    enterSystem(r);
                break;
            case 2:
                visitor();
                break;
            default:
                loop=0;
                break;
        }
        showTime(loop);
    }
    return 0;
}
