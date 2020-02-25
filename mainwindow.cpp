#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <iostream>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // pizzaBuilder = pizza::PizzaBuilder();
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_RadioButtonThinBase_clicked()
{
  pizzaBuilder.setBaseType(pizza::Pizza::BaseType::THIN);
}

void MainWindow::on_RadioButtonStandartBase_clicked()
{
  pizzaBuilder.setBaseType(pizza::Pizza::BaseType::STANDARD);
}

void MainWindow::on_RadioButtonPepperoni_clicked()
{
  pizzaBuilder.setRecipe(pizza::Pizza::PizzaRecipe::PEPPERONI);
}

void MainWindow::on_RadioButtonMargarita_clicked()
{
  pizzaBuilder.setRecipe(pizza::Pizza::PizzaRecipe::MARGARITA);
}

void MainWindow::on_RadioButtonFourCheese_clicked()
{
  pizzaBuilder.setRecipe(pizza::Pizza::PizzaRecipe::FOUR_CHEESES);
}

void MainWindow::on_RadioButtonSea_clicked()
{
  pizzaBuilder.setRecipe(pizza::Pizza::PizzaRecipe::SEA);
}

void MainWindow::on_RadioButtonYesOlives_clicked()
{
  pizzaBuilder.setOlives(pizza::Pizza::AdditionalOlives::YES);
}

void MainWindow::on_RadioButtonNoOlives_clicked()
{
  pizzaBuilder.setOlives(pizza::Pizza::AdditionalOlives::NO);
}

void MainWindow::on_RadioButtonYesPepperoni_clicked()
{
  pizzaBuilder.setPepperoni(pizza::Pizza::AdditionalPepperoni::YES);
}

void MainWindow::on_RadioButtonNoPepperoni_clicked()
{
  pizzaBuilder.setPepperoni(pizza::Pizza::AdditionalPepperoni::NO);
}

void MainWindow::on_RadioButtonYesCheese_clicked()
{
  pizzaBuilder.setDoubleCheese(pizza::Pizza::DoubleCheese::YES);
}

void MainWindow::on_RadioButtonNoCheese_clicked()
{
  pizzaBuilder.setDoubleCheese(pizza::Pizza::DoubleCheese::NO);
}

void MainWindow::on_RadioButtonYesPineapple_clicked()
{
  pizzaBuilder.setPineapples(pizza::Pizza::AdditionalPineapples::YES);
}

void MainWindow::on_RadioButtonNoPineapple_clicked()
{
  pizzaBuilder.setPineapples(pizza::Pizza::AdditionalPineapples::NO);
}

void MainWindow::on_PushButtonMakePizza_clicked()
{
  pizza::Pizza pizza = pizzaBuilder.makePizza();
  QString response = "Made pizza ";

  switch (pizza.getRecipe())
  {
    case pizza::Pizza::PizzaRecipe::PEPPERONI:
      response += "pepperoni ";
      break;
    case pizza::Pizza::PizzaRecipe::MARGARITA:
      response += "margarita ";
      break;
    case pizza::Pizza::PizzaRecipe::SEA:
      response += "sea ";
      break;
    case pizza::Pizza::PizzaRecipe::FOUR_CHEESES:
      response += "four cheeses ";
      break;
  }

  switch (pizza.getBaseType())
  {
    case pizza::Pizza::BaseType::THIN:
      response += "on thin dough ";
      break;
    case pizza::Pizza::BaseType::STANDARD:
      response += "on classic dough ";
      break;
  }

  response += "with additional ";

  bool wasSomethigBefore = false;

  if (pizza.getOlives() == pizza::Pizza::AdditionalOlives::YES)
  {
    response += "olives";
    wasSomethigBefore = true;
  }
  if (pizza.getPepperoni() == pizza::Pizza::AdditionalPepperoni::YES)
  {
    if (wasSomethigBefore)
      response += ", ";
    response += "pepperoni";
    wasSomethigBefore = true;
  }

  if (pizza.getPineapples() == pizza::Pizza::AdditionalPineapples::YES)
  {
    if (wasSomethigBefore)
      response += ", ";
    response += "pineapples";
    wasSomethigBefore = true;
  }

  if (pizza.getDoubleCheese() == pizza::Pizza::DoubleCheese::YES)
  {
    if (wasSomethigBefore)
      response += ", ";
    response += "double cheese";
    wasSomethigBefore = true;
  }
  ui->textEditLog->setText(response);
}
