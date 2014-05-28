/*
 * List.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef LIST_H_
#define LIST_H_

#include <iterator>
#include <iostream>
#include <stdexcept>

namespace structures {

template<typename T>
class List {
	struct node {
		node(node* pred, node* succ, const T& item) :
				pred(pred), succ(succ), item(item) {
		}

		node* pred;
		node* succ;
		T item;
	};

	node* _sentinel { new node { 0, 0, T() } };
	int count { };

	template<typename U>
	class iterator_base {
	public:
		iterator_base(node* ptr = 0) :
				ptr(ptr) {
		}

		iterator_base& operator++() {
			ptr = ptr->succ;
			return *this;
		}

		iterator_base operator++(int) {
			iterator_base other(*this);
			ptr = ptr->succ;
			return other;
		}

		iterator_base& operator--() {
			ptr = ptr->pred;
			return *this;
		}

		iterator_base operator--(int) {
			iterator_base other(*this);
			ptr = ptr->pred;
			return other;
		}

		bool operator==(const iterator_base& other) const {
			return ptr == other.ptr;
		}

		bool operator!=(const iterator_base& other) const {
			return ptr != other.ptr;
		}

		U& operator*() const {
			return ptr->item;
		}

		U* operator->() const {
			return &(ptr->item);
		}

	private:
		node* ptr;
	};

public:
	/**
	 * @brief Swap de lista
	 * @param a Lista origem
	 * @param b Lista destino
	 */
	friend void swap(List &a, List&b) {
		using std::swap;

		swap(a._sentinel, b._sentinel);
		swap(a.count, b.count);
	}

	/**
	 * @brief Construtor padrão de List.
	 */
	List() {
		_sentinel->succ = _sentinel->pred = _sentinel;
	}

	/**
	 * @brief Construtor de cópia de List.
	 * @param other List a ser copiada.
	 */
	List(const List& other) :
			List() {
		for (auto &element : other) {
			push_back(element);
		}
	}

	/**
	 * @brief Destrutor de List.
	 */
	~List() {
		while (_sentinel->succ != _sentinel) {
			this->_sentinel->succ = this->_sentinel->succ->succ;
			delete this->_sentinel->succ->pred;
		}

		delete _sentinel;
	}

	/**
	 * @brief Operador de assignment de List
	 * @param other List a ser copiada.
	 * @return
	 */
	List& operator=(List other) {
		swap(*this, other);
		return *this;
	}

	/**
	 * @brief Verifica se a List contém elementos ou não.
	 * @return List está vazia.
	 */
	bool empty() const {
		return count == 0;
	}

	/**
	 * @brief Quantidade de elementos dentro da List.
	 * @return Quantidade de elementos.
	 */
	int size() const {
		return count;
	}

	/**
	 * @brief Retorna uma cópia de um elemento na posição requisitada.
	 * @param position Posição requisitada.
	 * @return Elemento na posição.
	 */
	T at(int position) const {
		if (position == 0) {
			return this->front();
		} else if (position == count - 1) {
			return this->back();
		} else if (position < 0 || position >= count) {
			throw std::out_of_range("Invalid position.");
		}

		node* p = _sentinel->succ;
		for (int i = 0; i < position; ++i)
			p = p->succ;
		return p->item;
	}

	/**
	 * @brief Retorna uma cópia do elemento na última posição da List.
	 * @return Elemento na última posição.
	 */
	T back() const {
		return _sentinel->pred->item;
	}

	/**
	 * @brief Retorna uma cópia do elemento na primeira posição da List.
	 * @return Elemento na primeira posição.
	 */
	T front() const {
		return _sentinel->succ->item;
	}

	/**
	 * @brief Insere um elemento na posição requisitada da List.
	 * @param position Posição requisitada.
	 * @param item Item a ser inserido.
	 */
	void push(int position, const T& item) {
		if (position == 0) {
			push_front(item);
			return;
		} else if (position == count) {
			push_back(item);
			return;
		} else if (position < 0 || position > count) {
			throw std::out_of_range("Inserting out of bounds");
		}

		node* aux = _sentinel->succ;
		for (int i = 0; i < position; ++i) {
			aux = aux->succ;
		}

		aux->pred = aux->pred->succ = new node(aux->pred, aux, item);
		++count;
	}

	/**
	 * @brief Insere um elemento no final da List.
	 * @param item Item a ser inserido.
	 */
	void push_back(const T& item) {
		_sentinel->pred = _sentinel->pred->succ = new node(_sentinel->pred,
				_sentinel, item);
		++this->count;
	}

	/**
	 * @brief Insere um elemento no início da List.
	 * @param item Item a ser inserido.
	 */
	void push_front(const T& item) {
		_sentinel->succ = _sentinel->succ->pred = new node(_sentinel,
				_sentinel->succ, item);
		++this->count;
	}

	/**
	 * @brief Remove um elemento do final da List.
	 * @return Elemento que estava no final da List.
	 */
	T pop_back() {
		if (this->empty()) {
			throw std::out_of_range("Empty list.");
		}

		T removed = this->_sentinel->pred->item;
		this->_sentinel->pred = this->_sentinel->pred->pred;
		delete this->_sentinel->pred->succ;
		this->_sentinel->pred->succ = this->_sentinel;
		--this->count;
		return removed;
	}

	/**
	 * @brief Remove um elemento da posição requisitada da List.
	 * @param position Posição requisitada.
	 * @return Elemento que estava na posição requisitada.
	 */
	T pop(int position) {
		if (position == 0) {
			return this->pop_front();
		} else if (position == this->count - 1) {
			return this->pop_back();
		} else if (position < 0 || position >= this->count) {
			throw std::out_of_range("Invalid position.");
		}

		node* exNode = this->_sentinel->succ; // será o nó que estava na posição escolhida
		for (int i = 0; i < position; ++i) {
			exNode = exNode->succ;
		}
		T removed = exNode->item;
		exNode->pred->succ = exNode->succ;
		exNode->succ->pred = exNode->pred;
		delete exNode;
		--this->count;
		return removed;
	}

	/**
	 * @brief Remove um elemento do início da lista.
	 * @return Elemento que estava no início da List.
	 */
	T pop_front() {
		if (this->empty()) {
			throw std::out_of_range("Empty list.");
		}

		T removed = this->_sentinel->succ->item;
		this->_sentinel->succ = this->_sentinel->succ->succ;
		delete this->_sentinel->succ->pred;
		this->_sentinel->succ->pred = this->_sentinel;
		--this->count;
		return removed;
	}

	/**
	 * @brief Iterator não-const sobre a List.
	 */
	using iterator = iterator_base<T>;

	/**
	 * @brief Iterator const sobre a List.
	 */
	using const_iterator = iterator_base<const T>;

	/**
	 * @return Iterator não-const posicionado no início da List.
	 */
	iterator begin() {
		return iterator(_sentinel->succ);
	}

	/**
	 * @return Iterator não-const posicionado um elemento além do final da List.
	 */
	iterator end() {
		return iterator(_sentinel);
	}

	/**
	 * @return Iterator reverso não-const posicionado no final da List.
	 */
	iterator rbegin() {
		return iterator(_sentinel->pred);
	}

	/**
	 * @return Iterator reverso não-const posicionado um elemento além do início da List.
	 */
	iterator rend() {
		return iterator(_sentinel);
	}

	/**
	 * @return Iterator const posicionado no início da List.
	 */
	const_iterator begin() const {
		return const_iterator(_sentinel->succ);
	}

	/**
	 * @return Iterator const posicionado um elemento além do final da List.
	 */
	const_iterator end() const {
		return const_iterator(_sentinel);
	}

	/**
	 * @return Iterator reverso const posicionado no final da List.
	 */
	const_iterator rbegin() const {
		return const_iterator(_sentinel->pred);
	}

	/**
	 * @return Iterator reverso const posicionado um elemento além do início da List.
	 */
	const_iterator rend() const {
		return const_iterator(_sentinel);
	}
};

using std::begin;
using std::end;

}

#endif /* LIST_H_ */
