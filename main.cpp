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
#include "numibara.hpp"

int main(void){
    std::vector<double> x_vector = numibara::linvec<double>(0.0, 10.0, 1000);
    double delta = 10.0/1000.0;
    double x = 0.0;
    std::vector<double> y_vector(1000);

    for(auto& current_y : y_vector){
        current_y = x*x;
        x = x + delta;
    }

    for(auto& current_x : x_vector){
        std::cout << current_x << "\n";
    }

    std::string type_diff = "simpson";

    double integration_value = numibara::integration<double>(y_vector, x_vector, type_diff);

    std::cout << integration_value << "\n";

    return 0;
}