#ifndef TEMPLATE_NAMED_TYPES_HPP_
#define TEMPLATE_NAMED_TYPES_HPP_

#include <boost/parameter/keyword.hpp>
#include <boost/parameter/name.hpp>
#include <boost/parameter/preprocessor.hpp>
#include <boost/parameter.hpp>
#include <boost/mpl/placeholders.hpp>

namespace rb {

// Create keywords in tag namespace
BOOST_PARAMETER_TEMPLATE_KEYWORD(int_type)
BOOST_PARAMETER_TEMPLATE_KEYWORD(float_type)

using boost::parameter::parameters;
using boost::parameter::required;
using boost::mpl::placeholders::_;

// Create the template signature
using int_and_float_signature = parameters<
    required<tag::float_type, std::is_object<_>>,
    required<tag::int_type, std::is_object<_>>
>;

template<typename A0, typename A1>
struct int_and_float {

    using args = typename rb::int_and_float_signature::bind<A0, A1>::type;

    using float_type = typename
        boost::parameter::value_type<
            args, tag::float_type
        >::type;

    using int_type = typename
    boost::parameter::value_type<
            args, tag::int_type
        >::type;
};

} // namespace rb

#endif /* end of include guard: TEMPLATE_NAMED_TYPES_HPP_ */
