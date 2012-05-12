#include "daedalus.h"
#include <QDebug>

daedalus::daedalus(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    serport = new QextSerialPort(QextSerialPort::EventDriven);
    refreshPorts();
}

daedalus::~daedalus()
{
	delete serport;
}

void daedalus::refreshPorts()
{
	ui.portCBox->clear();
	portsList.clear();
    portsList = QextSerialEnumerator::getPorts();
    //qDebug() << "List of ports:";
    for (int i = 0; i < portsList.size(); i++) {
    	ui.portCBox->addItem(portsList.at(i).friendName);
    /*
        qDebug() << "port name:" << ports.at(i).portName;
        qDebug() << "friendly name:" << ports.at(i).friendName;
        qDebug() << "physical name:" << ports.at(i).physName;
        qDebug() << "enumerator name:" << ports.at(i).enumName;
        qDebug() << "vendor ID:" << QString::number(ports.at(i).vendorID, 16);
        qDebug() << "product ID:" << QString::number(ports.at(i).productID, 16);
        qDebug() << "===================================";
    */
    }


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

void daedalus::on_connectButton_clicked()
{
	QString portName = portsList.at(ui.portCBox->currentIndex()).physName;
	QString baudRateStr = ui.baudCBox->currentText();
	BaudRateType baudRate = BAUD9600;
	if(baudRateStr == "9600"){
		baudRate = BAUD9600;
	}else if(baudRateStr == "19200"){
		baudRate = BAUD19200;
	}else if(baudRateStr == "38400"){
		baudRate = BAUD38400;
	}else if(baudRateStr == "57600"){
		baudRate = BAUD57600;
	}else if(baudRateStr == "115200"){
		baudRate = BAUD115200;
	}

	if(!(serport->isOpen()))
	{
		serport->setPortName(portName);
		serport->setBaudRate(baudRate);
		serport->setFlowControl(FLOW_OFF);
		serport->setParity(PAR_NONE);
		serport->setDataBits(DATA_8);
		serport->setStopBits(STOP_1);

		if(serport->open(QIODevice::ReadWrite))
		{
			connect(serport, SIGNAL(readyRead()), this, SLOT(serportReadyRead()));
			qDebug() << "Listening for data on" << serport->portName();
			ui.connectButton->setText("Disconnect Device");
		}
		else
		{
			disconnect(serport, SIGNAL(readyRead()), this, SLOT(serportReadyRead()));
			qDebug() << "Device failed to open:" << serport->errorString();
		}
	}
	else
	{
		serport->close();
		qDebug() << "Closed port " << serport->portName();
		ui.connectButton->setText("Connect to Device");
	}

}

void daedalus::serportReadyRead()
{
    QByteArray bytes;
    int numBytes = serport->bytesAvailable();
    bytes.resize(numBytes);
    serport->read(bytes.data(), bytes.size());
    //qDebug() << "bytes read:" << bytes.size();

    bytesReceived.append(bytes);

    // only do input if all of it has been received.
    // without this the serial port transports line of messages
    // with only 3 or 4 bytes at a time
    if(bytes.contains('\n'))
    {
        qDebug() << QString::fromAscii(bytesReceived);
        bytesReceived.clear();
    }
}

