# Timeline - Interview_Preparation
05/04/2020

Apply for jobs at Snap, Lucid Motor, Inceptio

Study YOLOv4(CSPNet) and finished setting up environement for YOLOv4:

+ [CSPNet](https://github.com/WongKinYiu/CrossStagePartialNetworks) (Cross Stage Partial Network): 
+ **Advantage**: It's able to reduce computations by 20% with a bit superior accuracy. It can cope with architectures based on ResNet, ResNeXt, and DenseNet.
+ **Methods:** 
+ **Classification:** In order to strengthen learning bability of a CNN, **the feature maps of base layer are evenly split into two parts**, the latter one will go through the block (can be Dense block), then undergo a transition layer, next concatenate with the former part and undergo another transition layer. The author claims that both parts do not contain duplicate gradient info that belong to the other parts by truncating the gradient flow.
+ !["Dense block"](1.PNG )
+ **Detection:** Exact fusion model with Maxout operation. In the experiment settings, **GIoU,  SPP (Spatial Pyramid Pooling) and SAM (Spatial Attention Module)** are also applied to the EFM to conduct an ablation study. If compared to object detectors running at 30∼100 fps, **CSPResNeXt50 with PANet (SPP)** achieves the best performance
in AP, AP50 and AP75. They receive, respectively, 38.4%, 60.6%, and 41.6% detection rates.  
+ !["EFM"](2.PNG )
+ !["EFM experiments"](3.PNG )
+ **Inference rate:** If your detector is running on mobile GPU, use EFM based network, it can reduce the memory requirements when generating feature pyramids.

+ Before running [YOLOv4](https://github.com/AlexeyAB/darknet#how-to-use-on-the-command-line)

```cpp
// if use opencv, also don't forget to install opencv
sudo apt install libopencv-dev 

//change Makfile
// if use gpu
COMMON+= -DGPU -I/usr/local/cuda-10.2/include/
LDFLAGS+= -L/usr/local/cuda-10.2/lib -lcuda -lcudart -lcublas -lcurand
LDFLAGS+= -L/usr/local/cuda-10.2/lib64 -lcuda -lcudart -lcublas -lcurand

CFLAGS+= -DCUDNN -I/usr/local/cuda-10.2/include
LDFLAGS+= -L/usr/local/cuda-10.2/lib -lcudnn

CFLAGS+= -DCUDNN -I/usr/local/cudnn-10.2/include
LDFLAGS+= -L/usr/local/cudnn-10.2/lib64 -lcudnn


//add lines below to the ~/.bashrc, then source ~/.bashrc
export PATH=/usr/local/cuda-10.2/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64:$LD_LIBRARY_PATH
```

05/05/2020

Apply for jobs at DiDi, Nvidia, Skydio

1) Study YOLOv4(SPP, SAM)
2) update Leetcode folder

+ [SPP](https://arxiv.org/pdf/1406.4729.pdf) (Spatial Pyramid Pooling):
+ SPP eliminate the requirements of the fixed input size of the existed deep neural networks by generating a fixed-length representation regardless of image size/scale. It has been shown to be robust to object deformation.
+ To adopt SPP, we need to replace the last pooling layer (after the last convolutional layer) if any to the spatial pyramid pooling layer. The output of spatial pyramid pooling layer is kM - dimensional vector with the number of bins denoted as M (k is the number of filters in the last convolutional layer), the fixed-dimensional vectors are the input to the fully-connected layer.  
+ !["SPP"](4.PNG )
+ How do we train the SPP? We train each full epoch on one network, and then switch to the other one (keeping all weights) for the next full epoch...Author shows the example of training R-CNN with SPP in the paper.

+ [SAM](https://arxiv.org/pdf/1807.06521.pdf)(Spatial attention module):