#include <QtTest>
#include <mainwindow.h>
#include <ui_mainwindow.h>

// add necessary includes here

class RadioButtonTest : public QObject
{
    Q_OBJECT
    MainWindow w;

public:
    RadioButtonTest();
    ~RadioButtonTest();

private slots:
    void init();
    void test_pepperoni_radio();
    void test_doublecheese_radio();
    void test_pineapple_radio();

};

void RadioButtonTest::init(){

}

RadioButtonTest::RadioButtonTest()
{

}

RadioButtonTest::~RadioButtonTest()
{

}

void RadioButtonTest::test_pepperoni_radio()
{
    w.ui->pepperoniYesRadioButton->click();
    QCOMPARE(w.ui->pepperoniNoneRadioButton->isChecked(), false);
    QCOMPARE(w.ui->pepperoniYesRadioButton->isChecked(), true);
}

void RadioButtonTest::test_doublecheese_radio()
{
    w.ui->doublecheeseYesRadioButton->click();
    QCOMPARE(w.ui->doublecheeseNoneRadioButton->isChecked(), false);
    QCOMPARE(w.ui->doublecheeseYesRadioButton->isChecked(), true);
}

void RadioButtonTest::test_pineapple_radio()
{
    w.ui->pineappleYesRadioButton->click();
    QCOMPARE(w.ui->pineappleNoneRadioButton->isChecked(), false);
    QCOMPARE(w.ui->pineappleYesRadioButton->isChecked(), true);
}



QTEST_MAIN(RadioButtonTest)

#include "tst_buttontest.moc"
