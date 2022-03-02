#include "mylabelview.h"

MyLabelView::MyLabelView(QWidget *parent)
{
    lab_btn=new QPushButton(parent);
    tabView=new QTableView(parent);

    connect(lab_btn,SIGNAL(clicked(bool)),this,SLOT(TopThis()));
}

void MyLabelView::setbtn(QString btn_name, int x, int y, int w, int h)
{
    lab_btn->setText(btn_name);
    lab_btn->setGeometry(x,y,w,h);
    tabView->setGeometry(10,y+h+x,570,400);
}

void MyLabelView::TopThis()
{

}
