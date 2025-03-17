/*
 * mm-implicit.c - an empty malloc package
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 *
 * @id : 202102638
 * @name : ParkSungMin
 */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "mm.h"
#include "memlib.h"

/* If you want debugging output, use the following macro. When you hand
 * in, remove the #define DEBUG line. */
#define DEBUG
#ifdef DEBUG
# define dbg_printf(...) printf(VA_ARGS)
#else
# define dbg_printf(...)
#endif

/* do not change the following! */
#ifdef DRIVER
/* create aliases for driver tests */
#define malloc mm_malloc
#define free mm_free
#define realloc mm_realloc
#define calloc mm_calloc
#endif /* def DRIVER */

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE (1 << 12)
#define OVERHEAD 8
#define MAX(x,y) ((x)>(y) ? (x):(y))
#define PACK(size, alloc) ((size) | (alloc))
#define GET(p) ((unsigned int*)(p))
#define PUT(p,val) ((unsigned int)(p)=(val))

#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)
#define HDRP(bp) ((char*)(bp) - WSIZE)
#define FTRP(bp) ((char*)(bp) + GET_SIZE(HDRP(bp))-DSIZE)
#define NEXT_BLKP(bp) ((char*)(bp) + GET_SIZE((char*)(bp)-WSIZE))
#define PREV_BLKP(bp) ((char*)(bp) - GET_SIZE((char*)(bp)-DSIZE))

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(p) (((size_t)(p) + (ALIGNMENT-1)) & ~0x7)

static char *heap_listp = 0;
static char nextfit=0;
static void coalesce(void bp);
static void extend_heap(size_t words);

/*
 * Initialize: return -1 on error, 0 on success.
 */
int mm_init(void) {
    if((heap_listp = mem_sbrk(4*WSIZE)) == (void)-1){
        return -1;
    }
    PUT(heap_listp, 0);
    PUT(heap_listp+WSIZE, PACK(OVERHEAD, 1));
    PUT(heap_listp+DSIZE, PACK(OVERHEAD, 1));
    PUT(heap_listp+WSIZE+DSIZE, PACK(0, 1));
    heap_listp += DSIZE;
    nextfit = heap_listp;

    if(extend_heap(CHUNKSIZE/WSIZE) == NULL)
        return -1;

    return 0;
}

static void place(void *bp, size_t asize) {
    size_t csize = GET_SIZE(HDRP(bp));

    PUT(HDRP(bp), PACK(csize,1));
    PUT(FTRP(bp), PACK(csize,1));
}
static void *find_fit(size_t asize){
    void *bp;

    heap_listp = 0;
    for(bp = heap_listp;bp> 0; bp = NEXT_BLKP(bp)){
        if(!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp)))){
            return bp;
        }
    }
    return NULL;
}

static void *extend_heap(size_t words){
    size_t size = ALIGN(words * WSIZE);
    char bp = mem_sbrk(size);
    if((long) (bp) == -1){
        return NULL;
    }

    PUT(HDRP(bp), PACK(size,0));
    PUT(FTRP(bp), PACK(size,0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0,1));

    return bp;
}

/*
 * malloc
 */
void *malloc (size_t size) {
    size_t asize;
    size_t extendsize;
    char *bp;

    if(size == 0){
        return NULL;
    }
    asize = ALIGN(size + OVERHEAD);;
    if((bp = find_fit(asize)) != NULL){
        place(bp, asize);
        return bp;
    }

    extendsize = MAX(asize,CHUNKSIZE);

    if((bp = extend_heap(extendsize/WSIZE))==NULL){
        return NULL;
    }

    place(bp,asize);
    return bp;
}

void free (void *bp) {

}

static void *coalesce(void bp){
}

/*
 * realloc - you may want to look at mm-naive.c
 */
void *realloc(void *oldptr, size_t size) {

    size_t oldsize;
    void newptr;

    if(size == 0) {
        free(oldptr);
        return 0;
    }
    if(oldptr == NULL) {
        return malloc(size);
    }

    newptr = malloc(size);

    if(!newptr){
        return 0;
    }

    oldsize = GET_SIZE(HDRP(oldptr));
    if(size<oldsize){
        oldsize = size;
    }
    memcpy(newptr, oldptr, oldsize);
    free(oldptr);
    return newptr;
}

/*
 * calloc - you may want to look at mm-naive.c
 * This function is not tested by mdriver, but it is
 * needed to run the traces.
 */
void *calloc (size_t nmemb, size_t size) {
    size_t bytes = nmemb * size;
    void newptr;
    newptr = malloc(bytes);
    memset(newptr, 0, bytes);

    return newptr;
}

/*
 * Return whether the pointer is in the heap.
 * May be useful for debugging.
 */
static int in_heap(const void p) {
    return p < mem_heap_hi() && p >= mem_heap_lo();
}

/*
 * Return whether the pointer is aligned.
 * May be useful for debugging.
 */
static int aligned(const void p) {
    return (size_t)ALIGN(p) == (size_t)p;
}

/*
 * mm_checkheap
 */
void mm_checkheap(int verbose) {
}
