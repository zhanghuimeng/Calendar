#include "calendartableeventbutton.h"
#include "ui_calendartableeventbutton.h"

CalendarTableEventButton::CalendarTableEventButton(QSharedPointer<Event> event, QWidget *parent) :
    QPushButton(parent),
    mEvent(event),
    ui(new Ui::CalendarTableEventButton)
{
    ui->setupUi(this);
    QString text(QString("%1 - %2\n%3\n%4")
                 .arg(mEvent->startDate().time().toString("hh:mm"))
                 .arg(mEvent->endDate().time().toString("hh:mm"))
                 .arg(mEvent->name())
                 .arg(mEvent->location()));
    setText(text);


    setAutoFillBackground(true);
    QPalette palette(this->palette());
    palette.setColor(QPalette::Background, mEvent->color());
    setPalette(palette);
    // QColor paleColor(mEvent->color());
    // paleColor.setAlphaF(0.3);
    // setStyleSheet(QString("background-color: %1;").arg(paleColor.name()));
    setStyleSheet(QString("background-color: %1;").arg(mEvent->color().lighter(170).name()));

    /*
    background-color: red;
        border-style: outset;
        border-width: 2px;
        border-color: beige;
        */
}

CalendarTableEventButton::~CalendarTableEventButton()
{
    delete ui;
}
