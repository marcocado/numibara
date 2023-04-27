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

#include "differentiation_types.cpp"

namespace numibara {
    
    /**
     * Function name: Non-Uniform Differentiation
     * 
     * Description: Numerical Differentiation for non-uniform function values. 
     * 
     * Parameters:
     * - function_vector: f-Values f(x)
     * - variable_vector: x-Values
     * - differentiation_type: method for the numerical differentiation
     * 
     * Return value: differentiation-Values f'(x)
     */
    template<typename T>
    std::vector<T> differentiation(std::vector<T> function_vector, std::vector<T> variable_vector, std::string differentiation_type){
        int n_variable = variable_vector.size();
        int n_value = function_vector.size();
        std::vector<T> differentiation_vector(n_value);

        if(n_variable != n_value){
            std::cout << 'Error. Received vectors have a different size\n';
        }

        switch (enumerate_differentiation_type(differentiation_type)){
        // middle
        case 0:
            for(int i = 1; i != n_value; i++){
                differentiation_vector[i] = (function_vector[i+1]-function_vector[i-1])/(variable_vector[i+1]-variable_vector[i-1]);
            }
            differentiation_vector[0] = (function_vector[1]-function_vector[0])/(variable_vector[1]-variable_vector[0]);
            differentiation_vector[n_value-1] = (function_vector[n_value-1]-function_vector[n_value-2])/(variable_vector[n_value-1]-variable_vector[n_value-2]);
            break;
        // forward
        case 1:
            for(int i = 0; i != n_value-1; i++){
                differentiation_vector[i] = (function_vector[i+1]-function_vector[i])/(variable_vector[i+1]-variable_vector[i]);
            }
            differentiation_vector[n_value-1] = (function_vector[n_value-1]-function_vector[n_value-2])/(variable_vector[n_value-1]-variable_vector[n_value-2]);
            break;
        // backward
        case 2:
            for(int i = 1; i != n_value; i++){
                differentiation_vector[i] = (function_vector[i]-function_vector[i-1])/(variable_vector[i]-variable_vector[i-1]);
            }
            differentiation_vector[0] = (function_vector[1]-function_vector[0])/(variable_vector[1]-variable_vector[0]);
            break;
        }

        return differentiation_vector;
    }

    /**
     * Function name: Uniform Differentiation
     * 
     * Description: Numerical Differentiation for uniform function values. 
     * 
     * Parameters:
     * - function_vector: f-Values f(x)
     * - delta: difference between each x
     * - differentiation_type: method for the numerical differentiation
     * 
     * Return value: differentiation-Values f'(x)
     */
    template<typename T>
    std::vector<T> differentiation(std::vector<T> function_vector, T delta, std::string differentiation_type){
        int n_value = function_vector.size();
        std::vector<T> differentiation_vector(n_value);

        switch (enumerate_differentiation_type(differentiation_type)){
        // middle
        case 0:
            for(int i = 1; i != n_value-1; i++){
                differentiation_vector[i] = (function_vector[i+1]-function_vector[i-1])/(2*delta);
            }
            differentiation_vector[0] = (function_vector[1]-function_vector[0])/delta;
            differentiation_vector[n_value-1] = (function_vector[n_value-1]-function_vector[n_value-2])/delta;
            break;
        // forward
        case 1:
            for(int i = 0; i != n_value-1; i++){
                differentiation_vector[i] = (function_vector[i+1]-function_vector[i])/delta;
            }
            differentiation_vector[n_value-1] = (function_vector[n_value-1]-function_vector[n_value-2])/delta;
            break;
        // backward
        case 2:
            for(int i = 1; i != n_value; i++){
                differentiation_vector[i] = (function_vector[i]-function_vector[i-1])/delta;
            }
            differentiation_vector[0] = (function_vector[1]-function_vector[0])/delta;
            break;
        }

        return differentiation_vector;
    }
}