#ifndef PIZZA_H
#define PIZZA_H
#include <QString>

enum TasteType
{
  thin = -2,
  traditional = -3
};

enum PizzaType
{
  pepperoni = -2,
  margarita = -3,
  fourCheese = -4,
  seaPizza = -5
};

enum OlivesChoose
{
  olivesYes = -2,
  olivesNo = -3
};

enum PepperoniChoose
{
  pepperoniYes = -2,
  pepperoniNo = -3
};

enum DoubleCheeseChoose
{
  doubleCheeseYes = -2,
  doubleCheeseNo = -3
};

enum PineappleChoose
{
  pineappleYes = -2,
  pineappleNo = -3
};

struct Pizza
{
  class Builder
  {
    TasteType tasteType_;
    PizzaType pizzaType_;
    OlivesChoose olivesChoose_;
    PepperoniChoose pepperoniChoose_;
    DoubleCheeseChoose doubleCheeseChoose_;
    PineappleChoose pineappleChoose_;

  public:
    Builder& setTasteType(TasteType type);
    Builder& setPizzaType(PizzaType type);
    Builder& setOlives(OlivesChoose choose);
    Builder& setPepperoni(PepperoniChoose choose);
    Builder& setDoubleCheese(DoubleCheeseChoose choose);
    Builder& setPineapple(PineappleChoose choose);
    Pizza build();
  };

  QString print();

private:
  TasteType tasteType_;
  PizzaType pizzaType_;
  OlivesChoose olivesChoose_;
  PepperoniChoose pepperoniChoose_;
  DoubleCheeseChoose doubleCheeseChoose_;
  PineappleChoose pineappleChoose_;

  Pizza(TasteType tasteType, PizzaType pizzaType, OlivesChoose olivesChoose, PepperoniChoose pepperoniChoose,
        DoubleCheeseChoose doubleCheeseChoose, PineappleChoose pineappleChoose);
};
#endif  // PIZZA_H
