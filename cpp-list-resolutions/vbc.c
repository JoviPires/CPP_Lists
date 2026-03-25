//This file is given at the exam

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of input\n");
}

int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}

static node    *parse_expr_internal(char **s);

node    *parse_factor(char **s)
{
    node    n;
    node    *expr;

    if (isdigit(**s))
    {
        n.type = VAL;
        n.val = **s - '0';
        n.l = NULL;
        n.r = NULL;
        (*s)++;
        return (new_node(n));
    }
    if (accept(s, '('))
    {
        expr = parse_expr_internal(s);
        if (!expr)
            return (NULL);
        if (!expect(s, ')'))
        {
            destroy_tree(expr);
            return (NULL);
        }
        return (expr);
    }
    unexpected(**s);
    return (NULL);
}

node    *parse_term(char **s)
{
    node    *left;
    node    *right;
    node    n;

    left = parse_factor(s);
    if (!left)
        return (NULL);
    while (accept(s, '*'))
    {
        right = parse_factor(s);
        if (!right)
        {
            destroy_tree(left);
            return (NULL);
        }
        n.type = MULTI;
        n.val = 0;
        n.l = left;
        n.r = right;
        left = new_node(n);
        if (!left)
        {
            destroy_tree(n.l);
            destroy_tree(n.r);
            return (NULL);
        }
    }
    return (left);
}

static node    *parse_expr_internal(char **s)
{
    node    *ret;
    node    *right;
    node    n;

    ret = parse_term(s);
    if (!ret)
        return (NULL);
    while (accept(s, '+'))
    {
        right = parse_term(s);
        if (!right)
        {
            destroy_tree(ret);
            return (NULL);
        }
        n.type = ADD;
        n.val = 0;
        n.l = ret;
        n.r = right;
        ret = new_node(n);
        if (!ret)
        {
            destroy_tree(n.l);
            destroy_tree(n.r);
            return (NULL);
        }
    }
    return (ret);
}

node    *parse_expr(char *s)
{
    char    *s_ptr = s;
    node    *ret;

    ret = parse_expr_internal(&s_ptr);
    if (!ret)
        return (NULL);
    if (*s_ptr)
    {
        unexpected(*s_ptr);
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
        default:
            return (0);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
    return (0);
}
