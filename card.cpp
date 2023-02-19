#include "card.h"
#include <QPixmap>

card::card(QWidget *parent) : QWidget(parent)
{
    card_front  = new QLabel(this);
    setFixedSize(130,186);
    card_front->setFixedSize(130,186);
    card_front->setAlignment(Qt::AlignCenter);
    card_front->setText("??");
    card_front->show();

    card_back = new QLabel(this);
    card_back->setFixedSize(130,186);
    card_back->setAlignment(Qt::AlignCenter);
    QPixmap pic(":/Art/UNO-Back.png");
    pic = pic.scaled(card_back->size(),Qt::KeepAspectRatio);
    card_back->setPixmap(pic);
    card_back->hide();


}

void card::setup(QString text,Colour clr)
{
    name = text;
    card_front->setText(text);
    switch(clr)
    {
    case Red:;
        colour = "Red";
        break;
    case Green:
        colour = "Green";
        break;
    case Yellow:
        colour = "Yellow";
        break;
    case Blue:
        colour = "Blue";
        break;
    case None:
        colour = "None";
        break;
    }
    if(colour == "Red")
    {
        QString s(":/Art/"+colour+"/"+name+".png");
        QPixmap pic(s);
        pic = pic.scaled(card_front->size(),Qt::KeepAspectRatio);
        card_front->setPixmap(pic);
    }
    else if(colour == "Green")
    {
        QString s(":/Art/"+colour+"/"+name+".png");
        QPixmap pic(s);
        pic = pic.scaled(card_front->size(),Qt::KeepAspectRatio);
        card_front->setPixmap(pic);
    }
    else if(colour == "Blue")
    {
        QString s(":/Art/"+colour+"/"+name+".png");
        QPixmap pic(s);
        pic = pic.scaled(card_front->size(),Qt::KeepAspectRatio);
        card_front->setPixmap(pic);
    }
    else if(colour == "Yellow")
    {
        QString s(":/Art/"+colour+"/"+name+".png");
        QPixmap pic(s);
        pic = pic.scaled(card_front->size(),Qt::KeepAspectRatio);
        card_front->setPixmap(pic);
    }
    else if(colour == "None")
    {
        QString s(":/Art/"+colour+"/"+name+".png");
        QPixmap pic(s);
        pic = pic.scaled(card_front->size(),Qt::KeepAspectRatio);
        card_front->setPixmap(pic);
    }


}

QString card::cardName()
{
    return name;
}

QString card::cardColour()
{
    return colour;
}

void card::ShowFront()
{
    card_back->hide();
    show();
    card_front->show();
}

void card::ShowBack()
{
    card_back->show();
    show();
    card_front->hide();
}

void card::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        emit iWasClicked(this);
    }
}
