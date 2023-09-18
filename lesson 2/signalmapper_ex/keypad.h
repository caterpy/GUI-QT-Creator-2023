
#ifndef KEYPAD_H
#define KEYPAD_H
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>
#include <QSignalMapper>
class keyPad : public QWidget
{
    Q_OBJECT
public:
    keyPad(QWidget *parent = 0);
    ~keyPad();
public slots:
    void testCapturedSignal(int digit_num);
signals:
       void digitClicked(int digit);
private:
       void createLayout(void);
       QGridLayout *gridLayout;
       QPushButton *button[10];
     QSignalMapper *signalMapper;
};
#endif
