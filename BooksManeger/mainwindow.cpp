#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    //this->setWindowTitle("XXX书店管理系统");
    //设置不可最大化
    //this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    //this->setFixedSize(600,400);

   // 创建、初始化数据库
    blist=new BuyList();
    book_sql = new MySql("bootStore.db");

    /*book_sql->CreateTable("create table journal(name varchar(20),num varchar(20),"
                          "week int,period int,price double,code varchar(20),"
                          "count int)");*/
    book_sql->CreateTable("create table 期刊(期刊名 TEXT,期刊号 TEXT,"
                          "发行周期 int,期 int,价格 double,条码 TEXT,"
                          "商品余量 int)");
    book_sql->CreateTable("create table 书籍(书名 TEXT,作者 TEXT,"
                          "出版社 TEXT,ISBN码 TEXT,价格 double,条码 TEXT,"
                          "商品余量 int)");
    book_sql->CreateTable("create table 音乐CD(CD名 TEXT,艺术家 TEXT,"
                          "风格 TEXT,音乐时长 TEXT,价格 double,条码 TEXT,"
                          "商品余量 int)");
    book_sql->CreateTable("create table 电影VCD(VCD名 TEXT,主演 TEXT,"
                          "影片时长 TEXT,价格 double,条码 TEXT,"
                          "商品余量 int)");

    ui->setupUi(this);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    ui->Btn_Sub->hide();

    setModel_1();
    setModel_2();
    setModel_3();
    setModel_4();

    setModel_Sale();


}

void MainWindow::setModel_1()
{
    journal_model = new QStandardItemModel();
    journal_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("期刊名")));
    journal_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("发行刊号")));
    journal_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("发行周期")));
    journal_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("期")));
    journal_model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("价格(元)")));
    journal_model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("商品条码")));
    journal_model->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("商品剩余")));
//将所有相关数据用执行器读出，并写入model中以显示
    QString getstr;
    QSqlQuery *query = new QSqlQuery();
    getstr = QString("select * from 期刊;");
    query->prepare(getstr);
    if(query->exec(getstr))
    {
        int i=0;
        while(query->next())
        {
            qDebug()<<query->value(0).toString();
            qDebug()<<query->value(1).toString();
            qDebug()<<query->value(2).toString();
            qDebug()<<query->value(3).toString();
            qDebug()<<query->value(4).toString();
            qDebug()<<query->value(5).toString();
            qDebug()<<query->value(6).toString();


            QString str = query->value(0).toString();
            journal_model->setItem(i,0,new QStandardItem(str));
            str = query->value(1).toString();
            journal_model->setItem(i,1,new QStandardItem(str));
            str=QString("%1").arg(query->value(2).toInt());
            journal_model->setItem(i,2,new QStandardItem(str));
            str=QString("%1").arg(query->value(3).toInt());
            journal_model->setItem(i,3,new QStandardItem(str));
            str=QString("%1").arg(query->value(4).toDouble());
            journal_model->setItem(i,4,new QStandardItem(str));
            str=QString("%1").arg(query->value(5).toString());
            journal_model->setItem(i,5,new QStandardItem(str));
            str=QString("%1").arg(query->value(6).toInt());
            journal_model->setItem(i,6,new QStandardItem(str));
            i++;
        }
    }
     journal_model->appendRow(new QStandardItem(""));


}

void MainWindow::setModel_2()
{

    book_model = new QStandardItemModel();
    book_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("书名")));
    book_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("作者")));
    book_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("出版社")));
    book_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("ISBN")));
    book_model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("价格(元)")));
    book_model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("商品条码")));
    book_model->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("商品剩余")));
//将所有相关数据用执行器读出，并写入model中以显示
    QString getstr;
    QSqlQuery *query = new QSqlQuery();
    getstr = QString("select * from 书籍;");
    query->prepare(getstr);
    if(query->exec(getstr))
    {
        int i=0;
        while(query->next())
        {
            qDebug()<<query->value(0).toString();
            qDebug()<<query->value(1).toString();
            qDebug()<<query->value(2).toString();
            qDebug()<<query->value(3).toString();
            qDebug()<<query->value(4).toString();
            qDebug()<<query->value(5).toString();
            qDebug()<<query->value(6).toString();

            QString str = query->value(0).toString();
            book_model->setItem(i,0,new QStandardItem(str));
            str = query->value(1).toString();
            book_model->setItem(i,1,new QStandardItem(str));
            str=QString("%1").arg(query->value(2).toString());
            book_model->setItem(i,2,new QStandardItem(str));
            str=QString("%1").arg(query->value(3).toString());
            book_model->setItem(i,3,new QStandardItem(str));
            str=QString("%1").arg(query->value(4).toDouble());
            book_model->setItem(i,4,new QStandardItem(str));
            str=QString("%1").arg(query->value(5).toString());
            book_model->setItem(i,5,new QStandardItem(str));
            str=QString("%1").arg(query->value(6).toInt());
            book_model->setItem(i,6,new QStandardItem(str));
            i++;
        }
    }
     book_model->appendRow(new QStandardItem(""));
}

