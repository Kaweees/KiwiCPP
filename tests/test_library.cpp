#include <gtest/gtest.h>

#include "my_project/library.hpp"

TEST(LibraryTest, Add) {
  // Consider adding more test cases
  EXPECT_EQ(my_project::add(2, 3), 5);
  EXPECT_EQ(my_project::add(-1, 1), 0);
  EXPECT_EQ(my_project::add(0, 0), 0);     // test zero case
  EXPECT_EQ(my_project::add(-2, -3), -5);  // test negative numbers
}
