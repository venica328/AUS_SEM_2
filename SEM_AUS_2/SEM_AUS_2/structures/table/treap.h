#pragma once

#include "binary_search_tree.h"
#include <random>

namespace structures
{
	/// <summary> Prvok treap-u. </summary>
	/// <typeparam name = "K"> Kluc prvku. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template <typename K, typename T>
	class TreapItem : public TableItem<K, T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		/// <param name = "key"> Kluc prvku. </param>
		/// <param name = "data"> Data, ktore uchovava. </param>
		/// <param name = "priority"> Priorita. </param>
		TreapItem(K key, T data, int priority);

		/// <summary> Getter atributu priorita. </summary>
		/// <returns> Priorita. </returns>
		int getPriority();

		/// <summary> Nastavi minimalnu prioritu. </summary>
		void minimizePriority();
	private:
		/// <summary> Kluc prvku. </summary>
		int priority_;
	};

	/// <summary> Treap. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class Treap : public BinarySearchTree<K, T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		Treap();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Treap, z ktoreho sa prevezmu vlastnosti. </param>
		Treap(const Treap<K, T>& other);

		/// <summary> Destruktor. </summary>
		~Treap();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Binarny vyhladavaci strom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		BinarySearchTree<K, T>& operator=(const BinarySearchTree<K, T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Treap, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		virtual Treap<K, T>& operator=(const Treap<K, T>& other);

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>  
		void insert(const K& key, const T& data) override;

		/// <summary> Odstrani z tabulky prvok s danym klucom. </summary>
		/// <param name = "key"> Kluc prvku. </param>
		/// <returns> Odstranene data. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka neobsahuje data s takymto klucom. </exception>  
		T remove(const K& key) override;

	private:
		/// <summary> Generator nahodnej priority. </summary>
		std::default_random_engine* generator_;

		/// <summary> Skontroluje, ci je haldove usporiadanie prvkov okolo vrcholu OK. </summary>
		/// <param name = "node"> Vrchol, ktoreho susedstvo sa kontroluje. </param>
		/// <returns> true, ak je haldove usporiadanie prvkov okolo vrcholu OK, false inak. </returns>
		bool isHeapOK(BinarySearchTree<K, T>::BSTTreeNode* node);

		/// <summary> Vytiahne prioritu z vrcholu stromu. </summary>
		/// <param name = "node"> Vrchol, ktoreho priorita ma byt zistena. </param>
		/// <returns> Priorita vrcholu. Ak je vrchol nullptr, vrati -1. </returns>
		int extractPriority(BinarySearchTree<K, T>::BSTTreeNode* node);

		/// <summary> Spravi lavu rotaciu vrchola okolo otca. </summary>
		/// <param name = "node"> Vrchol, ktory sa bude rotovat. </param>
		/// <remarks> 
		/// Musi byt pravym synom otca!
		/// Zaujme miesto svojho otca.
		/// Otec sa stane lavym synom tohto vrchola.
		/// Potencialny lavy syn tohto vrchola sa stane pravym synom otca.
		/// </remarks>
		void rotateLeftOverParent(BinarySearchTree<K, T>::BSTTreeNode* node);

		/// <summary> Spravi pravu rotaciu vrchola okolo otca. </summary>
		/// <param name = "node"> Vrchol, ktory sa bude rotovat. </param>
		/// <remarks> 
		/// Musi byt lavym synom otca!
		/// Zaujme miesto svojho otca.
		/// Otec sa stane pravym synom tohto vrchola.
		/// Potencialny pravy syn tohto vrchola sa stane lavym synom otca.
		/// </remarks>
		void rotateRightOverParent(BinarySearchTree<K, T>::BSTTreeNode* node);
	};

	template<typename K, typename T>
	inline TreapItem<K, T>::TreapItem(K key, T data, int priority) :
		TableItem<K, T>(key, data),
		priority_(priority)
	{
	}

	template<typename K, typename T>
	inline int TreapItem<K, T>::getPriority()
	{
		return priority_;
	}

	template<typename K, typename T>
	inline void TreapItem<K, T>::minimizePriority()
	{
		priority_ = INT_MAX;
	}

	template<typename K, typename T>
	inline Treap<K, T>::Treap() :
		BinarySearchTree<K, T>(),
		generator_(new std::default_random_engine())
	{
	}

	template<typename K, typename T>
	inline Treap<K, T>::Treap(const Treap<K, T>& other) :
		Treap()
	{
		*this = other;
	}

	template<typename K, typename T>
	inline Treap<K, T>::~Treap()
	{
		delete generator_;
		generator_ = nullptr;
	}

	template<typename K, typename T>
	inline Structure* Treap<K, T>::clone() const
	{
		return new Treap<K, T>(*this);
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>& Treap<K, T>::operator=(const BinarySearchTree<K, T>& other)
	{
		return *this = dynamic_cast<const Treap<K, T>&>(other);
	}

	template<typename K, typename T>
	inline Treap<K, T>& Treap<K, T>::operator=(const Treap<K, T>& other)
	{
		if (this != &other)
		{
			BinarySearchTree<K, T>::operator=(other);
			(*generator_) = *other.generator_;
		}
		return *this;
	}

	template<typename K, typename T>
	inline void Treap<K, T>::insert(const K& key, const T& data)
	{
		TreapItem<K, T>* treapItem = new TreapItem<K, T>(key, data, (*generator_)());
		typename BinarySearchTree<K, T>::BSTTreeNode* treapNode = new typename BinarySearchTree<K, T>::BSTTreeNode(treapItem);

		//bez typename neslo najst treapNode
		//priorita otca je vzdy vyssia ako synovia nanajvys rovnaka!!!
		//priorita nemoze byt nizsia ako hranica INT_MIN
		//pri vkladani vygenerujeme nah. priroritu a ak nie je splnene haldove usporiadfanie treba treap konsolidovat pomocou rotacii
		if (tryToInsertNode(treapNode))
		{
			//vrati nam otca..jeho prioritu
			int fatherPriority = this->extractPriority(treapNode->getParent());
			while (fatherPriority >= treapItem->getPriority() && fatherPriority >= INT_MIN)
			{
				if (treapNode->isRightSon())
				{
					rotateLeftOverParent(treapNode);
				}
				else
				{
					rotateRightOverParent(treapNode);
				}
				//zistit ci netreba vymenit otca ak je novy treapNode korenom
				bool newFather = treapNode->getParent()->isRoot();
				if (newFather)
				{
					binaryTree_->replaceRoot(treapNode);
				}
				//potom je novy otec s prioritou
				fatherPriority = this->extractPriority(treapNode->getParent());
			}
		}
		else
		{
			//inak sa to nepodarilo musime zmazat co sme vytvorili
			delete treapItem;
			delete treapNode;
		}
	}

	/// <summary>
	/// Pomocou metÛdy findBSTNode()n·jde vrchol s kæ˙Ëom key.Ak vrchol s dan˝m kæ˙Ëom existuje, 
	/// pomocou metÛdy minimizePriority()implementovanej v triede TreapItem<K,T>mu je umelo nav˝öen· hodnota 
	/// priority na maxim·lnu moûn˙a pomocou rot·ciÌ je premiestÚovan˝ smerom klistom, pokiaæ treapnebude 
	/// vykazovaù korektnÈ haldovÈusporiadanie.N·sledne je pomocou metÛdy extractNode()odstr·nen˝ z bin·rneho stromu, 
	/// ktor˝ sa nach·dza v treap-e.Ak vrchol s dan˝m kæ˙Ëom neexistuje, vyhodÌ sa v˝nimka.
	/// (Nezabudnite aktualizovaù atrib˙t size_z BinarySearchTree<K,T>.)
	/// </summary>
	/// <typeparam name="K"></typeparam>
	/// <typeparam name="T"></typeparam>
	/// <param name="key"></param>
	/// <returns></returns>
	template<typename K, typename T>
	inline T Treap<K, T>::remove(const K& key)
	{
		bool found = false;
		typename BinarySearchTree<K, T>::BSTTreeNode* deletedNode = this->findBSTNode(key, found);

		if (found) {
			TreapItem<K, T>* treapItem = dynamic_cast<TreapItem<K, T>*>(deletedNode->accessData());
			treapItem->minimizePriority();

			int leftSonPriority = extractPriority(deletedNode->getLeftSon());
			int rightSonPriority = extractPriority(deletedNode->getRightSon());

			while (leftSonPriority != INT_MIN || rightSonPriority != INT_MIN) {
				typename BinarySearchTree<K, T>::BSTTreeNode* rotateSon = nullptr;

				if (leftSonPriority != INT_MIN && rightSonPriority != INT_MIN) {
					if (leftSonPriority < rightSonPriority)
					{
						rotateSon = deletedNode->getLeftSon();
					}
					else
					{
						rotateSon = deletedNode->getRightSon();
					}
				}
				else
				{
					if (leftSonPriority != INT_MIN)
					{
						rotateSon = deletedNode->getLeftSon();
					}
					else
					{
						rotateSon = deletedNode->getRightSon();
					}
				}

				rotateSon->isLeftSon() ? rotateRightOverParent(rotateSon) : rotateLeftOverParent(rotateSon);

				bool newRoot = deletedNode->isRoot();
				if (newRoot)
				{
					this->binaryTree_->replaceRoot(rotateSon);
				}

				leftSonPriority = extractPriority(deletedNode->getLeftSon());
				rightSonPriority = extractPriority(deletedNode->getRightSon());
			}
			extractNode(deletedNode);

			T result = deletedNode->accessData()->accessData();
			delete deletedNode->accessData();
			delete deletedNode;
			size_--;

			return result;
		}
		else
		{
			throw std::logic_error("Key for remove not found!");
		}
	}

	template<typename K, typename T>
	inline bool Treap<K, T>::isHeapOK(BinarySearchTree<K, T>::BSTTreeNode* node)
	{
		if (node != nullptr)
		{
			int priority = this->extractPriority(node);
			int priorityFather = this->extractPriority(node->getParent());
			int priorityRightSon = this->extractPriority(node->getRightSon());
			int priorityLefttSon = this->extractPriority(node->getLeftSon());

			if ((priorityFather <= priority) && (priorityRightSon >= priority) && (priorityLefttSon >= priority))
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}

	template<typename K, typename T>
	inline int Treap<K, T>::extractPriority(BinarySearchTree<K, T>::BSTTreeNode* node)
	{
		if (node != nullptr)
		{
			return dynamic_cast<TreapItem<K, T>*>(node->accessData())->getPriority();
		}
		else
		{
			return INT_MIN;
		}
	}

	template<typename K, typename T>
	inline void Treap<K, T>::rotateLeftOverParent(BinarySearchTree<K, T>::BSTTreeNode* node)
	{
		if (node->isRightSon())
		{
			typename BinarySearchTree<K, T>::BSTTreeNode* leftNode = node->changeLeftSon(nullptr);
			typename BinarySearchTree<K, T>::BSTTreeNode* fatherNode = node->getParent();
			typename BinarySearchTree<K, T>::BSTTreeNode* grandFather = fatherNode->getParent();
			fatherNode->setRightSon(nullptr);

			if (grandFather != nullptr)
			{
				fatherNode->isLeftSon() ? grandFather->setLeftSon(node) : grandFather->setRightSon(node);
			}

			fatherNode->setRightSon(leftNode);
			node->setLeftSon(fatherNode);
		}
	}

	template<typename K, typename T>
	inline void Treap<K, T>::rotateRightOverParent(BinarySearchTree<K, T>::BSTTreeNode* node)
	{
		if (node->isLeftSon())
		{
			typename BinarySearchTree<K, T>::BSTTreeNode* rightNode = node->changeRightSon(nullptr);
			typename BinarySearchTree<K, T>::BSTTreeNode* fatherNode = node->getParent();
			typename BinarySearchTree<K, T>::BSTTreeNode* grandFather = fatherNode->getParent();
			fatherNode->setLeftSon(nullptr);

			if (grandFather != nullptr)
			{
				fatherNode->isLeftSon() ? grandFather->setLeftSon(node) : grandFather->setRightSon(node);
			}

			fatherNode->setLeftSon(rightNode);
			node->setRightSon(fatherNode);
		}
	}
}