#include "phonedial.h"

PhoneDial::PhoneDial(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout();

    lineEdit = new QLineEdit();
    layout->addWidget(lineEdit);

    customKeypad = new keyPad();
    layout->addWidget(customKeypad);

    clearButton = new QPushButton("Clear");
    layout->addWidget(clearButton);

    connect(customKeypad, SIGNAL(digitClicked(int)), this, SLOT(handleDigitClicked(int)));
    connect(clearButton, SIGNAL(clicked()), this, SLOT(handleClearClicked()));

    setLayout(layout);
}

PhoneDial::~PhoneDial()
{
}

void PhoneDial::handleDigitClicked(int digit)
{
    // Append the digit to the text field
    lineEdit->setText(lineEdit->text() + QString::number(digit));
}

void PhoneDial::handleClearClicked()
{
    // Clear the text field
    lineEdit->clear();
}
