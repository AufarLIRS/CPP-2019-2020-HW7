#ifndef PIZZA_H
#define PIZZA_H
#include "pizzaEnumCollection.h"
#include <QtWidgets>

struct Pizza
{
  class Builder
  {
    DoughType _doughtype;
    PizzaType _pizzatype;
    Olives _olives;
    Pepperoni _pepperoni;
    DoubleCheese _doublecheese;
    Pineapples _pineapples;

  public:
    Builder& SetDoughType(DoughType doughtype);

    Builder& SetPizzaType(PizzaType pizzatype);

    Builder& SetOlives(Olives olives);

    Builder& SetPepperoni(Pepperoni pepperoni);

    Builder& SetDoubleCheese(DoubleCheese doublecheese);

    Builder& SetPineapples(Pineapples pineapples);

    Pizza build();
  };

  QString GetTheSummary();

private:
  DoughType _doughtype;
  PizzaType _pizzatype;
  Olives _olives;
  Pepperoni _pepperoni;
  DoubleCheese _doublecheese;
  Pineapples _pineapples;

  Pizza(DoughType doughtype, PizzaType pizzatype, Olives olives, Pepperoni pepperoni, DoubleCheese doublecheese,
        Pineapples pineapples);
};

#endif  // PIZZA_H
