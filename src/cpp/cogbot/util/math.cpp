#include "cogbot/util/math.hpp"
#include <functional>
#include <numeric>
#include <vector>

namespace cogbot::util::math {
	long double fibonacci_iter(long double n) {
		long double x, y, z, i;
		for(x = 1.0L,
			y = 1.0L,
			i = 1.0L; i <= n; i++
		) {
			z = x + y;
			x = y;
			y = z;
		}
		return y;
	}
	long double factorial_stl(long double n) {
		std::vector<long double> vec(n);
		std::iota(vec.begin(), vec.end(), 1.0L);
		return std::reduce(vec.begin(), vec.end(), 1.0L, std::multiplies<>());
	}
}