#ifndef PARAMDIALOG_H
#define PARAMDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ParamDialog : public QDialog
{
public:
    ParamDialog();
    void setNbAnnees(int n);
    void setNbHuits(int n);
    void addButtonToLayout(QPushButton * b);
    int getNbAnnees();
    int getNbHuits();
private:
    int Nb_Annees;
    int Nb_Huits;
    QSpinBox *nbHuits;
    QSpinBox *nbAnnees;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout1;
    QHBoxLayout *horizontalLayout2;
};

#endif // PARAMDIALOG_H
