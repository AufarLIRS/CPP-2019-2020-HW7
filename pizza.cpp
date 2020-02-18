#include "pizza.h"

Pizza::Builder& Pizza::Builder::SetDoughType(DoughType doughtype)
{
  _doughtype = doughtype;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPizzaType(PizzaType pizzatype)
{
  _pizzatype = pizzatype;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetOlives(Olives olives)
{
  _olives = olives;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPepperoni(Pepperoni pepperoni)
{
  _pepperoni = pepperoni;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetDoubleCheese(DoubleCheese doublecheese)
{
  _doublecheese = doublecheese;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPineapples(Pineapples pineapples)
{
  _pineapples = pineapples;
  return *this;
}

Pizza Pizza::Builder::build()
{
  return Pizza(_doughtype, _pizzatype, _olives, _pepperoni, _doublecheese, _pineapples);
}

QString Pizza::GetTheSummary()
{
  QString StringBuilder;
  switch (_doughtype)
  {
    case DoughType::Thin:
      StringBuilder.append("Пицца из тонкого теста\n");
      break;
    case DoughType::Traditional:
      StringBuilder.append("Пицца из традиционного теста\n");
      break;
  }
  switch (_pizzatype)
  {
    case PizzaType::Pepperoni:
      StringBuilder.append("Вид: Пепперони\n");
      break;
    case PizzaType::Margarita:
      StringBuilder.append("Вид: Маргарита\n");
      break;
    case PizzaType::FourCheeses:
      StringBuilder.append("Вид: Четыре сыра\n");
      break;
    case PizzaType::Sea:
      StringBuilder.append("Вид: Морская\n");
      break;
  }
  if (_olives == Olives::Yes)
    StringBuilder.append("Добавлены оливки\n");
  if (_pepperoni == Pepperoni::Yes)
    StringBuilder.append("Добавлены пепперони\n");
  if (_doublecheese == DoubleCheese::Yes)
    StringBuilder.append("Добавлен двойной сыр\n");
  if (_pineapples == Pineapples::Yes)
    StringBuilder.append("Добавлены ананасы\n");

  return StringBuilder;
}

Pizza::Pizza(DoughType doughtype, PizzaType pizzatype, Olives olives, Pepperoni pepperoni, DoubleCheese doublecheese,
             Pineapples pineapples)
{
  _doughtype = doughtype;
  _pizzatype = pizzatype;
  _olives = olives;
  _pepperoni = pepperoni;
  _doublecheese = doublecheese;
  _pineapples = pineapples;
}
