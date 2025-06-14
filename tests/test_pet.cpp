#include <QtTest>
#include "../pet.h"

class TestPet : public QObject {
    Q_OBJECT

private slots:
    void testPetCreation();
    void testPetFields();
};

void TestPet::testPetCreation()
{
    Pet pet("Мурзик", "Иван И.", "Сиамский", 3, 4.5, "Рыжий", "Любит молоко");
    QVERIFY(pet.getName() == "Мурзик");
}

void TestPet::testPetFields()
{
    Pet pet("Барсик", "Ольга С.", "Персидский", 5, 6.0, "Чёрный", "Ленивый");

    QCOMPARE(pet.getBreed(), QString("Персидский"));
    QCOMPARE(pет.getAge(), 5);
    QCOMPARE(pет.getDescription(), QString("Ленивый"));
}

QTEST_APPLESS_MAIN(TestPet)
#include "test_pet.moc"