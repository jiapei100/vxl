// This is mul/vil2/vil2_pixel_format.cxx
#include "vil2_pixel_format.h"
//:
// \file
// \author Ian Scott.

#include <vcl_cassert.h>

static unsigned component_size[]={
  0,                   //  VIL2_PIXEL_FORMAT_UNKNOWN

  0,                   //  VIL2_PIXEL_FORMAT_UINT_64
  0,                   //  VIL2_PIXEL_FORMAT_INT_64
  sizeof(vxl_uint_32), //  VIL2_PIXEL_FORMAT_UINT_32
  sizeof(vxl_int_32),  //  VIL2_PIXEL_FORMAT_INT_32
  sizeof(vxl_uint_16), //  VIL2_PIXEL_FORMAT_UINT_16
  sizeof(vxl_int_16),  //  VIL2_PIXEL_FORMAT_INT_16
  sizeof(vil2_byte),   //  VIL2_PIXEL_FORMAT_BYTE
  sizeof(vxl_int_8),   //  VIL2_PIXEL_FORMAT_INT_8
  sizeof(float),       //  VIL2_PIXEL_FORMAT_FLOAT
  sizeof(double),      //  VIL2_PIXEL_FORMAT_DOUBLE
  0,                   //  VIL2_PIXEL_FORMAT_LONG_DOUBLE
  sizeof(bool),        //  VIL2_PIXEL_FORMAT_BOOL

  0,                   //  VIL2_PIXEL_FORMAT_RGB_UINT_64
  0,                   //  VIL2_PIXEL_FORMAT_RGB_INT_64
  sizeof(vxl_uint_32), //  VIL2_PIXEL_FORMAT_RGB_UINT_32
  sizeof(vxl_int_32),  //  VIL2_PIXEL_FORMAT_RGB_INT_32
  sizeof(vxl_uint_16), //  VIL2_PIXEL_FORMAT_RGB_UINT_16
  sizeof(vxl_int_16),  //  VIL2_PIXEL_FORMAT_RGB_INT_16
  sizeof(vil2_byte),   //  VIL2_PIXEL_FORMAT_RGB_BYTE
  sizeof(vxl_int_8),   //  VIL2_PIXEL_FORMAT_RGB_INT_8
  sizeof(float),       //  VIL2_PIXEL_FORMAT_RGB_FLOAT
  sizeof(double),      //  VIL2_PIXEL_FORMAT_RGB_DOUBLE
  0,                   //  VIL2_PIXEL_FORMAT_RGB_LONG_DOUBLE

  0,                   //  VIL2_PIXEL_FORMAT_RGBA_UINT_64
  0,                   //  VIL2_PIXEL_FORMAT_RGBA_INT_64
  sizeof(vxl_uint_32), //  VIL2_PIXEL_FORMAT_RGBA_UINT_32
  sizeof(vxl_int_32),  //  VIL2_PIXEL_FORMAT_RGBA_INT_32
  sizeof(vxl_uint_16), //  VIL2_PIXEL_FORMAT_RGBA_UINT_16
  sizeof(vxl_int_16),  //  VIL2_PIXEL_FORMAT_RGBA_INT_16
  sizeof(vil2_byte),   //  VIL2_PIXEL_FORMAT_RGBA_BYTE
  sizeof(vxl_int_8),   //  VIL2_PIXEL_FORMAT_RGBA_INT_8
  sizeof(float),       //  VIL2_PIXEL_FORMAT_RGBA_FLOAT
  0,                   //  VIL2_PIXEL_FORMAT_RGBA_LONG_DOUBLE
};


static unsigned num_components[]={
  0,  //  VIL2_PIXEL_FORMAT_UNKNOWN

  0,  //  VIL2_PIXEL_FORMAT_UINT_64
  0,  //  VIL2_PIXEL_FORMAT_INT_64
  1,  //  VIL2_PIXEL_FORMAT_UINT_32
  1,  //  VIL2_PIXEL_FORMAT_INT_32
  1,  //  VIL2_PIXEL_FORMAT_UINT_16
  1,  //  VIL2_PIXEL_FORMAT_INT_16
  1,  //  VIL2_PIXEL_FORMAT_BYTE
  1,  //  VIL2_PIXEL_FORMAT_INT_8
  1,  //  VIL2_PIXEL_FORMAT_FLOAT
  1,  //  VIL2_PIXEL_FORMAT_DOUBLE
  0,  //  VIL2_PIXEL_FORMAT_LONG_DOUBLE
  1,  //  VIL2_PIXEL_FORMAT_BOOL

  3,  //  VIL2_PIXEL_FORMAT_RGB_UINT_32
  3,  //  VIL2_PIXEL_FORMAT_RGB_INT_32
  3,  //  VIL2_PIXEL_FORMAT_RGB_UINT_16
  3,  //  VIL2_PIXEL_FORMAT_RGB_INT_16
  3,  //  VIL2_PIXEL_FORMAT_RGB_BYTE
  3,  //  VIL2_PIXEL_FORMAT_RGB_INT_8
  3,  //  VIL2_PIXEL_FORMAT_RGB_FLOAT
  3,  //  VIL2_PIXEL_FORMAT_RGB_DOUBLE
  0,  //  VIL2_PIXEL_FORMAT_RGB_LONG_DOUBLE

  4,  //  VIL2_PIXEL_FORMAT_RGBA_UINT_32
  4,  //  VIL2_PIXEL_FORMAT_RGBA_INT_32
  4,  //  VIL2_PIXEL_FORMAT_RGBA_UINT_16
  4,  //  VIL2_PIXEL_FORMAT_RGBA_INT_16
  4,  //  VIL2_PIXEL_FORMAT_RGBA_BYTE
  4,  //  VIL2_PIXEL_FORMAT_RGBA_INT_8
  4,  //  VIL2_PIXEL_FORMAT_RGBA_FLOAT
  4,  //  VIL2_PIXEL_FORMAT_RGBA_DOUBLE
  0,  //  VIL2_PIXEL_FORMAT_RGBA_LONG_DOUBLE
};


