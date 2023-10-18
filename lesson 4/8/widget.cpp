#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    vboxlbl = new QVBoxLayout();
    vboxfield = new QVBoxLayout();
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout();
    namelbl = new QLabel("Name:           ");
    staddrlbl = new QLabel("Street Address: ");
    provlbl = new QLabel("Province:       ");
    postlbl = new QLabel("Postal Code:    ");
    countrylbl = new QLabel("Country:        ");
    senderiplbl = new QLabel("Sender IP:      ");
    senderportlbl = new QLabel("Sender Port:    ");
    recvstatuslbl = new QLabel("Received:       ");
    nameedt = new QLineEdit();
    straddredt = new QLineEdit();
    postedt = new QLineEdit();
    postalcoderegexp = new QRegExpValidator(QRegExp("[A-Za-z]{1}[0-9]{1}[A-Za-z]{1} [0-9]{1}[A-Za-z]{1}[0-9]{1}"));
    postedt->setValidator(postalcoderegexp);
    countryedt = new QLineEdit();
    countryedt->setReadOnly(true);
    countryedt->setText("Canada");
    senderipedt = new QLineEdit();
    senderportedt = new QLineEdit();
    sendbtn = new QPushButton("Send Address");
    provbox = new QComboBox();
    QStringList provStrList = {"AB", "BC", "MB", "NB", "NL", "NS", "NT", "NU", "ON", "PE", "QC", "SK", "YT"};
    provbox->addItems(provStrList);

    vboxlbl->addWidget(namelbl);
    vboxlbl->addWidget(staddrlbl);
    vboxlbl->addWidget(provlbl);
    vboxlbl->addWidget(postlbl);
    vboxlbl->addWidget(countrylbl);
    vboxlbl->addWidget(senderiplbl);
    vboxlbl->addWidget(senderportlbl);
    vboxfield->addWidget(nameedt);
    vboxfield->addWidget(straddredt);
    vboxfield->addWidget(provbox);
    vboxfield->addWidget(postedt);
    vboxfield->addWidget(countryedt);
    vboxfield->addWidget(senderipedt);
    vboxfield->addWidget(senderportedt);
    hbox->addLayout(vboxlbl);
    hbox->addLayout(vboxfield);
    vbox->addLayout(hbox);
    vbox->addWidget(sendbtn);
    vbox->addWidget(recvstatuslbl);
    setLayout(vbox);
    okcount = 0;

    udpSocket = new QUdpSocket(this);
    bool result = udpSocket->bind(QHostAddress::AnyIPv4, 8877, QUdpSocket::ShareAddress);
    qDebug() << result;
    if (result) {
        qDebug() << "PASS";
    } else {
        qDebug() << "FAIL";
    }
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readUDPDatareceived()));
    connect(sendbtn, SIGNAL(clicked()), this, SLOT(sendJsonUdp()));
}

Widget::~Widget() {}

void Widget::sendJsonUdp(void)
{
    QJsonObject objJson;
    objJson.insert("Name", nameedt->text());
    objJson.insert("Street Address", straddredt->text());
    objJson.insert("Province", provbox->currentText());
    objJson.insert("Postal Code", postedt->text());
    objJson.insert("Country", countryedt->text());
    objJson.insert("Quote", "IT WAS A MISINPUT!!!!"); // Add the "Quote" field with your desired quote.

    QJsonDocument docJson;
    docJson.setObject(objJson);
    QByteArray byteArray = docJson.toJson(QJsonDocument::Compact);
    qDebug() << byteArray << endl;
    unsigned short port = senderportedt->text().toUShort();
    QHostAddress address;
    address.setAddress(senderipedt->text());
    udpSocket->writeDatagram(byteArray.data(), byteArray.size(), address, port);
}

void Widget::readUDPDatareceived(void)
{
    qDebug() << "received datagram" << endl;
    while (udpSocket->hasPendingDatagrams()) {
        qDebug() << "found pending datagram" << endl;
        QNetworkDatagram datagram = udpSocket->receiveDatagram();
        qDebug() << datagram.data() << endl;
        QJsonDocument document = QJsonDocument::fromJson(datagram.data());
        QJsonObject jsonObj = document.object();
        QString ackMsg = jsonObj["Acknowledged"].toString();
        qDebug() << ackMsg << endl;
        if (ackMsg == "OK")
            okcount++;
        recvstatuslbl->setText("Received: " + ackMsg + " " + QString::number(okcount));
    }
}
