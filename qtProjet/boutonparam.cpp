#include "boutonparam.h"

BoutonParam::BoutonParam()
{
    QFont font("Helvetica", 12, QFont::Normal);
    setMaximumWidth(20);
    setMaximumHeight(30);
    setFont(font);
    setIcon(*(new QIcon("/home/mariep/workspace/build-qtProjet-Desktop_Qt_5_10_0_GCC_64bit-Debug/param.png")));
    setStyleSheet("background-color: LightSlateGrey ;");
}

