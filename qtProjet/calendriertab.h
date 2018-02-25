#ifndef CALENDRIERTAB_H
#define CALENDRIERTAB_H


class CalendrierTab : public QWidget
{
    Q_OBJECT
public:
    explicit CalendrierTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

#endif // CALENDRIERTAB_H
