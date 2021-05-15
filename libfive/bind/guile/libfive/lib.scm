#|
Guile bindings to the libfive CAD kernel
Copyright (C) 2021  Matt Keeter

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
|#

;; This is the core FFI library, which wraps libfive.h
;; For now, it's manually generated, since there aren't that many functions
(define-module (libfive lib))

(use-modules (system foreign) (srfi srfi-1) (srfi srfi-98))

; Workaround for a bug in Guile 3.0.7, reported to the mailing list: on macOS,
; it doesn't match the %host-type string, so fails to look for files ending
; in .dylib
(define (dynamic-link-workaround name)
  (if (and (string=? (version) "3.0.7") (string-contains %host-type "-darwin"))
    (begin
      (use-modules (system foreign-library))
      (load-foreign-library name #:extensions '(".dylib")))
    (dynamic-link name)))

(define (try-link lib name)
  (catch
    #t
    (lambda () (dynamic-link-workaround (string-append lib name)))
    (lambda (key . args) #f)))

;; Search various paths to find libfive.dylib, in order of priority:
;;  - LIBFIVE_FRAMEWORK_DIR hint (used by Mac app)
;;  - A relative path assuming we're in the build directory
;;  - Empty path, which uses the default system search path
(define lib-paths (list
  (get-environment-variable "LIBFIVE_FRAMEWORK_DIR")
  "libfive/src/"
  ""
))
(define lib (any (lambda (t) (try-link t "libfive")) lib-paths))
(if (not lib) (begin
  (error "Could not find libfive shared library")))

;; Do the same to load the standard library, which is exported to the public
;; and used in all of the (libfive stdlib ...) modules
(define stdlib-paths (list
  (get-environment-variable "LIBFIVE_FRAMEWORK_DIR")
  "libfive/stdlib/"
  ""
))
(define stdlib (any (lambda (t) (try-link t "libfive-stdlib")) stdlib-paths))
(if (not stdlib) (begin
  (error "Could not find libfive shared standard library")))
(export stdlib)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define libfive-interval_t (list float float))
(define-public (libfive-interval lower upper)
  " Constructs a libfive_interval "
  (make-c-struct libfive-interval_t (list lower upper)))

(define libfive-region_t
  (list libfive-interval_t libfive-interval_t libfive-interval_t))
(define-public (libfive-region X Y Z)
  " Constructs a libfive_region "
  (make-c-struct libfive-region_t (list X Y Z)))

(define-public libfive-vec2_t (list float float))
(define-public libfive-vec3_t (list float float float))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(define-public libfive-tree-del-ptr
    (dynamic-func "libfive_tree_delete" lib))

(define-public libfive-tree-const
  (pointer->procedure
    '* (dynamic-func "libfive_tree_const" lib) (list float)))

(define-public libfive-opcode-enum
  (pointer->procedure
    int (dynamic-func "libfive_opcode_enum" lib) (list '*)))

(define-public libfive-tree-is-var
  (pointer->procedure
    uint8 (dynamic-func "libfive_tree_is_var" lib) (list '*)))

(define-public libfive-tree-var
  (pointer->procedure
    '* (dynamic-func "libfive_tree_var" lib) '()))

(define-public libfive-opcode-args
  (pointer->procedure
    int (dynamic-func "libfive_opcode_args" lib) (list int)))

(define-public libfive-tree-nullary
  (pointer->procedure
    '* (dynamic-func "libfive_tree_nullary" lib) (list int)))

(define-public libfive-tree-unary
  (pointer->procedure
    '* (dynamic-func "libfive_tree_unary" lib) (list int '*)))

(define-public libfive-tree-binary
  (pointer->procedure
    '* (dynamic-func "libfive_tree_binary" lib) (list int '* '*)))

(define-public libfive-tree-id
  (pointer->procedure
    '* (dynamic-func "libfive_tree_id" lib) (list '*)))

(define-public libfive-tree-remap
  (pointer->procedure
    '* (dynamic-func "libfive_tree_remap" lib) (list '* '* '* '*)))

(define-public libfive-tree-print
  (pointer->procedure
    '* (dynamic-func "libfive_tree_print" lib) (list '*)))

(define-public libfive-free-str
  (pointer->procedure
    void (dynamic-func "libfive_free_str" lib) (list '*)))

(define-public libfive-tree-save-mesh
  (pointer->procedure
    uint8 (dynamic-func "libfive_tree_save_mesh" lib)
      (list '* libfive-region_t float '*)))

(define-public libfive-tree-save-meshes
  (pointer->procedure
    uint8 (dynamic-func "libfive_tree_save_meshes" lib)
      (list '* libfive-region_t float float '*)))

(define-public libfive-tree-save
  (pointer->procedure
    uint8 (dynamic-func "libfive_tree_save" lib) (list '* '*)))

(define-public libfive-tree-load
  (pointer->procedure
    '* (dynamic-func "libfive_tree_load" lib) (list '*)))

(define-public libfive-tree-eval-f
  (pointer->procedure
    float (dynamic-func "libfive_tree_eval_f" lib)
      (list '* libfive-vec3_t)))

(define-public libfive-tree-eval-i
  (pointer->procedure
    libfive-interval_t (dynamic-func "libfive_tree_eval_r" lib)
      (list '* libfive-region_t)))

(define-public libfive-tree-eval-d
  (pointer->procedure
    libfive-vec3_t (dynamic-func "libfive_tree_eval_d" lib)
      (list '* libfive-vec3_t)))
