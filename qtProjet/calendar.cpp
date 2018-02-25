#include "calendar.h"

Calendar::Calendar()
{
    createPreviewGroupBox();
    createNavigationGroupBox();

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(previewGroupBox, 0, 0);
    layout->addWidget(navigationGroupBox, 0, 1);
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    previewLayout->setRowMinimumHeight(0, calendar->sizeHint().height());
    previewLayout->setColumnMinimumWidth(0, calendar->sizeHint().width());

    setWindowTitle(tr("Calendrier"));
}

void Calendar::createPreviewGroupBox()
{
    previewGroupBox = new QGroupBox(tr("Preview"));

    calendar = new QCalendarWidget;
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);
    previewLayout = new QGridLayout;
    previewLayout->addWidget(calendar, 0, 0, Qt::AlignCenter);
    previewGroupBox->setLayout(previewLayout);
}

void Calendar::createNavigationGroupBox()
{
    navigationGroupBox = new QGroupBox(tr("Navigation"));

    todayButton = new QPushButton;
    todayButton->setText("Aujourd'hui");
    connect(todayButton, SIGNAL (released()), this, SLOT (currentTimeClicked()));

    validerButton = new QPushButton;
    validerButton->setText("Valider");

    annulerButton = new QPushButton;
    annulerButton->setText("Annuler");

    QGridLayout *navigationLayout = new QGridLayout;
    navigationLayout->addWidget(todayButton, 0, 0, Qt::AlignLeft);
    navigationLayout->addWidget(validerButton, 1, 0, Qt::AlignLeft);
    navigationLayout->addWidget(annulerButton, 1, 1, Qt::AlignLeft);
    navigationGroupBox->setLayout(navigationLayout);
}

void Calendar::currentTimeClicked()
{
    calendar->setSelectedDate(QDate::currentDate());
}

void Calendar::annulerClicked()
{

}