static vil2_pixel_format component_format[]={
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_UNKNOWN

VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_UINT_64
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_INT_64
VIL2_PIXEL_FORMAT_UINT_32,  //  VIL2_PIXEL_FORMAT_UINT_32
VIL2_PIXEL_FORMAT_INT_32,   //  VIL2_PIXEL_FORMAT_INT_32
VIL2_PIXEL_FORMAT_UINT_16,  //  VIL2_PIXEL_FORMAT_UINT_16
VIL2_PIXEL_FORMAT_INT_16,   //  VIL2_PIXEL_FORMAT_INT_16
VIL2_PIXEL_FORMAT_BYTE,     //  VIL2_PIXEL_FORMAT_BYTE
VIL2_PIXEL_FORMAT_INT_8,    //  VIL2_PIXEL_FORMAT_INT_8
VIL2_PIXEL_FORMAT_FLOAT,    //  VIL2_PIXEL_FORMAT_FLOAT
VIL2_PIXEL_FORMAT_DOUBLE,   //  VIL2_PIXEL_FORMAT_DOUBLE
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_LONG_DOUBLE
VIL2_PIXEL_FORMAT_BOOL,     //  VIL2_PIXEL_FORMAT_BOOL

VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGB_UINT_64
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGB_INT_64
VIL2_PIXEL_FORMAT_UINT_32,  //  VIL2_PIXEL_FORMAT_RGB_UINT_32
VIL2_PIXEL_FORMAT_INT_32,   //  VIL2_PIXEL_FORMAT_RGB_INT_32
VIL2_PIXEL_FORMAT_UINT_16,  //  VIL2_PIXEL_FORMAT_RGB_UINT_16
VIL2_PIXEL_FORMAT_INT_16,   //  VIL2_PIXEL_FORMAT_RGB_INT_16
VIL2_PIXEL_FORMAT_BYTE,     //  VIL2_PIXEL_FORMAT_RGB_BYTE
VIL2_PIXEL_FORMAT_INT_8,    //  VIL2_PIXEL_FORMAT_RGB_INT_8
VIL2_PIXEL_FORMAT_FLOAT,    //  VIL2_PIXEL_FORMAT_RGB_FLOAT
VIL2_PIXEL_FORMAT_DOUBLE,   //  VIL2_PIXEL_FORMAT_RGB_DOUBLE
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGB_LONG_DOUBLE

VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGBA_UINT_64
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGBA_INT_64
VIL2_PIXEL_FORMAT_UINT_32,  //  VIL2_PIXEL_FORMAT_RGBA_UINT_32
VIL2_PIXEL_FORMAT_INT_32,   //  VIL2_PIXEL_FORMAT_RGBA_INT_32
VIL2_PIXEL_FORMAT_UINT_16,  //  VIL2_PIXEL_FORMAT_RGBA_UINT_16
VIL2_PIXEL_FORMAT_INT_16,   //  VIL2_PIXEL_FORMAT_RGBA_INT_16
VIL2_PIXEL_FORMAT_BYTE,     //  VIL2_PIXEL_FORMAT_RGBA_BYTE
VIL2_PIXEL_FORMAT_INT_8,    //  VIL2_PIXEL_FORMAT_RGBA_INT_8
VIL2_PIXEL_FORMAT_FLOAT,    //  VIL2_PIXEL_FORMAT_RGBA_FLOAT
VIL2_PIXEL_FORMAT_DOUBLE,   //  VIL2_PIXEL_FORMAT_RGBA_DOUBLE
VIL2_PIXEL_FORMAT_UNKNOWN,  //  VIL2_PIXEL_FORMAT_RGBA_LONG_DOUBLE
};


