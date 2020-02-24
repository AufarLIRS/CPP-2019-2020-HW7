#ifndef PIZZA_H
#define PIZZA_H
#include "pizza_collection.h"
#include <QtWidgets>

class Pizza
{
private:
  Impasto _impasto;
  PizzaTipo _pizzatipo;
  Olive _olive;
  Pepperoni _pepperoni;
  DoppioFormaggio _doppioFormaggio;
  Ananas _ananas;

  Pizza(Impasto impasto, PizzaTipo pizzatipo, Olive olive, Pepperoni pepperoni, DoppioFormaggio doppioFormaggio,
        Ananas ananas);

public:
  class Builder
  {
  private:
    Impasto _impasto;
    PizzaTipo _pizzaTipo;
    Olive _olive;
    Pepperoni _pepperoni;
    DoppioFormaggio _doppioFormaggio;
    Ananas _ananas;

  public:
    Builder& SetImpasto(Impasto impasto);

    Builder& SetPizzaTipo(PizzaTipo PizzaTipo);

    Builder& SetOlives(Olive olive);

    Builder& SetPepperoni(Pepperoni pepperoni);

    Builder& SetdoppioFormaggio(DoppioFormaggio doppioFormaggio);

    Builder& SetAnanas(Ananas ananas);

    Pizza build();
  };

  QString GetOrder();
};

#endif
