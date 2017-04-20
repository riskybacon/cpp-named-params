#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "constructor_named_values"

#include <boost/test/unit_test.hpp>
#include <cpp_named_params/function.hpp>

using rb::_width;
using rb::_height;

BOOST_AUTO_TEST_CASE(function1) {
    float area = rb::area(
        _width = 10.2,
        _height = 3.4
    );

    BOOST_CHECK_CLOSE(area, 10.2 * 3.4, 0.00001);
}
