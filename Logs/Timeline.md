# Timeline - Interview_Preparation
05/04/2020

Apply for jobs at Snap, Lucid Motor, Inceptio

Study YOLOv4 and finished setting up environement for YOLOv4:

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

+ Before running ![YOLOv4](https://github.com/AlexeyAB/darknet#how-to-use-on-the-command-line)

```cpp
sudo apt install libopencv-dev 

change Makfile
export PATH=/usr/local/cuda-10.2/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64:$LD_LIBRARY_PATH

add lines below to the ./bashrc
export PATH=/usr/local/cuda-10.2/bin:$PATH
export LD_LIBRARY_PATH=/usr/local/cuda-10.2/lib64:$LD_LIBRARY_PATH
```