# Timeline - Interview_Preparation
05/04/2020

Apply for jobs at Snap, Lucid Motor, Inceptio

Study YOLOv4:

+ [CSPNet](https://github.com/WongKinYiu/CrossStagePartialNetworks) (Cross Stage Partial Network): 
  + Advantage: It's able to reduce computations by 20% with a bit superior accuracy. It can cope with architectures based on ResNet, ResNeXt, and DenseNet.
  + Methods: 
  + Classification: In order to strengthen learning bability of a CNN, the feature maps of base layer are evenly split into two parts, the latter one will go through the block (can be Dense block), then undergo a transition layer, next concatenate with the former part and undergo another transition layer. The author claims that both parts do not contain duplicate gradient info that belong to the other parts by truncating the gradient flow.
  + !["Dense block"](1.PNG )
+ Detection: Exact fusion model. In the experiment settings, GIoU,  SPP (Spatial Pyramid Pooling) and SAM (Spatial Attention Module) are also applied to the EFM to conduct an ablation study. 
+ !["EFM"](2.PNG )
+ !["EFM experiments"](3.PNG )