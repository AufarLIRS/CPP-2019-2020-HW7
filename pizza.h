

namespace pizza
{
class Pizza
{
public:
  enum class BaseType
  {
    STANDARD = 1,
    THIN = 2
  };

  enum class PizzaRecipe
  {
    PEPPERONI = 1,
    MARGARITA = 2,
    FOUR_CHEESES = 3,
    SEA = 4
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

private:
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
  void setBaseType(Pizza::BaseType arg);
  void setRecipe(Pizza::PizzaRecipe arg);
  void setOlives(Pizza::AdditionalOlives arg);
  void setDoubleCheese(Pizza::DoubleCheese arg);
  void setPineapples(Pizza::AdditionalPineapples arg);
  void setPepperoni(Pizza::AdditionalPepperoni arg);
  Pizza makePizza();
};
}
