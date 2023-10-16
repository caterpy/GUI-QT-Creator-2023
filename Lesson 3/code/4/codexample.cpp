#include "codexample.h"
codExample::codExample(QWidget *parent)
    : QWidget(parent)
{
    red = 0;green=0;blue=0;opacity=0;
    hbox = new QHBoxLayout();
    labelvbox = new QVBoxLayout();
    slidervbox = new QVBoxLayout();
    spinboxvbox = new QVBoxLayout();
    rlabel = new QLabel("red");
    glabel = new QLabel("green");
    blabel = new QLabel("blue");
    olabel = new QLabel("opacity");
    rslider = new QSlider(Qt::Horizontal); rslider->setMinimum(0); rslider->setMaximum(255);
    gslider = new QSlider(Qt::Horizontal); gslider->setMinimum(0); gslider->setMaximum(255);
    bslider = new QSlider(Qt::Horizontal); bslider->setMinimum(0); bslider->setMaximum(255);
    oslider = new QSlider(Qt::Horizontal); oslider->setMinimum(0); oslider->setMaximum(255);
    rspinbox = new QSpinBox(); rspinbox->setMinimum(0); rspinbox->setMaximum(255);
    gspinbox = new QSpinBox(); gspinbox->setMinimum(0); gspinbox->setMaximum(255);
    bspinbox = new QSpinBox(); bspinbox->setMinimum(0); bspinbox->setMaximum(255);
    ospinbox = new QSpinBox(); ospinbox->setMinimum(0); ospinbox->setMaximum(255);
    labelvbox->addWidget(rlabel); labelvbox->addWidget(glabel); labelvbox->addWidget(blabel); labelvbox->addWidget(olabel);
    slidervbox->addWidget(rslider); slidervbox->addWidget(gslider); slidervbox->addWidget(bslider); slidervbox->addWidget(oslider);
    spinboxvbox->addWidget(rspinbox); spinboxvbox->addWidget(gspinbox); spinboxvbox->addWidget(bspinbox); spinboxvbox->addWidget(ospinbox);
    hbox->addLayout(labelvbox); hbox->addLayout(slidervbox); hbox->addLayout(spinboxvbox);
    setLayout(hbox);
    connect(rslider,SIGNAL(valueChanged(int)),rspinbox,SLOT(setValue(int)));
    connect(gslider,SIGNAL(valueChanged(int)),gspinbox,SLOT(setValue(int)));
    connect(bslider,SIGNAL(valueChanged(int)),bspinbox,SLOT(setValue(int)));
    connect(oslider,SIGNAL(valueChanged(int)),ospinbox,SLOT(setValue(int)));

    connect(rspinbox,SIGNAL(valueChanged(int)),this,SLOT(setRed(int)));
    connect(gspinbox,SIGNAL(valueChanged(int)),this,SLOT(setGreen(int)));
    connect(bspinbox,SIGNAL(valueChanged(int)),this,SLOT(setBlue(int)));
    connect(ospinbox,SIGNAL(valueChanged(int)),this,SLOT(setOpacity(int)));

    //added code spin box to slider val
    connect(rspinbox,SIGNAL(valueChanged(int)),rslider,SLOT(setValue(int)));
    connect(gspinbox,SIGNAL(valueChanged(int)),gslider,SLOT(setValue(int)));
    connect(bspinbox,SIGNAL(valueChanged(int)),bslider,SLOT(setValue(int)));
    connect(ospinbox,SIGNAL(valueChanged(int)),bslider,SLOT(setValue(int)));

}
codExample::~codExample()
{
}
void codExample::updateBackgroundColor(void){
    color.setRgb(red,green,blue,opacity);
    pal.setColor(QPalette::Window,color);
    this->setPalette(pal);
}
void codExample::setRed(int r){
    red = r;
    updateBackgroundColor();
}
void codExample::setGreen(int g){
    green = g;
    updateBackgroundColor();
}
void codExample::setBlue(int b){
    blue = b;
    updateBackgroundColor();
}
void codExample::setOpacity(int o){
    opacity=o;
    updateBackgroundColor();
}
