#include <QtTest>
#include "../event.h"

class TestEvent : public QObject {
    Q_OBJECT

private slots:
    void testEventCreation();
    void testEventType();
};

void TestEvent::testEventCreation()
{
    Event event("Мурзик", "Посещение ветеринара", QDateTime::currentDateTime(), Event::Type::VisitToVet);
    QVERIFY(event.getPetName() == "Мурзик");
}

void TestEvent::testEventType()
{
    Event event("Барсик", "Прививка", QDateTime::currentDateTime().addDays(7), Event::Type::Vaccination);

    QCOMPARE(event.getDescription(), QString("Прививка"));
    QCOMPARE(event.getTypeString(), QString("Прививка"));
}

QTEST_APPLESS_MAIN(TestEvent)
#include "test_event.moc"