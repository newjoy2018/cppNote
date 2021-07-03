# Machines Detection with YOLO

## Functions
#### I Test
- Use our trained YOLOv4 model to detect trucks, excavators, wheel loaders, bulldozers, dumpers, person and cars.
#### II Training
- Train a YOLO model with your own dataset.

## I Test
#### Step 1. Clone Darknet to local
```sh
git clone https://github.com/AlexeyAB/darknet.git
cd darknet
```
#### Step 2. Modify the Makefile
- In the directory **darknet**, there is file called **Makefile**. Before building the darknet, we need to modify some varibles.
- If the NVIDIA driver, CUDA and CuDNN are installed, and the version of CUDA >= 10.2, we can change `GPU=0` to `GPU=1`, `CUDNN=0` to `CUDNN=1`, in order to use GPU acceleration.
- If OpenCV is installed, and the version of OpenCV >= 2.4, we can change `OPENCV=0` to `OPENCV=1`, in order to accelerate the image pre-processing.
- You can mannually change these variables in **Makefile**, or directly run the following commands in Terminal:
```sh
sed -i 's/GPU=0/GPU=1/' Makefile
sed -i 's/CUDNN=0/CUDNN=1/' Makefile
sed -i 's/OPENCV=0/OPENCV=1/' Makefile
```

#### Step 3. Build the Darknet
Run `make` in the Terminal. This step may need more than one minute.
```sh
make
```
#### Step 4. Prepare the configuration files
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

#### Step 5. Prepare the weight file
- Run the following commands to make a new folder for weight files.
```sh
mkdir weights
cd weights
```
- Download our pre-trained weight file from the following URL, so that the YOLOv4 model could be directly used to detect trucks, excavators et al.
```
https://drive.google.com/file/d/1fSKsHjh2rsq-j5JdytgbS0n7Fh-STKm4/view?usp=sharing
```
- After downloading the weight file, go back to the main directory.
```sh
cd ..
```


#### Step 6. Test your own images with this trained model
Run the following commands to test your own images. `chmod +x darknet/darknet` is used to make the `darknet` executable. `example.jpg` is your own images to be detected. 
```sh
chmod +x darknet/darknet
./darknet/darknet detector test cfg/obj.data cfg/yolov4.cfg weights/yolov4_CM.weights -ext_output example.jpg
```


## II Training
This section will introduce how to train a detection model of YOLO with your own data set. The key procedures include data set preparing and configuration files modifying.
#### Step 1. Clone Darknet to local
```sh
git clone https://github.com/AlexeyAB/darknet.git
cd darknet
```
#### Step 2. Modify the Makefile
- In the directory **darknet**, there is file called **Makefile**. Before building the darknet, we need to modify some varibles.
- If the NVIDIA driver, CUDA and CuDNN are installed, and the version of CUDA >= 10.2, we can change `GPU=0` to `GPU=1`, `CUDNN=0` to `CUDNN=1`, in order to use GPU acceleration.
- If OpenCV is installed, and the version of OpenCV >= 2.4, we can change `OPENCV=0` to `OPENCV=1`, in order to accelerate the image pre-processing.
- You can mannually change these variables in **Makefile**, or directly run the following commands in Terminal:
```sh
sed -i 's/GPU=0/GPU=1/' Makefile
sed -i 's/CUDNN=0/CUDNN=1/' Makefile
sed -i 's/OPENCV=0/OPENCV=1/' Makefile
```
- Important: the training time will be too long to accept without the support of GPU and OpenCV.

#### Step 3. Build the Darknet
Run `make` in the Terminal. This step may need more than one minute.
```sh
make
```
#### Step 4. Prepare the configuration files
- Run the following commands in Terminal to make a folder **cfg**, so that configuration files could be neatly organized.
```sh
cd ..
mkdir cfg
cd cfg
```
- If you want to train YOLOv4, run the following commands in Terminal.
```sh
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/yolov4.cfg
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/obj.names
wget https://raw.githubusercontent.com/newjoy2018/MA_YOLOv4/main/Downloads/cfg/obj.data
cd ..
```
- For YOLOv3, YOLOv2, YOLOv4-tiny, YOLOv3-tiny, or more other versions of YOLO, you could find the corresponding **.cfg** files in the directory `darknet/cfg`. Copy to the `cfg` folder you have created, and then modify it with the similar operations like the following description.

###### **yolov4.cfg**
- change line subdivisions to [`subdivisions=16`], if you have a GPU with the memory larger than 12GB. If not, change it to 32 or 64.
- change line max_batches to (`classes*2000`, but not less than number of training images and not less than `6000`).
- change line steps to 80% and 90% of max_batches, f.e. [`steps=4800,5400`]
- set network size `width=512 height=512` or any value multiple of 32
- change line `classes=80` to your number of objects in each of 3 `[yolo]`-layers
- change [`filters=255`] to filters=(classes + 5)x3 in the 3 `[convolutional]` before each `[yolo]` layer, keep in mind that it only has to be the last `[convolutional]` before each of the `[yolo]` layers. So if `classes=2` then write `filters=21`, if `classes=7` then write `filters=36`.
###### **obj.names**
- This file stores the names of objects to be detected, each one in a new line. 
###### **obj.data**
- **classes** = number of objects.
- **train** = the directory of a text file, in which the directory of each images in training set are stored. Look at an example of a training set list:
```
dataset/TrainingSet/00001.jpg
dataset/TrainingSet/00002.jpg
dataset/TrainingSet/00003.jpg
```
- **valid** = the directory of a text file, in which the directory of each images in validation set are stored, similar like the training set list.
- **names** = the directory of the file **obj.names**.
- **backup** = the directory to store the trained weights.

#### Step 5. Prepare the weight file
- Run the following commands to make a new folder for weight files.
```sh
mkdir weights
cd weights
```
- For training **YOLOv4** download the pre-trained weights-file (162 MB): [yolov4.conv.137](https://github.com/AlexeyAB/darknet/releases/download/darknet_yolo_v3_optimal/yolov4.conv.137) (Google drive mirror [yolov4.conv.137](https://drive.google.com/open?id=1JKF-bdIklxOOVy-2Cr5qdvjgGpmGfcbp) )
- For training **YOLOv3** download the pre-trained weights-file (155 MB): [darknet53.conv.74]
(https://pjreddie.com/media/files/darknet53.conv.74)
- For training **YOLOv2** download the pre-trained weights-file (76 MB): [darknet19_448.conv.23]
(http://pjreddie.com/media/files/darknet19_448.conv.23)
- For training **YOLOv4-tiny** download the pre-trained weights-file (19.8 MB): [yolov4-tiny.conv.29]
(https://github.com/newjoy2018/MA_YOLOv4/raw/main/Downloads/weight/yolov4-tiny.conv.29)
- For training **YOLOv3-tiny** download the pre-trained weights-file (6 MB): [yolov3-tiny.conv.11]
(https://github.com/newjoy2018/MA_YOLOv4/raw/main/Downloads/weight/yolov3-tiny.conv.11)

#### Step 6. Prepare the dataset
