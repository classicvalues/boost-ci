//
// Copyright (c) 2020 Mateusz Loskot <mateusz@loskot.net>
//
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

// Use some STL components just to quick check compilers
#include <string>
#include <map>
#include <vector>
// Use our dummy lib
#include <boost/boost-ci/boost_ci.hpp>
// And the usual test framwork
#include <boost/core/lightweight_test.hpp>
// Check that including a file from the same directory works
#include "test2.hpp"

int main()
{
    const bool isMSVC = MSVC_VALUE;
    std::map<std::string, std::vector<int> > map;
    map["result"].push_back(boost::boost_ci::get_answer());
    // Specifically crafted condition to check for coverage from MSVC and non MSVC builds
    if(isMSVC)
    {
      BOOST_TEST_EQ(boost::boost_ci::get_answer(), 21);
    } else
    {
      BOOST_TEST_EQ(boost::boost_ci::get_answer(), 42);
    }
    BOOST_TEST_EQ(map["result"].size(), 1u);
    return boost::report_errors();
}
