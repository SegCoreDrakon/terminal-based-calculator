/**
 * @file calculator_system.cpp
 * @brief the system for all big functions who can not be in the main calculator
 * @author SegCoreDrakon
 * @date 2025-05-2
 * @version 0.0.12
 */

#include <filesystem>
#include <iostream>
#include <thread>
#include <chrono>

#include "../include/calculator_system.hpp"
#include "../include/save_system.hpp"
#include "../include/terminal_ui.hpp"

UI ui;
void CalculatorSystem::delete_logs() const {
    ui.del_logs_display();
    ui.move(2, 3, false, false);
    std::cout << "removing the logs folder...";
    std::cout.flush();
    std::filesystem::remove("logs/history.log");
    std::filesystem::remove("logs/his_count.txt");
    sleep_timer(1);
    ui.move(0, 3, true, false);
    ui.move(1, 32, false, true);
    std::cout << "     logs folder removed      ";
    std::cout.flush();
    sleep_timer(2);
    ui.clear();
}

void CalculatorSystem::check_logs() const {
    ui.clear();
    ui.logs_display();
    sleep_timer(2);
    ui.clear();
    ui.menu_display();
    ui.move(2, 13, false, false);
}

void CalculatorSystem::leave_program() const {
    ui.move(1, 13, false, false);
    save_history_count();
    ui.empty_display();
    ui.move(2, 2, false, false);
    std::cout << "thank to use my calculator, bye!\n\n";
    std::exit(0);
}

void CalculatorSystem::uknown_option() const {
    ui.move(1, 13, false, false);
    std::cout << "unknow option!\n";
    sleep_timer(3);
    std::cin.ignore();
    std::cin.clear();
}

void CalculatorSystem::sleep_timer(int sec) const {
    std::this_thread::sleep_for(std::chrono::seconds(sec));
}
