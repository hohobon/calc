#ifndef ANSWER_H
#define ANSWER_H

#include <QDialog>

struct Show;

namespace Ui {
class answer;
}

class answer : public QDialog
{
    Q_OBJECT

public:
    explicit answer(Show Main, QWidget *parent = nullptr);
    ~answer();

private:
    Ui::answer *ui;
};

#endif // ANSWER_H
