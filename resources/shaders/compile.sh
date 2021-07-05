#!/bin/bash

dir=`dirname $0`
glslc $dir/shader.vert -o $dir/vert.spv
glslc $dir/shader.frag -o $dir/frag.spv
