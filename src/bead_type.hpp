#ifndef __BEAD_TYPE_HPP
#define __BEAD_TYPE_HPP

#include <string>
#include <map>

using BeadType = std::string;

std::pair<BeadType, BeadType> make_sorted_pair(
    const BeadType& type0, const BeadType& type1);

#endif /* __BEAD_TYPE_HPP */
