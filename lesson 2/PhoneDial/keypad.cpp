#include "keypad.h"
keyPad::keyPad(QWidget *parent)
    : QWidget(parent)
{
    signalMapper= new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SIGNAL(digitClicked(int)));
    createLayout();
    for (int i = 0; i < 10; ++i) {
        signalMapper->setMapping(button[i], i);
        connect(button[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
    }
}
keyPad::~keyPad()
{
}
void keyPad::createLayout(){
    gridLayout = new QGridLayout();
    for(int i=1; i<10 ; i++){
        button[i] = new QPushButton(QString::number(i));
        gridLayout->addWidget(button[i],((i-1)/3),((i-1)%3));
    }
    button[0] = new QPushButton(QString::number(0));
    gridLayout->addWidget(button[0],3,1);
    setLayout(gridLayout);
}