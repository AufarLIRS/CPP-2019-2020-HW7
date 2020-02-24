#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  pizzaBuilder = pizza::PizzaBuilder();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_RadioButtonThinBase_clicked()
{
  pizzaBuilder.setBaseType(pizza::BaseType::THIN);
}

void MainWindow::on_RadioButtonStandartBase_clicked()
{
  pizzaBuilder.setBaseType(pizza::BaseType::STANDART);
}

void MainWindow::on_RadioButtonPepperoni_clicked()
{
  pizzaBuilder.setRecipe(pizza::PizzaRecipe::PEPPERONI);
}

void MainWindow::on_RadioButtonMargarita_clicked()
{
  pizzaBuilder.setRecipe(pizza::PizzaRecipe::MARGARITA);
}

void MainWindow::on_RadioButtonFourCheese_clicked()
{
  pizzaBuilder.setRecipe(pizza::PizzaRecipe::FOUR_CHESES);
}

void MainWindow::on_RadioButtonSea_clicked()
{
  pizzaBuilder.setRecipe(pizza::PizzaRecipe::SEA);
}

void MainWindow::on_RadioButtonYesOlives_clicked()
{
  pizzaBuilder.setOlives(pizza::AdditionalOlives::YES);
}

void MainWindow::on_RadioButtonNoOlives_clicked()
{
  pizzaBuilder.setOlives(pizza::AdditionalOlives::NO);
}

void MainWindow::on_RadioButtonYesPepperoni_clicked()
{
  pizzaBuilder.setPepperoni(pizza::AdditionalPepperoni::YES);
}

void MainWindow::on_RadioButtonNoPepperoni_clicked()
{
  pizzaBuilder.setPepperoni(pizza::AdditionalPepperoni::NO);
}

void MainWindow::on_RadioButtonYesCheese_clicked()
{
  pizzaBuilder.setDoubleCheese(pizza::DoubleCheese::YES);
}

void MainWindow::on_RadioButtonNoCheese_clicked()
{
  pizzaBuilder.setDoubleCheese(pizza::DoubleCheese::NO);
}

void MainWindow::on_RadioButtonYesPineapple_clicked()
{
  pizzaBuilder.setPineapples(pizza::AdditionalPineapples::YES);
}

void MainWindow::on_RadioButtonNoPineapple_clicked()
{
  pizzaBuilder.setPineapples(pizza::AdditionalPineapples::NO);
}

void MainWindow::on_PushButtonMakePizza_clicked()
{
  pizza::Pizza pizza = pizzaBuilder.makePizza();
  QString responce = "Made pizza ";

  switch (pizza.getRecipe())
  {
    case pizza::PizzaRecipe::PEPPERONI:
      responce += "pepperoni ";
      break;
    case pizza::PizzaRecipe::MARGARITA:
      responce += "margarita ";
      break;
    case pizza::PizzaRecipe::SEA:
      responce += "sea ";
      break;
    case pizza::PizzaRecipe::FOUR_CHESES:
      responce += "four cheeses ";
      break;
  }

  switch (pizza.getBaseType())
  {
    case pizza::BaseType::THIN:
      responce += "on thin dough ";
      break;
    case pizza::BaseType::STANDART:
      responce += "on classic dough ";
      break;
  }

  responce += "with additional ";

  bool wasSomethigBefore = false;

  if (pizza.getOlives() == pizza::AdditionalOlives::YES)
  {
    responce += "olives";
    wasSomethigBefore = true;
  }
  if (pizza.getPepperoni() == pizza::AdditionalPepperoni::YES)
  {
    if (wasSomethigBefore)
      responce += ", ";
    responce += "pepperoni";
    wasSomethigBefore = true;
  }

  if (pizza.getPineapples() == pizza::AdditionalPineapples::YES)
  {
    if (wasSomethigBefore)
      responce += ", ";
    responce += "pineapples";
    wasSomethigBefore = true;
  }

  if (pizza.getDoubleCheese() == pizza::DoubleCheese::YES)
  {
    if (wasSomethigBefore)
      responce += ", ";
    responce += "double cheese";
    wasSomethigBefore = true;
  }
  ui->textEditLog->setText(responce);
}
