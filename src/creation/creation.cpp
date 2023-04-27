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

namespace numibara {
    /**
     * Function name: Linvec
     * 
     * Description: Creation of values with linear ascending order 
     * 
     * Parameters:
     * - function_vector: f-Values f(x)
     * - delta: difference between each x
     * - differentiation_type: method for the numerical differentiation
     * 
     * Return value: differentiation-Values f'(x)
     */
    template<typename T>
    std::vector<T> linvec(const T& start, const T& end, const int& number_elements){
        std::vector<T> created_vector(number_elements);

        if(number_elements == 1){
            created_vector[0] = start;
            return created_vector;
        }
        else{
            T T_number_elements = static_cast<T>(number_elements);
            T delta = (end - start)/T_number_elements;
            T current_value = start;

            for(auto& current_element : created_vector){
                current_element = current_value;
                current_value = current_value + delta;
            }
            return created_vector;
        }
    }
}