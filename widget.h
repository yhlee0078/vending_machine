#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int money = {0};
    void change_money(int n);

    void buy_drink(int n);

private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_pb_Coffee_clicked();

    void on_pb_Tea_clicked();

    void on_pb_Coke_clicked();
    void on_pb_Reset_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
