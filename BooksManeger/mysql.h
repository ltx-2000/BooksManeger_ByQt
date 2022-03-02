#ifndef MYSQL_H
#define MYSQL_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

/****************
 * 数据库类
 * 包含链接并创建数据库（.db文件）
 * 新建数据表
 * 向表中插入数据
 * 从表中删除数据
 *
 * 由于数据表的格式特殊性，并不存在完全通用的方法
 * 更多的还是要在需要的位置使用QSqlQuery执行器，对特殊数据做特殊处理。
*********************/

class MySql : public QSqlDatabase
{
public:
    MySql(QString basename);
    MySql(){;}
    ~MySql(){database.close();}
    bool CreateTable(QString create_sql);
    bool InsertToTable(QString insert_sql);
    bool DelFromTable(QString del_sql);

private:
    QSqlDatabase database;
    QSqlQuery * query_for_mysql;
    QString basename;
};

#endif // MYSQL_H
