# README

The purpose of this README is to give guidelines for developing applications with Terabee 3Dcam 80x60 using the OpenNI 1 framework on Linux. 

For more information about the Terabee 3Dcam 80x60, please click [here](https://www.terabee.com/portfolio-item/terabee-3dcam-80x60).

## System Requirements

* Ubuntu 14.04 or Ubuntu 16.04

## Prepare software development environment

### Install OpenCV 2

In order to use the SDK, installing OpenCV with the right version is **mandatory**. In the repository are included scripts that will help you install OpenCV on your system. Depending on your OS, you will have to run the relevant script as follows:

* If you are using Ubuntu 16.04, please install OpenCV 3.1.0:
```
./install-opencv-3.1.0.sh
```
* If you are using Ubuntu 14.04, please install OpenCV 2.4.11:
```
./install-opencv-2.4.11.sh
```

### Install USB-1.0 library

```
sudo apt-get install libusb-1.0-0
```

### Install Terabee 3Dcam SDK

* Download the Linux SDK from the Downloads section of Terabee 3Dcam [here](https://www.terabee.com/portfolio-item/terabee-3dcam-80x60).

* Extract the content of the archive (relevant to your system architecture and desired OpenNI version) in the directory of your choice

* Enter the SDK folder and install the SDK with root permission
```
sudo ./install.sh
```

## Start developing your application

To get started with your application development, we provide sample codes to help you initiate your development. The following steps provide instructions on how to download and run sample codes. 

### Install Git

If Git is not installed on your computer you can install it using the following command:

```
sudo apt-get install git-core
```

### Clone sample code
Clone the project into the SDK folder.

```
git clone https://github.com/terabee/linux_openni1_samples.git Terabee_samples
```

### Build and Run Terabee samples

#### Depth Viewer

This sample will show you how to access camera data and display it into a window.

To compile it, use the following commands:

```
cd Terabee_samples/DepthViewer
CXX=g++ make
```
Now to run the program, just use the following command:
```
./Bin/DepthViewer
```

### Build your own application

Taking as example the sample we provide, you can start to develop your own application. Depending on your case, you will need to adapt some items in the Makefile. For instance:

* Append the source files name to SRC
* According the path related to SDK, modify the CPPFLAGS and LDFLAGS appropriately. i.e., you may need to add -I and -L to the correct location.
