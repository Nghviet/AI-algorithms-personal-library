#ifndef __AI_IMPLEMENTATION_TENSOR_HPP__
#define __AI_IMPLEMENTATION_TENSOR_HPP__

namespace tensor {
    class Tensor {
    public:
        Tensor* reshape_tensor(int* new_shape, int dim);

        float get_item(int* indices);
        

    private:
        void* _data;
        void* _strides;
        void* _shape;
        int _nDim;
        int size = 1;

        char* _device = "cpu";
        
        int _variableSize = sizeof(float); // 4 for FP32 and 1 for INT8, need verification

        Tensor(void* data, void* shape, int nDim);

        ~Tensor();
    };
}

#endif