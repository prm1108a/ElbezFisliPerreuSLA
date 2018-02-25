#include "dateedit.h"

DateEdit::DateEdit()
{
    QFont font("Helvetica", 14, QFont::Normal);
    setMaximumWidth(300);
    setFont(font);
    setCalendarPopup(true);
}
