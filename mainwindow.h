#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QDebug>
#include <QLineEdit>
#include <QKeyEvent>
#include <answer.h>
#include <ui_mainwindow.h>

struct Show
{
   QString Discription,labelX1,labelX2,res1,res2 ;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected slots:
    bool eventFilter(QObject* sender, QEvent* event) {
        if (event->type() == QEvent::FocusIn) {
            currentSelected = (QLineEdit*)sender;
        }
        return false;
    }

private:
    double A,B,C;
    QLineEdit* currentSelected = nullptr;
    Ui::MainWindow *ui;

public slots:
    void digit_numbers();
    void ACbutton();
    void Cbutton();
    void start_btn1();
    //void on_change_window_released();
};
#endif // MAINWINDOW_H
