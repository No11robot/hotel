#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
struct usernode
{
    char userId[12];                    //编号
    char name[9];                       //姓名
    char sex[4];
    char role[8];                       //角色
    char email[20];                     //email
    char password[7];                   //密码
    //int roomId;                       //房间号
    struct usernode *next;
};
typedef struct usernode user;    //用户结构体类型
struct roomnode
{
    int roomId;         //房间号
    char name[15];      //房间类型
    int price;          //房价
    int discount;       //0表示正常价；1表示优惠价。
    int cashPledge;     //押金
    int status;         //房间状态：0表示空；1表示非空；2表示待打扫；3表示有人打扫
    struct roomnode *next;
};
typedef struct roomnode room;      //房间结构体类型
struct billnode
{
    int roomId;                         //房号
    int price;                          //房价
    int yingPrice;                      //应收费用
    int realPrice;                      //实收费用
    int cashPledge;                     //押金
    int change;                         //找零
    int status;                         //状态1表示入住押金；2表示预约押金；0表示已还押金
    char inDay[12];                     //开房时间
    char outDay[12];                    //退房时间
    struct billnode *next;
};
typedef struct billnode bill;         //账单结构体类型
struct tagCustomernode
{
    int roomId;         //房间号
    char m_ID[19];      //身份证号码
    char m_name[9];     //顾客姓名
    int  m_age;         //顾客年龄
    char  m_sex[4];     //顾客性别
    char phone[12];     //电话号码
    char inDay[12];     //开房时间
    char outDay[12];    //退房时间
    int status;         //旅客状态：1表示入住；0表示已退房；2表示预约；
    struct tagCustomernode *next;

};
typedef struct tagCustomernode customer;/*旅客结构*/

