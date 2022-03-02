#include "mysql.h"
MySql::MySql(QString basename)
{
    this->basename = basename;
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(basename);
    if(!database.open())
    {
        qDebug()<<"database not open!";
    }
    else
    {
        qDebug()<<"connect ok!";
    }
}
bool MySql::CreateTable(QString create_sql)
{
    query_for_mysql = new QSqlQuery;
    query_for_mysql->prepare(create_sql);
    if(!query_for_mysql->exec())
    {
        qDebug()<<"建表失败"<<"in createtable()";
        return false;
    }
    else
    {
        qDebug()<<"建表成功"<<"create ok!";
        return true;
    }
}
bool MySql::InsertToTable(QString insert_sql)
{
    query_for_mysql = new QSqlQuery;
    query_for_mysql->prepare(insert_sql);
    if(!query_for_mysql->exec())
    {
        qDebug()<<"error in insert()"<<query_for_mysql->lastError();
        return false;
    }
    else
    {
        qDebug()<<"insert!";
        return true;
    }
}

bool MySql::DelFromTable(QString del_sql)
{
    query_for_mysql = new QSqlQuery;
    query_for_mysql->prepare(del_sql);
    if(!query_for_mysql->exec())
    {
        qDebug()<<"error in del()"<<query_for_mysql->lastError();
        return false;
    }
    else
    {
        qDebug()<<"del!";
        return true;
    }
}
