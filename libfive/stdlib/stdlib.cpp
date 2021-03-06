/*
 *  C API for the libfive standard library
 *
 *  DO NOT EDIT BY HAND!
 *  This file is automatically generated from libfive/stdlib/stdlib.h
 *
 *  It was last generated on 2021-05-14 17:25:56 by user moritz
 */
#include "stdlib.h"
#include "stdlib_impl.hpp"

using namespace libfive;
////////////////////////////////////////////////////////////////////////////////
// csg
LIBFIVE_STDLIB libfivestd_union(libfive_tree a, libfive_tree b) {
    return _union(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB libfivestd_intersection(libfive_tree a, libfive_tree b) {
    return intersection(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB libfivestd_inverse(libfive_tree a) {
    return inverse(Tree(a)).release();
}
LIBFIVE_STDLIB libfivestd_difference(libfive_tree a, libfive_tree b) {
    return difference(Tree(a), Tree(b)).release();
}
LIBFIVE_STDLIB libfivestd_offset(libfive_tree a, tfloat o) {
    return offset(Tree(a), Tree(o)).release();
}
LIBFIVE_STDLIB libfivestd_clearance(libfive_tree a, libfive_tree b, tfloat offset) {
    return clearance(Tree(a), Tree(b), Tree(offset)).release();
}
LIBFIVE_STDLIB libfivestd_shell(libfive_tree a, tfloat offset) {
    return shell(Tree(a), Tree(offset)).release();
}
LIBFIVE_STDLIB libfivestd_blend_expt(libfive_tree a, libfive_tree b, tfloat m) {
    return blend_expt(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB libfivestd_blend_expt_unit(libfive_tree a, libfive_tree b, tfloat m) {
    return blend_expt_unit(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB libfivestd_blend_rough(libfive_tree a, libfive_tree b, tfloat m) {
    return blend_rough(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB libfivestd_blend_difference(libfive_tree a, libfive_tree b, tfloat m, tfloat o) {
    return blend_difference(Tree(a), Tree(b), Tree(m), Tree(o)).release();
}
LIBFIVE_STDLIB libfivestd_morph(libfive_tree a, libfive_tree b, tfloat m) {
    return morph(Tree(a), Tree(b), Tree(m)).release();
}
LIBFIVE_STDLIB libfivestd_loft(libfive_tree a, libfive_tree b, tfloat zmin, tfloat zmax) {
    return loft(Tree(a), Tree(b), Tree(zmin), Tree(zmax)).release();
}
LIBFIVE_STDLIB libfivestd_loft_between(libfive_tree a, libfive_tree b, tvec3 lower, tvec3 upper) {
    return loft_between(Tree(a), Tree(b), TreeVec3{Tree(lower.x), Tree(lower.y), Tree(lower.z)}, TreeVec3{Tree(upper.x), Tree(upper.y), Tree(upper.z)}).release();
}
////////////////////////////////////////////////////////////////////////////////
// shapes
LIBFIVE_STDLIB libfivestd_circle(tfloat r, tvec2 center) {
    return circle(Tree(r), TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB libfivestd_ring(tfloat ro, tfloat ri, tvec2 center) {
    return ring(Tree(ro), Tree(ri), TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB libfivestd_polygon(tfloat r, int n, tvec2 center) {
    return polygon(Tree(r), n, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB libfivestd_rectangle(tvec2 a, tvec2 b) {
    return rectangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}).release();
}
LIBFIVE_STDLIB libfivestd_rounded_rectangle(tvec2 a, tvec2 b, tfloat r) {
    return rounded_rectangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, Tree(r)).release();
}
LIBFIVE_STDLIB libfivestd_rectangle_exact(tvec2 a, tvec2 b) {
    return rectangle_exact(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}).release();
}
LIBFIVE_STDLIB libfivestd_rectangle_centered_exact(tvec2 size, tvec2 center) {
    return rectangle_centered_exact(TreeVec2{Tree(size.x), Tree(size.y)}, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB libfivestd_triangle(tvec2 a, tvec2 b, tvec2 c) {
    return triangle(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, TreeVec2{Tree(c.x), Tree(c.y)}).release();
}
LIBFIVE_STDLIB libfivestd_box_mitered(tvec3 a, tvec3 b) {
    return box_mitered(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}).release();
}
LIBFIVE_STDLIB libfivestd_box_mitered_centered(tvec3 size, tvec3 center) {
    return box_mitered_centered(TreeVec3{Tree(size.x), Tree(size.y), Tree(size.z)}, TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_box_exact_centered(tvec3 size, tvec3 center) {
    return box_exact_centered(TreeVec3{Tree(size.x), Tree(size.y), Tree(size.z)}, TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_box_exact(tvec3 a, tvec3 b) {
    return box_exact(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}).release();
}
LIBFIVE_STDLIB libfivestd_rounded_box(tvec3 a, tvec3 b, tfloat r) {
    return rounded_box(TreeVec3{Tree(a.x), Tree(a.y), Tree(a.z)}, TreeVec3{Tree(b.x), Tree(b.y), Tree(b.z)}, Tree(r)).release();
}
LIBFIVE_STDLIB libfivestd_sphere(tfloat radius, tvec3 center) {
    return sphere(Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_half_space(tvec3 norm, tvec3 point) {
    return half_space(TreeVec3{Tree(norm.x), Tree(norm.y), Tree(norm.z)}, TreeVec3{Tree(point.x), Tree(point.y), Tree(point.z)}).release();
}
LIBFIVE_STDLIB libfivestd_cylinder_z(tfloat r, tfloat h, tvec3 base) {
    return cylinder_z(Tree(r), Tree(h), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB libfivestd_cone_ang_z(tfloat angle, tfloat height, tvec3 base) {
    return cone_ang_z(Tree(angle), Tree(height), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB libfivestd_cone_z(tfloat radius, tfloat height, tvec3 base) {
    return cone_z(Tree(radius), Tree(height), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}).release();
}
LIBFIVE_STDLIB libfivestd_pyramid_z(tvec2 a, tvec2 b, tfloat zmin, tfloat height) {
    return pyramid_z(TreeVec2{Tree(a.x), Tree(a.y)}, TreeVec2{Tree(b.x), Tree(b.y)}, Tree(zmin), Tree(height)).release();
}
LIBFIVE_STDLIB libfivestd_torus_z(tfloat ro, tfloat ri, tvec3 center) {
    return torus_z(Tree(ro), Tree(ri), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_gyroid(tvec3 period, tfloat thickness) {
    return gyroid(TreeVec3{Tree(period.x), Tree(period.y), Tree(period.z)}, Tree(thickness)).release();
}
LIBFIVE_STDLIB libfivestd_emptiness() {
    return emptiness_().release();
}
////////////////////////////////////////////////////////////////////////////////
// generators
LIBFIVE_STDLIB libfivestd_array_x(libfive_tree shape, int nx, tfloat dx) {
    return array_x(Tree(shape), nx, Tree(dx)).release();
}
LIBFIVE_STDLIB libfivestd_array_xy(libfive_tree shape, int nx, int ny, tvec2 delta) {
    return array_xy(Tree(shape), nx, ny, TreeVec2{Tree(delta.x), Tree(delta.y)}).release();
}
LIBFIVE_STDLIB libfivestd_array_xyz(libfive_tree shape, int nx, int ny, int nz, tvec3 delta) {
    return array_xyz(Tree(shape), nx, ny, nz, TreeVec3{Tree(delta.x), Tree(delta.y), Tree(delta.z)}).release();
}
LIBFIVE_STDLIB libfivestd_array_polar_z(libfive_tree shape, int n, tvec2 center) {
    return array_polar_z(Tree(shape), n, TreeVec2{Tree(center.x), Tree(center.y)}).release();
}
LIBFIVE_STDLIB libfivestd_extrude_z(libfive_tree t, tfloat zmin, tfloat zmax) {
    return extrude_z(Tree(t), Tree(zmin), Tree(zmax)).release();
}
////////////////////////////////////////////////////////////////////////////////
// transforms
LIBFIVE_STDLIB libfivestd_move(libfive_tree t, tvec3 offset) {
    return move(Tree(t), TreeVec3{Tree(offset.x), Tree(offset.y), Tree(offset.z)}).release();
}
LIBFIVE_STDLIB libfivestd_reflect_x(libfive_tree t, tfloat x0) {
    return reflect_x(Tree(t), Tree(x0)).release();
}
LIBFIVE_STDLIB libfivestd_reflect_y(libfive_tree t, tfloat y0) {
    return reflect_y(Tree(t), Tree(y0)).release();
}
LIBFIVE_STDLIB libfivestd_reflect_z(libfive_tree t, tfloat z0) {
    return reflect_z(Tree(t), Tree(z0)).release();
}
LIBFIVE_STDLIB libfivestd_reflect_xy(libfive_tree t) {
    return reflect_xy(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_reflect_yz(libfive_tree t) {
    return reflect_yz(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_reflect_xz(libfive_tree t) {
    return reflect_xz(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_symmetric_x(libfive_tree t) {
    return symmetric_x(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_symmetric_y(libfive_tree t) {
    return symmetric_y(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_symmetric_z(libfive_tree t) {
    return symmetric_z(Tree(t)).release();
}
LIBFIVE_STDLIB libfivestd_scale_x(libfive_tree t, tfloat sx, tfloat x0) {
    return scale_x(Tree(t), Tree(sx), Tree(x0)).release();
}
LIBFIVE_STDLIB libfivestd_scale_y(libfive_tree t, tfloat sy, tfloat y0) {
    return scale_y(Tree(t), Tree(sy), Tree(y0)).release();
}
LIBFIVE_STDLIB libfivestd_scale_z(libfive_tree t, tfloat sz, tfloat z0) {
    return scale_z(Tree(t), Tree(sz), Tree(z0)).release();
}
LIBFIVE_STDLIB libfivestd_scale_xyz(libfive_tree t, tvec3 s, tvec3 center) {
    return scale_xyz(Tree(t), TreeVec3{Tree(s.x), Tree(s.y), Tree(s.z)}, TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_rotate_x(libfive_tree t, tfloat angle, tvec3 center) {
    return rotate_x(Tree(t), Tree(angle), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_rotate_y(libfive_tree t, tfloat angle, tvec3 center) {
    return rotate_y(Tree(t), Tree(angle), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_rotate_z(libfive_tree t, tfloat angle, tvec3 center) {
    return rotate_z(Tree(t), Tree(angle), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_taper_x_y(libfive_tree shape, tvec2 base, tfloat h, tfloat scale, tfloat base_scale) {
    return taper_x_y(Tree(shape), TreeVec2{Tree(base.x), Tree(base.y)}, Tree(h), Tree(scale), Tree(base_scale)).release();
}
LIBFIVE_STDLIB libfivestd_taper_xy_z(libfive_tree shape, tvec3 base, tfloat height, tfloat scale, tfloat base_scale) {
    return taper_xy_z(Tree(shape), TreeVec3{Tree(base.x), Tree(base.y), Tree(base.z)}, Tree(height), Tree(scale), Tree(base_scale)).release();
}
LIBFIVE_STDLIB libfivestd_shear_x_y(libfive_tree t, tvec2 base, tfloat height, tfloat offset, tfloat base_offset) {
    return shear_x_y(Tree(t), TreeVec2{Tree(base.x), Tree(base.y)}, Tree(height), Tree(offset), Tree(base_offset)).release();
}
LIBFIVE_STDLIB libfivestd_repel(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_x(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_x(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_y(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_y(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_z(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_z(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_xy(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_xy(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_yz(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_yz(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_repel_xz(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return repel_xz(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_x(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_x(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_y(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_y(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_z(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_z(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_xy(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_xy(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_yz(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_yz(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_attract_xz(libfive_tree shape, tvec3 locus, tfloat radius, tfloat exaggerate) {
    return attract_xz(Tree(shape), TreeVec3{Tree(locus.x), Tree(locus.y), Tree(locus.z)}, Tree(radius), Tree(exaggerate)).release();
}
LIBFIVE_STDLIB libfivestd_revolve_y(libfive_tree shape, tfloat x0) {
    return revolve_y(Tree(shape), Tree(x0)).release();
}
LIBFIVE_STDLIB libfivestd_twirl_x(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_x(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_twirl_axis_x(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_axis_x(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_twirl_y(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_y(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_twirl_axis_y(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_axis_y(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_twirl_z(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_z(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
LIBFIVE_STDLIB libfivestd_twirl_axis_z(libfive_tree shape, tfloat amount, tfloat radius, tvec3 center) {
    return twirl_axis_z(Tree(shape), Tree(amount), Tree(radius), TreeVec3{Tree(center.x), Tree(center.y), Tree(center.z)}).release();
}
////////////////////////////////////////////////////////////////////////////////
// text
LIBFIVE_STDLIB libfivestd_text(const char* txt, tvec2 pos) {
    return text(txt, TreeVec2{Tree(pos.x), Tree(pos.y)}).release();
}
