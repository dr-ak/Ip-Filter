#include "lib_ip_filter.hpp"
#include <gtest/gtest.h>

TEST(GTest, TestSplit){
    std::string str = "185.69.186.168	1	3";
    std::string a = "185.69.186.168";
    std::vector <std::string> b = split(str, '\t');
    ASSERT_STREQ(a.c_str(), b[0].c_str());
    str = "110.152.103.161	0	1";
    a = "110.152.103.161";
    b = split(str, '\t');
    ASSERT_STREQ(a.c_str(), b[0].c_str());
    str = "185.182.81.131	1	1";
    a = "185.182.81.131";
    b = split(str, '\t');
    ASSERT_STREQ(a.c_str(), b[0].c_str());
}


TEST(GTest, TestSplitToInt){
    std::vector <int> a = {222, 173, 235, 246};
    std::string str = "222.173.235.246";
    std::vector <int> b = split_to_int(str, '.');

    for (unsigned i = 0; i < a.size(); ++i)
        ASSERT_EQ(a[i], b[i]);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
