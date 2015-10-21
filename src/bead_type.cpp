#include "bead_type.hpp"

std::pair<BeadType, BeadType> make_sorted_pair(
    const BeadType& type0, const BeadType& type1) {
    BeadType former, latter;
    if (type0 < type1) {
        former = type0;
        latter = type1;
    } else {
        former = type1;
        latter = type0;
    }
    return std::make_pair(former, latter);
}
