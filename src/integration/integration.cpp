/**
 * MIT License
 * 
 * Copyright (c) 2023 Marco Werner
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
*/

#include "integration_types.cpp"

namespace numibara {

    /**
     * Function name: Non-Uniform Integration
     * 
     * Description: Numerical Integration for non-uniform function values. 
     * 
     * Parameters:
     * - function_vector: f-Values f(x)
     * - variable_vector: x-Values
     * - integration_type: method for the numerical integration
     * 
     * Return value: integration-Values ∫f(x)
     */
    template<typename T>
    T integration(const std::vector<T>& function_vector, const std::vector<T>& variable_vector, const std::string& integration_type){
        int n_variable = variable_vector.size();
        int n_value = function_vector.size();
        T integral_value = 0.0;

        if(n_variable != n_value){
            std::cout << "Error. Received vectors have a different size\n";
        }

        switch (enumerate_integration_type(integration_type)){
        // trapez
        case 0:
            for(int i = 0; i != n_value-1; i++){
                integral_value = integral_value + (0.5*(function_vector[i+1] + function_vector[i])*(variable_vector[i+1] - variable_vector[i]));
            }
            break;
        // simpson
        case 1:
            for(int i = 0; i != n_value-2; i= i + 2){
                integral_value = integral_value + ((variable_vector[i+2] - variable_vector[i+1])/3.0)*(4.0*function_vector[i+1] + 2.0*function_vector[i+2]);
            }
            integral_value = integral_value + ((variable_vector[1] - variable_vector[0])/6.0)*(function_vector[0]);
            integral_value = integral_value + ((variable_vector[n_value-1] - variable_vector[n_value-2])/6.0)*(function_vector[n_value-1]);
            break;
        //midpoint
        case 2:
            for(int i = 1; i != n_value-1; i++){
                integral_value = integral_value + 0.5*function_vector[i]*(variable_vector[i+1] - variable_vector[i-1]);
            }
            integral_value = integral_value + 0.25*function_vector[0]*(variable_vector[1] - variable_vector[0]);
            integral_value = integral_value + 0.25*function_vector[n_value-1]*(variable_vector[n_value-1] - variable_vector[n_value-2]);
            break;
        }

        return integral_value;
    }

    /**
     * Function name: Uniform integration
     * 
     * Description: Numerical integration for uniform function values. 
     * 
     * Parameters:
     * - function_vector: f-Values f(x)
     * - delta: difference between each x
     * - integration_type: method for the numerical integration
     * 
     * Return value: integration-Values ∫f(x)
     */
    template<typename T>
    T integration(const std::vector<T>& function_vector, const T& delta, const std::string& integration_type){
        T integral_value = 0.0;
        int n_value = function_vector.size();

        switch (enumerate_integration_type(integration_type)){
        // trapez
        case 0:
            for(int i = 0; i != n_value-1; i++){
                integral_value = integral_value + 0.5*(function_vector[i+1] + function_vector[i])*delta;
            }
            break;
        //simpson
        case 1:
            for(int i = 0; i != n_value-2; i= i + 2){
                integral_value = integral_value + (delta/3.0)*(4.0*function_vector[i+1] + 2.0*function_vector[i+2]);
            }
            integral_value = integral_value + (delta/3.0)*(function_vector[0] + function_vector[n_value-1]);
            break;
        // midpoint
        case 2:
            for(int i = 1; i != n_value-1; i++){
                integral_value = integral_value + function_vector[i]*delta;
            }
            integral_value = integral_value + 0.5*function_vector[0]*delta;
            integral_value = integral_value + 0.5*function_vector[n_value-1]*delta;
            break;
        }

        return integral_value;
    }
}