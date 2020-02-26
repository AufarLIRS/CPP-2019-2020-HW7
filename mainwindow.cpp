#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "pizzamaker.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->DoughButtonGroup->setId(ui->ThinDoughRadioButton, 1);
  ui->DoughButtonGroup->setId(ui->TraditionalDoughRadioButton, 2);
  ui->TypeButtonGroup->setId(ui->PepperRadioButton, 1);
  ui->TypeButtonGroup->setId(ui->MargaritaRadioButton, 2);
  ui->TypeButtonGroup->setId(ui->FourCheeseRadioButton, 3);
  ui->TypeButtonGroup->setId(ui->SeaRadioButton, 4);
  ui->OlivesButtonGroup->setId(ui->OlivesYesRadioButton, 1);
  ui->OlivesButtonGroup->setId(ui->OlivesNoRadioButton, 2);
  ui->PepperButtonGroup->setId(ui->PepperYesRadioButton, 1);
  ui->PepperButtonGroup->setId(ui->PepperNoRadioButton, 2);
  ui->CheeseButtonGroup->setId(ui->CheeseYesRadioButton, 1);
  ui->CheeseButtonGroup->setId(ui->CheeseNoRadioButton, 2);
  ui->PineapplesButtonGroup->setId(ui->PineapplesYesRadioButton, 1);
  ui->PineapplesButtonGroup->setId(ui->PineapplesNoRadioButton, 2);
}

void MainWindow::on_MakePizzaPushButton_clicked()
{
  ui->textEdit->clear();

  auto rawPizza = Pizza::Builder();
  rawPizza.SetDoughType(DoughType(ui->DoughButtonGroup->checkedId()));
  rawPizza.SetPizzaType(PizzaType(ui->TypeButtonGroup->checkedId()));
  rawPizza.SetOlives(Olives(ui->OlivesButtonGroup->checkedId()));
  rawPizza.SetPepperoni(Pepperoni(ui->PepperButtonGroup->checkedId()));
  rawPizza.SetCheese(Cheese(ui->CheeseButtonGroup->checkedId()));
  rawPizza.SetPineapples(Pineapples(ui->PineapplesButtonGroup->checkedId()));
  Pizza pizza = rawPizza.pizzaBuild();

  ui->textEdit->setText(pizza.GetResult());
}

MainWindow::~MainWindow()
{
  delete ui;
}
