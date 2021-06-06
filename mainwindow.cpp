#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <QDoubleValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn0,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn1,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn2,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn3,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn4,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn5,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn6,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn7,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn8,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn9,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->btn_point,SIGNAL(released()),this,SLOT(digit_numbers()));
    connect(ui->start_btn,SIGNAL(released()),this,SLOT(start_btn1()));
    connect(ui->btnAC,SIGNAL(released()),this,SLOT(ACbutton()));
     connect(ui->btnC,SIGNAL(released()),this,SLOT(Cbutton()));

    ui->K1->installEventFilter(this);
    ui->K2->installEventFilter(this);
    ui->K3->installEventFilter(this);
    ui->K1->setValidator(new QDoubleValidator(0, 10, 5, this));
    ui->K2->setValidator(new QDoubleValidator(0, 10, 5, this));
    ui->K3->setValidator(new QDoubleValidator(0, 10, 5, this));

    window()->setWindowFlags(window()->windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    setWindowIcon(QIcon(":/pics/png-transparent-sakura-samurai-art-of-the-sword-cherry-blossom-pink-cherry-cdr-leaf-heart.png"));


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: digit_numbers()
{
    if (!currentSelected) return;
    QPushButton * button = (QPushButton*)sender();

    QString text = currentSelected->text();

    currentSelected->setText(text + button->text());
}

void MainWindow::start_btn1()
{
    Show Main;
    A = ui->K1->text().toDouble();
    if (ui->K2->text()=="") B = 0.0;
    else B = ui->K2->text().toDouble();
    if (ui->K3->text()=="") C = 0.0;
    else C = ui->K3->text().toDouble();
    if ((A == 0.0) & (B == 0.0))
    {
        Main.Discription = "Это не уравнение\nКоэфиценты A и B равны нулю";
        Main.labelX1 = "";
        Main.labelX2 = "";
        Main.res1 = "";
        Main.res2 = "";



    }
    else {

      if ((A == 0.0) | (ui->K1->text() == ""))
      {
          QMessageBox::StandardButton reply = QMessageBox::question(this,"Введен ноль","Коэффицент при x^2 равен нулю \n Решить как обычное уравнение?",QMessageBox::No | QMessageBox::Yes);
          if (reply == QMessageBox::Yes)
          {
              double x = -C/B;
              QString X = QString::number(x);
              Main.Discription = "это обычное уравнение \n 1 корень :";
              Main.labelX1 = "X =";
              Main.labelX2 = "";
              Main.res1 = X;
              Main.res2 = "";

          }
          else{
              Main.Discription = "Это обычное кравнение уравнение\nКоэфиценты A и B равны нулю";
              Main.labelX1 = "";
              Main.labelX2 = "";
              Main.res1 = "";
              Main.res2 = "";
            }
      }


    else {
    QString txt,X1,X2,X1i,X2i;
    double x1, x2, x1i,x2i;


    double D = pow(B,2)-4*A*C;
    if (D > 0)
    {
        txt = "2 Корня :";
        x1 = (-B + sqrt(D))/2*A;
        X1 = QString::number(x1);
        x2 = (-B - sqrt(D))/2*A;
        X2 = QString::number(x2);
        Main.Discription = txt;
        Main.labelX1 = "X1 =";
        Main.labelX2 = "X2 =";
        Main.res1 = X1;
        Main.res2 = X2;
    }
        else if(D == 0.0)
    {
         txt = "2 одинаковых корня:";
         x1 = -B/2*A;
         X1 = QString::number(x1);
         Main.Discription = txt;
         Main.labelX1 = "X1|X2 =";
         Main.labelX2 = "";
         Main.res1 = "";
         Main.res2 = "";
    }
        else if(D < 0)
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this,"Отрицательный дискриминант","Хотите вычислить мнимые корни?",QMessageBox::No | QMessageBox::Yes);
        if (reply == QMessageBox::Yes)
        {
            D = -D;
            x1 = -B/2*A;
            X1 = QString::number(x1);
            x1i = sqrt(D)/2*A;
            X1i = QString::number(x1i);
            x2 = -B/2*A;
            X2 = QString::number(x2);
            x2i = -sqrt(D)/2*A;
            X2i = QString::number(x2i);
            Main.Discription = "Отрицательный дискриминант \n2 мнимых корня :";
            Main.labelX1 = "X1 =";
            Main.labelX2 = "X2 =";
            if (x1i < 0) { Main.res1 = X1 + " " + X1i + "*i";}
            else { Main.res1 = X1 + " + " + X1i + "*i";}
            if (x2i < 0) {Main.res2 = X2 + " " + X2i + "*i";}
            else {Main.res2 =X2 + " + " + X2i + "*i";}
        }
        else
        {
        txt = "Дискриминант меньше нуля \n действительных корней нет";
        Main.Discription = (txt);
        Main.labelX1 = "";
        Main.labelX2 = "";
        Main.res1 = "";
        Main.res2 = "";
        }

    }

}

}
    answer* ans = new answer(Main);
    ans->show();
}

void MainWindow ::ACbutton()
{
    ui->K1->setText("");
    ui->K2->setText("");
    ui->K3->setText("");
}
void MainWindow::Cbutton()
{
    if (!currentSelected) return;
    QPushButton * button = (QPushButton*)sender();
 
    QString text = currentSelected->text();

    currentSelected->setText("");
}




