#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>
#include <boost/parameter.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/parameter.hpp>

namespace rb {

using mpl_::_;

// Define the parameter names. Placed into the tag namespace
BOOST_PARAMETER_NAME(width);
BOOST_PARAMETER_NAME(height);

// Define the function
BOOST_PARAMETER_FUNCTION(
    (float),   // Return type
    area,      // Function name
    tag,       // Namespace for the parameter names
    (required (width, (float)))
    (required (height, (float)))
) {
    return width * height;
}

} // namespace rb

#endif /* end of include guard: FUNCTION_HPP_ */
