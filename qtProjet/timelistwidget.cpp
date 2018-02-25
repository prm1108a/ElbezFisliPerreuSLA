#include "timelistwidget.h"

TimeLine::TimeLine(QWidget *parent) : QTreeWidget(parent)
{
    setMaximumWidth(278);
    setMaximumHeight(700);
    setColumnCount(2);
    setColumnWidth(0, 160);
    setColumnWidth(1, 100);
    setRootIsDecorated(false);
    setIndentation(0);
    QGridLayout *layoutTimeLine = new QGridLayout;
    QString style = "QTreeWidget::item:selected"
                    "{"
                        "background-color: transparent; "
                        "color: black;"
                    "}"
                    "QTreeWidget"
                    "{"
                        "background-image: url(/home/mariep/workspace/build-qtProjet-Desktop_Qt_5_10_0_GCC_64bit-Debug/ligne.png); "
                        "background-position: center;"
                    "}";
    setStyleSheet(style);


    QDateTime dateToday = QDateTime::currentDateTime();
    int sYear = dateToday.date().year();
    QString sMonth = dateToday.date().longMonthName(dateToday.date().month()) + " " + QString::number(dateToday.date().year());
    sMonth = applyMajuscule(sMonth);
    QString sWeek = semaine + QString::number(dateToday.date().weekNumber());
    QString sDay = dateToday.date().longDayName(dateToday.date().dayOfWeek()) + " " + QString::number(dateToday.date().day());
    sDay = applyMajuscule(sDay);
    currentDate = dateToday.date();
    updateTimeLine(sYear, sMonth, sWeek, sDay);

    setHeaderHidden(true);
    setLayout(layoutTimeLine);
}

void TimeLine::mousePressEvent(QMouseEvent *event)
{
    QTreeWidget::mousePressEvent(event);
}

void TimeLine::mouseReleaseEvent(QMouseEvent *event)
{
    bool empty = currentItem()->text(currentColumn()).isEmpty();
    if(!empty){
        if(!currentItem()->isExpanded()){
            currentItem()->setExpanded(true);
            if(!estUnHuit(currentItem()->text(currentColumn()).toStdString())){
                currentItem()->setBackgroundColor(currentColumn(), QColor(220, 220, 220));
            }
        } else {
            currentItem()->setExpanded(false);
            currentItem()->setBackgroundColor(currentColumn(), Qt::transparent);
        }
        QTreeWidget::mouseReleaseEvent(event);
    }
}

void TimeLine::drawBranches(QPainter * painter, const QRect &rect, const QModelIndex &index)const
{
}

bool TimeLine::estUnHuit(string name){
    if(NB_HUITS == 3){
        for(int i(0); i < NB_HUITS; i++){
            if(trois_huits[i].toStdString() == name){
                return true;
            }
        }
    } else if (NB_HUITS == 2){
        for(int i(0); i < NB_HUITS; i++){
            if(deux_huits[i].toStdString() == name){
                return true;
            }
        }
    }
    return false;
}

QDate TimeLine::getCurrentDate(){
    return currentDate;
}