void MainWindow::setModel_3()
{

    MCD_model = new QStandardItemModel();
    MCD_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("CD名")));
    MCD_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("演唱者")));
    MCD_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("风格")));
    MCD_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("曲目时长")));
    MCD_model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("价格(元)")));
    MCD_model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("商品条码")));
    MCD_model->setHorizontalHeaderItem(6,new QStandardItem(QObject::tr("商品剩余")));
//将所有相关数据用执行器读出，并写入model中以显示
    QString getstr;
    QSqlQuery *query = new QSqlQuery();
    getstr = QString("select * from 音乐CD;");
    query->prepare(getstr);
    if(query->exec(getstr))
    {
        int i=0;
        while(query->next())
        {
            qDebug()<<query->value(0).toString();
            qDebug()<<query->value(1).toString();
            qDebug()<<query->value(2).toString();
            qDebug()<<query->value(3).toString();
            qDebug()<<query->value(4).toString();
            qDebug()<<query->value(5).toString();
            qDebug()<<query->value(6).toString();

            QString str = query->value(0).toString();
            MCD_model->setItem(i,0,new QStandardItem(str));
            str = query->value(1).toString();
            MCD_model->setItem(i,1,new QStandardItem(str));
            str=QString("%1").arg(query->value(2).toString());
            MCD_model->setItem(i,2,new QStandardItem(str));
            str=QString("%1").arg(query->value(3).toString());
            MCD_model->setItem(i,3,new QStandardItem(str));
            str=QString("%1").arg(query->value(4).toDouble());
            MCD_model->setItem(i,4,new QStandardItem(str));
            str=QString("%1").arg(query->value(5).toString());
            MCD_model->setItem(i,5,new QStandardItem(str));
            str=QString("%1").arg(query->value(6).toInt());
            MCD_model->setItem(i,6,new QStandardItem(str));
            i++;
        }
    }
     MCD_model->appendRow(new QStandardItem(""));
}

void MainWindow::setModel_4()
{
    VCD_model = new QStandardItemModel();
    VCD_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("VCD名")));
    VCD_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("主演")));
    VCD_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("影片时长")));
    VCD_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("价格(元)")));
    VCD_model->setHorizontalHeaderItem(4,new QStandardItem(QObject::tr("商品条码")));
    VCD_model->setHorizontalHeaderItem(5,new QStandardItem(QObject::tr("商品剩余")));

    //将所有相关数据用执行器读出，并写入model中以显示
    QString getstr;
    QSqlQuery *query = new QSqlQuery();
    getstr = QString("select * from 电影VCD;");
    query->prepare(getstr);
    if(query->exec(getstr))
    {
        int i=0;
        while(query->next())
        {
            qDebug()<<query->value(0).toString();
            qDebug()<<query->value(1).toString();
            qDebug()<<query->value(2).toString();
            qDebug()<<query->value(3).toString();
            qDebug()<<query->value(4).toString();
            qDebug()<<query->value(5).toString();


            QString str = query->value(0).toString();
            VCD_model->setItem(i,0,new QStandardItem(str));
            str = query->value(1).toString();
            VCD_model->setItem(i,1,new QStandardItem(str));
            str=QString("%1").arg(query->value(2).toString());
            VCD_model->setItem(i,2,new QStandardItem(str));
            str=QString("%1").arg(query->value(3).toDouble());
            VCD_model->setItem(i,3,new QStandardItem(str));
            str=QString("%1").arg(query->value(4).toString());
            VCD_model->setItem(i,4,new QStandardItem(str));
            str=QString("%1").arg(query->value(5).toInt());
            VCD_model->setItem(i,5,new QStandardItem(str));
            i++;
        }
    }
    VCD_model->appendRow(new QStandardItem(""));

}

