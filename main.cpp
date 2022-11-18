#include <iostream>
#include "gtest/gtest.h"
#include "Class_Vector_dinamic.h"

using namespace std;

TEST(test, creation_with_n_1){
    Vector v(5);
    string str = "xxxxx";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

TEST(test, creation_with_n_2){
    Vector v(10);
    string str = "xxxxxxxxxx";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

TEST(test, creation_with_str_1){
    Vector v("101010");
    string str = "101010";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

TEST(test, creation_with_str_2){
    Vector v("101010101010");
    string str = "101010101010";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

//TEST(test, set_array_1){
//    Vector v("101010101010");
//    v.set_array("1010");
//    string str = "1010";
//    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
//}
//
//TEST(test, set_array_2){
//    Vector v("21021032");
//    v.set_array("0000");
//    string str = "0000";
//    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
//}

TEST(test, set_array_i_1){
    Vector v("11111");
    v.set_array_i(0, '0');
    string str = "01111";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

TEST(test, set_array_i_2){
    Vector v("00000");
    v.set_array_i(1, '1');
    string str = "01000";
    ASSERT_STREQ(v.get_string_array().c_str(), str.c_str());
}

TEST(test, get_res_vector_1){
    Vector v("00000");
    Vector v2("111111");
    Vector res = v.get_res_vector(v2);
    string str = "xxxxxx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, get_res_vector_2){
    Vector v("0");
    Vector v2("111111");
    Vector res = v.get_res_vector(v2);
    string str = "xxxxxx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, AND1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.and_operation(v2);
    string str = "0010100";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, AND2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.and_operation(v2);
    string str = "x000xx0";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, OR1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.or_operation(v2);
    string str = "1111111";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, OR2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.or_operation(v2);
    string str = "111x11x";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, EQ1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.eq_operation(v2);
    string str = "0010100";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, EQ2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.eq_operation(v2);
    string str = "x00xxxx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, MORE1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.more_operation(v2);
    string str = "0000001";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, MORE2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.more_operation(v2);
    string str = "x10xxxx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, MOREEQ1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.more_eq_operation(v2);
    string str = "0010101";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, MOREEQ2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.more_eq_operation(v2);
    string str = "x1011xx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, LESS1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.more_operation(v2);
    string str = "0000001";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, LESS2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.more_operation(v2);
    string str = "x10xxxx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, LESSEQ1){
    Vector v1("0010101");
    Vector v2("1111110");
    Vector res = v1.more_eq_operation(v2);
    string str = "0010101";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, LESSEQ2){
    Vector v1("2102150");
    Vector v2("1010313");
    Vector res = v1.more_eq_operation(v2);
    string str = "x1011xx";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, get_in_use_1){
    Vector v1("0010101");
    ASSERT_EQ(v1.get_in_use(), 7);
}

TEST(test, get_in_use_2){
    Vector v1("2102150");
    ASSERT_EQ(v1.get_in_use(), 7);
}

TEST(test, NOT1){
    Vector v1("0010101");
    Vector res = v1.not_operation();
    string str = "1101010";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, NOT2){
    Vector v1("2102150");
    Vector res = v1.not_operation();
    string str = "x01x0x1";
    ASSERT_STREQ(res.get_string_array().c_str(), str.c_str());
}

TEST(test, certainty1){
    Vector v1("0010101");
    ASSERT_TRUE(v1.certainty());
}

TEST(test, certainty2){
    Vector v1("2102150");
    ASSERT_FALSE(v1.certainty());
}

int _tmain() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}