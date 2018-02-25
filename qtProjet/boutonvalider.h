#ifndef BOUTONVALIDER_H
#define BOUTONVALIDER_H

#include <QPushButton>

class BoutonValider : public QPushButton
{
public:
    BoutonValider();
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // BOUTONVALIDER_H
