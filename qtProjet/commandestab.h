#ifndef COMMANDESTAB_H
#define COMMANDESTAB_H


class CommandesTab : public QWidget
{
    Q_OBJECT

public:
    explicit CommandesTab(const QFileInfo &fileInfo, QWidget *parent = 0);
};

#endif // COMMANDESTAB_H
