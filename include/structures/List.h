/*
 * List.h
 *
 *  Created on: 20/05/2014
 *      Author: ranieri
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <stdexcept>

template<typename T>
class List {
	struct node {
		node(node* pred, node* succ, const T& item) :
				pred(pred), succ(succ), item(item) {
		}

		node* pred;
		node *succ;
		T item;
	};

	/* wardddd */
	node *sentinel;
	int count;

	template<typename U>
	class iterator_base {
	public:
		iterator_base(node* ptr) :
				ptr(ptr) {
		}

		iterator_base& operator=(const iterator_base& other) {
			if (!this == other) {
				return this(other);
			} else {
				return this;
			}
		}

		iterator_base& operator++() {
			this->ptr = this->ptr->succ;
			return *this;
		}

		iterator_base operator++(int) {
			iterator_base other(this);
			++this;
			return other;
		}

		iterator_base& operator--() {
			this->ptr = this->ptr->pred;
			return *this;
		}

		iterator_base operator--(int) {
			iterator_base other(this);
			--this;
			return other;
		}

		bool operator==(const iterator_base& other) const {
			return this->ptr == other.ptr;
		}

		bool operator!=(const iterator_base& other) const {
			return !(*this == other);
		}

		U& operator*() const {
			return this->ptr->item;
		}

		U* operator->() const {
			return &(this->ptr->item);
		}

	private:
		node* ptr;
	};

public:
	List() :
			sentinel(new node(0, 0, T())), count(0) {
		sentinel->succ = sentinel->pred = sentinel;
	}

	virtual ~List() {
		while (sentinel->succ != sentinel) {
			this->sentinel->succ = this->sentinel->succ->succ;
			delete this->sentinel->succ->pred;
		}
	}

	bool empty() const {
		return this->count == 0;
	}

	int length() const {
		return this->count;
	}

	T back() const {
		return sentinel->pred->item;
	}

	T front() const {
		return sentinel->succ->item;
	}

	/**
	 * Operações de inserção
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

		node *aux = sentinel;
		for (int i = 0; i < position; ++i) {
			aux = aux->succ;
		}

		/*
		 * Mudar o predecessor do sucessor de aux ->
		 *** Sucessor do predecessor de aux aponta para novo item
		 *** Predecessor de aux aponta para novo item
		 * Tempo: O(1)
		 */
		aux->pred = aux->pred->succ = new node(aux->pred, aux, item);
		++count;
	}

	void push_back(const T& item) {
		/*
		 * Mudar o predecessor do sucessor da sentinela ->
		 *** Sucessor do predecessor da sentinela aponta para novo item
		 *** Predecessor da sentinela aponta para novo item
		 */
		sentinel->pred = sentinel->pred->succ = new node(sentinel->pred,
				sentinel, item);
		++this->count;
	}

	void push_front(const T& item) {
		/*
		 * Mudar o sucessor do predecessor da sentinela ->
		 *** Predecessor do sucessor da sentinela aponta para novo item
		 *** Sucessor da sentinela aponta para novo item
		 */
		sentinel->succ = sentinel->succ->pred = new node(sentinel,
				sentinel->succ, item);
		++this->count;
	}

	/**
	 * Operações de remoção
	 */
	T pop_back() {
		if (this->count) {
			T removed = this->sentinel->pred->item;
			this->sentinel->pred = this->sentinel->pred->pred;
			delete this->sentinel->pred->succ;
			this->sentinel->pred->succ = 0;
			--this->count;
			return removed;
		} else {
			throw std::out_of_range("Empty list.");
		}
	}

	T pop(int position) {
		if (position == 0) {
			return this->pop_front();
		} else if (position == this->count - 1) {
			return this->pop_back();
		} else if (position < 0 && position >= this->count) {
			throw std::out_of_range("Invalid position.");
		}
		node* exNode = this->sentinel; // será o nó que estava na posição escolhida
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

	T pop_front() {
		if (this->empty()) {
			throw std::out_of_range("Empty list.");
		} else {
			T removed = this->sentinel->item;
			this->sentinel = this->sentinel->succ;
			delete this->sentinel->pred;
			this->sentinel->pred = 0;
			--this->count;
			return removed;
		}
	}

	typedef iterator_base<T> iterator;
	typedef iterator_base<const T> const_iterator;

	iterator begin() {
		return iterator(this->sentinel->succ);
	}

	iterator end() {
		return iterator(this->sentinel);
	}

	iterator rbegin() {
		return iterator(this->sentinel->pred);
	}

	iterator rend() {
		return iterator(this->sentinel);
	}

	const_iterator begin() const {
		return const_iterator(this->sentinel->succ);
	}

	const_iterator end() const {
		return const_iterator(this->sentinel);
	}

	const_iterator rbegin() const {
		return const_iterator(this->sentinel->pred);
	}

	const_iterator rend() const {
		return const_iterator(this->sentinel);
	}
};

#endif /* LIST_H_ */
