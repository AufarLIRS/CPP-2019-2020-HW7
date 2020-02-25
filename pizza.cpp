#include "pizza.h"

Pizza::Pizza(TasteType tasteType, PizzaType pizzaType, OlivesChoose olivesChoose, PepperoniChoose pepperoniChoose,
             DoubleCheeseChoose doubleCheeseChoose, PineappleChoose pineappleChoose)
{
  tasteType_ = tasteType;
  pizzaType_ = pizzaType;
  olivesChoose_ = olivesChoose;
  pepperoniChoose_ = pepperoniChoose;
  doubleCheeseChoose_ = doubleCheeseChoose;
  pineappleChoose_ = pineappleChoose;
}

Pizza::Builder& Pizza::Builder::setTasteType(TasteType type)
{
  tasteType_ = type;
  return *this;
}
Pizza::Builder& Pizza::Builder::setPizzaType(PizzaType type)
{
  pizzaType_ = type;
  return *this;
}
Pizza::Builder& Pizza::Builder::setOlives(OlivesChoose choose)
{
  olivesChoose_ = choose;
  return *this;
}
Pizza::Builder& Pizza::Builder::setPepperoni(PepperoniChoose choose)
{
  pepperoniChoose_ = choose;
  return *this;
}
Pizza::Builder& Pizza::Builder::setDoubleCheese(DoubleCheeseChoose choose)
{
  doubleCheeseChoose_ = choose;
  return *this;
}
Pizza::Builder& Pizza::Builder::setPineapple(PineappleChoose choose)
{
  pineappleChoose_ = choose;
  return *this;
}
Pizza Pizza::Builder::build()
{
  return Pizza(tasteType_, pizzaType_, olivesChoose_, pepperoniChoose_, doubleCheeseChoose_, pineappleChoose_);
}
QString Pizza::print()
{
  QString text = "Ваша изумительная пицца ";

  switch (pizzaType_)
  {
    case PizzaType::margarita:
      text.append("Маргарита ");
      break;
    case PizzaType::pepperoni:
      text.append("Пепперони ");
      break;
    case PizzaType::fourCheese:
      text.append("Четыре сыра ");
      break;
    case PizzaType::seaPizza:
      text.append("Морская ");
      break;
  }

  text.append("на ");

  switch (tasteType_)
  {
    case TasteType::thin:
      text.append("тонком тесте");
      break;
    case TasteType::traditional:
      text.append("традиционном тесте");
      break;
  }

  if (olivesChoose_ == olivesYes || pepperoniChoose_ == pepperoniYes || doubleCheeseChoose_ == doubleCheeseYes ||
      pineappleChoose_ == pineappleYes)
  {
    text.append(" с добавлением:");
    if (olivesChoose_ == olivesYes)
    {
      text.append("\n+ Оливок");
    }
    if (pepperoniChoose_ == pepperoniYes)
    {
      text.append("\n+ Пепперони");
    }
    if (doubleCheeseChoose_ == doubleCheeseYes)
    {
      text.append("\n+ Двойного сыра");
    }
    if (pineappleChoose_ == pineappleYes)
    {
      text.append("\n+ Кусочков ананаса");
    }
  }
  return text;
}
