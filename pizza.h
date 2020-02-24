#ifndef PIZZA_H
#define PIZZA_H
#include "pizza_collection.h"
#include <QtWidgets>

class Pizza
{
private:
  Dough _dough;
  PizzaType _pizzatipo;
  Olive _olive;
  Pepperoni _pepperoni;
  DoubleCheese _doubleCheese;
  Pineapple _pineapple;

  Pizza(Dough dough, PizzaType pizzatipo, Olive olive, Pepperoni pepperoni, DoubleCheese doubleCheese,
        Pineapple pineapple);

public:
  class Builder
  {
  private:
    Dough _dough;
    PizzaType _pizzaType;
    Olive _olive;
    Pepperoni _pepperoni;
    DoubleCheese _doubleCheese;
    Pineapple _pineapple;

  public:
    Builder& SetDough(Dough dough);

    Builder& SetPizzaType(PizzaType PizzaType);

    Builder& SetOlives(Olive olive);

    Builder& SetPepperoni(Pepperoni pepperoni);

    Builder& SetdoubleCheese(DoubleCheese doubleCheese);

    Builder& SetPineapple(Pineapple pineapple);

    Pizza build();
  };

  QString GetOrder();
};

#endif
