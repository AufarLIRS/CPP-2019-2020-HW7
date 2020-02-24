#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pizza.h>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  pizza::PizzaBuilder pizzaBuilder;

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

private slots:
  void on_RadioButtonThinBase_clicked();
  void on_RadioButtonStandartBase_clicked();
  void on_RadioButtonPepperoni_clicked();
  void on_RadioButtonMargarita_clicked();
  void on_RadioButtonFourCheese_clicked();
  void on_RadioButtonSea_clicked();
  void on_RadioButtonYesOlives_clicked();
  void on_RadioButtonNoOlives_clicked();
  void on_RadioButtonYesPepperoni_clicked();
  void on_RadioButtonNoPepperoni_clicked();
  void on_RadioButtonYesCheese_clicked();
  void on_RadioButtonNoCheese_clicked();
  void on_RadioButtonYesPineapple_clicked();
  void on_RadioButtonNoPineapple_clicked();
  void on_PushButtonMakePizza_clicked();

private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
