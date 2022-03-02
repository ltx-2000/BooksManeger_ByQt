#ifndef MYLABELVIEW_H
#define MYLABELVIEW_H

#include <QMainWindow>
#include <QTableView>
#include <QTableWidget>
#include <QPushButton>
#include <QObject>

class MyLabelView:public QWidget
{
    Q_OBJECT
public:
    MyLabelView(QWidget *parent);
    void setbtn(QString btn_name,int x,int y,int w,int h);

    QPushButton* lab_btn;
    QTableView* tabView;
public slots:
    void TopThis();//将此控件置顶
};

#endif // MYLABELVIEW_H
