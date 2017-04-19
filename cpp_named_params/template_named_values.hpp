/**
 * Demonstrates how to use named values in template parameters.
 *
 * The boost parameter library is designed to use named types for template
 * parameters. This shows how to use values instead.
 *
 * Limitation: it appears that a maximum of 8 template parameters can be used.
 */
#ifndef TEMPLATE_NAMED_VALUES_HPP_
#define TEMPLATE_NAMED_VALUES_HPP_

#include <ratio>

#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>

#include <boost/parameter.hpp>
#include <boost/mpl/placeholders.hpp>

#include <cpp_named_params/template_named_value_macros.hpp>

using boost::mpl::placeholders::_;
using boost::parameter::parameters;
using boost::parameter::required;
using boost::parameter::optional;
using boost::parameter::void_;

namespace rb {

// Create the keywords
PARAMETER_TEMPLATE_KEYWORD_SIZE(width)
PARAMETER_TEMPLATE_KEYWORD_SIZE(height)
PARAMETER_TEMPLATE_KEYWORD_RATIO(scale)

// Create the template signature
using rectangle_signature = parameters<
    required<tag::width, std::is_object<_>>,
    required<tag::height, std::is_object<_>>,
    required<tag::scale, std::is_object<_>>
>;

/**
 * Rectangle that has width, height and scale. Area is computed at compile
 * time.
 */
template <class A, class B, class C>
struct rectangle {
    using args = typename rb::rectangle_signature::bind<
        A, B, C
    >::type;

    // Create accessors
    PARAMETER_TEMPLATE_ACCESSOR_SIZE(width)
    PARAMETER_TEMPLATE_ACCESSOR_SIZE(height)
    PARAMETER_TEMPLATE_ACCESSOR_RATIO(scale, float)

    /**
     * Constructor
     */
    rectangle() {
        if (validate_template()) {
            // Do something only if template validates
        }
    }

    /**
     * Validate the template parameters
     *
     * @return true if template parameters validated, false otherwise
     */
    static constexpr bool validate_template() {
        constexpr bool width_gt_0 = width() > 0;
        constexpr bool height_gt_0 = height() > 0;

        static_assert(width_gt_0, "width must be greater than 0");
        static_assert(height_gt_0, "height must be greater than 0");

        return width_gt_0 && height_gt_0;
    }

    /**
     * The area of the rectangle. The return value is calculated at compile
     * time. The compile time calculation is guaranteed by the constexpr
     * keyword.
     *
     * @return the area of the rectangle
     */
    static constexpr auto
    area() -> decltype (width() * height()) {
        return width() * height();
    }
};

} // namespace rb

#endif /* end of include guard: TEMPLATE_NAMED_VALUES_HPP_ */
