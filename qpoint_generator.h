/**
 * Random point generator.
 */

#ifndef QPOINT_GENERATOR_H
#define QPOINT_GENERATOR_H

#include "randomize/randomize.hpp"

#include <QPointF>

#include <algorithm>
#include <iterator>
#include <vector>

/**
 * @brief The qpoint_generator struct enables
 * generating QPointF.
 */
struct qpoint_generator {
    /**
     * @brief minimum value.
     * @return the minimum generated value.
     */
    static float& min() {
        static float min_value{-40.};
        return min_value;
    }

    /**
     * @brief maximum value.
     * @return the maximum generated value.
     */
    static float& max() {
        static float max_value{40.};
        return max_value;
    }

    /**
     * @brief maximum number of points.
     * @return the maximum number of generated points.
     */
    static std::size_t& number() {
        static std::size_t number_value{1000};
        return number_value;
    }

    /**
     * @brief Generate a point.
     * @return the generated point.
     */
    static QPointF generate() {
        auto rand = randomize::get_rand(min(), max());
        return QPointF{rand(), rand()};
    }

    /**
     * Generate between 1 and number() points in the input container.
     * @param first - iterator to the first element of the input container where
     * points are to be added.
     * @return iterator to the last generated point in the container.
     */
    template <typename OutputIt>
    static OutputIt generate(OutputIt first) {
        const auto nb = randomize::rand(1ul, number());
        return std::generate_n(first, nb, [] { return qpoint_generator::generate(); });
    }

    /**
     * @brief Generate points into a vector.
     * @return the vector of generated points.
     */
    static std::vector<QPointF> generate_points() {
        std::vector<QPointF> res;
        generate(std::back_inserter(res));
        return res;
    }
};

#endif // QPOINT_GENERATOR_H
