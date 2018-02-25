#ifndef BUTTONAUJOURDHUI_H
#define BUTTONAUJOURDHUI_H

#include <QPushButton>
#include <QDate>

class ButtonAujourdhui : public QPushButton
{
    Q_OBJECT
public:
    ButtonAujourdhui();
    QDate getDateOfToday();
    void setDateOfToday(QDate date);
protected:
    void mouseReleaseEvent(QMouseEvent *event);
private:
    QDate dateOfToday;
};

#endif // BUTTONAUJOURDHUI_H
