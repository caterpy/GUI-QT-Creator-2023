#ifndef PHONEDIAL_H
#define PHONEDIAL_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include "keypad.h"

class PhoneDial : public QWidget
{
    Q_OBJECT

public:
    PhoneDial(QWidget *parent = nullptr);
    ~PhoneDial();

private slots:
    void handleDigitClicked(int digit);
    void handleClearClicked();

protected:
    void keyPressEvent(QKeyEvent *event); // Re-implement keyPressEvent

private:
    QLineEdit *lineEdit;
    keyPad *customKeypad;
    QPushButton *clearButton;
};

#endif // PHONEDIAL_H
