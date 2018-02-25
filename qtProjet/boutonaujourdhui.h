#ifndef BOUTONAUJOURDHUI_H
#define BOUTONAUJOURDHUI_H

#include <QPushButton>

class BoutonAujourdhui : public QPushButton
{
public:
    BoutonAujourdhui();
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // BOUTONAUJOURDHUI_H
