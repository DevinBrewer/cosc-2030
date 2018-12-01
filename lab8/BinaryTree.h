// BinaryTree.h

// A binary tree class using an embedded class for the nodes.
// All code is implemented here in the .h file.

// tom bailey   26 mar 01

// cleaned for lab use
// tom bailey   0820  18 oct 2010
// tom bailey   0850  4 apr 2011


#ifndef _BIN_TREE_H_
#define _BIN_TREE_H_


#include "RandomUtilities.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>


//***  Binary Tree class  ***//

class BinaryTree
{
protected:

   // Since the BinaryNode class is embedded in the BinaryTree
   //   class, the public data members and methods of
   //   BinaryNode are only visible within the BinaryTree class.
   //   Client code cannot see BinaryNode object data members
   //   or methods.
   class BinaryNode
   {
   public:
      short entry_;
      BinaryNode * left_;
      BinaryNode * right_;

   public:
      BinaryNode( short entry = 0,
         BinaryNode* left = NULL,
         BinaryNode* right = NULL )
         : entry_( entry ),
         left_( left ),
         right_( right )
      { }

      // NOTE: The standard BinaryNode destructor code does
      //   NOT delete BinaryNodes in the subtrees of left_ or right_.
      //   See BinaryTree destroy.
      ~BinaryNode()
      {
      }

   private:
      // Disable the BinaryNode copy constructor and the assignment
      //   operator.
      BinaryNode( const BinaryNode & );
      const BinaryNode & operator =( const BinaryNode & );
   };


public:
   // The no-parameter constructor creates an empty tree.
   BinaryTree();

   // The destructor deallocates all the nodes in the tree.
   ~BinaryTree();


   // Mutators

   // Destroy the current BinaryTree and build a randomly
   //   shaped tree of size nodes.  Node entries are
   //   successive shorts stored in the tree in
   //   preorder.
   void build( long size );


   // Accessors

   // Display the tree.
   // The node values are listed using an inorder
   //   traversal.
   // Node values are indented by the depth of the node to
   //   display the shape of the tree.
   // The tree shape is displayed with the left subtree at
   //   the top of the screen.
   void display( std::ostream& outfile ) const;


   // Several tree measures, special values, and traversals

   long size() const;

   long height() const;

   long leaves() const;

   // pre:  this BinaryTree is not empty.
   short leftmost() const;

   std::vector< short > preorder() const;


private:
   BinaryNode * tree_;
   static int btEntry_;

private:
   // Disable operator=
   BinaryTree& operator=( BinaryTree& );

   // Disable the copy constructor
   BinaryTree( const BinaryTree & );


private:
   // helper functions

   // Helper functions process a subtree.
   // Each helper function is called by a public function
   //   that fulfills a request to process the entire
   //   tree by calling the helper function that processes a
   //   subtree referenced by a pointer to its root node.
   //   The empty subtree is indicated by a NULL pointer.


   // Delete all nodes referenced via subtree.
   // Set subtree to NULL.
   static void destroy( BinaryNode * & subtree );


   // Build a random shaped tree of size nodes.
   //   The tree data values start with entry.
   //   subtree is set to point to this tree.
   //   entry is increased by size.
   static void buildRandom( long size, BinaryNode * & subtree );


   // This subtree is a left subtree.
   // Display the nodes connected to subtree on outfile.
   // Use a line by line display, order nodes from left to
   //   right, draw connecting lines.
   // Preface each line of the display with prefix.
   static void displayLeft( std::ostream & outfile,
      BinaryNode * subtree, std::string prefix );

   // This subtree is a right subtree.
   // Display the nodes connected to subtree on outfile.
   // Use a line by line display, order nodes from left to
   //   right, draw connecting lines.
   // Preface each line of the display with prefix.
   static void displayRight( std::ostream & outfile,
      BinaryNode * subtree, std::string prefix );


   // Return the number of nodes in the tree accessed by
   //   subtree.
   static long size( const BinaryNode * subtree );


   // Return the height of the tree accessed by subtree.
   static long height( const BinaryNode * subtree );


   // Return the number of leaves in the tree accessed by
   //   subtree.
   static long leaves( const BinaryNode * subtree );


   // pre:  this BinaryTree subtree is not empty.
   // Return the value in the leftmost node in the tree
   //   accessed by subtree.
   static short leftmost( const BinaryNode * subtree );


   // Write the values stored in the tree accessed by
   //   subtree.  Write the values to outfile.  Write the
   //   values in preorder.
   static void preorder( std::vector< short > & traversal,
      const BinaryNode * subtree );
};


// Set the initial value of the static binary tree entry.
int BinaryTree::btEntry_ = 1;


// Code for public methods of BinaryTree
// **********************************

// The no-parameter constructor creates an empty tree.
BinaryTree:: BinaryTree()
   : tree_( NULL )
{
}


// The destructor deallocates all the nodes in the tree.
BinaryTree:: ~BinaryTree()
{
   destroy( tree_ );
}


