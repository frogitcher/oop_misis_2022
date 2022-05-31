#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "rational.h"


TEST_CASE("Testing arithmetic operations") {
  CHECK(Rational(1, 10) == Rational(1, 10));
  CHECK(Rational(1, 4) + Rational(3, 4) == Rational(1, 1));
  CHECK(Rational(3, 3) - Rational(1, 2) == Rational(2, 4));
  CHECK(Rational(1, 3) - Rational(5, 3) == Rational(-4, 3));
  CHECK((Rational(7, 2) -= Rational(0, 5723)) == Rational(7, 2));
  CHECK((Rational(8, 2) /= Rational(1, 2)) == Rational(8, 1));
  CHECK((Rational(7, 2) -= Rational(0, 7895)) == Rational(7, 2));
  CHECK((Rational(8, 2) /= Rational(1, 2)) == Rational(8, 1));
  CHECK((Rational(8553467, 51653) -= Rational(93545, 250)) ==
        Rational(-538702627, 2582650));
}

TEST_CASE("Testing boolean functions (True cases)") {
  CHECK(Rational(1, -1) == Rational(-1, 1));
  CHECK(Rational(-1, 1) != Rational(1, 1));
  CHECK(Rational(20, 1) > Rational(1, 20));
  CHECK(Rational(-6, 9) < (Rational(5, -9)));
  CHECK(Rational(4, 7) >= (Rational(7, 31)));
  CHECK(Rational(4, 7) >= (Rational(4, 7)));
  CHECK(Rational(3, 14) <= (Rational(7, 15)));
  CHECK(Rational(3, 14) <= (Rational(3, 14)));
}

TEST_CASE("Testing boolean functions (False cases)") {
  CHECK_FALSE(Rational(5, 25) == Rational(1, 5));
  CHECK_FALSE(Rational(41, 25) >= Rational(9, 5));
  CHECK_FALSE(Rational(48, 25) <= Rational(10, 5));
  CHECK_FALSE(Rational(45, 25) < Rational(9, 5));
  CHECK_FALSE(Rational(39, 25) > Rational(10, 2));
}

TEST_CASE("Testing exceptions") {
  CHECK_THROWS_WITH(Rational(56, 0), "denominator must not be 0");
  CHECK_THROWS_WITH((Rational(1, 25) /= Rational(0, 15)), "division by 0");
}