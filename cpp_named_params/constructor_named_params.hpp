/**
 * Demonstrates how to use named parameters in a constructor.
 *
 * Limitation: it appears that a maximum of 8 parameters can be used.
 */
#ifndef CONSTRUCTOR_NAMED_VALUES_HPP_
#define CONSTRUCTOR_NAMED_VALUES_HPP_

#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>
#include <boost/parameter.hpp>
#include <boost/mpl/placeholders.hpp>

using boost::mpl::placeholders::_;
using boost::parameter::parameters;
using boost::parameter::required;
using boost::parameter::optional;
using boost::parameter::void_;

namespace rb {

// Create the parameter names
BOOST_PARAMETER_NAME(width)
BOOST_PARAMETER_NAME(height)

/**
 * Base class for the rectangle. The Boost Parameter library handles
 * named parameters in the constructor by passing an argument pack to the
 * the base class.
 */
template<typename T>
struct rectangle_params {
    using value_type = T;

    const value_type _width;
    const value_type _height;
    const value_type _area;

    // Helper macro for extracting a value for the argument parameter pack
    #define parameter_value(key) args[::boost::parameter::keyword<tag::key>()]

    // Helper macro for defining const, read-only accessors
    #define getter(key) \
    auto key() const -> \
        decltype(_ ## key) { \
        return _ ## key; \
    }

    template<typename ArgumentPack>
    rectangle_params(ArgumentPack const& args) :
        _width(parameter_value(width)),
        _height(parameter_value(height)),
        _area(_width * _height)
    {
        std::string errors = validate_parameters();

        if (errors.length() > 0) {
            throw std::runtime_error(errors);
        }
    }

    // Read-only accessors. Defined using a macro. No trailing semicolon!
    getter(width)
    getter(height)

    value_type area() const {
        return _area;
    }

    // Clean up macros
    #undef keyword_value
    #undef getter

    /**
     * Validate the parameters. Returns a zero-length string if there are no
     * errors
     *
     * @return a string with the errors
     */
    std::string validate_parameters() const {
        std::stringstream ss;
        bool first_error = true;

        if (width() < 0) {
            if (first_error) {
                ss << std::endl;
                first_error = false;
            }

            ss << "width (" << width() << ") must be greater than zero"
               << std::endl;
        }

        if (height() < 0) {
            if (first_error) {
                ss << std::endl;
                first_error = false;
            }

            ss << "height (" << height() << ") must be greater than zero"
               << std::endl;
        }

        return ss.str();
    }
};

/**
 * Rectangle class. Any code that relies on the parameters can go here
 */
template<typename T>
struct rectangle : rectangle_params<T> {
    using value_type = T;

    BOOST_PARAMETER_CONSTRUCTOR(rectangle, (rectangle_params<T>), tag,
        (required (width, (value_type)))
        (required (height, (value_type)))
    )
};

} // namespace rb

#endif /* end of include guard: CONSTRUCTOR_NAMED_VALUES_HPP_ */
