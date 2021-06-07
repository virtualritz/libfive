"""
Python bindings to the libfive CAD kernel

DO NOT EDIT BY HAND!
This file is automatically generated from libfive/stdlib/stdlib.h

It was last generated on 2021-05-14 17:17:35 by user moritz

This is libfive.stdlib.generators
"""

from libfive.ffi import libfive_tree, tfloat, tvec2, tvec3, stdlib
from libfive.shape import Shape

import ctypes

stdlib.libfivestd_array_x.argtypes = [libfive_tree, ctypes.c_int, tfloat]
stdlib.libfivestd_array_x.restype = libfive_tree
def array_x(shape, nx, dx):
    """ Iterates a part in a 1D array
    """
    args = [Shape.wrap(shape), nx, Shape.wrap(dx)]
    return Shape(stdlib.libfivestd_array_x(
        args[0].ptr,
        args[1],
        args[2].ptr))

stdlib.libfivestd_array_xy.argtypes = [libfive_tree, ctypes.c_int, ctypes.c_int, tvec2]
stdlib.libfivestd_array_xy.restype = libfive_tree
def array_xy(shape, nx, ny, delta):
    """ Iterates a part in a 2D array
    """
    args = [Shape.wrap(shape), nx, ny, list([Shape.wrap(i) for i in delta])]
    return Shape(stdlib.libfivestd_array_xy(
        args[0].ptr,
        args[1],
        args[2],
        tvec2(*[a.ptr for a in args[3]])))

stdlib.libfivestd_array_xyz.argtypes = [libfive_tree, ctypes.c_int, ctypes.c_int, ctypes.c_int, tvec3]
stdlib.libfivestd_array_xyz.restype = libfive_tree
def array_xyz(shape, nx, ny, nz, delta):
    """ Iterates a part in a 3D array
    """
    args = [Shape.wrap(shape), nx, ny, nz, list([Shape.wrap(i) for i in delta])]
    return Shape(stdlib.libfivestd_array_xyz(
        args[0].ptr,
        args[1],
        args[2],
        args[3],
        tvec3(*[a.ptr for a in args[4]])))

stdlib.libfivestd_array_polar_z.argtypes = [libfive_tree, ctypes.c_int, tvec2]
stdlib.libfivestd_array_polar_z.restype = libfive_tree
def array_polar_z(shape, n, center=(0, 0)):
    """ Iterates a shape about an optional center position
    """
    args = [Shape.wrap(shape), n, list([Shape.wrap(i) for i in center])]
    return Shape(stdlib.libfivestd_array_polar_z(
        args[0].ptr,
        args[1],
        tvec2(*[a.ptr for a in args[2]])))

stdlib.libfivestd_extrude_z.argtypes = [libfive_tree, tfloat, tfloat]
stdlib.libfivestd_extrude_z.restype = libfive_tree
def extrude_z(t, zmin, zmax):
    """ Extrudes a 2D shape between zmin and zmax
    """
    args = [Shape.wrap(t), Shape.wrap(zmin), Shape.wrap(zmax)]
    return Shape(stdlib.libfivestd_extrude_z(
        args[0].ptr,
        args[1].ptr,
        args[2].ptr))

array_polar = array_polar_z