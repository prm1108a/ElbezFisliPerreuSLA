#ifndef BOUTONPARAM_H
#define BOUTONPARAM_H

#include <QPushButton>

class BoutonParam : public QPushButton
{
public:
    BoutonParam();
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // BOUTONPARAM_H
