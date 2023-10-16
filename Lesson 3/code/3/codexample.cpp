#include "codexample.h"
codExample::codExample(QWidget *parent)
    : QWidget(parent)
{
    vbox = new QVBoxLayout();
    pic = new QPixmap("smiley.png");
    label1 = new QLabel("<a href=\"http://www.youtube.com/watch?v=yMe7mlRv8UE/\">These Pretzels are making me thristy!</a>");
    label1->setTextFormat(Qt::RichText);
    label1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    label1->setOpenExternalLinks(true);
    label2 = new QLabel();
    label2->setPixmap(*pic);
    vbox->addWidget(label1);
    vbox->addWidget(label2);
    setLayout(vbox);
    connect(label1,SIGNAL(linkHovered(QString)),this,SLOT(dispHovlink(QString)));
}
codExample::~codExample()
{
}
void codExample::dispHovlink(QString a){
        QMessageBox::information(this,"Link Hovered",a);
}
