#include "pizza.h"

//------------Сеттеры для Билдела-----------------//
Pizza::Builder& Pizza::Builder::SetDough(Dough Dough)
{
  _dough = Dough;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPizzaType(PizzaType PizzaType)
{
  _pizzaType = PizzaType;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetOlives(Olive olive)
{
  _olive = olive;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPepperoni(Pepperoni pepperoni)
{
  _pepperoni = pepperoni;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetdoubleCheese(DoubleCheese doubleCheese)
{
  _doubleCheese = doubleCheese;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPineapple(Pineapple pineapple)
{
  _pineapple = pineapple;
  return *this;
}

Pizza Pizza::Builder::build()
{
  return Pizza(_dough, _pizzaType, _olive, _pepperoni, _doubleCheese, _pineapple);
}
//----------------------------------------//

QString Pizza::GetOrder()
{
  QString StringBuilder;
  StringBuilder.append("Mamma Mia!\n").append("Вы собрали пиццу: \n");
  switch (_dough)
  {
    case Dough::Thin:
      StringBuilder.append("Пицца из тонкого теста\n");
      break;
    case Dough::Traditional:
      StringBuilder.append("Пицца из традиционного теста\n");
      break;
  }

  switch (_pizzatipo)
  {
    case PizzaType::Pepperoni:
      StringBuilder.append("Вид: Пепперони\n");
      break;
    case PizzaType::Margarita:
      StringBuilder.append("Вид: Маргарита\n");
      break;
    case PizzaType::DoubleCheese:
      StringBuilder.append("Вид: Четыре сыра\n");
      break;
    case PizzaType::Mare:
      StringBuilder.append("Вид: Морская\n");
      break;
  }

  switch (_olive)
  {
    case Olive::Yes:
      StringBuilder.append("Добавлены оливки\n");
    case Olive::No:
      StringBuilder.append("Без Оливок\n");
  }

  switch (_pepperoni)
  {
    case Pepperoni::Yes:
      StringBuilder.append("Добавлены Пепперони\n");
      break;
    case Pepperoni::No:
      StringBuilder.append("Без Пепперони\n");
      break;
  }

  switch (_doubleCheese)
  {
    case DoubleCheese::Yes:
      StringBuilder.append("Добавлен Сыр\n");
      break;
    case DoubleCheese::No:
      StringBuilder.append("Без Сыра\n");
      break;
  }

  switch (_pineapple)
  {
    case Pineapple::Yes:
      StringBuilder.append("Добавлены Ананасы\n");
      break;
    case Pineapple::No:
      StringBuilder.append("Без Ананасов\n");
      break;
  }

  return StringBuilder;
}

//Конструктор самой пиццы
Pizza::Pizza(Dough Dough, PizzaType PizzaType, Olive olive, Pepperoni pepperoni, DoubleCheese doubleCheese,
             Pineapple pineapple)
{
  _dough = Dough;
  _pizzatipo = PizzaType;
  _olive = olive;
  _pepperoni = pepperoni;
  _doubleCheese = doubleCheese;
  _pineapple = pineapple;
}
