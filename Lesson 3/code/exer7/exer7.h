#ifndef EXER7_H
#define EXER7_H

#include <QWidget>
#include <QProgressBar>
#include <QLCDNumber>
#include <QComboBox>
#include <QDial>
#include <QVBoxLayout>

class Exer7 : public QWidget
{
    Q_OBJECT

public:
    Exer7(QWidget *parent = 0);
    ~Exer7();

private:
    QVBoxLayout *layout; //vertical layout box
    QProgressBar *progressBar; // for the progress bar widget thing
    QComboBox *comboBox; //adds the combobox widget
    QDial *dial; //adds rotatry dial :D
    QLCDNumber *lcdNumber; //clock number digital thingyy!!!
};

#endif // EXER7_H
