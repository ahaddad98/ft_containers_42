/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bst.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:53:26 by ahaddad           #+#    #+#             */
/*   Updated: 2021/11/26 18:23:10 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BST_HPP
# define TEST_BST_HPP

#include <iostream>
// to test
typedef char item_type;

typedef struct s_tree_node
{
    item_type info;
    s_tree_node *right;
    s_tree_node *left;
} t_tree_node;

enum Order_type{
    PRE_ORDER,
    IN_ORDRE,
    POST_ORDER
};

class tree_type
{
private:
    t_tree_node *root;
public:
    tree_type()
    {
        root = NULL;
    }
    ~tree_type();
    tree_type(const tree_type & rhs);
    void operator=(const tree_type & rhs);
    void MakeEmpty();
    bool isEmpty() const
    {
        return root == NULL;
    }
    bool isFull() const
    {
        t_tree_node * location;
        try
        {
            location  = new t_tree_node;
            delete location;
            return false;
        }
        catch(std::bad_alloc exeption)
        {
            return true;
        }
        
    }
    int count_nodes(s_tree_node *tree) const
    {
        if (tree == NULL)
            return 0;
        return count_nodes(tree->left) + count_nodes(tree->right) + 1;
    }
    int Lengthis() const
    {
        return count_nodes(root);
    }
    void recupere(t_tree_node *tree, item_type &item, bool & found) const
    {
        if (tree == NULL)
            found  = false;
        else if (item < tree->info)
            recupere(tree->left, item, found);
        else if (item > tree->info)
            recupere(tree->right, item, found);
        else
        {
            item = tree->info;
            found = true;
        }
    }
    void recupere_Item(item_type & item, bool &found) const
    {
        recupere(root, item , found);
    }
    void insert(t_tree_node *&tree, item_type item)
    {
        if (tree == NULL)
        {
            tree = new t_tree_node;
            tree->left = NULL;
            tree->right = NULL;
            tree->info = item;
        }
        if (item < tree->info)
            insert(tree->left, item);
        if (item > tree->info)
            insert(tree->right, item);
    }
    void insertItem(item_type item)
    {
        insert(root, item);
    }
    void get_predecessor(t_tree_node *tree, item_type &data)
    {
        while (tree->right != NULL)
            tree = tree->right;
        data = tree->info;
    }
    // void Delete(t_tree_node *&tree , item_type item);
    // void delete_node(t_tree_node *&tree)
    // {
    //     item_type data;
    //     t_tree_node *tmp_ptr;

    //     tmp_ptr = tree;
    //     if (tree->left == NULL)
    //     {
    //         tree = tree->right;
    //         delete tmp_ptr;
    //     }
    //     else if (tree->right == NULL)
    //     {
    //         tree = tree->left;
    //         delete tmp_ptr;
    //     }
    //     else
    //     {
    //         get_predecessor(tree->left, data);
    //         tree->info = data;
    //         Delete(tree->left, data);
    //     }
    // }
    // void Delete(t_tree_node *&tree , item_type item)
    // {
    //     if (item < tree->info)
    //         Delete(tree->left, item);
    //     else if (item > tree->info)
    //         Delete(tree->right, item);
    //     else
    //         delete_node(tree);
    // }
    // void DeleteItem(item_type item)
    // {
    //     Delete(root , item);
    // }
    void reset_tree(Order_type order);
    void get_next_item(item_type & item, Order_type order,  bool & finished);
    void print_tree(t_tree_node *tree, std::ofstream & out)
    {
        if (tree != NULL)
        {
            print_tree(tree->left, out);
            out << tree->info;
            print_tree(tree->right, out);
        }
    }
    void print(std::ofstream & outfile)
    {
        print_tree(root, outfile);
    }
};

#endif