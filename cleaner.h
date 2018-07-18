#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void chaRoom();
void dasaoRoom();
void releaseRoom();
void cleaner(user *r)
{//保洁函数
    int c,loop=1;
    while(loop==1)
    {
        printf("\n%s",r->name);
        showTime(1);
        printf("\t\t\t  旅馆管理系统---保洁模块\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t  * 1  查询未打扫房间\n");
        printf("\t\t\t  * 2  确认房间打扫完成\n");
        printf("\t\t\t  * 3  修改个人信息\n");
        printf("\t\t\t  * 0  注销\n");
        printf("\t\t\t================================== \n");
        printf("\t\t\t请输入选项:");
        scanf("%d",&c);
        while(c<0||c>3)
        {
            printf("输入选项错误！请重新输入：");
            scanf("%d",&c);
        }
        system("cls");
        switch(c)
        {
            case 1:
                printf("\t\t\t\t\t#查询未打扫房间#\n");
                dasaoRoom();
                break;
            case 2:
                printf("\t\t\t\t\t#确认房间打扫完成#\n");
                releaseRoom();
                break;
            case 3:
                printf("\t\t\t\t\t#修改个人信息#\n");
                amendPassWord(r);
                break;
            default:
                loop=0;
                break;
        }
    }
}
void dasaoRoom()
{
    room *head,*p;
    int id,n=0,c=1;
    char ans;
    head=readRoom();
    p=head->next;
    while(c)
    {
        printf("**************************************************************************** \n");
        while(p)
        {
            if(p->status==2)
            {
                n++;
                printf("NO%d:\n",n);
                printf("房号: %d\t",p->roomId);
                printf("房间类型: %s\t",p->name);
                if(p->status==0)
                    printf("状态: 空\n");
                else if(p->status==1)
                    printf("状态: 非空\n");
                else if(p->status==2)
                    printf("状态: 未打扫\n");
                else
                    printf("状态: 正在打扫\n");

                p=p->next;
            }
            else p=p->next;
        }
        printf("***************************************************************************\n");
        printf("查询到%d间未打扫的房间\n",n);
        getch();
        p=head->next;
        printf("请输入要打扫房间号：");
        scanf("%d",&id);
        while(p)
        {
            if(p->roomId==id)
            {
                printf("房号: %d\t",p->roomId);
                printf("房间类型: %s\t",p->name);
                if(p->status==0)
                    printf("状态: 空\n");
                else if(p->status==1)
                    printf("状态: 非空\n");
                else if(p->status==2)
                    printf("状态: 未打扫\n");
                else
                    printf("状态: 正在打扫\n");
                printf("确定前去打扫？(y/n):");
                scanf(" %c",&ans);
                if(ans=='y'||ans=='Y')
                {
                    p->status=3;      //房间置为正在打扫
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
                    printf("操作完成！");
                    clearRoom(head);
                    c=0;
                    return;
                }
                else
                {
                    p=head->next;
                    c=0;
                    break;
                }
            }
            else p=p->next;
        }
        if(!p)
        {
            printf("\n无此客房！请重新输入！\n");
            p=head->next;
            n=0;
            c=1;
        }
    }
    clearRoom(head);
}
void releaseRoom()
{
    room *head,*p;
    int id;
    char ans;
    head=readRoom();
    p=head->next;
    printf("请输入打扫完成的房间号：");
    scanf("%d",&id);
    while(p)
    {
        if(p->roomId==id&&p->status==3)
        {
            printf("房号: %d\t",p->roomId);
            printf("房间类型: %s\t",p->name);
            if(p->status==0)
                printf("状态: 空\n");
            else if(p->status==1)
                printf("状态: 非空\n");
            else if(p->status==2)
                printf("状态: 未打扫\n");
            else
                printf("状态: 正在打扫\n");
            printf("确定打扫完成？(y/n):");
            scanf(" %c",&ans);
            if(ans=='y'||ans=='Y')
            {
                p->status=0;      //房间置为空
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
                printf("打扫完成！\n");
                clearRoom(head);
                return;
            }
            return;
        }
        else p=p->next;
    }
}

