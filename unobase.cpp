#include "unobase.h"
#include <QPixmap>
#include <QRandomGenerator>

unobase::unobase(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(1500,1200);



    initCards();


    shuffleDeck();
    //showDeck();
    dealCards();
    showLayout();


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

void unobase::dealCards()
{
    stack.clear();
    computerhand.clear();
    playerhand.clear();

    // Draw 7 cards each for the player and computer
    for (int i = 0; i < 7; i++)
    {
        playerhand.prepend(deck.takeFirst());
        computerhand.prepend(deck.takeFirst());
    }

    // Draw cards for the stack until a non-special card is drawn
    while (true)
    {
        if (deck.isEmpty())
        {
            // The deck is empty, so we can't draw any more cards
            break;
        }

        card *firstCard = deck.first();
        if (firstCard->cardName() == "" || firstCard->cardName() == "+2" || firstCard->cardName() == "+4" || firstCard->cardName() == "sk")
        {
            // This is a special card, so remove it from the deck and draw another card
            deck.append(deck.takeFirst());
        }
        else
        {
            // This is a non-special card, so add it to the stack
            stack.prepend(deck.takeFirst());
            break;
        }
    }
}




void unobase::showLayout()
{

    if (!playerhand.isEmpty())
    {
        for (int i = 0; i < playerhand.length(); i++) {
            card* c = playerhand.at(i);
            c->move(i * 136, height()-500);
            c->ShowFront();
            c->show();
        }
    }
    if (!computerhand.isEmpty())
    {
        for (int i = 0; i < computerhand.length(); i++) {
            card* c = computerhand.at(i);
            c->move(i * 136, 0);
            if(debugView)
            {
                c->ShowFront();
            }
            else
            {
                c->ShowBack();
            }
            c->show();
        }
    }
    if(!stack.isEmpty())
    {
        card *c = stack.first();
        c->move(width()/2-300, height()-800);
        c->show();
    }
    if(!deck.isEmpty())
    {
        card *c = deck.first();
        c->move(width()/2-150,height()-800);
        c->ShowBack();
        c->show();
    }

}

void unobase::cardClick(card *c)
{

}





