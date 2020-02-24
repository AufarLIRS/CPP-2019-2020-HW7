#include "pizza.h"

using namespace pizza;

Pizza::Pizza()
{
  ;
}

AdditionalOlives Pizza::getOlives()
{
  return olives_;
}

AdditionalPepperoni Pizza::getPepperoni()
{
  return pepperoni_;
}

AdditionalPineapples Pizza::getPineapples()
{
  return pineapples_;
}

DoubleCheese Pizza::getDoubleCheese()
{
  return doubleCheese_;
}

PizzaRecipe Pizza::getRecipe()
{
  return recipe_;
}

BaseType Pizza::getBaseType()
{
  return type_;
}

void PizzaBuilder::setOlives(AdditionalOlives arg)
{
  pizza.olives_ = arg;
}

void PizzaBuilder::setRecipe(PizzaRecipe arg)
{
  pizza.recipe_ = arg;
}

void PizzaBuilder::setBaseType(BaseType arg)
{
  pizza.type_ = arg;
}

void PizzaBuilder::setPepperoni(AdditionalPepperoni arg)
{
  pizza.pepperoni_ = arg;
}

void PizzaBuilder::setPineapples(AdditionalPineapples arg)
{
  pizza.pineapples_ = arg;
}

void PizzaBuilder::setDoubleCheese(DoubleCheese arg)
{
  pizza.doubleCheese_ = arg;
}

Pizza PizzaBuilder::makePizza()
{
  return pizza;
}

PizzaBuilder::PizzaBuilder()
{
  pizza.type_ = BaseType::STANDART;
  pizza.recipe_ = PizzaRecipe::PEPPERONI;
  pizza.olives_ = AdditionalOlives::NO;
  pizza.pepperoni_ = AdditionalPepperoni::NO;
  pizza.pineapples_ = AdditionalPineapples::NO;
  pizza.doubleCheese_ = DoubleCheese::NO;
}
