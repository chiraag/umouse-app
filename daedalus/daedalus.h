#ifndef DAEDALUS_H
#define DAEDALUS_H

#include <QtGui/QMainWindow>
#include <QEventLoop>
#include "ui_daedalus.h"
#include "qextserialport.h"
#include "qextserialenumerator.h"


class daedalus : public QMainWindow
{
    Q_OBJECT

public:
    daedalus(QWidget *parent = 0);
    ~daedalus();

private:
    void refreshPorts();

private:
    Ui::daedalusClass ui;
	QEventLoop serWaitLoop;
    QextSerialPort *serport;
    QList<QextPortInfo> portsList;
    QByteArray bytesReceived;
	bool bserialTimeout;

private slots:
	void on_modeCBox_currentIndexChanged(const QString &);
	void on_connectButton_clicked();
	void serportReadyRead();
};

#endif // DAEDALUS_H