void MainWindow::saveModel_1()
{
    int row = journal_model->rowCount();
    QStandardItemModel*model = journal_model;
    QModelIndex index;
    QVariant data;
    QString query_str;

    //sql执行器query，通过它对数据库进行操作
    QSqlQuery* query = new QSqlQuery();
    qDebug()<<row;
    //下列代码：每一行数据都通过select语句判断其是否存在数据库中
    //不存在时添加该数据，作为新增数据
    //存在时应该对其进行数据更新
    for(int i=0;i<row;i++)
    {
        index = model->index(i,1);//选中行第一列的内容
        data = model->data(index);
        if(data.toString()=="")
        {
            continue;
        }
        query_str = QString("from 期刊 where 期刊号='%1';").arg(data.toString());
        index = model->index(i,0);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("select '%1' ").arg(data.toString())+query_str;
        qDebug()<<query_str;
        if(!query->exec(query_str))
        {
            qDebug()<<query->lastError();
        }
        else
        {
            //query->next();
            if(query->next())
            {
                query->clear();
                query_str.clear();
                qDebug()<<data.toString()<<"存在,更新";
                index = model->index(i,3);//
                data = model->data(index);
                query_str.append(QString("update 期刊 set ").arg(data.toInt()));
                index = model->index(i,6);//
                data = model->data(index);
                query_str.append(QString("商品余量='%1'").arg(data.toString()));
               // qDebug()<<query_str;
                index = model->index(i,4);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(",价格='%1'").arg(data.toDouble()));
               // qDebug()<<query_str;
                index = model->index(i,5);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(",条码='%1'").arg(data.toString()));

                index = model->index(i,1);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" where 期刊号='%1';").arg(data.toString()));

                qDebug()<<query_str;
                query->exec(query_str);


                    qDebug()<<"更新成功";

                query_str.clear();
                continue;
            }
            query->clear();
            query_str.clear();
            qDebug()<<data.toString()<<"不存在,插入";
            index = model->index(i,0);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString("INSERT INTO 期刊 VALUES('%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,1);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,2);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toInt()));
           // qDebug()<<query_str;
            index = model->index(i,3);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toInt()));
           // qDebug()<<query_str;
            index = model->index(i,4);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toDouble()));
            //qDebug()<<query_str;
            index = model->index(i,5);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
            //qDebug()<<query_str;
            index = model->index(i,6);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1)").arg(data.toInt()));
            qDebug()<<query_str;

            book_sql->InsertToTable(query_str);
            //query->exec(query_str);
            query_str.clear();


        }


    }

}

void MainWindow::saveModel_2()
{
    int row = book_model->rowCount();
    QStandardItemModel*model = book_model;
    QModelIndex index;
    QVariant data;
    QString query_str;

    //sql执行器query，通过它对数据库进行操作
    QSqlQuery* query = new QSqlQuery();
    qDebug()<<row;
    //下列代码：每一行数据都通过select语句判断其是否存在数据库中
    //不存在时添加该数据，作为新增数据
    //存在时应该对其进行数据更新
    for(int i=0;i<row;i++)
    {
        index = model->index(i,1);//选中行第一列的内容
        data = model->data(index);
        if(data.toString()=="")
        {
            continue;
        }
        index = model->index(i,5);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("from 书籍 where 条码='%1';").arg(data.toString());

        index = model->index(i,0);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("select '%1' ").arg(data.toString())+query_str;
        qDebug()<<query_str;
        if(!query->exec(query_str))
        {
            qDebug()<<query->lastError();
        }
        else
        {
            //query->next();
            if(query->next())
            {
                query->clear();
                query_str.clear();
                qDebug()<<data.toString()<<"存在,更新";
                index = model->index(i,0);//
                data = model->data(index);
                query_str.append(QString("update 书籍 set 书名='%1'").arg(data.toString()));
                index = model->index(i,1);//
                data = model->data(index);
                query_str.append(QString(",作者='%1'").arg(data.toString()));
                index = model->index(i,2);//
                data = model->data(index);
                query_str.append(QString(",出版社='%1'").arg(data.toString()));
                index = model->index(i,3);//
                data = model->data(index);
                query_str.append(QString(",ISBN码='%1'").arg(data.toString()));
                index = model->index(i,4);//
                data = model->data(index);
                query_str.append(QString(",价格='%1'").arg(data.toString()));
                index = model->index(i,5);//
                data = model->data(index);
                query_str.append(QString(",条码='%1'").arg(data.toString()));
                index = model->index(i,6);//
                data = model->data(index);
                query_str.append(QString(",商品余量='%1'").arg(data.toString()));

                index = model->index(i,0);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" where 书名='%1'").arg(data.toString()));
                index = model->index(i,1);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" and 作者='%1';").arg(data.toString()));

                qDebug()<<query_str;
                query->exec(query_str);


                    qDebug()<<"更新成功";

                query_str.clear();
                continue;
            }
            query->clear();
            query_str.clear();
            qDebug()<<data.toString()<<"不存在,插入";
            index = model->index(i,0);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString("INSERT INTO 书籍 VALUES('%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,1);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,2);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,3);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,4);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toDouble()));
            //qDebug()<<query_str;
            index = model->index(i,5);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
            //qDebug()<<query_str;
            index = model->index(i,6);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1)").arg(data.toInt()));
            qDebug()<<query_str;

            book_sql->InsertToTable(query_str);
            //query->exec(query_str);
            query_str.clear();


        }


    }
}

