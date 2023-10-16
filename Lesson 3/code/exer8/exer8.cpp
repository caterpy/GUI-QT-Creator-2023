#include "exer8.h"
exer8::exer8(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout(); //vbox layout
    pic = new QPixmap("colon3.png"); //adds the silly pic to pic object
    label = new QLabel();
    label->setPixmap(*pic);
    vbox->addWidget(label);
    setLayout(vbox);

}
//destruct
exer8::~exer8()
{
}
