/**
 * @file calculator.cpp
 * @brief the base of the calculator system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.2.7
 */


#include <iostream>
#include <thread>
#include <chrono>
#include <string>

#include "../include/calculator.hpp"
#include "../include/calculator_system.hpp"
#include "../include/save_system.hpp"
#include "../include/terminal_ui.hpp"
#include "../include/debug.hpp"

UI UI;
CalculatorSystem calc_sys;

Calculator::Calculator() {};
Calculator::~Calculator() {};

double Calculator::m_division(double val1,  double val2) {
    if (val1 == 0 || val2 == 0) {
        std::cout << "cannot divide by 0\n";
        return 0;
    } else {
        return val1 / val2;
    }
}

double Calculator::m_addition(double val1,  double val2) {
    return val1 + val2;
}

double Calculator::m_subtraction(double val1,  double val2) {
    return val1 - val2;
}

double Calculator::m_multiplication(double val1,  double val2) {
    return val1 * val2;

}

void Calculator::operation() {
    debugsys::write_log("operation function called at line: "
                        + std::to_string(__LINE__ - 2));
    UI.clear();
    UI.menu_display();
    UI.move(2, 13, false, false);
    m_handle_choice();
}

void Calculator::m_set_result() {
    debugsys::write_log("m_set_result function called at line: "
                        + std::to_string(__LINE__ - 2));

    UI.move(1, 3, true, false);

    debugsys::write_log("result of the computation at line: "
                        + std::to_string(__LINE__ - 2));

    std::cout << "result  | " << m_result;
    std::cout.flush();

    history(m_result,  m_operation_type(m_oprt_type));
    sleep_timer(3);
    operation();
}

void Calculator::m_input_number() {
    debugsys::write_log("m_input_number function called at line: "
                        + std::to_string(__LINE__ - 2));
    UI.number_display();
    UI.move(6, 2, false, false);

    double number1 {input()};
    debugsys::write_log("number 1 var set at line: "
                        + std::to_string(__LINE__ - 2));

    UI.move(1, 2, true, false);

    double number2 {input()};
    debugsys::write_log("number 2 var set at line: "
                        + std::to_string(__LINE__ - 2));

    m_number1 = static_cast<float>(number1);
    m_number2 = static_cast<float>(number2);

    debugsys::write_log("number 1 and number 2 var converted to float"
                        "and set to m_number1 and m_number2, at line: "
                        + std::to_string(__LINE__ - 3));
}

double Calculator::input() {
    debugsys::write_log("input function called at line: "
                     + std::to_string(__LINE__ - 2));
    double userinput {};
    std::cout << "number   | ";
    std::cin >> userinput;
    debugsys::write_log("user set number");
    std::cin.clear();
    std::cin.ignore(9999, '\n');

    return userinput;
}

void Calculator::m_handle_choice() {
    debugsys::write_log("m_handle_choice function called at line: "
                        + std::to_string(__LINE__ - 2));

    do {
        int oprt;
        std::cin >> oprt;

        // we use a var to display the type in the history
        m_oprt_type = oprt;
        debugsys::write_log("var m_operation_type: "
                            + std::to_string(m_oprt_type)
                            + " at line: "
                            + std::to_string(__LINE__ - 4));

        switch (int(oprt)) {
            case 1:
                debugsys::write_log("addition performed at line: "
                                    + std::to_string(__LINE__ - 2));
                m_input_number();
                result(m_addition(m_number1, m_number2));
                break;

            case 2:
                debugsys::write_log("substraction performed at line: "
                                    + std::to_string(__LINE__ - 2));
                m_input_number();
                result(m_subtraction(m_number1, m_number2));
                break;

            case 3:
                debugsys::write_log("multiplication performed at line: "
                                    + std::to_string(__LINE__ - 2));
                m_input_number();
                result(m_multiplication(m_number1, m_number2));
                break;

            case 4:
                debugsys::write_log("division performed at line: "
                                    + std::to_string(__LINE__ - 2));
                m_input_number();
                result(m_division(m_number1, m_number2));
                break;

            case 5:
                debugsys::write_log("checking log at line: "
                                    + std::to_string(__LINE__ - 2));
                calc_sys.check_logs();
                break;

            case 6:
                debugsys::write_log("deleting logs at line: "
                                    + std::to_string(__LINE__ - 2));
                calc_sys.delete_logs();
                operation();
                break;

            case 7:
                debugsys::write_log("leaving the program at line: "
                                    + std::to_string(__LINE__ - 2));
                calc_sys.leave_program();
                break;

            default:
                debugsys::write_log("unknow operand set by user at line: "
                                    + std::to_string(__LINE__ - 2));
                calc_sys.uknown_option();

                // to avoid infinite loop
                // when an uncorrect numbed is provided
                oprt = 0;
                if (int(oprt) == 0) {
                    debugsys::write_log("operand set to zero at line: "
                                        + std::to_string(__LINE__ - 2));
                    UI.clear();
                    std::cin.clear();
                    UI.menu_display();
                    UI.move(2, 13, false, false);
                    break;
                }

        } // end of switch condition

    } while (true);
}

/**
 * @brief return the return type for history
 * @see m_set_result()
 */
std::string Calculator::m_operation_type(int oprt_type) {
    debugsys::write_log("m_operation_type function called at line: "
                        + std::to_string(__LINE__ - 2));

    switch (oprt_type) {
    case 1:
        return "addition";
        break;

    case 2:
        return "substraction";
        break;

    case 3:
        return "multiplication";
        break;

    case 4:
        return "division";
        break;

    default:
        return "ERROR";
        break;
    }
}

// used for making timer without write thread function
void sleep_timer(int time) {
    std::this_thread::sleep_for(std::chrono::seconds(time));
}

void Calculator::result(double computation) {
    debugsys::write_log("result function called at line: "
                        + std::to_string(__LINE__ - 2));
    m_result = static_cast<float>(computation);
    m_set_result();
}
