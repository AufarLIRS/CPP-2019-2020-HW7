#include <QtTest>
#include <mainwindow.h>
#include <ui_mainwindow.h>

// add necessary includes here

class ButtonTest : public QObject
{
  Q_OBJECT
  MainWindow w;

public:
  ButtonTest();
  ~ButtonTest();

private slots:
  void make_pizza_test1();
};

ButtonTest::ButtonTest()
{
}

ButtonTest::~ButtonTest()
{
}

void ButtonTest::make_pizza_test1()
{
  w.ui->seaRadioButton->click();
  w.ui->thinRadioButton->click();
  w.ui->pineappleYesRadioButton->click();
  w.ui->doublecheeseYesRadioButton->click();
  w.ui->pepperoniNoneRadioButton->click();
  w.ui->makePizzaButton->click();
  QCOMPARE("Dough value = \n-2\nType value = \n-5\nOlives value = \n-1\nPepperoni value = \n-3\nDoublecheese value = "
           "\n-2\nPineapple value = \n-2",
           w.ui->textEdit->toPlainText());
}

QTEST_MAIN(ButtonTest)

#include "tst_buttontest.moc"
