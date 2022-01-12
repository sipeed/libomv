# openmv核心算法imlib的移植


### 项目信息

1、相关函数使用参考代码将会放在reference文件夹内，主要是openmv的参考代码。

2、项目结构
~~~ bash
.
├── assets                          #相关附件
├── bug_report                      #bug报告
├── components                      #库文件位置
│   └── imlib                      #核心算法库
│       ├── CMakeLists.txt
│       ├── include
│       ├── Kconfig
│       ├── Makefile
│       ├── readme.md
│       └── src
├── examples                        #源码文件
│   ├── imlib_base_test
│   │   ├── CMakeLists.txt
│   │   ├── config_defaults.mk
│   │   ├── main
│   │   │   ├── CMakeLists.txt
│   │   │   ├── include
│   │   │   │   └── main.h
│   │   │   └── src
│   │   │       └── main.c
│   │   ├── Makefile
│   │   └── project.py
│   ├── imlib_find_blobs_test
│   └── imlib_test
├── Kconfig
├── LICENSE
├── README.md
├── README_ZH.md
├── reference                        #imlib使用参考代码
└── tools

~~~

### 相关工作

1、修改内存管理

2、做相关指令移植工作

3、添加rgb888的支持

4、完成imlib的相关库函数



### 移植要点

1、尽量在原openmv imlib库上做兼容修改。

2、尽量保持最小的修改。

3、尽量保持代码风格统一。

4、当需要添加新的模块程序时，如果不是必须，请新建源文件进行添加。

5、fb_alloc内存区使用要小心，更改了fb_alloc的内存释放fb_free()接口，方便做程序的移植。

以上要点可以在保持原汁原味的opemv风格下，添加我们自己的相关代码。好处是当openmv代码更新时可以最快的速度更新到我们自己代码中，
做到代码共享。


### 移植进度

1、完成了xalloc内存管理的移植。（动态内存的移植）

2、完成了fb_alloc内存管理的移植。（栈内存的移植）

3、完成了大部分的rgb888的支持添加，对imlib_draw_image()函数的rgb888支持工作还在进行中，目前需要测试后才能继续做支持添加工作。

4、正在进行相关测试。测试参考代码将会放在examples文件夹内。






### 使用注意

1、目前imlib库的图片输入输出只进行了bpm的移植。其他的正在移植工作中。

2、测试出现问题后，可以写到bug_report文件夹内，作者看到后会进行处理。

3、imlib算法内原生支持rgb565,有关rgb565的算法可以直接测试使用。

4、如果想要参与该项目，可以提交PR或者联系作者，作者将会将其添加到项目管理者内，让合作更加顺畅。

# 如果对项目有疑问，请重新阅读上述内容。如果还有疑问，请仔细阅读项目代码。如果再有疑问，请仔细阅读并背诵项目代码。





### 相关笔记

将库修改到标准linux c
大端是人的思维逻辑，小端是机器的逻辑

大端，高位在前
小端低位在前



#更新的文件
draw.c
imlib.c
blob.c
stats.c
zbar.c
line.c
apriltag.c
phasecorrelation.c
fft.c
yuv.c
xyz_tab.c
template.c
sincos_tab.c
selective_search.c

  uint8_t *op1_s = (uint8_t *) &op1, *op2_s = (uint8_t *) &op2;
  result = abs(op1_s[0] - op2_s[0]) + abs(op1_s[1] - op2_s[1]) + (op1_s[2] - op2_s[2]) + (op1_s[3] - op2_s[3]) + op3;

src_pixel   = 1111 1111 1111 1111     
dst_pixel   = 1111 1111 1111 1111
smuad_alpha = 1111 1111 1111 1111

mask_r = 0111 1100 0000 0000    0111 1100 0000 0000
mask_g = 0000 0111 1110 0000    0000 0111 1110 0000
mask_b = 0000 0000 0001 1111    0000 0000 0001 1111

rgb = (_src_pixel << 16) | _dst_pixel; 
rgb = src_pixel dst_pixel

long smuad_alpha = smuad_alpha_palette[COLOR_RGB888_TO_Y(src_pixel)];
const uint32_t *smuad_alpha_palette = data->smuad_alpha_palette;
imlib_draw_row_data_t *data


并行数据

long smlad_x_weight = (l_x_weight << 16) | r_x_weight;

long t_smlad_x_weight = smlad_x_weight * t_y_weight;
long b_smlad_x_weight = smlad_x_weight * b_y_weight;
long t_b_smlad_x_weight_sum = __QADD16(t_smlad_x_weight, b_smlad_x_weight);


__STATIC_FORCEINLINE uint32_t __SMLAD (uint32_t op1, uint32_t op2, uint32_t op3)
{
  uint32_t result;
  uint16_t *op1_s = (uint16_t *) &op1, *op2_s = (uint16_t *) &op2;
  
  result = op1_s[0] * op2_s[0];
  result += op1_s[1] * op2_s[1];
  result += op3;
  
  return result;
}

  smuad_y0 * rb_l0 +   smuad_y1 * rb_l1
  avg_rb0          +    avg_rb1


int rb_out_l = (__SMLAD(smuad_y, rb_l, avg_rb) >> 5) & 0x7c1f;


