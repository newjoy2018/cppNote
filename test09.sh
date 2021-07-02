# yoloDetection

## Functions
I Test - Use our trained YOLOv4 model to detect trucks, excavators, wheel loaders, bulldozers, dumpers, person, cars.
II Training - Train a YOLO model with your own dataset.

## I Test
### 1. Clone Darknet to local
```sh
git clone https://github.com/AlexeyAB/darknet.git
cd darknet
```
### 2. Modify the Makefile
In the directory 'darknet', there is file called 'Makefile'. Before building the darknet, we need to modify some varibles.
If the NVIDIA driver, CUDA and CuDNN are installed, and CUDA >= 10.2, we can change 'GPU=0' to 'GPU=1', 'CUDNN=0' to 'CUDNN=1', in order to use GPU acceleration.
If OpenCV is installed, and OpenCV >= 2.4, we can change 'OPENCV=0' to 'OPENCV=1', in order to accelerate the image pre-processing.
You can mannually change these variables, or directly run the following commands in Terminal:
```sh
sed -i 's/GPU=0/GPU=1/' Makefile
sed -i 's/CUDNN=0/CUDNN=1/' Makefile
sed -i 's/OPENCV=0/OPENCV=1/' Makefile
```

### 3. make the Darknet
Run 'make' in the Terminal:
```sh
make
```
