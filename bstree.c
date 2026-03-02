#include <stdio.h>
struct rec {
    int val;
    struct rec *lo;  
    struct rec *hi;  
};

struct rec *root;     
struct rec *add();
struct rec *drop();
struct rec *wipe();
struct rec *flip();
struct rec *least();
struct rec *most();
int        show_pre();
int        show_in();
int        show_post();
int        count();
int        leaves();
int        inner();
int        depth();

main()
{
    int ch, n;
    struct rec *p;

    root = NULL;

    do {
        printf("\n--- BST MENU ---\n");
        printf("1  Add a number\n");
        printf("2  Print pre-order\n");
        printf("3  Print in-order\n");
        printf("4  Print post-order\n");
        printf("5  Lowest value\n");
        printf("6  Highest value\n");
        printf("7  Remove a number\n");
        printf("8  How many nodes\n");
        printf("9  How many leaves\n");
        printf("10 How many inner nodes\n");
        printf("11 Tree depth\n");
        printf("12 Mirror the tree\n");
        printf("13 Wipe the tree\n");
        printf("14 Quit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {

        case 1:
            printf("Number to add: ");
            scanf("%d", &n);
            root = add(root, n);
            break;

        case 2:
            printf("Pre-order:  ");
            show_pre(root);
            printf("\n");
            break;

        case 3:
            printf("In-order:   ");
            show_in(root);
            printf("\n");
            break;

        case 4:
            printf("Post-order: ");
            show_post(root);
            printf("\n");
            break;

        case 5:
            p = least(root);
            if (p != NULL)
                printf("Lowest:  %d\n", p->val);
            else
                printf("Tree is empty.\n");
            break;

        case 6:
            p = most(root);
            if (p != NULL)
                printf("Highest: %d\n", p->val);
            else
                printf("Tree is empty.\n");
            break;

        case 7:
            printf("Number to remove: ");
            scanf("%d", &n);
            root = drop(root, n);
            break;

        case 8:
            printf("Nodes:        %d\n", count(root));
            break;

        case 9:
            printf("Leaves:       %d\n", leaves(root));
            break;

        case 10:
            printf("Inner nodes:  %d\n", inner(root));
            break;

        case 11:
            printf("Depth:        %d\n", depth(root));
            break;

        case 12:
            root = flip(root);
            printf("Tree mirrored.\n");
            break;

        case 13:
            root = wipe(root);
            printf("Tree wiped.\n");
            break;

        case 14:
            printf("Bye!\n");
            break;

        default:
            printf("Bad choice.\n");
            break;
        }

    } while (ch != 14);

    return 0;
}


struct rec *add(r, n)
struct rec *r;
int n;
{
    struct rec *fresh, *cur, *par;

    fresh = (struct rec *) alloc(6);
    fresh->val = n;
    fresh->lo  = NULL;
    fresh->hi  = NULL;

    if (r == NULL)
        return fresh;

    par = NULL;
    cur = r;
    while (cur != NULL) {
        par = cur;
        if (n < cur->val)
            cur = cur->lo;
        else
            cur = cur->hi;
    }
    if (n < par->val)
        par->lo = fresh;
    else
        par->hi = fresh;

    return r;
}


int show_pre(r)
struct rec *r;
{
    if (r != NULL) {
        printf("%d ", r->val);
        show_pre(r->lo);
        show_pre(r->hi);
    }
    return 0;
}

int show_in(r)
struct rec *r;
{
    if (r != NULL) {
        show_in(r->lo);
        printf("%d ", r->val);
        show_in(r->hi);
    }
    return 0;
}

int show_post(r)
struct rec *r;
{
    if (r != NULL) {
        show_post(r->lo);
        show_post(r->hi);
        printf("%d ", r->val);
    }
    return 0;
}


struct rec *least(r)
struct rec *r;
{
    if (r == NULL || r->lo == NULL)
        return r;
    return least(r->lo);
}

struct rec *most(r)
struct rec *r;
{
    if (r == NULL || r->hi == NULL)
        return r;
    return most(r->hi);
}


struct rec *drop(r, n)
struct rec *r;
int n;
{
    struct rec *cur, *par, *successor, *spar, *replacement;

    if (r == NULL) {
        printf("Tree is empty.\n");
        return r;
    }

    par = NULL;
    cur = r;
    while (cur != NULL && cur->val != n) {
        par = cur;
        if (n < cur->val)
            cur = cur->lo;
        else
            cur = cur->hi;
    }

    if (cur == NULL) {
        printf("%d not found.\n", n);
        return r;
    }

    if (cur->lo == NULL) {
        replacement = cur->hi;
    } else if (cur->hi == NULL) {
        replacement = cur->lo;
    } else {

        spar = cur;
        successor = cur->hi;
        while (successor->lo != NULL) {
            spar = successor;
            successor = successor->lo;
        }
        if (spar == cur) {
            successor->lo = cur->lo;
        } else {
            spar->lo      = successor->hi;
            successor->lo = cur->lo;
            successor->hi = cur->hi;
        }
        replacement = successor;
    }

    if (par == NULL) {
        free(cur);
        return replacement;
    }
    if (par->lo == cur)
        par->lo = replacement;
    else
        par->hi = replacement;

    free(cur);
    return r;
}

int count(r)
struct rec *r;
{
    if (r == NULL)
        return 0;
    return count(r->lo) + count(r->hi) + 1;
}

int leaves(r)
struct rec *r;
{
    if (r == NULL)
        return 0;
    if (r->lo == NULL && r->hi == NULL)
        return 1;
    return leaves(r->lo) + leaves(r->hi);
}

int inner(r)
struct rec *r;
{
    if (r == NULL || (r->lo == NULL && r->hi == NULL))
        return 0;
    return inner(r->lo) + inner(r->hi) + 1;
}

int depth(r)
struct rec *r;
{
    int l, h;
    if (r == NULL)
        return 0;
    l = depth(r->lo);
    h = depth(r->hi);
    return (l > h ? l : h) + 1;
}

struct rec *flip(r)
struct rec *r;
{
    struct rec *tmp;
    if (r != NULL) {
        flip(r->lo);
        flip(r->hi);
        tmp   = r->lo;
        r->lo = r->hi;
        r->hi = tmp;
    }
    return r;
}

struct rec *wipe(r)
struct rec *r;
{
    if (r != NULL) {
        wipe(r->lo);
        wipe(r->hi);
        free(r);
    }
    return NULL;
}
