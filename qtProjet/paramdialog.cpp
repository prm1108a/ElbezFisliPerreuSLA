#include "paramdialog.h"

ParamDialog::ParamDialog()
{
    verticalLayout = new QVBoxLayout;
    horizontalLayout1 = new QHBoxLayout;
    horizontalLayout2 = new QHBoxLayout;

    nbAnnees = new QSpinBox;
    QLabel *labelAnnees = new QLabel;
    labelAnnees->setText("Nombre d'années : ");

    horizontalLayout1->addWidget(labelAnnees);
    horizontalLayout1->addWidget(nbAnnees);

    nbHuits = new QSpinBox;
    QLabel *labelHuits = new QLabel;
    labelHuits->setText("Nombre de 8h : ");

    horizontalLayout2->addWidget(labelHuits);
    horizontalLayout2->addWidget(nbHuits);

    verticalLayout->addLayout(horizontalLayout1);
    verticalLayout->addLayout(horizontalLayout2);

    setLayout(verticalLayout);
    setWindowTitle("Paramètres");
    move(250, 60);
}

void ParamDialog::setNbAnnees(int n)
{
    Nb_Annees = n;
    nbAnnees->setValue(Nb_Annees);
}

void ParamDialog::setNbHuits(int n)
{
    Nb_Huits = n;
    nbHuits->setValue(Nb_Huits);
}

int ParamDialog::getNbAnnees()
{
    return nbAnnees->value();
}

int ParamDialog::getNbHuits()
{
    return nbHuits->value();
}

void ParamDialog::addButtonToLayout(QPushButton * b)
{
    verticalLayout->addWidget(b);
}
