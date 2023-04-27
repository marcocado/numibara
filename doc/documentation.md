# Documentation

## Creation of Vectors
```
std::vector<T> linvec(const T& start, const T& end, const int& number_elements)
```
You can create a linear ascending Vector with linvec.
```
// parameters for the setup
double start = 0.0;
double end = 10.0;
int number_of_elements = 1000;

// creating the linear ascending vector
std::vector<double> x_vector = numibara::linvec<double>(start, end, number_of_elements);
``` 

## Differentiation
### Differentiaton Types as std::string:
* forward
* backward
* middle

### Differentiation with Function and Variable Vector for Non-Uniform Grid
```
std::vector<T> differentiation(std::vector<T> function_vector, std::vector<T> variable_vector, std::string differentiation_type)
```
### Differentiation with Function and Delta for Uniform Grid
```
std::vector<T> differentiation(std::vector<T> function_vector, T delta, std::string differentiation_type)
```
You can differentiate a vector with function values with the following commands.
```
// parameters for the setup
double start = 0.0;
double end = 10.0;
int number_of_elements = 1000;
differentiation_type = 'forward';

// create x and f values
std::vector<double> x_vector = numibara::linvec<double>(start, end, number_of_elements);
std::vector<double> f_vector(number_of_elements);

// fill f_vector with f = x² + 2x - 4 values
for(int i = 0; i != number_of_elements; i++){
    f_vector[i] = x_vector[i]*x_vector[i] + 2.0*x_vector[i] - 4.0
}

// initialize a df_dx_vector and calculate it
std::vector<double> df_dx_vector(number_of_elements);
df_dx_vector = numibara::differentiation<double>(f_vector, x_vector, differentiation_type);
``` 

## Integration
### Integration Types as std::string:
* trapez
* simpson
* midpoint
### Integration with Function and Variable Vector for Non-Uniform Grid
```
T integration(const std::vector<T>& function_vector, const std::vector<T>& variable_vector, const std::string& integration_type)
```
### Integration with Function and Delta for Uniform Grid
```
T integration(const std::vector<T>& function_vector, const T& delta, const std::string& integration_type)
```
You can integrate a vector with function values with the following commands.
```
// parameters for the setup
double start = 0.0;
double end = 10.0;
int number_of_elements = 1000;
integration_type = 'simpson';

// create x and f values
std::vector<double> x_vector = numibara::linvec<double>(start, end, number_of_elements);
std::vector<double> f_vector(number_of_elements);

// fill f_vector with f = x² + 2x - 4 values
for(int i = 0; i != number_of_elements; i++){
    f_vector[i] = x_vector[i]*x_vector[i] + 2.0*x_vector[i] - 4.0
}

// initialize a df_dx_vector and calculate it
double integration_area;
df_dx_vector = numibara::integration<double>(f_vector, x_vector, integration_Type);
``` 