void MainWindow::saveModel_3()
{
    int row = MCD_model->rowCount();
    QStandardItemModel*model = MCD_model;
    QModelIndex index;
    QVariant data;
    QString query_str;

    //sql执行器query，通过它对数据库进行操作
    QSqlQuery* query = new QSqlQuery();
    qDebug()<<row;
    //下列代码：每一行数据都通过select语句判断其是否存在数据库中
    //不存在时添加该数据，作为新增数据
    //存在时应该对其进行数据更新
    for(int i=0;i<row;i++)
    {
        index = model->index(i,1);//选中行第一列的内容
        data = model->data(index);
        if(data.toString()=="")
        {
            continue;
        }
        index = model->index(i,5);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("from 音乐CD where 条码='%1';").arg(data.toString());
        index = model->index(i,0);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("select '%1' ").arg(data.toString())+query_str;
        qDebug()<<query_str;
        if(!query->exec(query_str))
        {
            qDebug()<<query->lastError();
        }
        else
        {
            //query->next();
            if(query->next())
            {
                query->clear();
                query_str.clear();
                qDebug()<<data.toString()<<"存在,更新";
                index = model->index(i,0);//
                data = model->data(index);
                query_str.append(QString("update 音乐CD set CD名='%1'").arg(data.toString()));
                index = model->index(i,1);//
                data = model->data(index);
                query_str.append(QString(",艺术家='%1'").arg(data.toString()));
                index = model->index(i,2);//
                data = model->data(index);
                query_str.append(QString(",风格='%1'").arg(data.toString()));
                index = model->index(i,3);//
                data = model->data(index);
                query_str.append(QString(",音乐时长='%1'").arg(data.toString()));
                index = model->index(i,4);//
                data = model->data(index);
                query_str.append(QString(",价格='%1'").arg(data.toString()));
                index = model->index(i,5);//
                data = model->data(index);
                query_str.append(QString(",条码='%1'").arg(data.toString()));
                index = model->index(i,6);//
                data = model->data(index);
                query_str.append(QString(",商品余量='%1'").arg(data.toString()));

                index = model->index(i,0);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" where CD名='%1'").arg(data.toString()));
                index = model->index(i,1);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" and 艺术家='%1';").arg(data.toString()));

                qDebug()<<query_str;
                query->exec(query_str);


                    qDebug()<<"更新成功";

                query_str.clear();
                continue;
            }
            query->clear();
            query_str.clear();
            qDebug()<<data.toString()<<"不存在,插入";
            index = model->index(i,0);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString("INSERT INTO 音乐CD VALUES('%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,1);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,2);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,3);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,4);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toDouble()));
            //qDebug()<<query_str;
            index = model->index(i,5);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
            //qDebug()<<query_str;
            index = model->index(i,6);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1);").arg(data.toInt()));
            qDebug()<<query_str;

            book_sql->InsertToTable(query_str);
            //query->exec(query_str);
            query_str.clear();


        }


    }
}
//保存电影信息到数据库文件
void MainWindow::saveModel_4()
{
    int row = VCD_model->rowCount();
    QStandardItemModel*model = VCD_model;
    QModelIndex index;
    QVariant data;
    QString query_str;

    //sql执行器query，通过它对数据库进行操作
    QSqlQuery* query = new QSqlQuery();
    qDebug()<<row;
    //下列代码：每一行数据都通过select语句判断其是否存在数据库中
    //不存在时添加该数据，作为新增数据
    //存在时应该对其进行数据更新
    for(int i=0;i<row;i++)
    {
        index = model->index(i,0);//选中行第一列的内容
        data = model->data(index);
        if(data.toString()=="")
        {
            continue;
        }
        index = model->index(i,4);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("from 电影VCD where 条码='%1';").arg(data.toString());
        index = model->index(i,0);//选中行第一列的内容
        data = model->data(index);
        query_str = QString("select '%1' ").arg(data.toString())+query_str;
        qDebug()<<query_str;
        if(!query->exec(query_str))
        {
            qDebug()<<query->lastError();
        }
        else
        {
            //query->next();
            if(query->next())
            {
                query->clear();
                query_str.clear();
                qDebug()<<data.toString()<<"存在,更新";
                index = model->index(i,0);//
                data = model->data(index);
                query_str.append(QString("update 电影VCD set VCD名='%1'").arg(data.toString()));
                index = model->index(i,1);//
                data = model->data(index);
                query_str.append(QString(",主演='%1'").arg(data.toString()));
                index = model->index(i,2);//
                data = model->data(index);
                query_str.append(QString(",影片时长='%1'").arg(data.toString()));
                index = model->index(i,3);//
                data = model->data(index);
                query_str.append(QString(",价格=%1").arg(data.toDouble()));
                index = model->index(i,4);//
                data = model->data(index);
                query_str.append(QString(",条码='%1'").arg(data.toString()));
                index = model->index(i,5);//
                data = model->data(index);
                query_str.append(QString(",商品余量='%1'").arg(data.toString()));

                index = model->index(i,0);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" where VCD名='%1'").arg(data.toString()));
                index = model->index(i,1);//选中行第一列的内容
                data = model->data(index);
                query_str.append(QString(" and 主演='%1';").arg(data.toString()));

                qDebug()<<query_str;
                query->exec(query_str);


                    qDebug()<<"更新成功";

                query_str.clear();
                continue;
            }
            query->clear();
            query_str.clear();
            qDebug()<<data.toString()<<"不存在,插入";
            index = model->index(i,0);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString("INSERT INTO 电影VCD VALUES('%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,1);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,2);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
           // qDebug()<<query_str;
            index = model->index(i,3);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1").arg(data.toDouble()));
            //qDebug()<<query_str;
            index = model->index(i,4);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",'%1'").arg(data.toString()));
            //qDebug()<<query_str;
            index = model->index(i,5);//选中行第一列的内容
            data = model->data(index);
            query_str.append(QString(",%1)").arg(data.toInt()));
            qDebug()<<query_str;

            book_sql->InsertToTable(query_str);
            //query->exec(query_str);
            query_str.clear();


        }


    }
    delete query;
    delete model;
}

