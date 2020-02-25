#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "pizza.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_makePushButton_clicked()
{
  qDebug() << "_____________________";
  qDebug() << ui->tasteButtonGroup->checkedId();
  qDebug() << ui->pizzaTypeButtonGroup->checkedId();
  qDebug() << ui->olivesButtonGroup->checkedId();
  qDebug() << ui->pepperoniButtonGroup->checkedId();
  qDebug() << ui->doubleCheeseButtonGroup->checkedId();
  qDebug() << ui->pineappleButtonGroup->checkedId();

  ui->textEdit->clear();
  auto builder = Pizza::Builder();
  builder.setTasteType(TasteType(ui->tasteButtonGroup->checkedId()));
  builder.setPizzaType(PizzaType(ui->pizzaTypeButtonGroup->checkedId()));
  builder.setOlives(OlivesChoose(ui->olivesButtonGroup->checkedId()));
  builder.setPepperoni(PepperoniChoose(ui->pepperoniButtonGroup->checkedId()));
  builder.setDoubleCheese(DoubleCheeseChoose(ui->doubleCheeseButtonGroup->checkedId()));
  builder.setPineapple(PineappleChoose(ui->pineappleButtonGroup->checkedId()));
  Pizza pizza = builder.build();
  ui->textEdit->setText(pizza.print());
}
