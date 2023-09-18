#include "phonedial.h"
#include <QKeyEvent>

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

void PhoneDial::keyPressEvent(QKeyEvent *event)
{
    // Check if the key event corresponds to a numeric key (0-9)
    if (event->key() >= Qt::Key_0 && event->key() <= Qt::Key_9) {
        // Get the numeric value from the key event
        int digit = event->key() - Qt::Key_0;

        // Append the digit to the text field
        lineEdit->setText(lineEdit->text() + QString::number(digit));
    }
    else if (event->key() == Qt::Key_Backspace) {
        // Handle backspace key to remove the last character
        QString currentText = lineEdit->text();
        if (!currentText.isEmpty()) {
            currentText.chop(1); // Remove the last character
            lineEdit->setText(currentText);
        }
    }
    else {
        // Call the base class implementation for other key events
        QWidget::keyPressEvent(event);
    }
}
