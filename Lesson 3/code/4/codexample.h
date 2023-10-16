#ifndef CODEXAMPLE_H
#define CODEXAMPLE_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QString>
class codExample : public QWidget
{
    Q_OBJECT
public:
    codExample(QWidget *parent = 0);
    ~codExample();
    void updateBackgroundColor(void);
public slots:
    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    void setOpacity(int);
private:
    QLabel *rlabel, *glabel, *blabel, *olabel;
    QHBoxLayout *hbox;
    QVBoxLayout *labelvbox, *slidervbox, *spinboxvbox;
    QSpinBox *rspinbox, *gspinbox, *bspinbox, *ospinbox;
    QSlider *rslider, *gslider, *bslider, *oslider;
    QPalette pal;
    QColor color;
    int red, green, blue, opacity;
};
#endif // CODEXAMPLE_H
