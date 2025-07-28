#pragma once
#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <string_view>
#include <source_location>

namespace debugsys {
    // void write_log(std::string data);
    void write_log(const std::string_view& message = "no message",
                   const std::source_location location =
                   std::source_location::current());
}
#endif // DEBUG_HPP
