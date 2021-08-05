// C++ program to implement optimized delete in BST.
#include <bits/stdc++.h>
using namespace std;
 

			// t_node	*delete_one_node_by_key(t_node *root, Key toFind)
			// {
			// 	if (!root )
			// 		return (root);
			// 	if (_comp(root->data->first, toFind))
			// 	{
			// 		std::cout << "RIGHT | root->data->first = " << root->data->first << std::endl;
			// 		root->right = delete_one_node_by_key(root->right, toFind);
			// 	}
			// 	else if (!_comp(root->data->first, toFind) && _comp(toFind, root->data->first) )
			// 	{
			// 		std::cout << "LEFT | root->data->first = " << root->data->first << std::endl;
			// 		root->left = delete_one_node_by_key(root->left, toFind);
			// 	}
			// 	else
			// 	{
			// 		if (root->right == NULL || root->left == NULL )/* If one of the children is empty*/
			// 		{
			// 			std::cout << "one of the children is empty" << std::endl;
			// 			std::cout << "root->data->first = " << root->data->first << std::endl;
			// 			root = delete_children_is_empty(root);
			// 		}
			// 		else
			// 		{
			// 			std::cout << "node to delete have two children" << std::endl;
			// 			t_node *succesor = root->get_next_node();
			// 			std::cout << "\nbefor SWap :" << std::endl;
			// 			std::cout << "root = " << root->data->first << " second " << root->data->second << std::endl;
			// 			std::cout << "succesor = " << succesor->data->first << " second " << succesor->data->second << std::endl;
			// 			ft_swap(succesor->data, root->data);
			// 			std::cout << "\nafter SWap:" << std::endl;
			// 			std::cout << "root = " << root->data->first << " second " << root->data->second << std::endl;
			// 			std::cout << "succesor = " << succesor->data->first << " second " << succesor->data->second << std::endl;
			// 			// succesor->parent = root->parent;
			// 			// root->parent = successorParent;
						
			// 			if (root->right == succesor)
			// 			{
			// 				std::cout << "salluuuuuutttt" << std::endl;
			// 				root->right = delete_one_node_by_key(succesor, toFind);
			// 			}
			// 			else if (root->left == succesor)
			// 			{
			// 				std::cout << "wshhhh ????" << std::endl;

			// 				root->left = delete_one_node_by_key(succesor, toFind);
			// 			}
			// 			else
			// 				delete_one_node_by_key(succesor->parent, toFind);
			// 			// t_node *successorParent = succesor->parent;

			// 			// std::cout << "\nafeter delete:" << std::endl;
			// 			// std::cout << "root = " << root->data->first << " second " << root->data->second << std::endl;
			// 			// root->right = 0;
			// 			// exit(0);
			// 			// root = succesor;
			// 		// 	std::cout << "succesor = " << succesor->data->first << " second = " << succesor->data->second << std::endl;
			// 		}
			// 	}
			// 	return (root);
			// }

struct Node {
    int key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// A utility function to do inorder traversal of BST
void inorder(Node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
/* A utility function to insert a new node with given key in
 * BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
 
/* Given a binary search tree and a key, this function
   deletes the key and returns the new root */
Node* deleteNode(Node* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->key > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->key < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
		{
			std::cout << "succParent->key = " << succParent->key << std::endl;
			// std::cout << "succParent->key = " << succ->right->key << std::endl;

            succParent->left = succ->right;
		}
		else
		{
            succParent->right = succ->right;
		}
        // Copy Successor Data to root
        root->key = succ->key;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}

void	my_clear_tree( Node*  node)
{
				if (node)
				{
					my_clear_tree(node->left);
					my_clear_tree(node->right);
					delete node;

				}
}
 
// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node* root = NULL;
    // root = insert(root, 50);
    // root = insert(root, 30);
    // root = insert(root, 20);
    // root = insert(root, 40);
    // root = insert(root, 70);
    // root = insert(root, 60);
    // root = insert(root, 55);
    // root = insert(root, 62);
    // root = insert(root, 80);
    root = insert(root, 11);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 12);
    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 6);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    // printf("\nDelete 30\n");
    // root = deleteNode(root, 30);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);
 
    // printf("\nDelete 50\n");
    // root = deleteNode(root, 50);
    // printf("Inorder traversal of the modified tree \n");
    // inorder(root);
 my_clear_tree(root);
    return 0;
}