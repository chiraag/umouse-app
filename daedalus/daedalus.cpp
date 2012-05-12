#include "daedalus.h"
#include <QDebug>
#include "qextserialenumerator.h"

daedalus::daedalus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QList<QextPortInfo> ports = QextSerialEnumerator::getPorts();
    qDebug() << "List of ports:";
    for (int i = 0; i < ports.size(); i++) {
        qDebug() << "port name:" << ports.at(i).portName;
        qDebug() << "friendly name:" << ports.at(i).friendName;
        qDebug() << "physical name:" << ports.at(i).physName;
        qDebug() << "enumerator name:" << ports.at(i).enumName;
        qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
        qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);
        qDebug() << "===================================";
    }
}

daedalus::~daedalus()
{

}

void daedalus::on_modeCBox_currentIndexChanged(const QString & choice)
{
	if(choice == "Live Mode"){
		ui.liveGBox->setEnabled(true);
		ui.simGBox->setEnabled(false);
	}else if (choice == "Simulation"){
		ui.liveGBox->setEnabled(false);
		ui.simGBox->setEnabled(true);
	}
}

