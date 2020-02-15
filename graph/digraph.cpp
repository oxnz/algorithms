//
//  digraph.cpp
//  graph
//
//  Created by 云心逸 on 8/7/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include "digraph.hpp"

std::istream& operator>>(std::istream &is, Digraph &g) {
    return is;
}

std::ostream& operator<<(std::ostream &os, const Digraph &g) {
    return os;
}