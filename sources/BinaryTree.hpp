#include <iostream>
using namespace std;

namespace ariel {

	template<typename T>
	class BinaryTree {

		class Node {
			friend class BinaryTree;
		private:
			T value;
			Node* left;
			Node* right;
			Node* root;
		};

		class PreorderIterator {
		private:
			Node* PreOrderNode;
		public:
			PreorderIterator(Node* root = nullptr) {}
			~PreorderIterator() {}

			bool operator!=(const PreorderIterator&) { return false; }
			bool operator==(const PreorderIterator&) { return true; }
			T& operator* () const { static T t; return t; }
			PreorderIterator& operator++() { return *this; }
			PreorderIterator operator++(int value) { return *this; }
			PreorderIterator& operator--() { return *this; }
			PreorderIterator  operator-- (int value) { return *this; }
			T* operator->() { return &(PreOrderNode->value); }
		};

		class InorderIterator {
		private:
			Node* InOrderNode;
		public:
			InorderIterator(Node* root = nullptr) {}
			~InorderIterator() {}
			bool operator!=(const InorderIterator&) { return false; }
			bool operator==(const InorderIterator&) { return true; }
			const T& operator*() const { static T t; return t; }
			InorderIterator& operator++() { return *this; }
			InorderIterator operator++(int value) { return *this; }
			InorderIterator& operator--() { return *this; }
			InorderIterator operator--(int value) { return *this; }
			T* operator->() { return &(InOrderNode->value); }
		};

		class PostorderIterator {
		private:
			Node* PostOrderNode;
		public:
			PostorderIterator(Node* root = nullptr) {}
			~PostorderIterator() {}
			bool operator!=(const PostorderIterator&) { return false; }
			bool operator==(const PostorderIterator&) { return true; }
			T& operator*() const { static T t; return t; }
			PostorderIterator& operator++() { return *this; }
			PostorderIterator operator++(int value) { return *this; }
			PostorderIterator& operator--() { return *this; }
			PostorderIterator  operator--(int value) { return *this; }
			T* operator->() { return &(PostOrderNode->value); }

		};
	private:
		Node* root;

	public:
		BinaryTree() : root(nullptr) {}
		BinaryTree(BinaryTree* binarytree);
		~BinaryTree() {}
		BinaryTree& add_root(T value) { return *this; }
		BinaryTree& add_left(T rootVal, T LeftVal) { return *this; }
		BinaryTree& add_right(T rootVal, T RightVal) { return *this; }
		InorderIterator begin() {
			begin_inorder();
			return root;
		}
		InorderIterator end() {
			end_inorder();
			return InorderIterator();
		}
		PreorderIterator begin_preorder() { return PreorderIterator(root); }
		PreorderIterator end_preorder() { return PreorderIterator(); }

		InorderIterator begin_inorder() { return InorderIterator(root); }
		InorderIterator end_inorder() { return InorderIterator(); }

		PostorderIterator begin_postorder() { return PostorderIterator(root); }
		PostorderIterator end_postorder() { return PostorderIterator(); }

		bool operator==(const BinaryTree& Tree) { return true; }
		bool operator!=(const BinaryTree& Tree) { return false; }

		friend std::ostream& operator<<(std::ostream& os, const BinaryTree& binaryTree);
	};
}