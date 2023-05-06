#include <gtest/gtest.h>

#include <iostream>

#include "shared_ptr.h"
#include "unique_ptr.h"

int main(int argc, char **argv) {
    if (false)  // make false to run unit-tests
    {
        // debug section

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}