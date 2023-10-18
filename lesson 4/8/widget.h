#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QRegExpValidator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QDebug>
#include <QtNetwork>
#include <QUdpSocket>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void sendJsonUdp(void);
    void readUDPDatareceived(void);

private:
    QVBoxLayout *vbox, *vboxlbl, *vboxfield;
    QHBoxLayout *hbox;
    QLabel *namelbl, *staddrlbl, *provlbl, *postlbl, *countrylbl, *senderiplbl, *senderportlbl, *recvstatuslbl;
    QLineEdit *nameedt, *straddredt, *postedt, *countryedt, *senderipedt, *senderportedt;
    QPushButton *sendbtn;
    QComboBox *provbox;
    QRegExpValidator *postalcoderegexp;
    QUdpSocket *udpSocket;
    int okcount;
};

#endif // WIDGET_H
