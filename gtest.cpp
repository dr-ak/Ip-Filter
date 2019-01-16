#include "lib_ip_filter.hpp"
#include <gtest/gtest.h>
#include <string>


/*TEST(GTest, TestSplit){
    std::vector <std::string> a = {"222", "173", "235", "246"};
    std::string str = "222.173.235.246";
    std::vector <std::string> b = split(str, '.');

    for (unsigned i = 0; i < a.size(); ++i)
        ASSERT_STREQ(a[i].c_str(), b[i].c_str());
}*/

TEST(GTest, TestAllowPrintIp){
    //std::string str = "222.173.235.246";
    //ASSERT_TRUE(allow_print_ip("\\.173\\.", str));
    //ASSERT_TRUE(true);

}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
