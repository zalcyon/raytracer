#!/bin/bash

echo "Compile time: "
time make
echo "Execution time: "
time ./raytracer $1 $2
convert scene.ppm scene.png
rm scene.ppm
eog scene.png &

