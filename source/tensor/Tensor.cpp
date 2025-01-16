#include "Tensor.hpp"

#include <stdexcept>
#include <exception>


namespace tensor {
    Tensor::Tensor(void* data, int* shape, int nDim) {
        if(data == nullptr || shape == nullptr || nDim == 0) {
            throw std::invalid_argument("Invalid input for creating Tensor");
        }

        _strides = (int*) malloc(nDim * sizeof(int));
        if(_strides == nullptr) {
            throw std::bad_alloc();
        }

        _data = data;
        _shape = shape;
        _nDim = nDim;

        int strideValue = 1;
        for(int i = 0; i < _nDim; i++) {
            size = size * _shape[i];
            _strides[_nDim - 1 - i] = strideValue;
            strideValue *= _shape[i];
        }


    }   
}                       