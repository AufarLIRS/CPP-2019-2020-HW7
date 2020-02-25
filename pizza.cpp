#include "pizza.h"

using namespace pizza;

Pizza::Pizza()
{
  ;
}

Pizza::AdditionalOlives Pizza::getOlives()
{
  return olives_;
}

Pizza::AdditionalPepperoni Pizza::getPepperoni()
{
  return pepperoni_;
}

Pizza::AdditionalPineapples Pizza::getPineapples()
{
  return pineapples_;
}

Pizza::DoubleCheese Pizza::getDoubleCheese()
{
  return doubleCheese_;
}

Pizza::PizzaRecipe Pizza::getRecipe()
{
  return recipe_;
}

Pizza::BaseType Pizza::getBaseType()
{
  return type_;
}

void PizzaBuilder::setOlives(Pizza::AdditionalOlives arg)
{
  pizza.olives_ = arg;
}

void PizzaBuilder::setRecipe(Pizza::PizzaRecipe arg)
{
  pizza.recipe_ = arg;
}

void PizzaBuilder::setBaseType(Pizza::BaseType arg)
{
  pizza.type_ = arg;
}

void PizzaBuilder::setPepperoni(Pizza::AdditionalPepperoni arg)
{
  pizza.pepperoni_ = arg;
}

void PizzaBuilder::setPineapples(Pizza::AdditionalPineapples arg)
{
  pizza.pineapples_ = arg;
}

void PizzaBuilder::setDoubleCheese(Pizza::DoubleCheese arg)
{
  pizza.doubleCheese_ = arg;
}

Pizza PizzaBuilder::makePizza()
{
  return pizza;
}

PizzaBuilder::PizzaBuilder()
{
  pizza.type_ = Pizza::BaseType::STANDARD;
  pizza.recipe_ = Pizza::PizzaRecipe::PEPPERONI;
  pizza.olives_ = Pizza::AdditionalOlives::NO;
  pizza.pepperoni_ = Pizza::AdditionalPepperoni::NO;
  pizza.pineapples_ = Pizza::AdditionalPineapples::NO;
  pizza.doubleCheese_ = Pizza::DoubleCheese::NO;
}
