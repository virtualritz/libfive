#|
Guile bindings to the libfive CAD kernel

DO NOT EDIT BY HAND!
This file is automatically generated from libfive/stdlib/stdlib.h

It was last generated on 2021-05-14 18:36:36 by user moritz
|#

(define-module (libfive stdlib csg))
(use-modules (system foreign) (libfive lib) (libfive kernel) (libfive vec))

(define ffi_union (pointer->procedure '*
  (dynamic-func "libfivestd_union" stdlib)
  (list '* '*)))
(define* (union a b)
  "union a b
  Returns the union of two shapes"
  (ptr->shape (ffi_union
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b)))))
(export union)

(define ffi_intersection (pointer->procedure '*
  (dynamic-func "libfivestd_intersection" stdlib)
  (list '* '*)))
(define* (intersection a b)
  "intersection a b
  Returns the intersection of two shapes"
  (ptr->shape (ffi_intersection
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b)))))
(export intersection)

(define ffi_inverse (pointer->procedure '*
  (dynamic-func "libfivestd_inverse" stdlib)
  (list '*)))
(define* (inverse a)
  "inverse a
  Returns a shape that's the inverse of the input shape"
  (ptr->shape (ffi_inverse
    (shape->ptr (ensure-shape a)))))
(export inverse)

(define ffi_difference (pointer->procedure '*
  (dynamic-func "libfivestd_difference" stdlib)
  (list '* '*)))
(define* (difference a b)
  "difference a b
  Subtracts the second shape from the first"
  (ptr->shape (ffi_difference
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b)))))
(export difference)

(define ffi_offset (pointer->procedure '*
  (dynamic-func "libfivestd_offset" stdlib)
  (list '* '*)))
(define* (offset a o)
  "offset a o
  Expand or contract a given shape by an offset
  Positive offsets expand the shape; negative offsets shrink it"
  (ptr->shape (ffi_offset
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape o)))))
(export offset)

(define ffi_clearance (pointer->procedure '*
  (dynamic-func "libfivestd_clearance" stdlib)
  (list '* '* '*)))
(define* (clearance a b offset)
  "clearance a b offset
  Expands shape b by the given offset then subtracts it from shape a"
  (ptr->shape (ffi_clearance
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape offset)))))
(export clearance)

(define ffi_shell (pointer->procedure '*
  (dynamic-func "libfivestd_shell" stdlib)
  (list '* '*)))
(define* (shell a offset)
  "shell a offset
  Returns a shell of a shape with the given offset"
  (ptr->shape (ffi_shell
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape offset)))))
(export shell)

(define ffi_blend-expt (pointer->procedure '*
  (dynamic-func "libfivestd_blend_expt" stdlib)
  (list '* '* '*)))
(define* (blend-expt a b m)
  "blend-expt a b m
  Blends two shapes by the given amount using exponents"
  (ptr->shape (ffi_blend-expt
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape m)))))
(export blend-expt)

(define ffi_blend-expt-unit (pointer->procedure '*
  (dynamic-func "libfivestd_blend_expt_unit" stdlib)
  (list '* '* '*)))
(define* (blend-expt-unit a b m)
  "blend-expt-unit a b m
  Blends two shapes by the given amount using exponents,
  with the blend term adjusted to produce results approximately
  resembling blend_rough for values between 0 and 1."
  (ptr->shape (ffi_blend-expt-unit
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape m)))))
(export blend-expt-unit)

(define ffi_blend-rough (pointer->procedure '*
  (dynamic-func "libfivestd_blend_rough" stdlib)
  (list '* '* '*)))
(define* (blend-rough a b m)
  "blend-rough a b m
  Blends two shapes by the given amount, using a fast-but-rough
  CSG approximation that may not preserve gradients"
  (ptr->shape (ffi_blend-rough
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape m)))))
(export blend-rough)

(define ffi_blend-difference (pointer->procedure '*
  (dynamic-func "libfivestd_blend_difference" stdlib)
  (list '* '* '* '*)))
(define* (blend-difference a b m #:optional (o 0))
  "blend-difference a b m #:optional (o 0)
  Blends the subtraction of b, with optional offset o,
  from a, with smoothness m"
  (ptr->shape (ffi_blend-difference
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape m))
    (shape->ptr (ensure-shape o)))))
(export blend-difference)

(define ffi_morph (pointer->procedure '*
  (dynamic-func "libfivestd_morph" stdlib)
  (list '* '* '*)))
(define* (morph a b m)
  "morph a b m
  Morphs between two shapes.
  m = 0 produces a, m = 1 produces b"
  (ptr->shape (ffi_morph
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape m)))))
(export morph)

(define ffi_loft (pointer->procedure '*
  (dynamic-func "libfivestd_loft" stdlib)
  (list '* '* '* '*)))
(define* (loft a b zmin zmax)
  "loft a b zmin zmax
  Produces a blended loft between a (at zmin) and b (at zmax)
  a and b should be 2D shapes (i.e. invariant along the z axis)"
  (ptr->shape (ffi_loft
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (shape->ptr (ensure-shape zmin))
    (shape->ptr (ensure-shape zmax)))))
(export loft)

(define ffi_loft-between (pointer->procedure '*
  (dynamic-func "libfivestd_loft_between" stdlib)
  (list '* '* (list '* '* '*) (list '* '* '*))))
(define* (loft-between a b lower upper)
  "loft-between a b lower upper
  Produces a blended loft between a (at lower.z) and b (at upper.z),
  with XY coordinates remapped to slide between lower.xy and upper.xy.
  a and b should be 2D shapes (i.e. invariant along the z axis)"
  (ptr->shape (ffi_loft-between
    (shape->ptr (ensure-shape a))
    (shape->ptr (ensure-shape b))
    (vec3->tvec3 lower)
    (vec3->tvec3 upper))))
(export loft-between)

(define-public blend blend-expt-unit)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Hand-written functions which allow for arbitrary numbers of arguments
(use-modules (srfi srfi-1))

(define union-prev union)
(define-public (union a . args)
  "union a [b [c [...]]]
  Returns the union of any number of shapes"
  (fold union-prev a args))

(define intersection-prev intersection)
(define-public (intersection a . args)
  "intersection a [b [c [...]]]
  Returns the intersection of any number of shapes"
  (fold intersection-prev a args))

(define-public (difference a . bs)
  "difference a b [c [d [...]]]
  Subtracts any number of shapes from the first argument"
  (intersection a (inverse (apply union bs))))
