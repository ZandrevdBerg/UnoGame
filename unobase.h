#ifndef UNOBASE_H
#define UNOBASE_H

#include <QMainWindow>
#include <card.h>
#include <QList>



class unobase : public QMainWindow
{
    Q_OBJECT

public:
    unobase(QWidget *parent = nullptr);
    ~unobase();
    void initCards();
    void showDeck();
    //Do  Fisher-Yates shuffle next
    void shuffleCards();
private:
    QList<card*> deck;
};
#endif // UNOBASE_H
