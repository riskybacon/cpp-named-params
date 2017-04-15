#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "template_named_values"

#include <boost/test/unit_test.hpp>
#include <iostream>
#include <include/template_named_values.hpp>

BOOST_AUTO_TEST_CASE(test_named_values) {
    using namespace example;

    rectangle<
        width  < 10   >,
        height < 30   >,
        scale  < 1, 3 >
    > rect;

    BOOST_CHECK(rect.width() == 10);
    BOOST_CHECK(rect.height() == 30);
    BOOST_CHECK(rect.area() == 10 * 30);
    BOOST_CHECK(rect.scale() == float(1) / float(3));
}