// BinaryTree methods
// Each method is converted to a call to one of the helper
//   functions.  The pointer to the tree root BinaryNode, tree_,
//   is passed to the helper function as an additional
//   parameter.  The additional parameter changes the
//   signature, so the same method/function name can be
//   used.  The helper functions do not need access to the
//   entire tree, so they are declared static, meaning the
//   object pointer passed to non-static methods is not
//   passed to these helper methods.


// Build a randomly shaped tree of size nodes.
void
   BinaryTree:: build( long size )
{
   destroy( tree_ );
   buildRandom( size, tree_ );
}


// Display the tree.
// The node values are ordered using an inorder traversal.
// Node values are indented by the depth of the node to display
//   the shape of the tree.
void
   BinaryTree:: display( std::ostream& outfile ) const
{
   std::string prefix;
   if( tree_ == NULL )
   {
      outfile << "-" << std::endl;
   }
   else
   {
      displayLeft( outfile, tree_->left_, "    " );
      outfile << "---" << tree_->entry_ << std::endl;
      displayRight( outfile, tree_->right_, "    " );
   }
}


long
   BinaryTree:: height() const
{
   return  height( tree_ );
}


long
   BinaryTree:: size() const
{
   return  size( tree_ );
}


long
   BinaryTree:: leaves() const
{
   return  leaves( tree_ );
}


short
   BinaryTree:: leftmost() const
{
   return  leftmost( tree_ );
}


std::vector< short >
   BinaryTree:: preorder() const
{
   std::vector< short > traversal;
   preorder( traversal, tree_ );
   return traversal;
}


// code for helper functions

// Delete all nodes connected to subtree
void
   BinaryTree:: destroy( BinaryNode * & subtree )
{
   if( subtree != NULL )
   {
      destroy( subtree->left_ );
      destroy( subtree->right_ );
      delete subtree;
      subtree = NULL;
   }
}


// Build a random shaped tree of size nodes.
// Construct the BinaryNodes in preorder sequence.
void
   BinaryTree:: buildRandom( long size, BinaryNode * & subtree )
{
   if( size == 0 )
   {
      subtree = NULL;
   }
   else
   {
      subtree = new BinaryNode( btEntry_ );
      btEntry_++;
      long leftSize = randInt( 0, size );
      buildRandom( leftSize, subtree->left_ );
      long rightSize = size - 1 - leftSize;
      buildRandom( rightSize, subtree->right_ );
   }
}


// Display the nodes connected to subtree.
// This is a left subtree.
// Use a line by line display, order nodes from left to
//   right, draw connecting lines.
void
   BinaryTree:: displayLeft( std::ostream & outfile,
   BinaryNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "/" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "     " );
      outfile << prefix + "/---" << subtree->entry_ << std::endl;
      displayRight( outfile, subtree->right_, prefix + "|    " );
   }
}


// Display the nodes connected to subtree.
// This is a right subtree.
// Use a line by line display, order nodes from left to
//   right, draw connecting lines.
void
   BinaryTree:: displayRight( std::ostream & outfile,
   BinaryNode * subtree, std::string prefix )
{
   if( subtree == NULL )
   {
      outfile << prefix + "\\" << std::endl;
   }
   else
   {
      displayLeft( outfile, subtree->left_, prefix + "|    " );
      outfile << prefix + "\\---" << subtree->entry_ << std::endl;
      displayRight( outfile, subtree->right_, prefix + "     " );
   }
}


long
   BinaryTree:: size( const BinaryNode * subtree )
{
  long s = 1;
  if (subtree->left_ != NULL) {
    s += size(subtree->left_);
  }

  if (subtree->right_ != NULL) {
    s += size(subtree->right_);
  }
   return  s;
}


long
   BinaryTree:: height( const BinaryNode * subtree )
{
   long le = 0;
   long ri = 0;

   // Check the left subtree and compare the size to the right subtree
   if (subtree->left_ != NULL) {
     le = height(subtree->left_);
   }

   if (subtree->right_ != NULL) {
     ri = height(subtree->right_);
   }

   if (le > ri) {
     return le + 1;
   } else {
     return ri + 1;
   }

}


long
   BinaryTree:: leaves( const BinaryNode * subtree )
{
   if (subtree->left_ == NULL && subtree->right_ == NULL) {
     return 1;
   }

   long l = 0;
   if (subtree->left_ != NULL) {
     l += leaves(subtree->left_);
   }
   if (subtree->right_ != NULL) {
     l += leaves(subtree->right_);
   }
   return l;
}


short
   BinaryTree:: leftmost( const BinaryNode * subtree )
{
   return -4;
}


void
   BinaryTree:: preorder( std::vector< short > & traversal,
      const BinaryNode * subtree )
{
   if( subtree != NULL )
   {
      traversal.push_back( subtree->entry_ );
      preorder( traversal, subtree->left_ );
      preorder( traversal, subtree->right_ );
   }
}

#endif
