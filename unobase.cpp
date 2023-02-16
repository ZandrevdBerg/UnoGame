#include "unobase.h"
#include <QPixmap>

unobase::unobase(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1000,800);



    initCards();
    showDeck();
}

unobase::~unobase()
{
}

void unobase::initCards()
{
    card *c;
    for (int i = 0; i < 10; ++i)
    {
        c = new card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i), Red);
    }

    c = new card(this);
    c->setup("+2",Red);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("",Red);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("sk",Red);
    c->hide();
    deck.append(c);


    for(int i = 0; i < 10; i++)
    {
        c = new card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i),Blue);

    }

    c = new card(this);
    c->setup("+2",Blue);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("",Blue);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("sk",Blue);
    c->hide();
    deck.append(c);

    for(int i = 0; i < 10; i++)
    {
        c = new card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i),Green);

    }

    c = new card(this);
    c->setup("+2",Green);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("",Green);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("sk",Green);
    c->hide();
    deck.append(c);


    for(int i = 0; i < 10; i++)
    {
        c = new card(this);
        deck.append(c);
        c->hide();
        c->setup(QString::number(i),Yellow);

    }

    c = new card(this);
    c->setup("+2",Yellow);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("",Yellow);
    c->hide();
    deck.append(c);
    c = new card(this);
    c->setup("sk",Yellow);
    c->hide();
    deck.append(c);


    for(int i = 0; i < 2; i++)
    {
        c = new card(this);
        c->hide();
        deck.append(c);
        c->setup("+4",None);

    }
    for(int i = 0; i < 2; i++)
    {
        c = new card(this);
        c->hide();
        deck.append(c);
        c->setup("",None);

    }
}

void unobase::showDeck()
{
    int x = 0;
    int y = 0;
    QListIterator<card*> deckIterator(deck);
    while (deckIterator.hasNext())
    {
        card *c = deckIterator.next();
        c->move(70*x, 102*y);
        c->show();
        ++x;
        if (x == 11)
        {
            ++y;
            x = 0;
        }
    }
}
