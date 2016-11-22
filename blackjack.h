#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <QWidget>

namespace Ui {
class blackjack;
}

class blackjack : public QWidget
{
    Q_OBJECT

public:
    explicit blackjack(QWidget *parent = 0);
    ~blackjack();

private:
    Ui::blackjack *ui;
};

#endif // BLACKJACK_H
