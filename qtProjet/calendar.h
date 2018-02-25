#ifndef CALENDAR_H
#define CALENDAR_H

#include <QWidget>

#include <QCalendarWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QDate>
#include <QDateEdit>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QtWidgets>

class Calendar: public QDialog
{
    Q_OBJECT

public:
    Calendar();

private slots:
    void currentTimeClicked();
    void annulerClicked();

private:
    void createPreviewGroupBox();
    void createNavigationGroupBox();

    QCalendarWidget *calendar;

    QGridLayout *previewLayout;

    QGroupBox *previewGroupBox;
    QGroupBox *navigationGroupBox;

    QPushButton *todayButton;
    QPushButton *annulerButton;
    QPushButton *validerButton;
};

#endif // CALENDAR_H
