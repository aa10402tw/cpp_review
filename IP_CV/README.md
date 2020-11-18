
## Usful website
[ISP图像处理流程及各块名词解释](https://zhuanlan.zhihu.com/p/165476173)


## Digital Image Fundamentals
### Aliasing
- 發生在 sample rate 不夠高的時候

### Zooming and Shrinking
- Nearest Neigbor interpolation
    - 4 neighbors for horizonail and vertical ()
    - 4 neighbors for diagonal
- Pixel replication
- Bilinear Interpolation


### Histogram Equalization
Histogram灰階影像的直方圖，可以推論出影像大致上的特性。
-   較暗的影像灰階值聚集在數值低的區域，
-   整體亮的或曝光過度的灰階值聚集在數值高的區域，對比均衡灰階值平均分散於所有範圍。
<img src = "Histogram-Equalization.png" width = "70%"> <br/>
可以發現 Adaptive Equalization(適應性等化)讓圖片的品質更好，有點像高斯分佈。

### Neighborhood Processing
- Corrlation/Convolution

### Blur
- local mean: all pixels belonging to the structuring element to compute average gray level.
- percentile mean: only use values between percentiles p0 and p1 (here 10% and 90%).
- bilateral mean: only use pixels of the structuring element having a gray level situated inside g-s0 and g+s1 (here g-500 and g+500)

Percentile and usual mean give here similar results, these filters smooth the complete image (background and details). Bilateral mean exhibits a high filtering rate for continuous area (i.e. background) while higher image frequencies remain untouched.

### Binarization (二值化)
將 0-255 變成 0-1
-   可用 threshold, local threshold, OTSU 等演算法

<img src = "Binarization.png" width = "50%"><img src = "Binarization2.png" width = "30%"> <br/>

### Edge detection
- Sobel Filter
- Canny Edge

### Morphology (形態學)
- Dilation 膨脹
- Erosion 侵蝕


## Image Enhancement
- 可分為兩類 spatial domain and frequency domain methods
    - g(x,y), = T[f(x,y)]
    - f(x,y) 代表 image plane 上的值 (spatial domain), T is operator on f
    - neighbor size -> mask/kernel/template/window
- Gray-Level Transformation
    - Contrast stretching
    - Thresholding
    - Image negatives
    - Log Transformation
    - Power-law transformation
    - Gamma correction
    - Piece-wise Linear Transformation

- Histogram-Processing
    - Normalized histogram
    - Historgram Equalization (將原本的histogram分布變成 uniform)
    - Histogram Matching (變成別的分布)

- Spatial Filtering
    - mask/convolution kernels, odd sizes
    - corrleation 
    - Smoothing
        - linear filter (box filter, weighted average)
        - Order-statistics filter (median filter, max filter, min filter)
        - Laplacian
        - Bilateral filter

- Frequency Domain
    - 頻率就是信號變化的快慢，也就是圖像的梯度變化
        - 整面牆壁圖像 -> Intensity 變化不大，低頻較強高頻較弱（週期波主峰再0位置）
        - 棋盤圖像 -> Intensity 變化快速，高頻較強低頻較弱 （週期波多個旁峰偏離0)
        - 低頻：強度，高頻：邊緣輪廓
    - Fourier Transform 
        - 流程： f(x,y)->fourier transform get F(u,v) -> H(u,v)F(u,v) -> inverse fourier transform g(x,y)
        - 在 frequency domain 相乘 = 在 spatial domain convolve 
    - Noise Reduction (移除高頻率，Lowpass filter)
        - Notch filter 
        - Ideal lowpass, Butterworth, Gaussian
        - Ringing effect (斜率無窮大)
    - Sharpen (增強高頻率, Highpass filter)
        - In general, H_hp = 1-H_lp
        - Ideal highpass , Butterworth highpass, Gaussain highpass, Laplacian
        - Homomorphisc filter (non-linear)

