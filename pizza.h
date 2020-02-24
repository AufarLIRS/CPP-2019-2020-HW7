

namespace pizza
{
enum class BaseType
{
  STANDART = 1,
  THIN = 2
};

enum class PizzaRecipe
{
  PEPPERONI = 1,
  MARGARITA = 2,
  FOUR_CHESES,
  SEA
};

enum class AdditionalOlives
{
  YES = 1,
  NO = 2
};

enum class AdditionalPepperoni
{
  YES = 1,
  NO = 2
};

enum class DoubleCheese
{
  YES = 1,
  NO = 2
};

enum class AdditionalPineapples
{
  YES = 1,
  NO = 2
};

class Pizza
{
  BaseType type_;
  PizzaRecipe recipe_;
  AdditionalOlives olives_;
  AdditionalPepperoni pepperoni_;
  AdditionalPineapples pineapples_;
  DoubleCheese doubleCheese_;

  friend class PizzaBuilder;

public:
  Pizza();
  BaseType getBaseType();
  PizzaRecipe getRecipe();
  AdditionalOlives getOlives();
  DoubleCheese getDoubleCheese();
  AdditionalPineapples getPineapples();
  AdditionalPepperoni getPepperoni();
};

class PizzaBuilder
{
  Pizza pizza;

public:
  PizzaBuilder();
  void setBaseType(BaseType arg);
  void setRecipe(PizzaRecipe arg);
  void setOlives(AdditionalOlives arg);
  void setDoubleCheese(DoubleCheese arg);
  void setPineapples(AdditionalPineapples arg);
  void setPepperoni(AdditionalPepperoni arg);
  Pizza makePizza();
};
}
