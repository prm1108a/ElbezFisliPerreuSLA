#include "buttonaujourdhui.h"

ButtonAujourdhui::ButtonAujourdhui() : QPushButton()
{
    QFont font("Helvetica", 14, QFont::Normal);
    setText("Aujourd'hui");
    setMaximumWidth(90);
    setFont(font);
}

void ButtonAujourdhui::mouseReleaseEvent(QMouseEvent *event)
{

}

