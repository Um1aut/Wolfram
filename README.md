# Simple cross-platform Vulkan API Engine
The main direction of this project is learning the Vulkan API and learning the basic structure and principles of how game engine works
## Requirements
- [Graphics Card's culpability for Vulkan](http://vulkan.gpuinfo.org/)
- **For GNU/Linux**. Vulkan driver installed
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
Clone the repository. Because of github's policy you need to clone glfw repository(for window creation and Vulkan initialization)
```
$ cd includes
$ rm -rf glfw
$ git clone https://github.com/glfw/glfw
$ git clone https://github.com/Groovounet/glm.git
```  
Finally, build and run project with CMake
```
$ mkdir build && cd build
$ cmake ..
$ make
$ cd src
$ ./Wolfram
```
## Compile for Windows
- [install the 1.2.176.1 version of Vulkan SDK](https://vulkan.lunarg.com/sdk/home). Choose path `C:\VulkanSDK`
- clone the repository, then `cd includes`, and clone [glfw](https://github.com/glfw/glfw) and [glm](https://github.com/Groovounet/glm.git) repositories with replace
- open cmake gui and choose your cmake generation option(for example, Visual Studio 19)
- run your application. If you have any issues, see "Issue page" on github, or write it to my [telegram](t.me/Umlaut)
