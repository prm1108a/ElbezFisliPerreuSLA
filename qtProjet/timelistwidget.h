#ifndef TIMELISTWIDGET_H
#define TIMELISTWIDGET_H

#include <iostream>
#include <QWidget>
#include <QTreeWidget>
#include <QCalendarWidget>
#include <time.h>
#include <QGridLayout>
#include <QPushButton>
using namespace std;

class TimeLine : public QTreeWidget
{
    Q_OBJECT
public:
    TimeLine(QWidget *parent = 0);
    QDate getCurrentDate();
    void updateTimeLine(int sYear, QString sMonth, QString sWeek, QString sDay);
    void setNbAnnees(int n);
    void setNbHuits(int n);
    int getNbAnnees();
    int getNbHuits();
    QString applyMajuscule(QString s);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void drawBranches(QPainter *, const QRect &, const QModelIndex &)const override;
    bool estUnHuit(string name);
private:
    QString trois_huits[3];
    QString deux_huits[2];
    int NB_ANNEES = 1;
    QString annee_deb;
    int NB_HUITS = 2;
    QDate currentDate;
    QString semaine = "Semaine ";
};

#endif // TIMELISTWIDGET_H
