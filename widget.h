#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QString>
#include <QLineEdit>
#include <QString>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots :
    void    handleButton();
    void    resetAllButtons();
private:
    Ui::Widget *ui;
    QPushButton *reset;
    QPushButton *butoms_1;
    QPushButton *butoms_2;
    QPushButton *butoms_3;
    QPushButton *butoms_4;
    QPushButton *butoms_5;
    QPushButton *butoms_6;
    QPushButton *butoms_7;
    QPushButton *butoms_8;
    QPushButton *butoms_9;
    QGridLayout *layout;
    QGridLayout *player_layout;
    QLabel *Lable_1;
    QLabel *Lable_2;
    void    createConnectAndButtons();
    void    createLayout();
    bool player;
    int player_1_score;
    int player_2_score;
    bool player_1_turn;
};

#endif // WIDGET_H
