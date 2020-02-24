#include "pizza.h"

//------------Сеттеры для Билдела-----------------//
Pizza::Builder& Pizza::Builder::SetImpasto(Impasto Impasto)
{
  _impasto = Impasto;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetPizzaTipo(PizzaTipo PizzaTipo)
{
  _pizzaTipo = PizzaTipo;
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

Pizza::Builder& Pizza::Builder::SetdoppioFormaggio(DoppioFormaggio doppioFormaggio)
{
  _doppioFormaggio = doppioFormaggio;
  return *this;
}

Pizza::Builder& Pizza::Builder::SetAnanas(Ananas ananas)
{
  _ananas = ananas;
  return *this;
}

Pizza Pizza::Builder::build()
{
  return Pizza(_impasto, _pizzaTipo, _olive, _pepperoni, _doppioFormaggio, _ananas);
}
//----------------------------------------//

QString Pizza::GetOrder()
{
  QString StringBuilder;
  StringBuilder.append("Mamma Mia!\n").append("Вы собрали пиццу: \n");
  switch (_impasto)
  {
    case Impasto::Sottile:
      StringBuilder.append("Пицца из тонкого теста\n");
      break;
    case Impasto::Tradizionale:
      StringBuilder.append("Пицца из традиционного теста\n");
      break;
  }

  switch (_pizzatipo)
  {
    case PizzaTipo::Pepperoni:
      StringBuilder.append("Вид: Пепперони\n");
      break;
    case PizzaTipo::Margarita:
      StringBuilder.append("Вид: Маргарита\n");
      break;
    case PizzaTipo::QuattroFormaggi:
      StringBuilder.append("Вид: Четыре сыра\n");
      break;
    case PizzaTipo::Mare:
      StringBuilder.append("Вид: Морская\n");
      break;
  }

  switch (_olive)
  {
    case Olive::Si:
      StringBuilder.append("Добавлены оливки\n");
    case Olive::No:
      StringBuilder.append("Без Оливок\n");
  }

  switch (_pepperoni)
  {
    case Pepperoni::Si:
      StringBuilder.append("Добавлены Пепперони\n");
    case Pepperoni::No:
      StringBuilder.append("Без Пепперони\n");
  }

  switch (_doppioFormaggio)
  {
    case DoppioFormaggio::Si:
      StringBuilder.append("Добавлен Сыр\n");
    case DoppioFormaggio::No:
      StringBuilder.append("Без Сыра\n");
  }

  switch (_ananas)
  {
    case Ananas::Si:
      StringBuilder.append("Добавлены Ананасы\n");
    case Ananas::No:
      StringBuilder.append("Без Ананасов\n");
  }

  return StringBuilder;
}

//Конструктор самой пиццы
Pizza::Pizza(Impasto Impasto, PizzaTipo PizzaTipo, Olive olive, Pepperoni pepperoni, DoppioFormaggio doppioFormaggio,
             Ananas ananas)
{
  _impasto = Impasto;
  _pizzatipo = PizzaTipo;
  _olive = olive;
  _pepperoni = pepperoni;
  _doppioFormaggio = doppioFormaggio;
  _ananas = ananas;
}
