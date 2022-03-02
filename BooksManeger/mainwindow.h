#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QArrayData>
#include <QMessageBox>

#include "bookstore.h"
#include "mysql.h"

namespace Ui {
class MainWindow;
}





//自定义的坐标结构体，可用于接受inModel(model,str)函数的返回值
//x,y对应row,col。state确定该坐标是否可用
struct Pos
{
    int x;
    int y;
    bool state;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    //BookStore * bs;
    BuyList* blist;
    MySql * book_sql;
//这几个链表暂时没有作用
//    QStringList  counts_1;
//    QStringList  counts_2;
//    QStringList  counts_3;
//    QStringList  counts_4;

    void setModel_1();//设置model
    void setModel_2();
    void setModel_3();
    void setModel_4();

    void saveModel_1();//保存model到msqlite数据库
    void saveModel_2();
    void saveModel_3();
    void saveModel_4();

    void setModel_Sale();
    Pos inModel(QStandardItemModel*model,QString itemName);

    QStandardItemModel *journal_model;
    QStandardItemModel *book_model;
    QStandardItemModel *MCD_model;
    QStandardItemModel *VCD_model;

    QStandardItemModel *Sale_model;//购物清单模型
    int sum;//购物清单商品数量
    ~MainWindow();
//槽函数，用于响应各种操作信号，如点击按钮
private slots:
    void on_Btn_1_clicked();//期刊按钮

    void on_Btn_2_clicked();//书籍按钮

    void on_Btn_3_clicked();//音乐CD按钮

    void on_Btn_4_clicked();//电影VCD按钮

    void on_Btn_list_released();//购物清单

    void on_Btn_addlist_clicked();//添加到购物清单

    void on_Btn_Pay_released();//结账、支付

    void on_Btn_Sub_released();//从沟渠清单减少每个商品，每次减一

    void on_Btn_search_clicked();//搜索按钮

    void on_Btn_Flush_released();//刷新按钮，

    void on_Btn_AddRow_released();//新增行数据

    void on_Btn_SubRow_released();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