void MainWindow::setModel_Sale()
{
    Sale_model = new QStandardItemModel();
    Sale_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("商品")));
    Sale_model->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("价格")));
    Sale_model->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("数量")));
    Sale_model->setHorizontalHeaderItem(3,new QStandardItem(QObject::tr("总计（元）")));

}

Pos MainWindow::inModel(QStandardItemModel *model, QString itemName)
{
    int rows = model->rowCount();
    int cols = model->columnCount();
    Pos RC;
    for(int i =0;i<rows;i++)
    {
        for(int j =0;j<cols;j++)
        {
            QModelIndex index;
            QVariant data;
            index = model->index(i,j);//选中行第一列的内容
            data = model->data(index);
            //QStandardItem*item = model->item(i,j);
            if(data.toString()!="")
            {
                /*QVariant str = item->data();*/
                qDebug()<<data.toString();
                if(data.toString()==itemName)
                {
                    //存在，返回坐标
                    RC.x = i;
                    RC.y = j;
                    RC.state = true;
                    return RC;
                }
            }
        }
    }
    RC.state=false;
    return RC;
}

MainWindow::~MainWindow()
{
    delete blist;
    delete book_sql;
    delete journal_model;
    delete book_model;
    delete MCD_model;
    delete VCD_model;
    delete Sale_model;//购
    delete ui;
}

void MainWindow::on_Btn_1_clicked()
{
    ui->Btn_3->setEnabled(true);
    ui->Btn_2->setEnabled(true);
    ui->Btn_1->setDisabled(true);
    ui->Btn_4->setEnabled(true);
    ui->Btn_Sub->hide();
    ui->Btn_AddRow->show();
    ui->Btn_SubRow->show();
    ui->Line_search->setPlaceholderText("请输入期刊名");

    ui->tableView->setModel(journal_model);

}

void MainWindow::on_Btn_2_clicked()
{
    ui->Btn_1->setEnabled(true);
    ui->Btn_3->setEnabled(true);
    ui->Btn_2->setDisabled(true);
    ui->Btn_4->setEnabled(true);
    ui->Btn_Sub->hide();
    ui->Btn_AddRow->show();
    ui->Btn_SubRow->show();
    ui->Line_search->setPlaceholderText("请输入书名");


    ui->tableView->setModel(book_model);

}

void MainWindow::on_Btn_3_clicked()
{
    ui->Btn_1->setEnabled(true);
    ui->Btn_2->setEnabled(true);
    ui->Btn_3->setDisabled(true);
    ui->Btn_4->setEnabled(true);
    ui->Btn_Sub->hide();
    ui->Btn_AddRow->show();
    ui->Btn_SubRow->show();
    ui->Line_search->setPlaceholderText("请输入音乐CD名");


    ui->tableView->setModel(MCD_model);
}

void MainWindow::on_Btn_4_clicked()
{
    ui->Btn_1->setEnabled(true);
    ui->Btn_2->setEnabled(true);
    ui->Btn_4->setDisabled(true);
    ui->Btn_3->setEnabled(true);
    ui->Btn_Sub->hide();
    ui->Btn_AddRow->show();
    ui->Btn_SubRow->show();
    ui->Line_search->setPlaceholderText("请输入VCD名");

    ui->tableView->setModel(VCD_model);

}


void MainWindow::on_Btn_list_released()
{
    ui->Btn_1->setEnabled(true);
    ui->Btn_2->setEnabled(true);
    ui->Btn_4->setEnabled(true);
    ui->Btn_3->setEnabled(true);
    ui->Btn_Sub->show();
    ui->Btn_AddRow->hide();
    ui->Btn_SubRow->hide();

    ui->tableView->setModel(Sale_model);

}

