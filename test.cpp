// #include "Map/test_bst.hpp"

#include <iostream>

enum colors{
    RED,
    BLACK
};

typedef struct s_Node
{
    std::string str;
    colors Color;
    s_Node *left;
    s_Node *right;
    s_Node *parents;
} t_Node;

class test
{

public:
        test()
        {
            root = nullptr;
        }
        ~test()
        {

        }
        t_Node * create_NODE(std::string str)
        {

            // std::allocator alloc<t_Node>;
            t_Node *ret = new t_Node;
            ret->str = str;
            ret->Color  = RED;
            ret->left = nullptr;
            ret->right = nullptr;
            ret->parents = nullptr;

            return ret;
        }
        void insert(std::string key) 
        {
            t_Node *node;
            // t_Node *t_NULL  = new t_Node;
            // t_NULL->Color = BLACK;
            // t_NULL->right = nullptr;
            // t_NULL->left = nullptr;

            // t_Node *Tnode = create_NODE(NULL);
            t_Node *x;
            t_Node *y;
            x = this->root;
            y = nullptr;
            node  = create_NODE(key);
                // std::cout << "im here" << std::endl;
            while (x != NULL)
            {
                // std::cout << "amine" << std::endl;
                y = x;
                // std::cout << "im here1" << std::endl;
                if (node->str < x->str)
                {
                    std::cout << "node->str = " << node->str << std::endl;
                    std::cout << "x->str = " << x->str << std::endl;
                    x = x->left;
                }
                else
                    x = x->right;
                // std::cout << "im here2" << std::endl;
            }
            node->parents = y;
            if (y == NULL)
                this->root = node;
            else if (node->str < y->str)
                y->left = node;
            else
                y->right = node;
        }
        void print_tree_in_ordre_travers(t_Node *root1)
        {
            t_Node *tmp;
            // tmp = root;
            // if (tmp != NULL)
            // {
            //     tmp = most_left(tmp);
            //     while (tmp)
            //     {
            //         std::cout << tmp->str << std::endl;
            //         tmp = tmp->parents;
            //         tmp = tmp->right;

            //         if (!tmp)
            //             std::cout << "tmp->str" << std::endl;
            //         // tmp = most_left(tmp);
            //     }
            tmp = root1;
            if (tmp)
            {
                print_tree_in_ordre_travers(tmp->left);
                std::cout << tmp->str << std::endl;
                print_tree_in_ordre_travers(tmp->right);
            }
            // }
        }
        t_Node *getroot()
        {
            return root;
        }
    private:
        t_Node *root;
};




// t_Node *insert(t_Node *node, std::string key) 
// {
//     if (node == NULL) 
//         return create_NODE(key);
//     if (key < node->str)
//         node->left = insert(node->left, key);
//     else
//         node->right = insert(node->right, key);

//     return node;
// }

t_Node * most_left(t_Node * root)
{
    t_Node *tmp;

    if (tmp->left)
    {
        tmp = root;
        while (tmp->left)
        {
            tmp = tmp->left;
        }
    }
    return tmp;
}
t_Node * most_right(t_Node * root)
{
    t_Node *tmp;

    if (tmp->right)
    {
        tmp = root;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
    }
    return tmp;
}

void print_tree_in_ordre_travers(t_Node *root)
{
    t_Node *tmp;
    // tmp = root;
    // if (tmp != NULL)
    // {
    //     tmp = most_left(tmp);
    //     while (tmp)
    //     {
    //         std::cout << tmp->str << std::endl;
    //         tmp = tmp->parents;
    //         tmp = tmp->right;

    //         if (!tmp)
    //             std::cout << "tmp->str" << std::endl;
    //         // tmp = most_left(tmp);
    //     }
    tmp = root;
    if (tmp)
    {
        print_tree_in_ordre_travers(tmp->left);
        std::cout << tmp->str << std::endl;
        print_tree_in_ordre_travers(tmp->right);
    }
    // }
}

t_Node *root_prev(t_Node * root)
{
    // t_Node *tmp1 = root;
    if (root->left)
    {
        root = most_right(root->left);
    }
    // else
    // {
    //     t_Node *tmp = root->parents;
    //     while (tmp && tmp->left == tmp1)
    //     {
    //         tmp1 = tmp;
    //         tmp = tmp->parents;
    //     }
    //     if (tmp)
    //         tmp1 = tmp;
    //     else
    //         tmp1 = NULL;
    // }
    return (root);
}
t_Node *root_next(t_Node *root)
{
    // t_Node *next = root;
    if (root->right != NULL)
    {
        root = most_left(root->right);
    }
    // else
    // {
    //     t_Node *tmp = root->parents;
    //     while (tmp && tmp->right == next)
    //     {
    //         next = tmp;
    //         tmp = tmp->parents;
    //     }
    //     if (tmp)
    //         next = tmp;
    //     else
    //         next = NULL;
    // }
    return (root);
}


int main()
{
    test bst;
    bst.insert("amine");
    bst.insert("amine5");
    bst.insert("amine4");
    bst.insert("amine3");
    bst.print_tree_in_ordre_travers(bst.getroot());
    // test insert
    // std::string str1 = "A";
    // std::string str2 = "D";
    // std::string str3 = "J";
    // std::string str4 = "M";
    // std::string str5 = "R";
    // std::string str6 = "Q";
    // std::string str7 = "T";
    // t_Node *tmp1 = create_NODE(str1);
    // t_Node *tmp2 = create_NODE(str2);
    // t_Node *tmp3 = create_NODE(str3);
    // t_Node *root = create_NODE(str4);
    // t_Node *tmp5 = create_NODE(str5);
    // t_Node *tmp6 = create_NODE(str6);
    // t_Node *tmp7 = create_NODE(str7);
    // root->left = tmp2;
    // tmp2->left = tmp1;
    // tmp2->right = tmp3;
    // tmp2->parents = root;
    // root->right = tmp5;
    // tmp5->left = tmp6;
    // tmp5->right = tmp7;
    // tmp5->parents = root;
    // t_Node * root = NULL;
    // root = insert(root, "B");
    // root = insert(root, "J");
    // root = insert(root, "A");
    // root = insert(root, "R");
    // root = insert(root, "Z");
    // root = insert(root, "M");
    // root = insert(root, "Q");
    // root = insert(root, "T");
    // root = insert(root, "Y");
    // root = insert(root, "D"); 
    // t_Node *print = root;
    // std::cout << root->str << std::endl;
    // print = root_prev(print);
    // std::cout << print->str << std::endl;
    // print = root_prev(print);
    // std::cout << print->str << std::endl;
    // print = root_next(print);
    // std::cout << print->str << std::endl;
    // print = root_next(print);
    // std::cout << print->str << std::endl;
    // std::cout << root_next(root)->str << std::endl;
    // std::cout << root_next(root)->str << std::endl;
    // print_tree_in_ordre_travers(print);
    // while (1);
}
// NodePtr y = x->parent;
// 		while (y != TNULL && x == y->left) {
// 			x = y;
// 			y = y->parent;
// 		}