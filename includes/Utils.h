#ifndef A5_UTILS_H
#define A5_UTILS_H

#include <cstddef>

namespace cpp_custom {
namespace Utils {
constexpr std::size_t Log2(std::size_t x) {
    return x == 1 ? 0 : 1 + Log2(x / 2);
}
} // namespace Utils
} // namespace cpp_custom

#endif // !A5_UTILS_H
