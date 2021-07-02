# yoloDetection

## Functions
### I Test
- Use our trained YOLOv4 model to detect trucks, excavators, wheel loaders, bulldozers, dumpers, person, cars.
### II Training
- Train a YOLO model with your own dataset.

## I Test
### 1. Clone Darknet to local
```sh
git clone https://github.com/AlexeyAB/darknet.git
cd darknet
```
### 2. Modify the Makefile
- In the directory **darknet**, there is file called **Makefile**. Before building the darknet, we need to modify some varibles.
- If the NVIDIA driver, CUDA and CuDNN are installed, and CUDA >= 10.2, we can change `GPU=0` to `GPU=1`, `CUDNN=0` to `CUDNN=1`, in order to use GPU acceleration.
- If OpenCV is installed, and OpenCV >= 2.4, we can change `OPENCV=0` to `OPENCV=1`, in order to accelerate the image pre-processing.
- You can mannually change these variables, or directly run the following commands in Terminal:
```sh
sed -i 's/GPU=0/GPU=1/' Makefile
sed -i 's/CUDNN=0/CUDNN=1/' Makefile
sed -i 's/OPENCV=0/OPENCV=1/' Makefile
```

### 3. make the Darknet
Run `make` in the Terminal:
```sh
make
```
### 4. Prepare the configuration files
- Run the following commands in Terminal to make a folder **cfg**, so that configuration files could be neatly organized.
```sh
cd ..
mkdir cfg
cd cfg
```
- Run the following commands in Terminal. **yolov4.cfg** contains the network structure and basic training parameters of YOLOv4. **obj.names** contains the class names of our model. **obj.data** contains the custom files we need.
```sh
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/yolov4.cfg
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/obj.names
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/obj.data
cd ..
```

### 5. Prepare the weight file
- Run the following commands to make a new folder for weight files.
```sh
mkdir weights
cd weights
```
- Download our pre-trained weight file from following URL, so that the YOLOv4 model could be directly used to detect trucks, excavators, wheel loaders, bulldozers, dumpers, person, cars.
```
https://drive.google.com/file/d/1UT9pLx44Cp8RCwxmuLu2kKZO5Es7taC4/view?usp=sharing
```
- Go back to the main directory.
```sh
cd ..
```


### 6. Test your own images with this trained model
Run the following commands to test your own images. `chmod +x darknet/darknet` is used to make the darknet executable. `example.jpg` is your own images to be detected. 
```sh
chmod +x darknet/darknet
./darknet/darknet detector test cfg/obj.data cfg/yolov4.cfg weights/yolov4_CM.weights -ext_output example.jpg
```
