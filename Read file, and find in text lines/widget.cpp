#include "widget.h"
#include "ui_widget.h"
#include <QAction>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    creatEditLable();
    creatTextBrowser();
    creatFindBox();
    createMenu();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(edit_box);
    mainLayout->addWidget(text_box);
    mainLayout->addWidget(find_box);


    setLayout(mainLayout);
    setWindowTitle(tr("Main Box"));
}

void        Widget::readFile()
{
    QFile file(file_name);
    if (file.open(QFile::ReadOnly | QFile::Text)){
            label_file_name->setText(file_name);
            QTextStream ReadFile(&file);
            browser->setPlainText(ReadFile.readAll());
    }
    else
        browser->setPlainText("Can't read file : " + file_name);
}

void        Widget::pressed()
{
    file_name = line->text();
    line->setText("");
    readFile();
}

void    Widget::pressedFind()
{
    find_text = find_line->text();
    find_line->setText("");
    QString text = browser->toHtml();
    if (text.contains(find_text)){
        text = text.replace(find_text, "<font color = red>" + find_text + "</font size = 11 >");
        browser->setHtml(text);
    }
    else
        find_line->setText("None");
}

void  Widget::createMenu()
{
    QAction *clear_action = new QAction(tr("&Clear"));
    QAction *exit_action = new QAction(tr("&Exit"));
    QAction *reset_action = new QAction(tr("&Reset"));
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&Help Menu"), this);
    fileMenu->addAction(clear_action);
    fileMenu->addAction(exit_action);
    fileMenu->addAction(reset_action);
    menuBar->addMenu(fileMenu);
    connect(clear_action, SIGNAL(triggered()), this, SLOT(clearAction()));
    connect(exit_action, SIGNAL(triggered()), this, SLOT(exitAction()));
    connect(reset_action, SIGNAL(triggered()), this, SLOT(resetAction()));
}

void  Widget::clearAction()
{
    browser->setHtml(tr("ReadFile.readAll()"));
    label_file_name->setText(tr("File : "));
}

void  Widget::exitAction()
{
    QCoreApplication::quit();
}

void  Widget::resetAction()
{
    if (!file_name.isEmpty())
        readFile();
}

void        Widget::creatEditLable()
{
    edit_box =      new QGroupBox(tr("&Edit Box"));
    label =         new QLabel();
    info_lable =    new QLabel("File name : ");
    line =          new QLineEdit(this);
    layout =        new QHBoxLayout();

    label->setBuddy(line);
    layout->addWidget(info_lable);
    layout->addWidget(line);
    edit_box->setLayout(layout);
    connect(line, SIGNAL(returnPressed()), this, SLOT(pressed()));
}

void        Widget::creatFindBox()
{
    hlayout =           new QHBoxLayout();
    find_lable =        new QLabel();
    find_line =         new QLineEdit();
    info_find =         new QLabel(tr("Find text :"));
    find_box =          new QGroupBox(tr("&Find box"));

    find_lable->setBuddy(find_line);
    hlayout->addWidget(info_find);
    hlayout->addWidget(find_line);
    find_box->setLayout(hlayout);
    connect(find_line, SIGNAL(returnPressed()), this, SLOT(pressedFind()));
}

void        Widget::creatTextBrowser()
{
    text_box =          new QGroupBox(tr("&Text Browser"));
    v_layout =          new QVBoxLayout();
    label_file_name =   new QLabel(tr("File :"));
    browser =           new QTextBrowser();

    label_file_name->setAlignment(Qt::AlignCenter);
    browser->setHtml(tr("ReadFile.readAll()"));
    v_layout->addWidget(label_file_name);
    v_layout->addWidget(browser);
    text_box->setLayout(v_layout);
}

Widget::~Widget()
{
    delete ui;
}
