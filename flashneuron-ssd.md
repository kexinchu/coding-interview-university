# Flashneuron - SSD

- based on pytorch(was contained with Pytorch Code)

### Code Structure (Actually, It is the structure of Pytorch Code)

- android : Demos of deploying models to android services
- c10 : Core library files that work everywhere, both server and mobile. We are slowly moving pieces from ATen/core here. 
- aten : C++ tensor library for PyTorch (no autograd support)
  - src : contains the low-level tensor libraries for PyTorch.
    - TH : Torch, THC : Torch Cuda, THCUNN - Torch cunn :  Legacy library code from the original Torch. Try not to add things here; we're slowly porting these to native.
      - generic - Contains actual implementations of operators, parametrized over scalar_t.
    - ATen : **A Tensor Library, contains the definition, storage, operation functions here. Was combined with CPU/GPU**
      - core : Core functionality of ATen. This is migrating to top-level c10 folder.
      - native : Modern implementations of operators.
        - cpu : Not actually CPU implementations of operators, but specifically implementations which are compiled with processor-specific instructions, like AVX.
        - cuda : **CUDA implementations of operators.**
        - sparse : CPU and CUDA implementations of COO sparse tensor operations
        - mkl mkldnn miopen cudnn : implementations of operators which simply bind to some backend library.
        - quantized : Quantized tensor operation implementations.
- torch - The actual PyTorch library. Everything that is not in csrc is a Python module, following the PyTorch Python frontend module structure.
  - csrc - C++ files composing the PyTorch library. Files in this directory tree are a mix of Python binding code, and C++ heavy lifting. Consult setup.py for the canonical list of Python binding files; conventionally, they are often prefixed with python_.
    - jit - Compiler and frontend for TorchScript JIT frontend.
    - autograd - Implementation of reverse-mode automatic differentiation.
    - api - The PyTorch C++ frontend.
    - distributed - Distributed training support for PyTorch.
- tools - Code generation scripts for the PyTorch library.
- test - Python unit tests for PyTorch Python frontend.
  - test_torch.py - Basic tests for PyTorch functionality.
  - test_autograd.py - Tests for non-NN automatic differentiation support.
  - test_nn.py - Tests for NN operators and their automatic differentiation.
  - test_jit.py - Tests for the JIT compiler and TorchScript.
  - ...
  - cpp - C++ unit tests for PyTorch C++ frontend.
  - expect - Automatically generated "expect" files which are used to compare against expected output.
  - onnx - Tests for ONNX export functionality, using both PyTorch and Caffe2.
- caffe2 - The Caffe2 library.
  - core - Core files of Caffe2, e.g., tensor, workspace, blobs, etc.
  - operators - Operators of Caffe2.
  - python - Python bindings to Caffe2.
  - ...

### FlashNeuron was combined with GPU memory resouces and SSD-GPU communication => aten/src/ATen/native/cuda/flashneuron.h

- defined a structure of FN_Memory and provide some basic functions
- Structure:
  - aten/src/ATen/native/cuda/flashneuron.h
  - aten/src/ATen/native/cuda/flashneuron.cu 
```
class FN_memory {
  FN_memory();    // init a cuda event

  // malloc memory space on GPU;
  // BLK_SZ = 4096
  // return gpu_ptr : the address of malloced GPU memory space
  void device_malloc(void** gpu_ptr, size_t size);
  void device_malloc_reverse(void** gpu_ptr, size_t size);

  void device_free(void* addr, size_t size);

  size_t device_occupancy_size();
  size_t p2p_occupancy_size();

  // return the free size of device memeory
  double device_occupancy();
  double device_occupancy_future(size_t size);
  double p2p_occupancy();

  // malloc p2p
  void p2p_malloc(void** gpu_ptr, size_t size);
  void p2p_free(void* addr, size_t size);
}
```

### Where the code was called
- Use GPU => aten/src/ATen/native/cuda/Copy.cu 
- FN_copy_kernel_cuda
  - judge the communication type

    ```
    // Copy between CPU and GPU
    cuda::OptionalCUDAGuard device_guard;
    cudaMemcpyKind kind;
    if (dst_device.is_cuda() && src_device.is_cpu()) {
        device_guard.set_device(dst_device);
        kind = cudaMemcpyHostToDevice;
        fn_memorymanager.event_arr_h2d[tid] = true;
    } else if (dst_device.is_cpu() && src_device.is_cuda()) {
        device_guard.set_device(src_device);
        kind = cudaMemcpyDeviceToHost;
        fn_memorymanager.event_arr_d2h[tid] = true;
    } else {
        TORCH_INTERNAL_ASSERT(false, "unsupported devices in GPU copy_()");
    }
    ```
  
  - CPU -> GPU
    - fn_memorymanager.p2p_malloc()
    - cudaMemsetAsync()
    - fn_memorymanager.p2p_free()

  - GPU -> CPU
    - use fn_memorymanager.p2p_malloc() to malloc space
    - use cudaMemsetAsync() to sets device memory to a value. (copy data from host to GPU)

- Every modules do use fn_memorymanager; Like Dropout.cu; save_variable.cpp