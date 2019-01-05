//
//  main.cpp
//  graph
//
//  Created by 云心逸 on 8/4/16.
//  Copyright © 2016 Errpro,Inc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "graph.hpp"

int xmain(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    Graph g;
    { // read graph
        std::ifstream ifs("graph/tinyG.txt");
        std::cin.rdbuf(ifs.rdbuf());
        std::cin >> g;
        ifs.close();
    }
    std::cout << "graph: " << std::endl << g << std::endl;
    return 0;
}
