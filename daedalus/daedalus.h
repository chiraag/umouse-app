#ifndef DAEDALUS_H
#define DAEDALUS_H

#include <QtGui/QMainWindow>
#include "ui_daedalus.h"

class daedalus : public QMainWindow
{
    Q_OBJECT

public:
    daedalus(QWidget *parent = 0);
    ~daedalus();

private:
    Ui::daedalusClass ui;
};

#endif // DAEDALUS_H
