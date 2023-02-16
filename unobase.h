#ifndef UNOBASE_H
#define UNOBASE_H

#include <QMainWindow>
#include <card.h>
#include <QList>
#include <QDebug>


class unobase : public QMainWindow
{
    Q_OBJECT

public:
    unobase(QWidget *parent = nullptr);
    ~unobase();
    void initCards();
    void showDeck();
    void shuffleDeck();
private:
    QList<card*> deck;
};
#endif // UNOBASE_H
