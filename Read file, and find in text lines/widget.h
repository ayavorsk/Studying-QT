#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <QGroupBox>
#include <QFile>
#include <QTextStream>
#include <QMenuBar>
#include <QMenu>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void     creatEditLable();
    void     creatTextBrowser();
    void     creatFindBox();
    void     readFile();
    void     onClick();
    void     createMenu();
    ~Widget();
public slots :
    void    pressed();
    void    pressedFind();
    void    clearAction();
    void    exitAction();
    void    resetAction();

private:
    Ui::Widget      *ui;
    QLabel          *label;
    QLabel          *label_file_name;
    QLabel          *info_lable;
    QLineEdit       *line;
    QHBoxLayout     *layout;
    QVBoxLayout     *v_layout;
    QTextBrowser    *browser;
    QString         file_name;
    QString         find_text;
    QGroupBox       *edit_box;
    QGroupBox       *find_box;
    QGroupBox       *text_box;
    QLabel          *find_lable;
    QLineEdit       *find_line;
    QLabel          *info_find;
    QHBoxLayout     *hlayout;
    QMenuBar        *menuBar;
    QMenu           *fileMenu;
};


#endif // WIDGET_H
