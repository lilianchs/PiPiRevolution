#include "ringbuffer2d.h"
#include "assert.h"
#include "malloc.h"
#include "gl.h"

#define ROWS gl_get_height()
#define COLS gl_get_width()


/*
 * A ring buffer is represented using a struct containing a fixed-size array
 * and head and tail fields, which are indexes into the entries[] array.
 * head is the index of the frontmost element (head advances during dequeue)
 * tail is the index of the next position to use (tail advances during enqueue)
 * Both head and tail advance circularly, i.e. index = (index + 1) % LENGTH
 * The ring buffer is empty if tail == head
 * The ring buffer is full if tail + 1 == head
 * (Note: one slot remains permanently empty to distinguish full from empty)
 */

struct ringbuffer2d {
    int entries[1][1];
    int head_row, tail_row;
};

rb2d_t *rb_new2d(void) {
    rb2d_t *rb = malloc(sizeof(struct ringbuffer));
    assert(rb != NULL);
    rb->head_row = rb->tail_row = 0;
    return rb;
}

bool rb_empty(rb2d_t *rb) {
    assert(rb != NULL);
    return (rb->head_row == rb->tail_row) && (rb->head_col == rb->tail_col);
}

bool rb_full(rb2d_t *rb) {
    assert(rb != NULL);
    return ((rb->tail_row + 1) % ROWS == rb->head_row) && ((rb->tail_col + 1) % COLS == rb->head_col);
}

/*
 * Note: enqueue is called by writer. enqueue advances rb->tail,
 * no changes to rb->head.  This design allows safe concurrent access.
 */
bool rb_enqueue(rb2d_t *rb, int elem) {
  assert(rb != NULL);
    if (rb_full(rb)) {
      return false;
    }

    rb->entries[rb->tail_row][rb->tail_col] = elem;
    rb->tail_col = (rb->tail_col + 1) % COLS;
    if (rb->tail_col == 0) {
      rb->tail_row = (rb->tail_row + 1) % ROWS;
    }
    return true;
}

/*
 * Note: dequeue is called by reader. dequeue advances rb->head,
 * no changes to rb->tail. This design allows safe concurrent access.
 */
bool rb_dequeue(rb2d_t *rb, int *p_elem) {
    assert(rb != NULL && p_elem != NULL);
    if (rb_empty(rb)) {
      return false;
    }

    *p_elem = rb->entries[rb->head_row][rb->head_col];
    rb->head_col = (rb->head_col + 1) % COLS;
    if (rb->head_col == 0) {
      rb->head_row = (rb->head_row + 1) % ROWS;
    }
    return true;
}
