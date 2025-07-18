/**
 * @file debug.hpp
 * @brief header of the debug system
 * @author segcoredrakon
 * @version 0.0.3
 */

#include <fstream>
#include <filesystem>
#include <iostream>
#include "../include/debug.hpp"

namespace debugsys {
    void write_log(std::string data) {
        std::string fdebug;
        if (!std::filesystem::exists("logs/debug.log")) {
             fdebug = "===========[ DEBUG FILE FOR DEBUG PURPOSE ]===========";
        }
        std::ofstream f("logs/debug.log", std::ios::app);
        if (!std::filesystem::exists("logs/")) {
            std::filesystem::create_directories("logs/");
        }


        if (!f) {
            std::cerr << "CAUTION: cannot open the debug file\n";
            return;
        }
        if (!(fdebug == "")) {
            f << fdebug << "\n\n";
        }

        f << data << '\n';
        f.flush();
        f.close();
    }
}


