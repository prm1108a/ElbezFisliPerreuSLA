#include "boutonvalider.h"

BoutonValider::BoutonValider()
{
    QFont font("Helvetica", 13, QFont::Normal);
    setText("Valider");
    setMaximumWidth(50);
    setMaximumHeight(30);
    setFont(font);
    setStyleSheet("background-color: CornflowerBlue ;");
}
