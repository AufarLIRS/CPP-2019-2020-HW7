#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QtWidgets>
#include "pizza.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

QAbstractButton* GetCheckedButton(const QGroupBox* box)
{
  QButtonGroup group;
  QList<QRadioButton*> allButtons = box->findChildren<QRadioButton*>();
  for (int i = 0; i < allButtons.size(); ++i)
  {
    group.addButton(allButtons[i], i);
  }
  return group.checkedButton();
}

void MainWindow::on_PizzaPushButton_clicked()
{
  ui->textEdit->clear();
  auto builder = Pizza::Builder();

  if (GetCheckedButton(ui->DoughGroupBox) == ui->ThinDoughRadioButton)
    builder.SetDoughType(DoughType::Thin);
  else
    builder.SetDoughType(DoughType::Traditional);

  auto pizzaTypeButton = GetCheckedButton(ui->PizzaTypeGroupBox);
  if (pizzaTypeButton == ui->PepperoniRadioButton)
    builder.SetPizzaType(PizzaType::Pepperoni);
  else if (pizzaTypeButton == ui->MargaritaRadioButton)
    builder.SetPizzaType(PizzaType::Margarita);
  else if (pizzaTypeButton == ui->CheeseRadioButton)
    builder.SetPizzaType(PizzaType::FourCheeses);
  else
    builder.SetPizzaType(PizzaType::Sea);

  if (ui->YesCheeseRadioButton->isChecked())
    builder.SetDoubleCheese(DoubleCheese::Yes);
  if (ui->YesOlivesRadioButton->isChecked())
    builder.SetOlives(Olives::Yes);
  if (ui->YesPepperoniRadioButton->isChecked())
    builder.SetPepperoni(Pepperoni::Yes);
  if (ui->YesPineappleRadioButton->isChecked())
    builder.SetPineapples(Pineapples::Yes);

  auto pizza = builder.build();

  ui->textEdit->setText(pizza.GetTheSummary());
}
