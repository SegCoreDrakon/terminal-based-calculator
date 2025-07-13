/**
 * @file calculator.hpp
 * @brief the header base of the calculator system
 * @author SegCoreDrakon
 * @date 2025-03-31
 * @version 0.1.7
 */

#include <string>

#pragma once
#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

class Calculator {
public:
    Calculator();
    ~Calculator();

    int his = 1; ///< history variable

    void operation();

private:
    double m_number1;
    double m_number2;

    float m_result;

    /**
     * @details
     * remember the computation the
     * user choose and display it in string
     * version in history function
     * @see m_set_result() for where the var go
     */
    int m_oprt_type;

    /**
     * @defgroup Calculs
     * all basics computations,
     * the base of the program.
     *
     * @warning
     * don't change something if you are not sure
     * of what you do, this is the base of the project.
     * One error can collapse the whole project
     *
     * @addtogroup Calculs
     * @{
     */

    /**
     * @param val1 value 1 of the number
     * @param val2 value 2 of the number
     * @return addition of val1 and val2
     */
    double m_addition(double val1, double val2);

    /**
    * @param val1 value 1 of the number
    * @param val2 value 2 of the number
    * @return subtraction of val1 and val2
    */
    double m_subtraction(double val1, double val2);

    /**
    * @param val1 value 1 of the number
    * @param val2 value 2 of the number
    * @return multiplication of val1 and val2
    */
    double m_multiplication(double val1, double val2);

    /**
    * @param val1 value 1 of the number
    * @param val2 value 2 of the number
    * @return disivion of val1 and val2
    */
    double m_division(double val1, double val2);
    /** @} */ // end of groups Calculs

    /**
     * @brief check and apply correct options
     *
     * @details
     * the function check the user input from 1 to 7
     * and apply all functions and display the result, and display again
     * the menu_ui again if the number is not equal to the exit number (7)
     *
     * @warning
     * don't remove the default and else condition, it's a security to avoid
     * the possiblity of infinity loop, remove them can cause undefined action
     * and may crash the whole program
     */

    void m_handle_choice();

    void m_set_result();
    void m_input_number();
    double input();

    std::string m_operation_type(int oprt_type);

    void result(double computation);
};
void sleep_timer(int time);

#endif // CALCULATOR_HPP

