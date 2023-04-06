//объясни код на C
#include "IntVector.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// создает новый вектор
struct IntVector *int_vector_new(size_t initial_capacity) {
  if (initial_capacity == 0)
    return NULL;
  struct IntVector *a1 = malloc(sizeof(struct IntVector));
  if (!a1) {
    printf("Not enough space for struct");
    return NULL;
  }
  a1->size = 0;
  a1->capacity = initial_capacity;
  a1->data = malloc(sizeof(int) * initial_capacity);
  if (!(a1->data)) {
    printf("Not enough space for massive");
    free(a1);
    return NULL;
  }
  return a1;
}
// создвет комию вектора
struct IntVector *int_vector_copy(struct IntVector *v) {
  struct IntVector *copy = malloc(sizeof(struct IntVector));
  if ((!copy) || (v->capacity == 0)) {
    return NULL;
  }
  copy->size = v->size;
  copy->capacity = v->capacity;
  copy->data = malloc(copy->capacity * sizeof(int));
  if (!(copy->data)) {
    free(copy);
    return NULL;
  };
  for (int i = 0; i < v->capacity; i++) {
    copy->data[i] = v->data[i];
  };
  return copy;
}

// освобождает память, занятую динамическим массивом внутри и занятую структурой
void int_vector_free(struct IntVector *v) {
  if (v != NULL) {
    free(v->data);
    free(v);
  }
}

// возвращает элемент элемент под намером index.  В случае выхода за границы массива поведение не определено.
int int_vector_get_item(const struct IntVector *v, size_t index) {
  return v->data[index];
}

//  Присваивает элементу под номером index значение item. В случае выхода за границы массива поведение не определено.
void int_vector_set_item(struct IntVector *v, size_t index, int item) {
  if (index < v->size)
    v->data[index] = item;
}

// возвращает размер вектора 
size_t int_vector_get_size(const struct IntVector *v) { 
  return v->size; }

size_t int_vector_get_capacity(const struct IntVector *v) {
  return v->capacity;
}
// Добавляет элемент в конец массива. При необходимости меняет size
int int_vector_push_back(struct IntVector *v, int item) {
  if (v->capacity > v->size) {
    v->data[v->size] = item;
    v->size++;
    return 0;
  } else {
    v->capacity = v->capacity * 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data)) {
      return -1;
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
  }
  //
}

// Удаляет последний элемент из массива. Нет эффекта, если размер массива равен 0. 
void int_vector_pop_back(struct IntVector *v) {
  if (v->size > 0) {
    v->size--;
  }
}

// 
int int_vector_shrink_to_fit(struct IntVector *v) {
  if (v->capacity == v->size) {
    return 0;
  } else {
    v->capacity = v->size;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data))
      return -1;
    return 0;
  }
}

// Изменяет размер массива (size), 
int int_vector_resize(struct IntVector *v, size_t new_size) {
  if (new_size > v->size) {
    if (v->capacity < new_size) {
      v->capacity = new_size;
      v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    for (int i = new_size - (new_size - v->size); i < new_size; i++) {
      v->data[i] = 0;
    }
    v->size = new_size;
    return 0;
  } else if (new_size == v->size) {
    return 0;
  } else {
    printf("error : use int_vector_shrink_to_fit ");
    return -1;
    // error error : use int_vector_shrink_to_fit resize         capacity - 12 size - 3  321 123 612
  }
  // 
}

// Изменяет емкость (capacity) массива, перераспределяет память.
int int_vector_reserve(struct IntVector *v, size_t new_capacity) {
  if (new_capacity > v->capacity) {
    v->capacity = new_capacity;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data))
      return -1;
    return 0;
  } else
    return 0;
  // 
}

// Вывод массива
void prmas(struct IntVector *v) {
  for (int i = 0; i < v->size; i++) {
    printf(" %d", v->data[i]);
  }
  printf("\n");
}