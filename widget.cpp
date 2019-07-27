#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pb_Tea->setEnabled(false);
    ui->pb_Coffee->setEnabled(false);
    ui->pb_Coke->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int n)
{
    money += n;
    if(money >= 100) ui->pb_Coffee->setEnabled(true);
    if(money >= 150) ui->pb_Tea->setEnabled(true);
    if(money >= 200) ui->pb_Coke->setEnabled(true);
}

void Widget::buy_drink(int n)
{
    money -= n;
    if(money < 100) ui->pb_Coffee->setEnabled(false);
    if(money < 150) ui->pb_Tea->setEnabled(false);
    if(money < 200) ui->pb_Coke->setEnabled(false);
}

void Widget::on_pb_10_clicked()
{
    change_money(10);
    /*
    QMessageBox msg;
    QString ms = "abc";
    msg.information(nullptr, ms, "error2");
    */
    //QString - https://norux.me/33
    ui->lcdNumber->display(money);
}

void Widget::on_pb_50_clicked()
{
    change_money(50);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_100_clicked()
{
    change_money(100);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_500_clicked()
{
    change_money(500);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_Coffee_clicked()
{
    buy_drink(100);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_Tea_clicked()
{
    buy_drink(150);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_Coke_clicked()
{
    buy_drink(200);
    ui->lcdNumber->display(money);
}

void Widget::on_pb_Reset_clicked()
{

    QMessageBox msg;
    int num[4], coins[4]={500, 100, 50, 10};
    for(int i=0; i<4; i++){
        num[i] = money/coins[i];
        money = money%coins[i];
    }

    QString ms;
    ms.sprintf("500 : %d\n\n100 : %d\n\n50 : %d\n\n10 : %d\n", num[0], num[1], num[2], num[3]);

    msg.information(nullptr,"keep_the_change", ms);

    money = 0;
    ui->lcdNumber->display(money);
}
