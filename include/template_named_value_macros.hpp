#ifndef TEMPLATE_NAMED_VALUE_MACROS_HPP_
#define TEMPLATE_NAMED_VALUE_MACROS_HPP_

/**
 * Wrapper for values of type size_t
 */
template<size_t V>
struct size_value {
    static constexpr size_t value = V;
};

/**
 * Macro to simplify the creation of template keyword tags that refer to size
 */
#define PARAMETER_TEMPLATE_KEYWORD_SIZE(keyword)                             \
namespace tag { struct keyword; }                                            \
template <size_t V>                                                          \
struct keyword                                                               \
  : boost::parameter::template_keyword<tag::keyword,size_value<V>> {};

/**
 * Macro for creating accessor functions for size keywords. Call this macro
 * inside the class definition.
 */
#define PARAMETER_TEMPLATE_ACCESSOR_SIZE(keyword)                            \
static constexpr decltype(boost::parameter::value_type<                      \
        args, tag::keyword                                                   \
    >::type::value                                                           \
) keyword() {                                                                \
    return boost::parameter::value_type<args, tag::keyword>::type::value;    \
}

/**
 * Macro for creating ratio keywords for use in named template parameter
 * values.
 *
 * Floats cannot be used as template parameters, only integers. To get around
 * this, use std::ratio to represent these values.
 *
 * @param keyword   Name of the ratio keyword
 */
#define PARAMETER_TEMPLATE_KEYWORD_RATIO(keyword)                            \
namespace tag { struct keyword; }                                            \
template <intmax_t N, intmax_t D>                                            \
struct keyword                                                               \
  : boost::parameter::template_keyword<tag::keyword,std::ratio<N,D>> {};

/**
 * Macro for creating read only accessor function for ratio keywords
 *
 * @param keyword   Name of the accessor function
 * @param tp        The return type
 */
#define PARAMETER_TEMPLATE_ACCESSOR_RATIO(keyword, tp)                       \
static constexpr tp keyword() {                                              \
    tp num = boost::parameter::value_type<args, tag::keyword>::type::num;    \
    tp den = boost::parameter::value_type<args, tag::keyword>::type::den;    \
    return num / den;                                                        \
}

#endif /* end of include guard: TEMPLATE_NAMED_VALUE_MACROS_HPP_ */
