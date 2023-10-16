#include "exer7.h"

Exer7::Exer7(QWidget *parent)
    : QWidget(parent)
{
    //set up constructors
    layout = new QVBoxLayout();
    progressBar = new QProgressBar();
    comboBox = new QComboBox();
    dial = new QDial();
    lcdNumber = new QLCDNumber();

    progressBar->setRange(0, 100); //sets range of progress(starts at 0 ends at 100%)
    progressBar->setValue(40); //how much progress is done(normally would make this value update from a different task (like download or whatever)

    //combobox item menuuuuu
    comboBox->addItem("bruh1");
    comboBox->addItem("bruh2");
    comboBox->addItem("bruh3");
    comboBox->addItem("spaghettii");

    //the digital number clock thingy lol
    lcdNumber->display(43770);

    //the knob :D
    dial->setRange(0, 100);
    dial->setValue(50);

    //add the widgets in the vbox layout thing
    layout->addWidget(dial);
    layout->addWidget(progressBar);
    layout->addWidget(lcdNumber);
    layout->addWidget(comboBox);

    //update layout
    setLayout(layout);
}
//destruct
Exer7::~Exer7()
{
}
