#ifndef CODEXAMPLE_H
#define CODEXAMPLE_H
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
class codExample : public QWidget
{
    Q_OBJECT
public:
    codExample(QWidget *parent = 0);
    ~codExample();
private slots:
    void dispHovlink(QString a);
private:
    QLabel *label1, *label2;
    QVBoxLayout *vbox;
    QPixmap *pic;
};
#endif // CODEXAMPLE_H
