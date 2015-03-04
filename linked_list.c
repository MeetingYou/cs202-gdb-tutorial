#include <stdio.h>
#include <string.h>
#include "linked_list.h"

void list_init(list_t *h) {
    *h = NULL;
}

int list_size(list_t *h) {
	if (h == NULL || *h == NULL)
		return 0;
    node_t *p = *h;
    int r = 0;
    do {
        r += 1;
        p = p->next;
    } while (p);
    return r;
}

int list_empty(list_t *h) {
	if (*h = NULL) {
		return 1;
	} else {
		return 0;
	}
}

int list_not_empty(list_t *h) {
    return !list_empty(h);
}

void list_insert(list_t *h, node_t *n) {
    n->next = *h;
    *h = n;
}

node_t *list_find(const list_t *h, int id) {
    node_t *p = *h;
    while (p) {
        if (p->id == id) return p;
        p = p->next;
    }
}

node_t *list_find_before(const list_t *h, int id) {
    node_t *p = *h;
    while (p && p->next) {
        if (p->next->id == id) return p;
        p = p->next;
    }
    return NULL;
}

node_t *list_delete(list_t *h, int id) {
    node_t *r = NULL;
    if (*h && (*h)->id == id) {
        r = *h;
        *h = NULL;
        return r;
    }
    node_t *p = list_find_before(h, id);
    if (p) {
        r = p->next;
        p->next = p->next->next;
        r->next = NULL; 
    }
    return r;
}

void print_list(const list_t *h) {
    node_t *p = *h;
    while (p) {
        printf("%d: %s says %s\n", p->id, p->name, p->msg);
        p = p->next;
    }
}
