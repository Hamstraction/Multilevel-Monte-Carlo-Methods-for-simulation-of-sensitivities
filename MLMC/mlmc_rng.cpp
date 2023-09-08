#include <random>           // C++11 random number generators
#include <functional>
//Use Mersenne twister as generator
std::mt19937 rng;

std::uniform_real_distribution<float> uniform(0.0f,1.0f);
std::normal_distribution<float> normal(0.0f,1.0f);
std::exponential_distribution<float> exponential(1.0f);

auto next_uniform     = std::bind(std::ref(uniform),     std::ref(rng));
auto next_normal      = std::bind(std::ref(normal),      std::ref(rng));
auto next_exponential = std::bind(std::ref(exponential), std::ref(rng));

void rng_initialisation() {
    rng.seed(1234);
    uniform.reset();
    normal.reset();
    exponential.reset();
}

void rng_termination() {
}


