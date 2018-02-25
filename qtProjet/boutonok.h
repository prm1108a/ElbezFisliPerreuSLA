#ifndef BOUTONOK_H
#define BOUTONOK_H

#include <QPushButton>

class BoutonOk : public QPushButton
{
public:
    BoutonOk();
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // BOUTONOK_H
