(import (chicken foreign))
(import (chicken gc))
(import srfi-1)
(import srfi-4)

; (foreign-declare "#include <string.h>")
(foreign-declare "#include \"include/numb/array.h\"")

(define nb-array-print
  (foreign-lambda
    void
    "nb_array_print"
    nonnull-c-pointer))

(define nb-array-new
  (foreign-lambda nonnull-c-pointer
                  "nb_array_new"
                  unsigned-integer64
                  nonnull-u64vector))

(define nb-array-destroy
  (foreign-lambda void
                  "nb_array_destroy"
                  nonnull-c-pointer))

(define nb-array-data-len
  (foreign-lambda unsigned-integer64
                  "nb_array_data_len"
                  nonnull-c-pointer))

(define nb-array-copy-data
  (foreign-lambda void
                  "nb_array_copy_data"
                  f64vector
                  nonnull-c-pointer))

(define nb-array-load-data
  (foreign-lambda void
                  "nb_array_load_data"
                  nonnull-c-pointer
                  f64vector))

(define nb-array-fill
  (foreign-lambda void
                  "nb_array_fill"
                  nonnull-c-pointer
                  double))

(define nb-array-add
  (foreign-lambda void
                  "nb_array_add"
                  nonnull-c-pointer
                  nonnull-c-pointer))

(define (nb-array->f64vector array)
  (let* ((len (nb-array-data-len array))
         (vec (make-f64vector len)))
    (begin
      (nb-array-copy-data vec array)
      (set-finalizer! array nb-array-destroy)
      vec)))

(define (loop x)
  x
  (loop x))

; (define (f64vector-shape vec)

(define (f64vector->nb-array vec shape)
  (let* ((shape (if (u64vector? shape) shape (list->u64vector shape)))
         (dim (u64vector-length shape))
         (array (nb-array-new dim shape)))
    (begin
      (nb-array-load-data array vec)
      array)))

(define (list-shape l)
  (if (not (list? (car l)))
    (list (length l))
    (let* ((first (car l))
           (rest (cdr l))
           (not-equal-lengths (filter (lambda (x) (not (= x (length first))))
                                      (map length rest))))
        (if (not (null? not-equal-lengths))
          (error "Not all element of the list are of the same length")
          (cons (length l) (list-shape (car l)))))))


(define (list->nb-array l)
  (f64vector->nb-array (list->f64vector (flatten l)) (list-shape l)))

(define array1 (list->nb-array '((1 2 3)
                                 (4 5 6)
                                 (7 8 9))))

; (define array1 (nb-array-new 1 (make-u64vector 1 3)))
; (nb-array-fill array1 3.14)
(nb-array-print array1)
; (print (nb-array->f64vector array1))
