#ifndef CODEXAMPLE_H
#define CODEXAMPLE_H
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QSize>
class codExample : public QWidget
{
    Q_OBJECT
public:
    codExample(QWidget *parent = 0);
    ~codExample();
private slots:
    void btnClicked(void);
private:
    QPushButton *clickbtn, *togglebtn, *flatbtn, *iconbtn;
    QHBoxLayout *hbox;
};
#endif // CODEXAMPLE_H
