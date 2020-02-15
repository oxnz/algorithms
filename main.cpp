/*
 * Filename:	main.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2020-02-13 00:54:42 CST
 * Last-update:	2020-02-13 00:54:42 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2020 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include "config.h"

using namespace std;

int main(int argc, char *argv[]) {
    std::cout << argv[0] << ":";
    for (int i = 1; i < argc; ++i)
        std::cout << " " << argv[i];
    std::cout << "\n";

    return 0;
}

