static char* free_start;
static char* h_ptr = NULL;
static void *coalesce(void *bp);

static void *extend_heap(size_t words) {
    size_t size;

    size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
    char *bp = mem_sbrk(size);
    if((size_t)(bp) < 0) {
        return NULL;
    }

    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));

    PUT8(PREV_FREEP(bp), NULL);
    PUT8(NEXT_FREEP(bp), NULL);
    if(heap_start != NULL) {
        PUT8(PREV_FREEP(heap_start), bp);
        PUT8(NEXT_FREEP(bp), heap_start);
    }
    heap_start = bp;
    return heap_start;
}

int mm_init(void) {
    if ((h_ptr = mem_sbrk(DSIZE + 4 * HDRSIZE)) == NULL) {
        return -1;
    }
    free_start = h_ptr;
    PUT8(h_ptr, NULL);
    PUT(h_ptr + DSIZE, 0);
    PUT(h_ptr + DSIZE + HDRSIZE, PACK(OVERHEAD,1));
    PUT(h_ptr + DSIZE + HDRSIZE + FTRSIZE, PACK(OVERHEAD,1));
    PUT(h_ptr + DSIZE + 2 * HDRSIZE + FTRSIZE, PACK(0,1));
    h_ptr+=(DSIZE + DSIZE);
    return 0;
}

static void *find_fit(size_t asize) {
    void *bp = free_start;
    void *best_fit = NULL;
    size_t best_fit_size = -1;

    while(bp != NULL) {
        size_t free_block_size = GET_SIZE(HDRP(bp));
        if(free_block_size >= asize) {
            if(best_fit_size == -1) {
                best_fit_size = free_block_size;
                best_fit = bp;
            }
            if(best_fit_size > free_block_size) {
                best_fit_size = free_block_size;
                best_fit = bp;
            }
            if(free_block_size == asize) {
                return bp;
            }
        }
        bp = NEXT_FREE_BLKP(bp);
    }
    return best_fit;
}

static void place(void *bp, size_t asize) {
    size_t csize = GET_SIZE(HDRP(bp));

    char *prev_bp = PREV_FREE_BLKP(bp);
    char *next_bp = NEXT_FREE_BLKP(bp);

    PUT(HDRP(bp), PACK(csize, 1));
    PUT(FTRP(bp), PACK(csize, 1));

    if(prev_bp == NULL && next_bp == NULL) {
        free_start = NULL;
        return;
    }
    if(prev_bp == NULL && next_bp != NULL) {
        PUT8(PREV_FREEP(next_bp), NULL);
        free_start = next_bp;
        return;
    }
    if(prev_bp != NULL && next_bp == NULL) {
        PUT8(NEXT_FREEP(prev_bp), NULL);
        return;
    }
    PUT8(NEXT_FREEP(prev_bp), next_bp);
    PUT8(PREV_FREEP(next_bp), prev_bp);
}

void *malloc(size_t size) {
    char *bp;
    unsigned asize;
    if (size <= 0)
        return NULL;

    asize =  MAX(ALIGN(size + OVERHEAD), (2 * DSIZE + OVERHEAD));
    if ((bp = find_fit(asize)) != NULL) {
        place(bp, asize);
        return bp;
    }
    if((bp = extend_heap(asize / WSIZE)) == NULL) {
        return NULL;
    }
    place(bp, asize);
    return bp;
}

void free(void *ptr) {
}

static void *coalesce(void *bp) {
}

void *realloc(void *oldptr, size_t size) {
    if (size == 0) {
        free(oldptr);
        return 0;
    }
    if (oldptr == NULL) {
        return malloc(size);
    }
    void *newptr = malloc(size);
    if (newptr == NULL) {
        return NULL;
    }
    size_t oldsize = GET_SIZE(HDRP(oldptr));
    if(size < oldsize) oldsize = size;
    memcpy(newptr, oldptr, oldsize);
    free(oldptr);
    return newptr;
}

void *calloc(size_t nmemb, size_t size) {
    size_t bytes = nmemb * size;
    void *newptr;

    newptr = malloc(bytes);
    memset(newptr, 0, bytes);
    return newptr;
}

static int in_heap(const void *p) {
    return p < mem_heap_hi() && p >= mem_heap_lo();
}

static int aligned(const void *p) {
    return (size_t)ALIGN(p) == (size_t)p;
}

void mm_checkheap(int verbose) {
}
