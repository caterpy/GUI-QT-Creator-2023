#ifndef EXER8_H
#define EXER8_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
class exer8 : public QWidget
{
    Q_OBJECT
public:
    exer8(QWidget *parent = 0);
    ~exer8();

private:
    QLabel *label;
    QVBoxLayout *vbox;
    QPixmap *pic;
};

#endif // EXER8_H
