#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
user *read();
void display_user(user *head);
void write();
void deleteUser();
void initPassWord();
void amendPassWord(user *r);
void backupUser();
void backupRoom();
void backupBill();
void backupCustomer();
void showTime(int k);
room *readRoom();
bill *readBill();
customer *readCustomer();
void clear(user *head);
void clearRoom(room *head);
void clearBill(bill *head);
void clearCustomer(customer *head);
void adminSystem(user *r)
{//系统管理员函数
    int c,loop=1;
    while(loop==1)
    {

        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  旅馆管理系统---系统管理\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1 浏览用户\n");
        printf("\t\t\t  * 2 增加用户\n");
        printf("\t\t\t  * 3 删除用户\n");
        printf("\t\t\t  * 4 初始化用户密码\n");
        printf("\t\t\t  * 5 修改个人信息\n");
        printf("\t\t\t  * 6 系统备份\n");
        printf("\t\t\t  * 0 注销\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&c);
        while(c<0||c>6)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {

            case 1:
                printf("\n\t\t\t\t\t#浏览用户#\n");
                display_user(read());
                break;
            case 2:
                printf("\n\t\t\t\t\t#增加用户#\n");
                write();
                break;
            case 3:
                printf("\n\t\t\t\t\t#删除用户#\n");
                deleteUser();
                break;
            case 4:
                printf("\n\t\t\t\t\t#初始化用户密码#\n");
                initPassWord();
                break;
            case 5:
                printf("\n\t\t\t\t\t#修改个人信息#\n");
                amendPassWord(r);
                break;
            case 6:
                printf("\n\t\t\t\t\t#系统备份#\n");
                backupUser();
                backupRoom();
                backupBill();
                backupCustomer();
                break;
            default:
                loop=0;
                break;
        }
    }
}
void initPassWord()
{//初始化用户密码
    int pos;
    char id[12],ans;
    user *head,*p;
    head=read();
    p=head->next;
    display_user(head);
    printf("请输入用户账号（若账号不存在返回）：");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(id,p->userId)==0)
        {
            printf("%s\n",p->name);
            printf("确定初始化该用户密码？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                strcpy(p->password,"000000");
                printf("%s的账号密码已置为000000\n",p->name);
                p=head->next->next;
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
void backupUser()
{//用户文件备份
    user *head,*p;
    char filename[30]="user_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("用户数据成功备份到：%s\n",filename);
    head=read();
    p=head->next->next;
    FILE *f = fopen(filename,"w");//以“w”（写）方式打开user.txt
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
}
void backupRoom()
{//客房文件备份
    room *head,*p;
    char filename[30]="room_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("客房数据成功备份到：%s\n",filename);
    head=readRoom();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
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
}
void backupBill()
{//账单文件备份
    bill *head,*p;
    char filename[30]="bill_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("账单数据成功备份到：%s\n",filename);
    head=readBill();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
    while(p)
    {
        fprintf(f,"%-5d",p->roomId);
        fprintf(f,"%-5d",p->price);
        fprintf(f,"%-5d",p->cashPledge);
        fprintf(f,"%-5d",p->yingPrice);
        fprintf(f,"%-5d",p->realPrice);
        fprintf(f,"%-5d",p->change);
        fprintf(f,"%-3d",p->status);
        fprintf(f,"%-12s",p->inDay);
        fprintf(f,"%-12s\n",p->outDay);
        p=p->next;
    }
    fclose(f);//当前文件的写操作执行完毕，需要关闭该操作否则会影响对当前文件的其他操作
    clearBill(head);
}
void backupCustomer()
{//旅客信息文件备份
    customer *head,*p;
    char filename[30]="customer_";
    time_t t;
    time(&t);
    strcat(filename,ctime(&t));
    strcpy(filename+strlen(filename)-15,".txt");
    printf("旅客信息成功备份到：%s\n",filename);
    head=readCustomer();
    p=head->next->next;
    FILE *f = fopen(filename,"w");
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
    clearCustomer(head);
}
