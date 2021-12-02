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

t_Node * create_NODE(std::string str)
{
    t_Node *ret = new t_Node;
    ret->str = str;
    ret->Color  = RED;
    ret->left = NULL;
    ret->right = NULL;
    ret->parents = NULL;

    return ret;
}

void print_tree_in_ordre_travers(t_Node *root)
{
    if (root != NULL)
    {
        print_tree_in_ordre_travers(root->left);
        std::cout << root->str << std::endl;
        print_tree_in_ordre_travers(root->right);
    }
}

int main()
{
    std::string str1 = "A";
    std::string str2 = "D";
    std::string str3 = "J";
    std::string str4 = "M";
    std::string str5 = "R";
    std::string str6 = "Q";
    std::string str7 = "T";
    t_Node *tmp1 = create_NODE(str1);
    t_Node *tmp2 = create_NODE(str2);
    t_Node *tmp3 = create_NODE(str3);
    t_Node *root = create_NODE(str4);
    t_Node *tmp5 = create_NODE(str5);
    t_Node *tmp6 = create_NODE(str6);
    t_Node *tmp7 = create_NODE(str7);
    root->left = tmp2;
    tmp2->left = tmp1;
    tmp2->right = tmp3;
    tmp2->parents = root;
    root->right = tmp5;
    tmp5->left = tmp6;
    tmp5->right = tmp7;
    tmp5->parents = root;
    t_Node *print = root;
    print_tree_in_ordre_travers(print);
    // while (1);
}