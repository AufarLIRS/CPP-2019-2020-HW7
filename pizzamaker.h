#ifndef PIZZAMAKER_H
#define PIZZAMAKER_H
#include <QDebug>

enum class DoughType
{
  Thin = 1,
  Traditional = 2
};

enum class PizzaType
{
  Pepperoni = 1,
  Margarita = 2,
  FourCheese = 3,
  Sea = 4
};

enum class Olives
{
  Yes = 1,
  No = 2
};

enum class Pepperoni
{
  Yes = 1,
  No = 2
};

enum class Cheese
{
  Yes = 1,
  No = 2
};

enum class Pineapples
{
  Yes = 1,
  No = 2
};

struct Pizza
{
  class Builder
  {
    DoughType _doughtype;
    PizzaType _pizzatype;
    Olives _olives;
    Pepperoni _pepperoni;
    Cheese _cheese;
    Pineapples _pineapples;

  public:
    Builder& SetDoughType(DoughType doughtype);

    Builder& SetPizzaType(PizzaType pizzatype);

    Builder& SetOlives(Olives olives);

    Builder& SetPepperoni(Pepperoni pepperoni);

    Builder& SetCheese(Cheese cheese);

    Builder& SetPineapples(Pineapples pineapples);

    Pizza pizzaBuild();
  };

public:
  QString GetResult();

private:
  DoughType _doughtype;
  PizzaType _pizzatype;
  Olives _olives;
  Pepperoni _pepperoni;
  Cheese _cheese;
  Pineapples _pineapples;

  Pizza(DoughType doughtype, PizzaType pizzatype, Olives olives, Pepperoni pepperoni, Cheese cheese,
        Pineapples pineapples);
};

#endif  // PIZZAMAKER_H
