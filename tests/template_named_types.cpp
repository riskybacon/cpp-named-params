#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "template_named_types"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <cpp_named_params/template_named_types.hpp>

BOOST_AUTO_TEST_CASE(test_named_types) {
    using namespace rb;

    using test_type =
        int_and_float<
            int_type<size_t>,
            float_type<double>
        >;

    int_and_float<
        int_type<size_t>,
        float_type<double>
    > i_and_f;

    constexpr bool test1 = std::is_same<
            test_type::int_type,
            size_t
        >{};

    constexpr bool test2 = std::is_same<
            test_type::float_type,
            double
        >{};

    BOOST_CHECK(test1 == true);
    BOOST_CHECK(test2 == true);
}
