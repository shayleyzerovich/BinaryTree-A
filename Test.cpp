#include "doctest.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "BinaryTree.hpp"

using namespace std;
using namespace ariel;
BinaryTree<int>intTree;
BinaryTree<double>doubleTree;
BinaryTree<string> stringTree;
BinaryTree<int> intBad;


TEST_CASE("initialization for intTree "){

CHECK_NOTHROW(intTree.add_root(1));
CHECK_NOTHROW(intTree.add_left(1, 2));    
CHECK_NOTHROW(intTree.add_left(2, 3));     
CHECK_NOTHROW(intTree.add_right(2, 4));     
CHECK_NOTHROW(intTree.add_right(1, 5));
CHECK_NOTHROW(intTree.add_left(1, 6));

/* should look like this:
    1
    |--------|
    6       5
    |---|
    3   4
*/

int preorderArr[] = {1, 6, 3, 4, 5};

int i = 0;
for (auto it=intTree.begin_preorder(); it!=intTree.end_preorder(); ++it) {
    CHECK((*it) == preorderArr[i]);
    i++;
    }

int inorderArr[] = {3,6,4,1,5};

i = 0;
for (auto it=intTree.begin_inorder(); it!=intTree.end_inorder(); ++it) {
        CHECK((*it) == inorderArr[i]);
        i++;
    }

int postorderArr[] = {3,4,6,5,1};

i = 0;
for (auto it=stringTree.begin_postorder(); it!=stringTree.end_postorder(); ++it) {
    CHECK((*it) == postorderArr[i]);
        i++;
    }

}

TEST_CASE("initialization for doubleTree "){

CHECK_NOTHROW(intTree.add_root(1.5));
CHECK_NOTHROW(intTree.add_left(1.5, 2.3));    
CHECK_NOTHROW(intTree.add_left(2.3, 3.8));     
CHECK_NOTHROW(intTree.add_right(2.3, 4.1));     
CHECK_NOTHROW(intTree.add_right(1.5, 5.7));
CHECK_NOTHROW(intTree.add_left(1.5, 6.3));

/* should look like this:
    1.5
    |----------|
    6.3       5.7
    |------|
    3.8   4.1
*/

double preorderArr[] = {1.5, 6.3, 3.8, 4.1, 5.7};

int i = 0;
for (auto it=doubleTree.begin_preorder(); it!=doubleTree.end_preorder(); ++it) {
    CHECK((*it) == preorderArr[i]);
    i++;
    }

double inorderArr[] = {3.8,6.3,4.1,1.5,5.7};

i = 0;
for (auto it=doubleTree.begin_inorder(); it!=doubleTree.end_inorder(); ++it) {
        CHECK((*it) == inorderArr[i]);
        i++;
    }

double postorderArr[] = {3.8,4.1,6.3,5.7,1.5};

i = 0;
for (auto it=doubleTree.begin_postorder(); it!=doubleTree.end_postorder(); ++it) {
    CHECK((*it) == postorderArr[i]);
        i++;
    }
}

TEST_CASE("initialization for stringTree "){

CHECK_NOTHROW(stringTree.add_root("hey"));
CHECK_NOTHROW(stringTree.add_left("hey", "everyone"));    
CHECK_NOTHROW(stringTree.add_left("everyone", "is"));     
CHECK_NOTHROW(stringTree.add_right("everyone", "shay"));     
CHECK_NOTHROW(stringTree.add_right("hey", "name"));
CHECK_NOTHROW(stringTree.add_left("hey", "my"));

/* should look like this:
    "hey"
    |-------------|
    "my"         "name"
    |---------|
    "is"   "shay"
*/

string preorderArr[] = {"hey", "my", "is", "shay", "name"};

int i = 0;
for (auto it=stringTree.begin_preorder(); it!=stringTree.end_preorder(); ++it) {
    CHECK((*it) == preorderArr[i]);
    i++;
    }

string inorderArr[] = {"is", "my", "shay", "hey", "name"};

i = 0;
for (auto it=stringTree.begin_inorder(); it!=stringTree.end_inorder(); ++it) {
        CHECK((*it) == inorderArr[i]);
        i++;
    }


string postorderArr[] = {"is", "shay", "my", "name", "hey"};

i = 0;
for (auto it=stringTree.begin_postorder(); it!=stringTree.end_postorder(); ++it) {
    CHECK((*it) == postorderArr[i]);
        i++;
    }

i = 0;
for (auto it=stringTree.begin_postorder(); it!=stringTree.end_postorder(); ++it) {
        CHECK(it->size() == postorderArr[i].size());
        i++;
    }

i = 0;
for (const string& element: stringTree) {  
        CHECK(element == inorderArr[i]);
        i++;
    }  
}


TEST_CASE("Bad initialization") {

    CHECK_NOTHROW(intBad.add_root(1));
    CHECK_NOTHROW(intBad.add_root(1)); // same value twice
    CHECK_NOTHROW(intBad.add_right(1, 5));
    CHECK_THROWS(intBad.add_left(6, 8)); // 6 is not the root
    CHECK_THROWS(intBad.add_right(3, 2)); // 3 is not in the tree

    CHECK_NOTHROW(intBad.add_root(3)); 
    CHECK_THROWS(intBad.add_left(1, 9)); // is not the root
    CHECK_THROWS(intBad.add_right(1, 7)); // same as above

    CHECK_NOTHROW(intBad.add_right(3, 2)); 
    CHECK_THROWS(intBad.add_left(19, 42));//19 is not in the tree
    CHECK_NOTHROW(intBad.add_root(9));
    CHECK_NOTHROW(intBad.add_left(3, 6));

/* should look like this:
    3
    |-------------|
    6             5 

*/
    int postorderArr[] = {6, 5, 3};

    int i = 0;
    bool flag;
    for (auto it=intBad.begin_preorder(); it!=intBad.end_preorder(); ++it) {
        CHECK_FALSE((*it) == postorderArr[i]);
        i++;
    }

    CHECK_THROWS(intBad.add_right(1, 6)); // 4 is not in the tree
   

}

TEST_CASE("print intTree"){
    CHECK_NOTHROW( cout << intTree << endl);
}

TEST_CASE("print stringTree"){
    CHECK_NOTHROW( cout << stringTree << endl);
}

TEST_CASE("print doubleTree"){
    CHECK_NOTHROW( cout << doubleTree << endl);
}

TEST_CASE("print intBad"){
     CHECK_NOTHROW(cout << intBad << endl);
}



