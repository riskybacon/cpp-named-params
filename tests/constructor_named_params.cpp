#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "constructor_named_values"

#include <boost/test/unit_test.hpp>
#include <cpp_named_params/constructor_named_params.hpp>

BOOST_AUTO_TEST_CASE(test_named_values) {
    using namespace rb;

    rectangle<float> rect(
        _width = 10,
        _height = 30
    );

    BOOST_CHECK(rect.width() == 10);
    BOOST_CHECK(rect.height() == 30);
    BOOST_CHECK(rect.area() == 10 * 30);
}
