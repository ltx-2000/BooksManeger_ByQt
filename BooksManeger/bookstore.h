#ifndef BOOKSTORE_H
#define BOOKSTORE_H

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

/****************自定义的商品结构体*************
 * 包含商品的各种参数
 * 为了方便调数据而存在
 * 现大多已不再被调用
**********************************/
//时间
class Time_t
{
public:
    double hour;
    double minute;
    double second;
};

//期刊
class Journal
{
public:
    Journal();
    Journal(char* name, char* num, int cycle, int period, double price, char *codes,int sum);
    char* name;//期刊名
    char* num;//期刊号
    int cycle;//发行周期
    int period;//期
    double price;//价格
    char* codes;//条码
    int sum;//商品数量
};
//书籍
class Book
{
public:
    Book();
    Book(char name[20],char authorName[20],char Press[40],char ISBN[10],double price,char*codes,int sum);
    char name[20];//书名
    char authorName[20];//作者
    char Press[40];//出版社
    char ISBN[20];//ISBN码
    double price;//价格
    char* codes;//条码
    int sum;//商品数量
};
//音乐cd
class MCD
{
public:
    MCD();
    MCD(char name[10],char ArtistName[20],char style[10],Time_t time,double price,char*codes,int sum);
    char name[10];//cd名
    char ArtistName[20];//艺术家、演唱者
    char style[10];//风格流派
    Time_t time;//存储曲目的时间信息:  00:00:00
    double price;
    char* codes;//条码
    int sum;//商品数量
};
//VCD
class VCD
{
public:
    VCD();
    VCD(char name[20],char actorName[10],Time_t time, double price,char*codes,int sum);
    char name[20];//VCD名
    char actorName[10];//主演姓名
    Time_t time;//影片时长： 00:00:00
    double price;//VCD价格
    char* codes;//条码
    int sum;//商品数量
};

/*******************************************************/
/*******************
 * 购物单类，包含商品数量、名字、价格、和总价，在添加购物车
 *和移除购物车等处有调用
*******************************/
class BuyList
{
public:
    BuyList(){count=0;price=0.0;price_count=0.0;}
    int count;
    QString name;
    double price;
    double price_count;
};
/**********************
 * 书店类
 * 起初是为了方便生成数据
 * 现已不使用
*********************/
class BookStore
{
public:
    BookStore();
    //为每种商品设置初始化数量
    BookStore(int Jnum,int Bnum,int Mnum,int Vnum);
    list <Journal> journals;
    list <Book> books;
    list <MCD> mcds;
    list <VCD> vcds;

};


#endif // BOOKSTORE_H
