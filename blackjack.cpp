#include "blackjack.h"
#include "ui_blackjack.h"

blackjack::blackjack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::blackjack)
{
    ui->setupUi(this);
}

blackjack::~blackjack()
{
    delete ui;
}

