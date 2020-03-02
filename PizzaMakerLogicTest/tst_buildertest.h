#ifndef TST_BUILDERTEST_H
#define TST_BUILDERTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <PizzaBuilder.h>

using namespace testing;

TEST(BuilderTest, BuilderTestStatic)
{
  static_assert(std::is_same<PizzaBuilder,
                             decltype(std::declval<PizzaBuilder>().setDoublecheese(DoublecheeseType::NONE))>::value);
  static_assert(
      std::is_same<PizzaBuilder, decltype(std::declval<PizzaBuilder>().setPineapple(PineappleType::NONE))>::value);
  static_assert(std::is_same<Pizza, decltype(std::declval<PizzaBuilder>().build())>::value);
}

TEST(BuilderTest, BuilderTestDefault)
{
  PizzaBuilder builder(DoughType::THIN, PizzaType::MARGARITA);
  auto pizza = builder.build();
  EXPECT_EQ(pizza.getType(), PizzaType::MARGARITA);
  EXPECT_EQ(pizza.getDough(), DoughType::THIN);
  EXPECT_EQ(pizza.getOlives(), OlivesType::NONE);
  EXPECT_EQ(pizza.getPepperoni(), PepperoniType::NONE);
  EXPECT_EQ(pizza.getPineapple(), PineappleType::NONE);
  EXPECT_EQ(pizza.getDoublecheese(), DoublecheeseType::NONE);
}

TEST(BuilderTest, BuilderTestAll)
{
  PizzaBuilder builder(DoughType::THIN, PizzaType::MARGARITA);
  builder.setOlives(OlivesType::YES);
  builder.setPepperoni(PepperoniType::YES);
  builder.setPineapple(PineappleType::YES);
  builder.setDoublecheese(DoublecheeseType::YES);
  auto pizza = builder.build();
  EXPECT_EQ(pizza.getType(), PizzaType::MARGARITA);
  EXPECT_EQ(pizza.getDough(), DoughType::THIN);
  EXPECT_EQ(pizza.getOlives(), OlivesType::YES);
  EXPECT_EQ(pizza.getPepperoni(), PepperoniType::YES);
  EXPECT_EQ(pizza.getPineapple(), PineappleType::YES);
  EXPECT_EQ(pizza.getDoublecheese(), DoublecheeseType::YES);
}

#endif  // TST_BUILDERTEST_H
