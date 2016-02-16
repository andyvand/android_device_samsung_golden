#ifndef SYSTEM_CORE_INCLUDE_ANDROID_GRAPHICS_H
#define SYSTEM_CORE_INCLUDE_ANDROID_GRAPHICS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef HAL_PRIORITY_URGENT_DISPLAY
#define HAL_PRIORITY_URGENT_DISPLAY     (-8)
#endif

enum {
    HAL_PIXEL_FORMAT_RGBA_8888          = 1,
    HAL_PIXEL_FORMAT_RGBX_8888          = 2,
    HAL_PIXEL_FORMAT_RGB_888            = 3,
    HAL_PIXEL_FORMAT_RGB_565            = 4,
    HAL_PIXEL_FORMAT_BGRA_8888          = 5,
    HAL_PIXEL_FORMAT_YV12   = 0x32315659, // YCrCb 4:2:0 Planar
    HAL_PIXEL_FORMAT_Y8     = 0x20203859,
    HAL_PIXEL_FORMAT_Y16    = 0x20363159,
    HAL_PIXEL_FORMAT_RAW16 = 0x20,
    HAL_PIXEL_FORMAT_RAW10 = 0x25,
    HAL_PIXEL_FORMAT_RAW12 = 0x26,
    HAL_PIXEL_FORMAT_RAW_OPAQUE = 0x24,
    HAL_PIXEL_FORMAT_BLOB = 0x21,
    HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED = 0x22,
    HAL_PIXEL_FORMAT_YCbCr_420_888 = 0x23,
    HAL_PIXEL_FORMAT_YCbCr_422_888 = 0x27,
    HAL_PIXEL_FORMAT_YCbCr_444_888 = 0x28,
    HAL_PIXEL_FORMAT_FLEX_RGB_888 = 0x29,
    HAL_PIXEL_FORMAT_FLEX_RGBA_8888 = 0x2A,
    HAL_PIXEL_FORMAT_YCbCr_422_SP       = 0x10, // NV16
    HAL_PIXEL_FORMAT_YCrCb_420_SP       = 0x11, // NV21
    HAL_PIXEL_FORMAT_YCbCr_422_I        = 0x14, // YUY2

#ifdef STE_HARDWARE
    HAL_PIXEL_FORMAT_YCBCR42XMBN        = 0xE,
    HAL_PIXEL_FORMAT_YCbCr_420_P        = 0x13,
    HAL_PIXEL_FORMAT_YCbCr_420_SP       = 0x21,
#endif
};

struct android_ycbcr {
    void *y;
    void *cb;
    void *cr;
    size_t ystride;
    size_t cstride;
    size_t chroma_step;

    /** reserved for future use, set to 0 by gralloc's (*lock_ycbcr)() */
    uint32_t reserved[8];
};

struct android_depth_points {
    uint32_t num_points;

    /** reserved for future use, set to 0 by gralloc's (*lock)() */
    uint32_t reserved[8];

    float xyzc_points[];
};

enum {
    /* flip source image horizontally (around the vertical axis) */
    HAL_TRANSFORM_FLIP_H    = 0x01,
    /* flip source image vertically (around the horizontal axis)*/
    HAL_TRANSFORM_FLIP_V    = 0x02,
    /* rotate source image 90 degrees clockwise */
    HAL_TRANSFORM_ROT_90    = 0x04,
    /* rotate source image 180 degrees */
    HAL_TRANSFORM_ROT_180   = 0x03,
    /* rotate source image 270 degrees clockwise */
    HAL_TRANSFORM_ROT_270   = 0x07,
    /* don't use. see system/window.h */
    HAL_TRANSFORM_RESERVED  = 0x08,
};

typedef unsigned int android_dataspace;
typedef unsigned int android_dataspace_t;

enum {
    HAL_DATASPACE_UNKNOWN = 0x0,
    HAL_DATASPACE_ARBITRARY = 0x1,
    HAL_DATASPACE_SRGB_LINEAR = 0x200,
    HAL_DATASPACE_SRGB = 0x201,
    HAL_DATASPACE_JFIF = 0x101,
    HAL_DATASPACE_BT601_625 = 0x102,
    HAL_DATASPACE_BT601_525 = 0x103,
    HAL_DATASPACE_BT709 = 0x104,
    HAL_DATASPACE_DEPTH = 0x1000
};

#ifdef __cplusplus
}
#endif

#endif

