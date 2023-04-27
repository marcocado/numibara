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
     * Function name: Cummulative Product
     * 
     * Description: Iterates through all values of a vector and make a cummulative sum of them. 
     * 
     * Parameters:
     * - value_vector: vector with values
     * 
     * Return value: cummulated sum of all elements of the vector
     */
    template<typename T>
    T cummulative_sum(const std::vector<T>& value_vector){
        T sum_value = 0.0;
        for(auto& current_value : value_vector){
            sum_value = sum_value + current_value;
        }
        return sum_value
    }

    /**
     * Function name: Cummulative Product
     * 
     * Description: Iterates through all values of a vector and make a cummulative product of them. 
     * 
     * Parameters:
     * - value_vector: vector with values
     * 
     * Return value: cummulated product of all elements of the vector
     */
    template<typename T>
    T cummulative_prod(const std::vector<T>& value_vector){
        T sum_value = 1.0;
        for(auto& current_value : value_vector){
            sum_value = sum_value*current_value;
        }
        return sum_value
    }
}
