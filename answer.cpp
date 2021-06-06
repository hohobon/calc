#include "answer.h"
#include "ui_answer.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "mainwindow.cpp"


answer::answer(Show Main, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::answer)
{
    ui->setupUi(this);
    window()->setWindowFlags(window()->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    connect(ui->OKbutton,SIGNAL(released()),this,SLOT(close()));
    ui->label_x1->setText(Main.labelX1);
    ui->label_x2->setText(Main.labelX2);
    ui->result_show->setText(Main.Discription);
    ui->result_show2->setText(Main.res1);
    ui->result_show3->setText(Main.res2);
}

answer::~answer()
{
    delete ui;
}
