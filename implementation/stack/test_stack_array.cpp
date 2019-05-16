#include "stack_array.c"
#include "gtest/gtest.h"

namespace {

class StackArrayTest : public ::testing::Test {
    protected:
        StackArrayTest() {
        }

        ~StackArrayTest() override {
        }

        void SetUp() override {
        }

        void TearDown() override {
        }

};  // class StackArrayTest

TEST(StackArrayTest, TestTest) {
    EXPECT_EQ(ForTest(), 1);
}

}   // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TEST();
}
