#include <random>

namespace helpers {
    uint32_t GenerateNumberInRange(int min, int max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);

        return static_cast<uint32_t>(dist(mt));
    };
}
