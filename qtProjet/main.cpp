#include <QApplication>
#include <QPushButton>
#include <window.h>
#include <QTabWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include <iostream>
#include <timelistwidget.h>
#include <boutonaujourdhui.h>
#include <boutonvalider.h>
#include <paramdialog.h>
#include <dateedit.h>
#include <boutonparam.h>
#include <boutonok.h>
using namespace std;


TimeLine * timeLine;
BoutonAujourdhui *buttonAujourdhui;
DateEdit *dateEdit;
BoutonValider *buttonValidate;
ParamDialog *paramDialog;
BoutonParam *boutonParam;
BoutonOk *boutonOk;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFont font("Helvetica", 14, QFont::Normal);

    QHBoxLayout *layoutWindow = new QHBoxLayout;
    QVBoxLayout *layoutLeftWindow = new QVBoxLayout;
    QHBoxLayout *layoutSearchZone = new QHBoxLayout;

    timeLine = new TimeLine;

    paramDialog = new ParamDialog;
    paramDialog->setNbAnnees(timeLine->getNbAnnees());
    paramDialog->setNbHuits(timeLine->getNbHuits());
    boutonOk = new BoutonOk;
    paramDialog->addButtonToLayout(boutonOk);

    dateEdit = new DateEdit;
    dateEdit->setDate(timeLine->getCurrentDate());

    buttonAujourdhui = new BoutonAujourdhui;
    buttonValidate = new BoutonValider;
    boutonParam = new BoutonParam;

    layoutSearchZone->addWidget(dateEdit);
    layoutSearchZone->addWidget(buttonAujourdhui);
    layoutSearchZone->addWidget(buttonValidate);
    layoutSearchZone->addWidget(boutonParam);

    layoutLeftWindow->addLayout(layoutSearchZone);
    layoutLeftWindow->addWidget(timeLine);

    QTabWidget * tab = new QTabWidget;
    tab->addTab(new QLabel("Tableau de bord"), "Tableau de bord");
    tab->addTab(new QLabel("Performances"), "Performances");
    tab->addTab(new QLabel("Historique"), "Historique");
    tab->addTab(new QLabel("Configuration"), "Configuration");
    tab->setTabIcon(0,*(new QIcon(QApplication::applicationDirPath() + "/agenda.png")));
    tab->setTabIcon(1,*(new QIcon(QApplication::applicationDirPath() + "/performances.png")));
    tab->setTabIcon(2,*(new QIcon(QApplication::applicationDirPath() + "/historique.png")));
    tab->setTabIcon(3,*(new QIcon(QApplication::applicationDirPath() + "/configuration.png")));
    tab->setFont(font);
    layoutWindow->addLayout(layoutLeftWindow);
    layoutWindow->addWidget(tab);

    QWidget * windowWidget = new QWidget;
    windowWidget->setLayout(layoutWindow);
    windowWidget->showMaximized();
    windowWidget->setWindowTitle("Outil de Supervision de Lignes d'Assemblage");

    return app.exec();
}


void BoutonAujourdhui::mouseReleaseEvent(QMouseEvent *event)
{
    QDateTime dateToday = QDateTime::currentDateTime();
    int sYear = dateToday.date().year();
    QString sMonth = dateToday.date().longMonthName(dateToday.date().month()) + " " + QString::number(dateToday.date().year());
    sMonth= timeLine->applyMajuscule(sMonth);
    QString sWeek = "Semaine " + QString::number(dateToday.date().weekNumber());
    QString sDay = dateToday.date().longDayName(dateToday.date().dayOfWeek()) + " " + QString::number(dateToday.date().day());
    sDay = timeLine->applyMajuscule(sDay);
    timeLine->updateTimeLine(sYear, sMonth, sWeek, sDay);
    dateEdit->setDate(dateToday.date());
}

void BoutonValider::mouseReleaseEvent(QMouseEvent *event)
{
    int sYear = dateEdit->date().year();
    QString sMonth = dateEdit->date().longMonthName(dateEdit->date().month()) + " " + QString::number(dateEdit->date().year());
    sMonth = timeLine->applyMajuscule(sMonth);
    QString sWeek = "Semaine " + QString::number(dateEdit->date().weekNumber());
    QString sDay = dateEdit->date().longDayName(dateEdit->date().dayOfWeek()) + " " + QString::number(dateEdit->date().day());
    sDay = timeLine->applyMajuscule(sDay);
    timeLine->updateTimeLine(sYear, sMonth, sWeek, sDay);
}

void BoutonParam::mouseReleaseEvent(QMouseEvent *event)
{
    paramDialog->show();
}

void BoutonOk::mouseReleaseEvent(QMouseEvent *event)
{
    paramDialog->setNbAnnees(paramDialog->getNbAnnees());
    paramDialog->setNbHuits(paramDialog->getNbHuits());
    timeLine->setNbAnnees(paramDialog->getNbAnnees());
    timeLine->setNbHuits(paramDialog->getNbHuits());
    int sYear = dateEdit->date().year();
    QString sMonth = dateEdit->date().longMonthName(dateEdit->date().month()) + " " + QString::number(dateEdit->date().year());
    sMonth = timeLine->applyMajuscule(sMonth);
    QString sWeek = "Semaine " + QString::number(dateEdit->date().weekNumber());
    QString sDay = dateEdit->date().longDayName(dateEdit->date().dayOfWeek()) + " " + QString::number(dateEdit->date().day());
    sDay = timeLine->applyMajuscule(sDay);
    timeLine->updateTimeLine(sYear, sMonth, sWeek, sDay);
    paramDialog->close();
}
