#include "codeexample.h"

CodeExample::CodeExample(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout();
    label = new QLabel("Hello World");
    button = new QPushButton("Hide Label");
    button1 = new QPushButton("quit"); //quit button
    flag = 0;
    showMessage = true; // Initialize message to true
    vbox->addWidget(label);
    vbox->addWidget(button);
    vbox->addWidget(button1); // adds quit button to the layout
    setLayout(vbox);

    connect(button, SIGNAL(clicked()), this, SLOT(buttonPressed()));
    connect(button1, SIGNAL(clicked()), this, SLOT(close())); // connect quit button
}

CodeExample::~CodeExample()
{
}

void CodeExample::buttonPressed()
{
    if (showMessage) {
        label->setText("bruh"); // text 1
    } else {
        label->setText("wow"); //text2
    }

    showMessage = !showMessage; // toggle msg
}