//: Return the number of bytes used by each component of pixel format f
unsigned vil2_pixel_format_sizeof_components(enum vil2_pixel_format f)
{
  assert (f >= VIL2_PIXEL_FORMAT_UNKNOWN && f < VIL2_PIXEL_FORMAT_ENUM_END);
  return component_size[f];
}
//: Return the number of components in pixel format f
unsigned vil2_pixel_format_num_components(enum vil2_pixel_format f)
{
  assert (f >= VIL2_PIXEL_FORMAT_UNKNOWN && f < VIL2_PIXEL_FORMAT_ENUM_END);
  return num_components[f];
}


//: Return the number of components in pixel format f
vil2_pixel_format vil2_pixel_format_component_format(enum vil2_pixel_format f)
{
  assert (f >= VIL2_PIXEL_FORMAT_UNKNOWN && f < VIL2_PIXEL_FORMAT_ENUM_END);
  return component_format[f];
}


//: output a pretty string representing the pixel format.
vcl_ostream & operator << (vcl_ostream &os, vil2_pixel_format f)
{
  switch(f) {
    case VIL2_PIXEL_FORMAT_UNKNOWN: os << "VIL2_PIXEL_FORMAT=UNKNOWN";  break;

    case VIL2_PIXEL_FORMAT_UINT_32: os << "VIL2_PIXEL_FORMAT=vxl_uint_32";  break;
    case VIL2_PIXEL_FORMAT_INT_32:  os << "VIL2_PIXEL_FORMAT=vxl_int_32";  break;
    case VIL2_PIXEL_FORMAT_UINT_16: os << "VIL2_PIXEL_FORMAT=vxl_uint_16";  break;
    case VIL2_PIXEL_FORMAT_INT_16:  os << "VIL2_PIXEL_FORMAT=vxl_int_16";  break;
    case VIL2_PIXEL_FORMAT_BYTE:    os << "VIL2_PIXEL_FORMAT=vil2_byte";  break;
    case VIL2_PIXEL_FORMAT_INT_8:   os << "VIL2_PIXEL_FORMAT=vxl_int_8";  break;
    case VIL2_PIXEL_FORMAT_FLOAT:   os << "VIL2_PIXEL_FORMAT=float";  break;
    case VIL2_PIXEL_FORMAT_DOUBLE:  os << "VIL2_PIXEL_FORMAT=double";  break;
    case VIL2_PIXEL_FORMAT_BOOL:    os << "VIL2_PIXEL_FORMAT=bool";  break;

    case VIL2_PIXEL_FORMAT_RGB_INT_32:  os << "VIL2_PIXEL_FORMAT=vil_rgb<vxl_int_32>";  break;
    case VIL2_PIXEL_FORMAT_RGB_UINT_32: os << "VIL2_PIXEL_FORMAT=vil_rgb<vxl_uint_32>";  break;
    case VIL2_PIXEL_FORMAT_RGB_INT_16:  os << "VIL2_PIXEL_FORMAT=vil_rgb<vxl_int_16>";  break;
    case VIL2_PIXEL_FORMAT_RGB_UINT_16: os << "VIL2_PIXEL_FORMAT=vil_rgb<vxl_uint_16>";  break;
    case VIL2_PIXEL_FORMAT_RGB_BYTE:    os << "VIL2_PIXEL_FORMAT=vil_rgb<vil2_byte>";  break;
    case VIL2_PIXEL_FORMAT_RGB_INT_8:   os << "VIL2_PIXEL_FORMAT=vil_rgb<vxl_int_8>";  break;
    case VIL2_PIXEL_FORMAT_RGB_FLOAT:   os << "VIL2_PIXEL_FORMAT=vil_rgb<float>";  break;
    case VIL2_PIXEL_FORMAT_RGB_DOUBLE:  os << "VIL2_PIXEL_FORMAT=vil_rgb<double>";  break;

    case VIL2_PIXEL_FORMAT_RGBA_INT_32:  os << "VIL2_PIXEL_FORMAT=vil_rgba<vxl_int_32>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_UINT_32: os << "VIL2_PIXEL_FORMAT=vil_rgba<vxl_uint_32>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_INT_16:  os << "VIL2_PIXEL_FORMAT=vil_rgba<vxl_int_16>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_UINT_16: os << "VIL2_PIXEL_FORMAT=vil_rgba<vxl_uint_16>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_BYTE:    os << "VIL2_PIXEL_FORMAT=vil_rgba<vil2_byte>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_INT_8:   os << "VIL2_PIXEL_FORMAT=vil_rgba<vxl_int_8>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_FLOAT:   os << "VIL2_PIXEL_FORMAT=vil_rgba<float>";  break;
    case VIL2_PIXEL_FORMAT_RGBA_DOUBLE:  os << "VIL2_PIXEL_FORMAT=vil_rgba<double>";  break;

    default:  os << "VIL2_PIXEL_FORMAT_INVALID";  break;
  }
  return os;
}

