#include "bookstore.h"


BookStore::BookStore()
{

}


//默认构造，默认数据
Journal::Journal()
{

}
//带参构造，构造灵活数据
Journal::Journal(char *name, char *num, int cycle, int period, double price,char*codes,int sum)
{
    this->name=name;
    this->num=num;
    this->cycle=cycle;
    this->period=period;
    this->price=price;
    this->codes=codes;
    this->sum=sum;
}

Book::Book()
{

}

Book::Book(char name[], char authorName[], char Press[], char ISBN[], double price, char*codes, int sum)
{
    strcpy_s(this->name,name);
    strcpy_s(this->authorName,authorName);
    strcpy_s(this->Press,Press);
    strcpy_s(this->ISBN,ISBN);
    this->price=price;
    this->codes=codes;
    this->sum=sum;
}


MCD::MCD()
{

}

MCD::MCD(char name[], char ArtistName[], char style[], Time_t time, double price, char *codes,int sum)
{
    strcpy_s(this->name,name);
    strcpy_s(this->ArtistName,ArtistName);
    strcpy_s(this->style,style);
    this->price=price;
    this->time=time;
    this->codes=codes;
    this->sum=sum;
}

VCD::VCD()
{

}

VCD::VCD(char name[20], char actorName[10], Time_t time, double price, char *codes,int sum)
{
    strcpy_s(this->name,name);
    strcpy_s(this->actorName,actorName);
    this->price=price;
    this->time=time;
    this->codes=codes;
    this->sum=sum;
}