void MainWindow::on_Btn_addlist_clicked()
{
    //str=QString("%1").arg(J.codes);
    //Sale_model->setItem(i,5,new QStandardItem(str));
    //获取被选中的单元行
    //取出合适的内容
    //为Sale_model添加适当的内容
    //Sale_model->appendRow();

    /*这句代码会导致tabview表格无法编辑，请不要使用*/
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
      //ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->hide();
   //*********************************************************************************
      int row= ui->tableView->currentIndex().row();
      QAbstractItemModel *model = ui->tableView->model();
      QModelIndex index;
      QVariant data1,data2,data_num;
      //下列均为定位对应数据--名字--价格--剩余量
      if(!ui->Btn_1->isEnabled())
      {
         index = model->index(row,0);//选中行第一列的内容
         data1 = model->data(index);
         index = model->index(row,4);//选中行第四列的内容
         data2 = model->data(index);
         index = model->index(row,6);//选中行的内容--商品剩余量
         data_num = model->data(index);
      }
      if(!ui->Btn_2->isEnabled())
      {
         index = model->index(row,0);//选中行第一列的内容
         data1 = model->data(index);
         index = model->index(row,4);//选中行第四列的内容
         data2 = model->data(index);
         index = model->index(row,6);//选中行的内容--商品剩余量
         data_num = model->data(index);
      }
      if(!ui->Btn_3->isEnabled())
      {
         index = model->index(row,0);//选中行第一列的内容
         data1 = model->data(index);
         index = model->index(row,4);//选中行第四列的内容
         data2 = model->data(index);
         index = model->index(row,6);//选中行的内容--商品剩余量
         data_num = model->data(index);
      }
      if(!ui->Btn_4->isEnabled())
      {
         index = model->index(row,0);//选中行第一列的内容
         data1 = model->data(index);
         index = model->index(row,3);//选中行第三列的内容
         data2 = model->data(index);
         index = model->index(row,5);//选中行的内容--商品剩余量
         data_num = model->data(index);
      }

      //未选中商品，不向model添加数据
      if(data1.isNull())
      {
          //没选中商品就不继续了，直接返回
          return;
      }
      //商品缺货，提示店家补货
      if(data_num.toDouble()==0)
      {
          //消息窗提示
          QString msg = QString("商品：%1,已售空，请及时补货！").arg(data1.toString());
          QMessageBox::warning(this,"缺货中",msg);
            return;
      }

      //将已获得的选中行进行数据处理，将对应数据写入model
      /*这部分计算可能有些重复，但不影响最终结果*/
      blist->count+=1;
      blist->name=data1.toString();
      blist->price=data2.toDouble();
      blist->price_count += blist->price;
       qDebug()<<blist;
      QString data3,data4;
      data3=QString("%1").arg(blist->count);
      data4=QString("%1").arg(blist->price_count);
      int i = Sale_model->rowCount();
      qDebug()<<data1.toString()<<Sale_model->rowCount();
      QString dd = data1.toString();
      Pos RC=inModel(Sale_model,dd);
      if(RC.state)
      {
          index = Sale_model->index(RC.x,0);//选中行第一列的内容
          data3 = Sale_model->data(index).toString();
          data3=QString("%1").arg(data3.toDouble()+1);
          Sale_model->setItem(RC.x,0,new QStandardItem(data3));
          Sale_model->setItem(0,3,new QStandardItem(data4));

      }
      else
      {
          if(i<1)
          {
              Sale_model->setItem(i+1,0,new QStandardItem(data3));
              Sale_model->setItem(i+1,1,new QStandardItem(data1.toString()));
              Sale_model->setItem(i+1,2,new QStandardItem(data2.toString()));
          }
          else
          {
              //在某行某列添加（或设置）一个数据
          Sale_model->setItem(i,0,new QStandardItem(data3));
          Sale_model->setItem(i,1,new QStandardItem(data1.toString()));
          Sale_model->setItem(i,2,new QStandardItem(data2.toString()));
          }
          Sale_model->setItem(0,3,new QStandardItem(data4));

      }
      blist->count=0;

      //加入购物清单，书店相关库存-1
      if(!ui->Btn_4->isEnabled())
      {
            int count;
            index = model->index(row,5);//选中行第6列的内容//数量
            count = model->data(index).toInt()-1;
            //index = model->index(row,5);
            model->setData(index,QString("%1").arg(count));
            //model->setItem(row,6,QString("%1").arg(count));
      }
      else
      {
          int count;
          index = model->index(row,6);//选中行第7列的内容//数量
          count = model->data(index).toInt()-1;
          //index = model->index(row,6);
          model->setData(index,QString("%1").arg(count));
         // model->setItem(row,6,QString("%1").arg(count));
      }
}

