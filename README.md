# Simple cross-platform Vulkan API Engine
The main direction of this project is learning the Vulkan API and learning the basic structure and principles of how engine works
## First steps
- Check culpability for your graphics card(http://vulkan.gpuinfo.org/)
- **For GNU/Linux**. Check if your driver has vulkan installed
- GNU/Linux or Windows based system
- CMake(10.13 or higher), follow the [installation guide](https://cmake.org/install/)
- C++ compiler([clang](https://clang.llvm.org/get_started.html))
## Compile for GNU/Linux
Check version(1.2.176.1) of Vulkan SDK installed with path `~/VulkanSDK`  
If not, follow next steps:  
  - Downloand from [LunargXchange](https://vulkan.lunarg.com/sdk/home) 1.2.176.1 version of Vulkan SDK.  
  - Create the directory in the `~` named `VulkanSDK`(the same as it is shown). Unzip all the files from SDK archive and unzip it into `~/VulkanSDK`  
  - Open `~/.bashrc` and type following:  
  ```
  export VULKAN_SDK=~/VulkanSDK/1.2.176.1/x86_64   
  export PATH=$VULKAN_SDK/bin:$PATH  
  export LD_LIBRARY_PATH=$VULKAN_SDK/lib:$LD_LIBRARY_PATH   
  export VK_LAYER_PATH=$VULKAN_SDK/etc/vulkan/explicit_layer.d
  ```
Clone the repository.
```
$ mkdir build && cd build
$ cmake ..
$ make
$ cd src
$ ./Wolfram
```
<<<<<<< HEAD
# Windows
- [install the 1.2.176.1 version of Vulkan SDK](https://vulkan.lunarg.com/sdk/home). Choose path `C:\VulkanSDK`
- open cmake gui and choose your cmake generation option(for example, Visual Studio 19)
- run your application. If you have any issues, see "Issue page" on github, or write it to my [telegram](t.me/Umlaut)
=======
>>>>>>> 4f39e3e8d36c6115a2a878a80f937eb11f9a242d