void TimeLine::updateTimeLine(int sYear, QString sMonth, QString sWeek, QString sDay){
    clear();
    QFont fontMois("Helvetica", 16, QFont::Bold);
    QFont fontUnselected("Helvetica", 13, QFont::Normal);

    trois_huits[0] = "1er 8h"; trois_huits[1] = "2nd 8h"; trois_huits[2] = "3ème 8h";
    deux_huits[0] = "1er 8h"; deux_huits[1] = "2nd 8h";

    QCalendarWidget * calendar = new QCalendarWidget;
    calendar->setHidden(true);
    calendar->setMinimumDate(QDate(sYear, 1, 1));
    calendar->setSelectedDate(calendar->minimumDate());


    QString previousMonth = "Janvier " + QString::number(sYear);
    QTreeWidgetItem * itemMonth = new QTreeWidgetItem;
    if(previousMonth == sMonth) itemMonth->setExpanded(true);
    itemMonth->setFont(0, fontMois);
    itemMonth->setText(0, previousMonth);
    addTopLevelItem(itemMonth);

    QString previousWeek = "Semaine 1";
    QTreeWidgetItem * itemWeek = new QTreeWidgetItem;
    if(previousWeek == sWeek) itemWeek->setExpanded(true);
    itemWeek->setFont(0, fontUnselected);
    itemWeek->setText(0, previousWeek);
    itemMonth->addChild(itemWeek);

    QTreeWidgetItem * itemDay;
    QTreeWidgetItem * itemHuit;
    QString week, day, month;

    QTreeWidgetItem * itemSystemMonth = new QTreeWidgetItem;
    QTreeWidgetItem * itemSystemWeek = new QTreeWidgetItem;
    QTreeWidgetItem * itemSystemDay = new QTreeWidgetItem;
    QTreeWidgetItem * itemSystemHuit = new QTreeWidgetItem;
    for(int i(0); i < NB_ANNEES*365; i++){
        day = calendar->selectedDate().longDayName(calendar->selectedDate().dayOfWeek()) + " " + QString::number(calendar->selectedDate().day());
        day = applyMajuscule(day);
        month = calendar->selectedDate().longMonthName(calendar->selectedDate().month()) + " " + QString::number(calendar->selectedDate().year());
        month = applyMajuscule(month);
        week = semaine + QString::number(calendar->selectedDate().weekNumber());
        if( (month != previousMonth) && (week == previousWeek) ){
            previousMonth = month;
            itemMonth = new QTreeWidgetItem;
            if(month == sMonth) itemSystemMonth = itemMonth;
            itemMonth->setFont(0, fontMois);
            itemMonth->setText(0, previousMonth);
            addTopLevelItem(itemMonth);
            itemWeek = new QTreeWidgetItem;
            if( (month == sMonth) && (week == sWeek) ) itemSystemWeek = itemWeek;
            itemWeek->setFont(0, fontUnselected);
            itemWeek->setText(0, previousWeek);
            itemMonth->addChild(itemWeek);
        } else if( (month == previousMonth) && (week != previousWeek) ){
            previousWeek = week;
            itemWeek = new QTreeWidgetItem;
            if( (month == sMonth) && (week == sWeek) ) itemSystemWeek = itemWeek;
            itemWeek->setFont(0, fontUnselected);
            itemWeek->setText(0, previousWeek);
            itemMonth->addChild(itemWeek);
        } else if ( (month != previousMonth) && (week != previousWeek) ){
            previousMonth = month;
            previousWeek = week;
            itemMonth = new QTreeWidgetItem;
            if(month == sMonth) itemSystemMonth = itemMonth;
            itemMonth->setFont(0, fontMois);
            itemMonth->setText(0, previousMonth);
            addTopLevelItem(itemMonth);
            itemWeek = new QTreeWidgetItem;
            if( (month == sMonth) && (week == sWeek) ) itemSystemWeek = itemWeek;
            itemWeek->setFont(0, fontUnselected);
            itemWeek->setText(0, previousWeek);
            itemMonth->addChild(itemWeek);
        }
        itemDay = new QTreeWidgetItem;
        if( (day == sDay) && (month == sMonth) && (week == sWeek) ) itemSystemDay = itemDay;
        itemDay->setFont(1, fontUnselected);
        itemDay->setText(1, day);
        itemWeek->addChild(itemDay);
        for(int j(0); j < NB_HUITS; j++){
            itemHuit = new QTreeWidgetItem;
            if( (day == sDay) && (month == sMonth) && (week == sWeek) && (j == 0) ) itemSystemHuit = itemHuit;
            itemHuit->setFont(1, fontUnselected);
            itemHuit->setTextAlignment(1, Qt::AlignRight);
            if(NB_HUITS == 2) itemHuit->setText(1, deux_huits[j]);
            else if(NB_HUITS == 3) itemHuit->setText(1, trois_huits[j]);
            itemDay->addChild(itemHuit);
        }
        calendar->setSelectedDate(calendar->selectedDate().addDays(1));
    }
    itemSystemMonth->setExpanded(true);
    itemSystemMonth->setBackgroundColor(0, QColor(220, 220, 220));

    itemSystemWeek->setExpanded(true);
    itemSystemWeek->setBackgroundColor(0, QColor(220, 220, 220));

    itemSystemDay->setExpanded(true);
    itemSystemDay->setBackgroundColor(1, QColor(220, 220, 220));

    setCurrentItem(itemSystemHuit, 1);
}

void TimeLine::setNbAnnees(int n)
{
    NB_ANNEES = n;
}

void TimeLine::setNbHuits(int n)
{
    NB_HUITS = n;
}

int TimeLine::getNbAnnees()
{
    return NB_ANNEES;
}

int TimeLine::getNbHuits()
{
    return NB_HUITS;
}

QString TimeLine::applyMajuscule(QString s)
{
    QString ss = s;
    QString maj = ss[0].toUpper();
    ss.remove(0, 1);
    QString sss = maj + ss;
    return sss;
}
