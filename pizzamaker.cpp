#include "pizzamaker.h"

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

Pizza::Builder& Pizza::Builder::SetCheese(Cheese cheese)
{
  _cheese = cheese;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPineapples(Pineapples pineapples)
{
  _pineapples = pineapples;
  return *this;
}

Pizza Pizza::Builder::pizzaBuild()
{
  return Pizza(_doughtype, _pizzatype, _olives, _pepperoni, _cheese, _pineapples);
}

Pizza::Pizza(DoughType doughtype, PizzaType pizzatype, Olives olives, Pepperoni pepperoni, Cheese cheese,
             Pineapples pineapples)
{
  _doughtype = doughtype;
  _pizzatype = pizzatype;
  _olives = olives;
  _pepperoni = pepperoni;
  _cheese = cheese;
  _pineapples = pineapples;
}

QString Pizza::GetResult()
{
  QString message = "Будет приготовлена пицца ";

  switch (_pizzatype)
  {
    case PizzaType::Pepperoni:
      message.append("'Пепперони' ");
      break;
    case PizzaType::Margarita:
      message.append("'Маргарита' ");
      break;
    case PizzaType::FourCheese:
      message.append("'Четыре сыра' ");
      break;
    case PizzaType::Sea:
      message.append("'Морская' ");
      break;
  }

  switch (_doughtype)
  {
    case DoughType::Thin:
      message.append("на тонком тесте");
      break;
    case DoughType::Traditional:
      message.append("на традиционном тесте");
      break;
  }

  if (_olives == Olives::Yes)
    message.append(", дополнительно оливки");
  if (_pepperoni == Pepperoni::Yes)
    message.append(", дополнительно пепперони");
  if (_cheese == Cheese::Yes)
    message.append(", дополнительно двойной сыр");
  if (_pineapples == Pineapples::Yes)
    message.append(", дополнительно ананасы");

  return message;
}
