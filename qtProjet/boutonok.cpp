#include "boutonok.h"

BoutonOk::BoutonOk()
{
    QFont font("Helvetica", 10, QFont::Normal);
    setText("OK");
    setFont(font);
    setStyleSheet("background-color: LightSlateGrey ;");
}
