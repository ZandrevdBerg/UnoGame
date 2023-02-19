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
    void dealCards();
    void showLayout();
private:
    QList<card*> deck;
    QList<card*> stack;
    QList<card*> playerhand;
    QList<card*> computerhand;


    const bool debugView = false;

private slots:
    void cardClick(card*);
};
#endif // UNOBASE_H