//结账、付款
void MainWindow::on_Btn_Pay_released()
{
    ui->Btn_1->setEnabled(true);
    ui->Btn_2->setEnabled(true);
    ui->Btn_4->setEnabled(true);
    ui->Btn_3->setEnabled(true);
    ui->Btn_AddRow->hide();

    ui->tableView->setModel(Sale_model);
    //获取Sale_model中的商品数，商品名，和商品价
    //计算总价
    //提示“是否付款？”
    //删除所有model中的相关商品，并更新数据库。
    QAbstractItemModel *model = ui->tableView->model();
    QModelIndex index;
    QVariant data1,data2;
    QVariant data3,data4;
    QString ReSult,str;//结算信息

    //计算交易信息
    for(int i=1;i<model->rowCount();i++)
    {
        index = model->index(i,1);//第2列的内容//数量
        data1 = model->data(index);
        index = model->index(i,0);//第1列的内容//价格
        data2 = model->data(index);
        index = model->index(i,2);//第3列的内容//价格
        data3 = model->data(index);
        str= QString("商品：%1,数量：%2，单价：%3 \n").arg(data1.toString()).arg(data2.toString()).arg(data3.toString());
        ReSult.append(str);
    }
    index = model->index(0,3);//第4列的内容//价格
    data4 = model->data(index);
    str=QString("总计：%1 元\n").arg(data4.toString());
    ReSult.append(str);
    qDebug()<<ReSult;
    //用一个消息窗口提示结算信息
    QMessageBox::StandardButton re=QMessageBox::information(this,"请确认交易信息",ReSult,QMessageBox::Yes|QMessageBox::No);
    int rcount;
    QModelIndex Index;
    switch (re) {
    case QMessageBox::Yes:
        //确认则清空购物清单
        qDebug()<<"yes";
        //
        rcount = Sale_model->rowCount();
        for(int j =1;j<rcount;j++)
        {
            Index = Sale_model->index(j,1);
            Sale_model->removeRow(Index.row());
        }
        Index = Sale_model->index(0,3);
        Sale_model->setData(Index,"");
        blist->price_count=0;

        on_Btn_Flush_released();

        break;
    case QMessageBox::No:
        //否则，不做操作
        qDebug()<<"no";
        break;
    default:
        break;
    }

}
//减
void MainWindow::on_Btn_Sub_released()
{
      int row= ui->tableView->currentIndex().row();//获取当前选中行
      QAbstractItemModel *model = ui->tableView->model();//获取当前model
      QModelIndex index;//用来定位数据
      QVariant data1,data2;

      index = model->index(row,0);//选中行第一列的内容//数量
      data1 = model->data(index);
      index = model->index(row,2);//选中行第3列的内容//价格
      data2 = model->data(index);

          //未选中商品，不向model修改数据
      if(data1.isNull())
      {
          return;
      }

      //将已获得的选中行进行数据处理，将对应数据写入model
      blist->name=data1.toString();
      blist->price=data2.toDouble();


      QString data3,data4;

      qDebug()<<data1.toString();
      QString dd = data1.toString();
      Pos RC=inModel(Sale_model,dd);
      index = Sale_model->index(RC.x,0);//选中行第一列的内容
      data3 = Sale_model->data(index).toString();
      data3=QString("%1").arg(data3.toDouble()-1);
      index = Sale_model->index(0,3);//选中行第三列（总计价格）的内容
      data4 = Sale_model->data(index).toString();
      data4=QString("%1").arg(data4.toDouble()-blist->price);
      blist->price_count -= blist->price;

      //更新购物车表格model
      Sale_model->setItem(RC.x,0,new QStandardItem(data3));
      Sale_model->setItem(0,3,new QStandardItem(data4));

      //购物清单移除一份，书店库存恢复一份
      //下列每一个if都是在判断移除的商品是否在某个model内，是则对对应的行进行修改
      index = model->index(row,1);//选中行第一列的内容//数量
      data1 = model->data(index);
      if(inModel(journal_model,data1.toString()).state)
      {
          int count;
          Pos RC=inModel(journal_model,data1.toString());
          index = journal_model->index(RC.x,6);//选中行第一列的内容//数量
          count = journal_model->data(index).toInt()+1;
          journal_model->setData(index,QString("%1").arg(count));
      }
      if(inModel(book_model,data1.toString()).state)
      {
          int count;
          Pos RC=inModel(book_model,data1.toString());
          index = book_model->index(RC.x,6);//选中行第一列的内容//数量
          count = book_model->data(index).toInt()+1;
          book_model->setData(index,QString("%1").arg(count));
      }
      if(inModel(MCD_model,data1.toString()).state)
      {
          int count;
          Pos RC=inModel(MCD_model,data1.toString());
          index = MCD_model->index(RC.x,6);//选中行第一列的内容//数量
          count = MCD_model->data(index).toInt()+1;
          MCD_model->setData(index,QString("%1").arg(count));
      }
      if(inModel(VCD_model,data1.toString()).state)
      {
          int count;
          Pos RC=inModel(VCD_model,data1.toString());
          index = VCD_model->index(RC.x,6);//选中行第一列的内容//数量
          count = VCD_model->data(index).toInt()+1;
          VCD_model->setData(index,QString("%1").arg(count));
      }

      //完全移除某项商品，该行将不存在，故将回复库存写在前面
      index = model->index(row,0);//选中行第一列的内容//数量
      data1 = model->data(index);
      if(data1.toDouble() <= 0.0)
      {
          //清单内的某种商品清空后，从清单移除，需重新从商店选入。
          qDebug()<<Sale_model->rowCount();
          QModelIndex curIndex = ui->tableView->currentIndex();
          Sale_model->removeRow(curIndex.row());
      }

}

