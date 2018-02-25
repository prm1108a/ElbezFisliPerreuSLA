#include "boutonaujourdhui.h"
#include "timelistwidget.h"

BoutonAujourdhui::BoutonAujourdhui()
{
    QFont font("Helvetica", 13, QFont::Normal);
    setText("Aujourd'hui");
    setMaximumWidth(80);
    setMaximumHeight(30);
    setFont(font);
    setStyleSheet("background-color: LightCyan ;");
}


