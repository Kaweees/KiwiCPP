#include <gtest/gtest.h>

#include "../include/kiwicpp/library.hpp"

TEST(LibraryTest, Add) {
  // Consider adding more test cases
  EXPECT_EQ(KiwiCPP::add(2, 3), 5);
  EXPECT_EQ(KiwiCPP::add(-1, 1), 0);
  EXPECT_EQ(KiwiCPP::add(0, 0), 0);
  EXPECT_EQ(KiwiCPP::add(-2, -3), -5);
}
