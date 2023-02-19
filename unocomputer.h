#ifndef UNOCOMPUTER_H
#define UNOCOMPUTER_H

#include "unobase.h"

class unocomputer : public unobase
{
public:
    unocomputer();

private slots:
    void cardClick(card*);
};

#endif // UNOCOMPUTER_H
