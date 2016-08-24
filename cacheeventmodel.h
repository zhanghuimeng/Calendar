#ifndef CACHEEVENTMODEL_H
#define CACHEEVENTMODEL_H

#include "sqleventmodel.h"

#include <QObject>
#include <QVector>
#include <QPair>
#include <QMap>
#include <QDate>
/*
 * 启动时自动读取今年和前后两年内数据。
 * 在切换到新一年时，再多读一年数据。
 * 读入的数据都保存下来。
*/
class CacheEventModel : public SqlEventModel
{
    Q_OBJECT

public:
    CacheEventModel();
    QList<Event*> eventsForDate(const QDate &date);
    void addEvent(Event* event);
    void deleteEvent(Event* event);

public slots:
    void refreshOneDay(const QDate& date);

private:
    void readOneYear(int year);
    QMap<QDate, QList<Event*> > mEvents;
};

#endif // CACHEEVENTMODEL_H