void MainWindow::on_Btn_search_clicked()
{
    //下列每一个if语句都是在区分搜索区间，并给出对应的搜索结果
    //避免搜索错乱
    QString search  = ui->Line_search->text();
    Pos RC;
    //判断search数据是否在某个model内，是则选中他的对应行
    if(inModel(journal_model,search).state && !ui->Btn_1->isEnabled())
    {
        RC=inModel(journal_model,search);
        ui->tableView->setModel(journal_model);
        ui->tableView->selectRow(RC.x);
    }
    if(inModel(book_model,search).state && !ui->Btn_2->isEnabled())
    {
        RC=inModel(book_model,search);
        ui->tableView->setModel(book_model);
        ui->tableView->selectRow(RC.x);
    }
    if(inModel(MCD_model,search).state && !ui->Btn_3->isEnabled())
    {
        RC=inModel(MCD_model,search);
        ui->tableView->setModel(MCD_model);
        ui->tableView->selectRow(RC.x);
    }
    if(inModel(VCD_model,search).state && !ui->Btn_4->isEnabled())
    {
        RC=inModel(VCD_model,search);
        ui->tableView->setModel(VCD_model);
        ui->tableView->selectRow(RC.x);
    }
}


void MainWindow::on_Btn_Flush_released()
{

    //把所有model写入数据库
    saveModel_1();
    saveModel_2();
    saveModel_3();
    saveModel_4();

    //设置model内容
    //从数据库将数据读出到各个对应的model
    setModel_1();
    setModel_2();
    setModel_3();
    setModel_4();


    //刷新model，否则数据输入时会有丢失现象
    if(!ui->Btn_1->isEnabled())
    {
     ui->Btn_2->clicked();
     ui->Btn_1->clicked();
    }
    if(!ui->Btn_2->isEnabled())
    {
     ui->Btn_1->clicked();
     ui->Btn_2->clicked();
    }
    if(!ui->Btn_3->isEnabled())
    {
     ui->Btn_2->clicked();
     ui->Btn_3->clicked();
    }
    if(!ui->Btn_4->isEnabled())
    {
     ui->Btn_2->clicked();
     ui->Btn_4->clicked();
    }
}

void MainWindow::on_Btn_AddRow_released()
{
    //新增一行以供添加数据
    ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
}

void MainWindow::on_Btn_SubRow_released()
{
    int row= ui->tableView->currentIndex().row();//获取当前选中行
    QAbstractItemModel *model = ui->tableView->model();//获取当前model
    QModelIndex index = model->index(row,0);//选中行第三列（总计价格）的内容
    QVariant data1 = model->data(index).toString();
    //删除库存为0的商品信息//，暂时不做处理
    if(!ui->Btn_1->isEnabled())
    {
      QString del_str = QString("delete from 期刊 where 期刊名 = '%1'").arg(data1.toString());
      QSqlQuery * query_del=new QSqlQuery();
      query_del->prepare(del_str);
      query_del->exec();
    }
    if(!ui->Btn_2->isEnabled())
    {
      QString del_str = QString("delete from 书籍 where 书名 = '%1'").arg(data1.toString());
      QSqlQuery * query_del=new QSqlQuery();
      query_del->prepare(del_str);
      query_del->exec();
    }
    if(!ui->Btn_3->isEnabled())
    {
      QString del_str = QString("delete from 音乐CD where CD名 = '%1'").arg(data1.toString());
      QSqlQuery * query_del=new QSqlQuery();
      query_del->prepare(del_str);
      query_del->exec();
    }
    if(!ui->Btn_4->isEnabled())
    {
      QString del_str = QString("delete from 电影VCD where VCD名 = '%1'").arg(data1.toString());
      QSqlQuery * query_del=new QSqlQuery();
      query_del->prepare(del_str);
      query_del->exec();
    }
    qDebug()<<model->rowCount();
    QModelIndex curIndex = ui->tableView->currentIndex();
    model->removeRow(curIndex.row());
}
