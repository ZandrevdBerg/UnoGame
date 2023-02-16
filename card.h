#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QString>
#include <QMouseEvent>
#include <QLabel>

enum Colour
{
    Red = 0,
    Blue,
    Green,
    Yellow,
    None
};

class card : public QWidget
{
    Q_OBJECT
public:
    card(QWidget *parent = nullptr);
    void setup(QString, Colour);
    QString cardName();
    QString cardColour();
    void ShowFront();
    void ShowBack();
private:
    QString name;
    QString colour;
    QLabel *card_front;
    QLabel *card_back;
};




#endif // CARD_H