## Image Restoration
- Goal: improve an image in some predefined sense
    - Image enhancement: subjective process
    - Image restoration: objective process
    - Restoration attempts to reconstruct an image that has been degraded by using a priori knowledge of the degradation process.
    - Modeling the degradation and applying the inverse
process to recover the original image.
- Model of degradation
    - g(x,y) = h(x,y)*f(x,y)+n(x,y) (star is the convolve operator)
    - or G(u,v) = H(u,v)F(u,v)+N(u,v) in frequency domain
- Noise model
    - Gaussian noise (electronic circuit sensor noise)
    - Rayleigh noise (range imaging)
    - Gamma noise (laser image)
    - Exponentila noise (laser image)
    - Uniform noise
    - Impulse of salt-and-pepper noise (faulty switching)
    - Periodic noise
- Estimation of Noise Parameters
    - Periodic noises: from Fourier spectrum
    - Other: try to compute mean and variance of a subimage S
        - 如用某塊相同灰階來計算 noise
    - 要先對 noise 有一定了解才有辦法 denoise
- Mean filters:
    - Arithmetic mean / Geometric mean / Harmonic mean / Contaharmonic mean
- Order-Statistic filters
    - Median / Min / Max / Midpoint / Alpha-trimmed mean
- Adaptive filters
    - Filter's behavior changes based on statistical characteristics inside the filter window
    - Adaptive local noise reduction filter
    - Adaptive median filter
- Periodic Noise Reduction
    - Fourier domain filtering
        - Bandreject filter
        - Bandpass filter
        - Notch filter (Ideal, Butterworth, Gaussian)
- Linear, Position-Invariant Degradations
    - Estimating the degradation function
        - By image observation, experimentation, and modeling
- Deconvolution
    - Inverse filtering
    - Minimum mean square error filtering (Wiener)
    - Constrained least squares filtering
    - Geometric mean filter
<img src="noise.png" >

## Image Segmentation
- 目標：切多個區域，每個區域內的 Property 相似
- 通常 Image segmentation algorithms base on **discontinuity** (e.g., edges) and **similarity** (e.g., thresholding, region growing etc)

- Detection of discontinuities
    - Point detection, Line detection, Edge detection 
    - 一次微分 highpass 沒變化微分完為0，二次微分看正/負（開始/結束）
    - 先用 low-pass 消除 noise 再用 high-pass 找 edge (high-pass 會增強 noise)
    - 定義 edge point 為一次微分後大於某 threshold 的 point
    - 將 edge point 連接可得 edge
    - Sobel, The Laplacian (**Zero-crossings**) 
    - 先做 Gaussian 再做 Laplacian
- Edge linking
    - 將 edge point 相連（Gradient / Magnitude 相似視為同 edge）
    - Hough Transform (將線段用 parametric space 表示, polar coordinate)
    - Graphic-Theoretic Techniques
        - Minimal-cost path
- Thresholding
- Region-Based Segmentation
    - Region Growing
    - Region-Splitting and Merging
    - Morphological Watersheds
- Motion-based Segmentation

## 影像處理大致上可分為7個步驟
- 1.擷取影像(acquiring the image):可能從相機來或電子顯微鏡。
- 2.前置處理(preprocessing):將影像處理程適合接下來步驟的樣子。
- 3.切割(segmentation):例如擷取車牌號碼
- 4.表示與描述(representation and description):尋找曲線或corner來辨識車牌數字
- 5.辨識與解讀(recognition and interpretation):給物體不同標示與意義，例如是那個縣市的車

數位影像的類型有四種：
- 1.Binary:二元影像非黑即白，每個像素只佔1位元。適合文字、指紋等。
- 2.Gray-scale:灰階影像從0(黑)~255(白)，每個像素8位元。
- 3.RGB:由紅藍綠調配深淺從0~255，有255的三次方需要用24-bit又稱24位元彩色影像。
- 4.Indexed:大部分影像都只用到1600萬種可能顏色的一小部分。為了方便儲存及處理於是建立色譜(color map)或調色盤(color palette)。每個像素的值不代表像素的顏色，是代表色譜上對應顏色的索引(index) ex:GIF檔
