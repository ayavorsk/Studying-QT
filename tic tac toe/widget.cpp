#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    layout(new QGridLayout()),
    player_layout(new QGridLayout()),
    player_1_score(0) , player_2_score(0),
    player_1_turn(true), player(false)
{
    ui->setupUi(this);
    createConnectAndButtons();
    createLayout();
    setLayout(layout);
    setWindowTitle("Studying QT");
}

void    Widget::handleButton()
{
    QObject* button = QObject::sender();
    static_cast<QPushButton*>(button)->setText(player == false ? "X" : "O");
    static_cast<QPushButton*>(button)->setEnabled(false);
    player = (player == false ? player = true : player = false);
}

void    Widget::createConnectAndButtons()
{
    reset = new QPushButton("Clear");
    butoms_1 = new QPushButton();
    butoms_2 = new QPushButton();
    butoms_3 = new QPushButton();
    butoms_4 = new QPushButton();
    butoms_5 = new QPushButton();
    butoms_6 = new QPushButton();
    butoms_7 = new QPushButton();
    butoms_8 = new QPushButton();
    butoms_9 = new QPushButton();
    connect(butoms_1, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_2, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_3, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_4, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_5, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_6, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_7, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_8, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(butoms_9, SIGNAL (clicked()), this, SLOT (handleButton()));
    connect(reset, SIGNAL (clicked()), this, SLOT (resetAllButtons()));
}

void    Widget::createLayout()
{
    Lable_1 = new QLabel("Player 2 :    " + QString::number(player_1_score));
    Lable_2 = new QLabel("Player 2 :    " + QString::number(player_1_score));
    Lable_1->setGeometry(0, 0, 10, 10);
    Lable_1->setStyleSheet("color: rgb(255, 0, 0);");
    Lable_2->setGeometry(0, 0, 10, 10);
    player_layout->addWidget(Lable_1, 0, 1);
    player_layout->addWidget(Lable_2, 0, 2);
    layout->setHorizontalSpacing (0);
    layout->setVerticalSpacing(0);
    layout->addWidget(butoms_1, 2, 0);
    layout->addWidget(butoms_2, 2, 1);
    layout->addWidget(butoms_3, 2, 2);
    layout->addWidget(butoms_4, 3, 0);
    layout->addWidget(butoms_5, 3, 1);
    layout->addWidget(butoms_6, 3, 2);
    layout->addWidget(butoms_7, 4, 0);
    layout->addWidget(butoms_8, 4, 1);
    layout->addWidget(butoms_9, 4, 2);
    layout->addWidget(reset, 1, 1);
    layout->addLayout(player_layout, 0, 0, 1, 0);
}

void    Widget::resetAllButtons()
{
    butoms_1->setText("");
    butoms_2->setText("");
    butoms_3->setText("");
    butoms_4->setText("");
    butoms_5->setText("");
    butoms_6->setText("");
    butoms_7->setText("");
    butoms_8->setText("");
    butoms_9->setText("");
    butoms_1->setEnabled(true);
    butoms_2->setEnabled(true);
    butoms_3->setEnabled(true);
    butoms_4->setEnabled(true);
    butoms_5->setEnabled(true);
    butoms_6->setEnabled(true);
    butoms_7->setEnabled(true);
    butoms_8->setEnabled(true);
    butoms_9->setEnabled(true);
    player = false;
    if (player_1_turn == true){
        Lable_2->setStyleSheet("color: rgb(255, 0, 0);");
        Lable_1->setStyleSheet("color: rgb(0, 0, 0);");
        player_1_turn = false;
    }
    else{
        Lable_1->setStyleSheet("color: rgb(255, 0, 0);");
        Lable_2->setStyleSheet("color: rgb(0, 0, 0);");
        player_1_turn = true;
    }
}

Widget::~Widget()
{
    delete ui;
}
