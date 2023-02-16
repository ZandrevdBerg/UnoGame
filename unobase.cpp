#include "unobase.h"
#include <QPixmap>
#include <QRandomGenerator>
#include <iostream>

unobase::unobase(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1500,1200);



    initCards();


    shuffleDeck();
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
    int cardWidth = deck[0]->width();
    int cardHeight = deck[0]->height();

    for (int i = 0; i < deck.size(); ++i)
    {
        card* c = deck[i];
        c->move(i % 11 * cardWidth, i / 11 * cardHeight);
        c->show();
    }
}


void unobase::shuffleDeck()
{
    int deck_length = deck.length();
    for (int i = deck_length - 1; i > 0; i--)
    {
        int j = QRandomGenerator::global()->bounded(i + 1);
        card* temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;

    }

}








