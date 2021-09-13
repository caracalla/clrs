#pragma once

#include <random>


namespace clrs {
	namespace random {
		namespace {
			static bool randomReady = false;
			static std::mt19937 mt;

			void initRandom() {
				std::random_device rd;
				mt = std::mt19937(rd());
			}
		}

		double randomDouble(double lower_bound, double upper_bound) {
			if (!randomReady) {
				initRandom();
			}

			std::uniform_real_distribution<double> dist(lower_bound, upper_bound);

			return dist(mt);
		}

		int randomInt(int lower_bound, int upper_bound) {
			return (int)randomDouble(lower_bound, upper_bound);
		}
	}
}
